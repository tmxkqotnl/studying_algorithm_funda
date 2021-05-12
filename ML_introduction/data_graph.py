import pandas as pd
import matplotlib.pyplot as plt
import seaborn as sns

df = pd.read_csv("./pima-indians-diabetes.csv",names=["pregnant","plasma","pressure","thickness","insulin","BMI","pedigree","age","class"])
print(df.head(5))

colormap = plt.cm.gist_heat
plt.figure(figsize=(10,10))

sns.heatmap(df.corr(),linewidths=0.1,vmax=0.5,cmap=colormap,linecolor='white',annot=True)
plt.show()
grid = sns.FacetGrid(df, col='class')
grid.map(plt.hist,'plasma',bins=10)
plt.show()