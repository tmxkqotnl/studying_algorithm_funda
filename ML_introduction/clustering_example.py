import matplotlib.pyplot as plt
from sklearn.datasets import load_wine

data = load_wine()

x = data.data[:,[0]]
y = data.data[:,[9]]
plt.scatter(x,y)
plt.show()

from sklearn.cluster import KMeans

x = data.data[:,[0,9]]
n_cluster = 3
model = KMeans(n_clusters=n_cluster)
pred = model.fit_predict(x)


fig, ax = plt.subplots()

ax.scatter(x[pred==0,0],x[pred==0,1],color='red',marker='s',label='Label1')
ax.scatter(x[pred==1,0],x[pred==1,1],color='blue',marker='s',label='Label2')
ax.scatter(x[pred==2,0],x[pred==2,1],color='green',marker='s',label='Label3')
ax.scatter(model.cluster_centers_[:,0],model.cluster_centers_[:,1],s=200,color='yellow',marker="*",label="center")

ax.legend()
plt.show()