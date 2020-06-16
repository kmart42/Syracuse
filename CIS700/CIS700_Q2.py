#python libararies
import warnings
import numpy as np
import pandas as pd
warnings.filterwarnings("ignore")
import matplotlib.pyplot as plt
from sklearn.model_selection import train_test_split
import xgboost as xgb
from sklearn.metrics import mean_squared_error as mse
from sklearn.metrics import mean_absolute_error as mae
from sklearn.ensemble import GradientBoostingRegressor
from statistics import mode
from sklearn.preprocessing import scale
from sklearn.decomposition import PCA

# load my dataset, same setup as Q1
path = '/home/kebin/Syracuse/CIS700_All/Assignment1/crypto.csv'
df = pd.read_csv(path, sep=',')

# clean dataset by dropping unnecessary columns, missing values
del_col_list = ['site_url', 'github_url', 'platform_name', 'industry_name', 'crypto_type']
df.drop(del_col_list, axis=1, inplace=True)
df.dropna(inplace=True)
btc_data = df[df['ticker'] == 'BTC']
time_data = btc_data['price_usd']
total = df[df.ticker=='BTC'].shape[0]
test = int(round(total * .25))
train = total - test
buff = 80

prev_values = time_data.iloc[:1200]
y_train3 = time_data[buff:train]
y_test3 = time_data[train:]
X_train3 = pd.DataFrame([list(time_data[i:i+buff]) for i in range(train - buff)],
                       columns=range(buff,0,-1),index=y_train3.index)
X_test3 = pd.DataFrame([list(time_data[i:i+buff]) for i in range(train - buff,total - buff)],
                       columns=range(buff,0,-1),index=y_test3.index)


def plot_pred(pred,title):
    plt.figure(figsize=(17,5))
    plt.plot(prev_values,label='Train')
    plt.plot(y_test3,label='Actual')
    plt.plot(pred,label='Predicted')
    plt.ylabel("Stock prices")
    plt.title(title,fontsize=20)
    plt.legend()
    plt.show()


def evaluate(model):
    out_mod = model.fit(X_train3, y_train3)
    y_pred_mod = model.predict(X_test3)
    print('Accuracy: ', out_mod.score(X_test3, y_test3))
    print('MSE: ',"%.2f" % mse(y_pred_mod,y_test3))
    print('MAE: ',"%.2f" % mae(y_pred_mod,y_test3))
    # return out_mod
    return y_pred_mod


final_vars = ['volume', 'market_cap', 'capitalization_change_1_day', 'max_supply', 'minable']
train_y = btc_data.price_usd.values
train_X = btc_data[final_vars]
xgb_params = {
    'eta': 0.05,
    'max_depth': 10,
    'subsample': 1.0,
    'colsample_bytree': 0.7,
    'objective': 'reg:linear',
    'eval_metric': 'rmse',
    'silent': 1
}
dtrain = xgb.DMatrix(train_X, train_y, feature_names=train_X.columns.values)
dmodel = xgb.train(dict(xgb_params, silent=1), dtrain, num_boost_round=100)
remain_num = 99

pca_check = btc_data.select_dtypes(exclude="object").values
pca_check = scale(pca_check);pca_check
covar = PCA(n_components=5)
covar.fit(pca_check)
var = covar.explained_variance_ratio_
var = np.cumsum(np.round(covar.explained_variance_ratio_, decimals=5)*100)
# uncomment print to see the amount each attribute contributes
# print(var)

result = np.where(var >= 90)
# note that printing the results below will give a value of 2, which is the third index position
# this indicates three attributes account for 90% of the variance
# print(result[0][0])

xgb_vars = ['volume', 'market_cap', 'capitalization_change_1_day']

# uncomment to see graphs, also present in write up
"""
plt.ylabel('% Variance Explained')
plt.xlabel('Number of Features')
plt.title('PCA Analysis')
plt.plot(var)
fig, ax = plt.subplots(figsize=(5,9))
xgb.plot_importance(dmodel, max_num_features=remain_num, height=0.2, ax=ax)
plt.show()

for f in [x for x in xgb_vars]:
    sns.scatterplot(y=btc_data[f].values, x=btc_data.price_usd.values, size=6)
    plt.xlabel('Price', fontsize=8)
    plt.ylabel(f, fontsize=8)
    plt.show()
"""

y = btc_data.price_usd
X = btc_data[xgb_vars]
gmodel = GradientBoostingRegressor()
gmodel.fit(X, y)
# partial dependence plots, not as useful but still available
"""
plots = plot_partial_dependence(gmodel,       
                                   features=[0, 1, 2], # column numbers of plots we want to show
                                   X=X,            # raw predictors data.
                                   feature_names=['Volume', 'Market Cap', 'cap_change'], # labels on graphs
                                   grid_resolution=10,
                                   target='price_usd') # number of values to plot on x axis
"""

# Model 1: using the xgb_vars found above
# This is the "best" model and truly the optimal result of the previous analysis
X_train, X_test, y_train, y_test = train_test_split(X,y, test_size=.2998, random_state=61)
gfit = gmodel.fit(X_train, y_train)
gpred = gfit.predict(X_test)
gpred_shift = pd.Series(gpred[:],index=y_test.index)
print('Model 1: optimal attributes')
print('MSE: ',"%.2f" % mse(gpred,y_test))
print('MAE: ',"%.2f" % mae(gpred,y_test))

"""
fig1 = go.Figure()
fig1.add_trace(go.Scatter(y=btc_data.iloc[btc_data.shape[0]-100:]['price_usd'], name='Real price'))
fig1.add_trace(go.Scatter(y=gpred_shift[-100:], name='Predict price'))
fig1.show()
"""

# Model 2: using all the relevant variables
mod2_vars = ['volume', 'price_usd', 'price_btc', 'market_cap', 'capitalization_change_1_day',
            'USD_price_change_1_day', 'BTC_price_change_1_day', 'max_supply', 'minable']
X2 = btc_data[mod2_vars]
X_train2, X_test2, y_train2, y_test2 = train_test_split(X2,y, test_size=.2998, random_state=61)
gfit2 = gmodel.fit(X_train2, y_train2)
gpred2 = gfit2.predict(X_test2)
gpred2_shift = pd.Series(gpred2[:],index=y_test2.index)
print('Model 2: all relevant attributes')
print('MSE: ',"%.2f" % mse(gpred2,y_test2))
print('MAE: ',"%.2f" % mae(gpred2,y_test2))

"""
fig2 = go.Figure()
fig2.add_trace(go.Scatter(y=btc_data.iloc[btc_data.shape[0]-100:]['price_usd'], name='Real price'))
fig2.add_trace(go.Scatter(y=gpred2_shift[-100:], name='Prediction - All'))
fig2.show()
"""

# Model 3: using irrelvant/poor attributes
mod3_vars = ['max_supply', 'minable', 'USD_price_change_1_day']
X3 = btc_data[mod3_vars]
X_trainM, X_testM, y_trainM, y_testM = train_test_split(X3, y, test_size=.2998, random_state=61)
gfit3 = gmodel.fit(X_trainM, y_trainM)
gpred3 = gfit3.predict(X_testM)
gpred3_shift = pd.Series(gpred3[:],index=y_testM.index)
print('Model 3: poor attributes')
print('MSE: ',"%.2f" % mse(gpred3,y_testM))
print('MAE: ',"%.2f" % mae(gpred3,y_testM))

"""
fig2 = go.Figure()
fig2.add_trace(go.Scatter(y=btc_data.iloc[btc_data.shape[0]-100:]['price_usd'], name='Real price'))
fig2.add_trace(go.Scatter(y=gpred3_shift[-100:], name='Prediction - Poor'))
fig2.show()
"""

# ensemble approaches
# hard voting
final_pred = np.array([])
for i in range(0,len(X_test3)):
    final_pred = np.append(final_pred, mode([gpred[i], gpred2[i], gpred3[i]]))
final_pred2 = pd.Series(final_pred[:],index=y_test3.index)
print('Ensemble 1: Hard Voting')
print("MSE: ", "%.2f" % mse(final_pred2,y_test3))
print('MAE: ',"%.2f" % mae(final_pred2,y_test3))
# plot_pred(final_pred2, 'Hard Voting')

# weighted
final_pred_w = np.array([])
for i in range(0,len(X_test3)):
    final_pred_w = np.append(final_pred_w, (.33*gpred[i] + .33*gpred2[i] + .33*gpred3[i]))
final_pred_w2 = pd.Series(final_pred_w[:],index=y_test3.index)
print('Ensemble 2: Equal Weighting')
print("MSE: " "%.2f" % mse(final_pred_w2,y_test3))
print('MAE: ',"%.2f" % mae(final_pred_w2,y_test3))
# plot_pred(final_pred_w2, 'Weighted')

# summary table, if desired
"""
table_data2=[
    ['Model 1', 'Top 3 Features', 8876.25, 54.49,],
    ['Model 2', 'All Relevant Features', 2503.04, 25.91],
    ['Model 3', 'Irrelevant/Poor Features', 15483777.57, 3401.44],
    ['Ensemble 1','Hard Voting', 28019704.97, 4441.12],
    ['Ensemble 2','Weighted', 19740732.54, 3708.91],

]
df_table2 = pd.DataFrame(table_data2)
# sort table in descending order by accuracy
df_table2 = df_table2.sort_values(by=[2], kind="quicksort", ascending=True)
fig2 = go.Figure(data=[go.Table(header=dict(values=['Method','Features', 'MSE','MAE']),
                 cells=dict(values=[df_table2[0], df_table2[1], df_table2[2], df_table2[3]]))
                     ])
fig2.show()
"""
