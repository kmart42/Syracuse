# Import Libraries Required
import csv
from _ast import List

from numpy.ma import anomalies
import matplotlib
import pandas as pd
import matplotlib.pyplot as plt
matplotlib.use('TkAgg')
# %matplotlib inline
import numpy as np
import seaborn as sns


# Data source:
# Source Query location:


path = '/home/kebin/Syracuse/Syracuse/CIS600/HW1/employee_attrition.csv'
# reads the data from the file - denotes as CSV, it has no header, sets column headers
df =  pd.read_csv(path, sep=',')

# print(df.columns)
# print(df.shape)
# print(df.dtypes)
# print(df.describe())
# print(df.info())
# print(df.head(5))

# df.isnull().sum()

"""
def missing_values_table(df):
    mis_val = df.isnull().sum()
    mis_val_percent = 100 * df.isnull().sum() / len(df)
    mis_val_table = pd.concat([mis_val, mis_val_percent], axis=1)
    mis_val_table_ren_columns = mis_val_table.rename(
        columns={0: 'Missing Values', 1: '% of Total Values'})
    mis_val_table_ren_columns = mis_val_table_ren_columns[
        mis_val_table_ren_columns.iloc[:, 1] != 0].sort_values(
        '% of Total Values', ascending=False).round(1)
    print("Your selected dataframe has " + str(df.shape[1]) + " columns.\n"
                                                              "There are " + str(mis_val_table_ren_columns.shape[0]) +
          " columns that have missing values.")
    return mis_val_table_ren_columns


missing_values_table(df)

# Get the columns with > 50% missing
missing_df = missing_values_table(df);
missing_columns = list(missing_df[missing_df['% of Total Values'] > 50].index)
print('There are %d columns missing more than half the data.' % len(missing_columns))

"""


def find_anomalies(random_data):
    # Set upper and lower limit to 3 standard deviation
    random_data_std = np.std(random_data)
    random_data_mean = np.mean(random_data)
    anomaly_cut_off = random_data_std * 3

    lower_limit = random_data_mean - anomaly_cut_off
    upper_limit = random_data_mean + anomaly_cut_off
    print(lower_limit)
    # Generate outliers
    for outlier in random_data:
        if outlier > upper_limit or outlier < lower_limit:
            anomalies.append(outlier)
    return anomalies


data = np.genfromtxt(path, delimiter=',')
data2 = pd.read_csv(path, index_col=0)
# find_anomalies(data)

"""
dataframe = pd.read_csv(path)
x = dataframe.Age
y = dataframe.Attrition
# plt.scatter(x, y)
# plt.show()

sns.boxplot(data=x)
plt.show()

######
corr = data2.corr()
fig = plt.figure()
ax = fig.add_subplot(111)
cax = ax.matshow(corr,cmap='coolwarm', vmin=-1, vmax=1)
fig.colorbar(cax)
ticks = np.arange(0, len(data2.columns),1)
ax.set_xticks(ticks)
plt.xticks(rotation=90)
ax.set_yticks(ticks)
ax.set_xticklabels(data2.columns)
ax.set_yticklabels(data2.columns)
plt.show()

"""

# df.plot.scatter("Attrition", "Age")
# sns.heatmap(df.corr)#
test = sns.load_dataset(data2)
sns.pairplot(path.dropna().drop(['Attrition'], axis=1), hue='y', kind ='reg')
plt.show()
