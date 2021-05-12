import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
## y= ax + b
## gradient descent of MSE.
data = [[2,81],[4,93],[6,91],[8,97]]
x = [i[0] for i in data]
y = [i[1] for i in data]

plt.figure(figsize=(8,5))
plt.scatter(x,y)
plt.show()

x_data = np.array(x)
y_data = np.array(y)

a = 0
b = 0
lr = 0.03

epochs = 2001
for i in range(epochs):
    y_hat = a*x_data+b
    error = y_data-y_hat

    a_diff = -(2/len(x_data))*sum(x_data*(error))
    b_diff = -(2/len(x_data))*sum(error)
    a = a-lr*a_diff
    b = b-lr*b_diff

    if i%100 == 0:
        print("epoch=%.f, gradient=%.04f, intercept=%0.4f" % (i,a,b))

## by using scikit-learn
from sklearn.linear_model import LinearRegression

x = [[2],[4],[6],[8]]
y = [i[1] for i in data]

model = LinearRegression()
model.fit(x,y)
print("gradient = ",model.coef_,"intercept = ",model.intercept_)
