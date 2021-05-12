import numpy

numpy.random.seed(3)

dataset = numpy.loadtxt("./pima-indians-diabetes.csv",delimiter=",")
x = dataset[:,0:8]
y = dataset[:,8]

from sklearn.linear_model import LogisticRegression
from sklearn.metrics import accuracy_score

model = LogisticRegression(solver='lbfgs')
model.fit(x,y)

y_pred = model.predict(x)
y_pred = y_pred//1000
print("Accuracy {:.2%}".format(accuracy_score(y,y_pred)))

from sklearn.ensemble import RandomForestClassifier

model = RandomForestClassifier(n_estimators=10)

model.fit(x,y)
y_pred = model.predict(x)
print("Accuracy {:.2%}".format(accuracy_score(y,y_pred)))
##########################################################
dataset = numpy.loadtxt("./pima-indians-diabetes_processed.csv",delimiter=",")
x = dataset[:,0:3]
y = dataset[:,3]

model = LogisticRegression(solver='lbfgs')
model.fit(x,y)

y_pred = model.predict(x)
y_pred = y_pred//1000
print("Accuracy {:.2%}".format(accuracy_score(y,y_pred)))

model = RandomForestClassifier(n_estimators=10)

model.fit(x,y)
y_pred = model.predict(x)
print("Accuracy {:.2%}".format(accuracy_score(y,y_pred)))

