import pandas as pd

no_stall = 'IF  ID  EX  M   W'
one_stall = 'IF  S   ID  EX  M   W'
two_stall = 'IF  S   S   ID  EX  M   W'
reg_space = '    '
path = './input2.csv'
df = pd.read_csv(path, sep=',')
df['stall'] = 0
df['space'] = 0
df['fstall'] = 0
df['fspace'] = 0


def dependency_check(row):
    if df.action[row - 1] != 'sw' and df.action[row-1] != 'lw' and df.action[row] != 'sw':
        if df.action[row] == 'beq' or df.action[row] == 'bne':
            if df.reg1[row - 1] == df.reg1[row] or df.reg1[row - 1] == df.reg2[row]:
                df.at[row, 'stall'] = 2
                print('Data Dependency with', df.reg1[row - 1], 'from instruction', row, 'and', row - 1)
        elif df.reg1[row - 1] == df.reg2[row] or df.reg1[row - 1] == df.reg3[row]:
            df.at[row, 'stall'] = 2
            print('Data Dependency with', df.reg1[row - 1], 'from instruction', row, 'and', row - 1)
    elif df.action[row] == 'sw':
        if df.reg1[row - 1] == df.reg1[row]:
            df.at[row, 'stall'] = 2
            print('Name Dependency with', df.reg1[row - 1], 'from instruction', row, 'and', row - 1)
    elif df.action[row-1] == 'lw' and df.action[row] != 'sw':
        if df.reg1[row - 1] == df.reg2[row] or df.reg1[row - 1] == df.reg3[row]:
            df.at[row, 'stall'] = 2
            df.at[row, 'fstall'] = 1
            print('Data Dependency with', df.reg1[row - 1], 'from instruction', row, 'and', row - 1)
    if row > 2 and df.action[row - 2] == 'lw' and df.action[row] == 'add':
        if df.reg1[row - 2] == df.reg2[row] or df.reg1[row - 2] == df.reg3[row]:
            df.at[row, 'stall'] = 1
            print('Data Dependency with', df.reg1[row - 2], 'from instruction', row, 'and', row - 2)


print(' \n****WITHOUT ANY SOLUTION****')
for i in range(1, df.shape[0]):
    dependency_check(i)


print(' \n****SOLUTION 1 - NO FORWARDING UNIT****')
print('', no_stall)
for i in range(1, df.shape[0]):
    df.at[i, 'space'] = df.space[i-1] + df.stall[i-1]
    if df.stall[i] == 2:
        print((df.space[i] + i) * reg_space, two_stall)
    if df.stall[i] == 1:
        print((df.space[i] + i) * reg_space, one_stall)
    elif df.stall[i] == 0:
        print((df.space[i] + i) * reg_space, no_stall)

print(' \n****SOLUTION 2 - WITH FORWARDING UNIT****')
print('', no_stall)
for i in range(1, df.shape[0]):
    # df_for.at[i, 'stall'] = forward_check(i)
    df.at[i, 'fspace'] = df.fspace[i-1] + df.fstall[i-1]
    if df.fstall[i] == 2:
        print((df.fspace[i] + i) * reg_space, two_stall)
    if df.fstall[i] == 1:
        print((df.fspace[i] + i) * reg_space, one_stall)
    elif df.fstall[i] == 0:
        print((df.fspace[i] + i) * reg_space, no_stall)
