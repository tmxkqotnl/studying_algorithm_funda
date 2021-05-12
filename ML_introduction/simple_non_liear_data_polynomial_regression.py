import numpy as np
import numpy.random as rnd
import matplotlib.pyplot as plt

## non-linear data + noise

np.random.seed(42)

m = 100
x = 6*np.random.rand(m,1)-3
y = 0.5*x**2+x+2+np.random.randn(m,1)

plt.plot(x,y,"b.")
plt.xlabel("$x_1$",fontsize=18)
plt.ylabel("$y$", rotation = 0, fontsize=18)
plt.axis([-3,3,0,10])
plt.show()

from sklearn.preprocessing import PolynomialFeatures

poly_features = PolynomialFeatures(degree=2,include_bias=False)
x_poly = poly_features.fit_transform(x)

print(x[0])
print(x_poly[0])

from sklearn.linear_model import LinearRegression

lin_reg = LinearRegression()
lin_reg.fit(x_poly,y)
print(lin_reg.intercept_,lin_reg.coef_)