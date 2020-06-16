#python libararies
import warnings

import numpy as np
import pandas as pd
warnings.filterwarnings("ignore")
import matplotlib.pyplot as plt
import plotly.graph_objects as go
from sklearn.metrics import mean_squared_error as mse
from sklearn.metrics import mean_absolute_error as mae
from sklearn import linear_model
from sklearn.svm import LinearSVR
from sklearn.pipeline import make_pipeline
from statistics import mode

# load my dataset as a pandas dataframe
path = '/home/kebin/Syracuse/CIS700_All/Assignment1/crypto.csv'
df = pd.read_csv(path, sep=',')

# clean dataset by dropping unnecessary columns, missing values, and adding a binary 'IsBit' flag
del_col_list = ['site_url', 'github_url', 'platform_name', 'industry_name', 'crypto_type']
df.drop(del_col_list, axis=1, inplace=True)
df.dropna(inplace=True)

# I will be focusing bitcoin, and using the btc_data data frame
btc_data = df[df['ticker']=='BTC']

# driver functions
time_data = btc_data['price_usd']
total = df[df.ticker == 'BTC'].shape[0]
test = int(round(total * .25))
train = total - test
buff = 80

prev_values = time_data.iloc[:1200]
y_train3 = time_data[buff:train]
y_test3 = time_data[train:]
X_train3 = pd.DataFrame([list(time_data[i:i + buff]) for i in range(train - buff)],
                        columns=range(buff, 0, -1), index=y_train3.index)
X_test3 = pd.DataFrame([list(time_data[i:i + buff]) for i in range(train - buff, total - buff)],
                       columns=range(buff, 0, -1), index=y_test3.index)


def plot_pred(pred, title):
    plt.figure(figsize=(17, 5))
    plt.plot(prev_values, label='Train')
    plt.plot(y_test3, label='Actual')
    plt.plot(pred, label='Predicted')
    plt.ylabel("Stock prices")
    plt.title(title, fontsize=20)
    plt.legend()
    plt.show()


def evaluate(model):
    out_mod = model.fit(X_train3, y_train3)
    y_pred_mod = model.predict(X_test3)
    print('Accuracy: ', out_mod.score(X_test3, y_test3))
    print('MSE: ', "%.2f" % mse(y_pred_mod, y_test3))
    print('MAE: ', "%.2f" % mae(y_pred_mod, y_test3))
    # return out_mod
    return y_pred_mod

# setting up the nine models
# uncomment the last two lines for each to see graph


regl = linear_model.LinearRegression()
print('Linear - 25%')
regl_train = evaluate(regl)
# regl_train_shift = pd.Series(regl_train[:],index=y_test3.index)
# plot_pred(regl_train_shift,"Linear - 25%")

regr = linear_model.Ridge(alpha=200)
print('Ridge - 25%')
regr_train = evaluate(regr)
# regr_train_shift = pd.Series(regr_train[:],index=y_test3.index)
# plot_pred(regr_train_shift,"Ridge - 25%")

reg_svr = make_pipeline(LinearSVR())
print('SVR - 25%')
regs_train = evaluate(reg_svr)
# regs_train_shift = pd.Series(regs_train[:],index=y_test3.index)
# plot_pred(regs_train_shift,"SVR - 25%")


# to keep variables separate, I created a new driver function/graph function
def data_gen(day_frac):
    tmp_data = df[df['ticker'] == 'BTC']
    price_data = tmp_data['price_usd']
    total = df[df.ticker == 'BTC'].shape[0]
    test = int(round(total * day_frac))
    train = total - test
    buff = 80

    prev = price_data.iloc[:1200]
    y_train = price_data[buff:train]
    y_test = price_data[train:]
    x_train = pd.DataFrame([list(price_data[i:i + buff]) for i in range(train - buff)],
                           columns=range(buff, 0, -1), index=y_train.index)
    x_test = pd.DataFrame([list(price_data[i:i + buff]) for i in range(train - buff, total - buff)],
                          columns=range(buff, 0, -1), index=y_test.index)

    return x_train, y_train, x_test, y_test, prev


def evaluate_tick(model, xtrain, ytrain, xtest, ytest):
    out_mod = model.fit(xtrain, ytrain)
    y_pred_mod2 = model.predict(xtest)
    print('Accuracy: ', out_mod.score(xtest, ytest))
    print('MSE: ', "%.2f" % mse(y_pred_mod2, ytest))
    # return out_mod
    return y_pred_mod2


def plot_pred_tick(pred, title, test, pre):
    plt.figure(figsize=(17, 5))
    plt.plot(pre, label='Train')
    plt.plot(test, label='Actual')  # y_test3
    plt.plot(pred, label='Predicted')
    plt.ylabel("Stock prices")
    plt.title(title, fontsize=20)
    plt.legend()
    plt.show()


train_days2 = .35
# linear
trainx2_l, trainy2_l, testx2_l, testy2_l, prev_input2_l = data_gen(train_days2)
print('Linear - 35%')
regl_train2 = evaluate_tick(regl, trainx2_l, trainy2_l, testx2_l, testy2_l)
# regl_train2_shift = pd.Series(regl_train2[:],index=testy2_l.index)
# plot_pred_tick(regl_train2_shift, 'Linear - 35%', testy2_l, prev_input2_l)

# ridge
trainx2_r, trainy2_r, testx2_r, testy2_r, prev_input2_r = data_gen(train_days2)
print('Ridge - 35%')
regr_train2 = evaluate_tick(regr, trainx2_r, trainy2_r, testx2_r, testy2_r)
# regr_train2_shift = pd.Series(regr_train2[:],index=testy2_r.index)
# plot_pred_tick(regr_train2_shift, 'Ridge - 35%', testy2_r, prev_input2_r)

# svr
trainx2_s, trainy2_s, testx2_s, testy2_s, prev_input2_s = data_gen(train_days2)
print('SVR - 35%')
regs_train2 = evaluate_tick(reg_svr, trainx2_s, trainy2_s, testx2_s, testy2_s)
# regs_train2_shift = pd.Series(regs_train2[:],index=testy2_s.index)
# plot_pred_tick(regs_train2_shift, 'SVR - 35%', testy2_s, prev_input2_s)

train_days3 = .5

# linear
trainx3_l, trainy3_l, testx3_l, testy3_l, prev_input3_l = data_gen(train_days3)
print('Linear - 50%')
regl_train3 = evaluate_tick(regl, trainx3_l, trainy3_l, testx3_l, testy3_l)
# regl_train3_shift = pd.Series(regl_train3[:],index=testy3_l.index)
# plot_pred_tick(regl_train3_shift, 'Linear - 50%', testy3_l, prev_input3_l)

# ridge
trainx3_r, trainy3_r, testx3_r, testy3_r, prev_input3_r = data_gen(train_days3)
print('Ridge - 50%')
regr_train3 = evaluate_tick(regr, trainx3_r, trainy3_r, testx3_r, testy3_r)
# regr_train3_shift = pd.Series(regr_train3[:],index=testy3_r.index)
# plot_pred_tick(regr_train3_shift, 'Ridge - 50%', testy3_r, prev_input3_r)

# svr
trainx3_s, trainy3_s, testx3_s, testy3_s, prev_input3_s = data_gen(train_days3)
print('SVR - 50%')
regs_train3 = evaluate_tick(reg_svr, trainx3_s, trainy3_s, testx3_s, testy3_s)
# regs_train3_shift = pd.Series(regs_train3[:],index=testy3_s.index)
# plot_pred_tick(regs_train3_shift, 'SVR - 50%', testy3_s, prev_input3_s)

# ensemble approaches
# hard voting
final_pred = np.array([])
for i in range(0,len(X_test3)):
    final_pred = np.append(final_pred, mode([
        regl_train[i],
        regr_train[i],
        regs_train[i],
        regl_train2[i],
        regr_train2[i],
        regs_train2[i],
        regl_train3[i],
        regr_train3[i],
        regs_train3[i],
    ]))
final_pred2 = pd.Series(final_pred[:], index=y_test3.index)
print('Ensemble: Hard Voting')
print("MSE", "%.2f" % mse(final_pred2, y_test3))
# plot_pred(final_pred2, 'Hard Voting')

# weighted
final_pred_w = np.array([])
for i in range(0, len(X_test3)):
    final_pred_w = np.append(final_pred_w, (
        .111*regl_train[i] +
        .111*regr_train[i] +
        .111*regs_train[i] +
        .111*regl_train2[i] +
        .111*regr_train2[i] +
        .111*regs_train2[i] +
        .111*regl_train3[i] +
        .111*regr_train3[i] +
        .111*regs_train3[i]
    ))
final_pred_w2 = pd.Series(final_pred_w[:], index=y_test3.index)
print('Ensemble: Equal Weighting')
print("MSE", "%.2f" % mse(final_pred_w2,y_test3))
# plot_pred(final_pred_w2, 'Weighted')

# remove quotes to see summary table if desired
# note it is already in write up portion as well
"""
table_data=[
    ['Linear Regression - 25%', .25, 0.9677, 195745.43,],
    ['Ridge Regression - 25%', .25, 0.9677, 195744.89],
    ['Linear SVR - 25%', .25, 0.9370, 382764.17],
    ['Linear Regression - 35%',.35, 0.9710, 174824.90],
    ['Ridge Regression - 35%',.35, 0.9710, 174824.38],
    ['Linear SVR - 35%',.35, 0.9788, 127628.45],
    ['Linear Regression - 50%',.5, 0.8893, 535564.03],
    ['Ridge Regression - 50%',.5, 0.8893, 535541.05],
    ['Linear SVR - 50%', .5,0.9169, 401630.79],

]
df_table = pd.DataFrame(table_data)
# sort table in descending order by accuracy
df_table = df_table.sort_values(by=[3], kind="quicksort", ascending=True)
df_table[1] = pd.Series(["{0:.1f}%".format(val * 100) for val in df_table[1]], index = df_table.index)
df_table[2] = pd.Series(["{0:.1f}%".format(val * 100) for val in df_table[2]], index = df_table.index)
fig = go.Figure(data=[go.Table(header=dict(values=['Method','Test %', 'Accuracy','MSE']),
                 cells=dict(values=[df_table[0], df_table[1], df_table[2], df_table[3]]))
                     ])
fig.show()
"""
