import pandas as pd
import numpy as np

np.random.seed(3)

Data_set = np.loadtxt("./ThoraricSurgery_evildata.csv",delimiter=",")

x = Data_set[:,0:17]
y = Data_set[:,17]

from sklearn.linear_model import LogisticRegression

model = LogisticRegression(solver='lbfgs')
model.fit(x,y)

y_pred = model.predict(x)

from sklearn.metrics import accuracy_score
y_pred = y_pred//1000
print("Accuracy: {:.2%}".format(accuracy_score(y,y_pred)))

from tensorflow.keras.models import Sequential
from tensorflow.keras.layers import Dense
import tensorflow as tf

tf.random.set_seed(3)

model = Sequential()
model.add(Dense(60,input_dim=17,activation='relu'))
model.add(Dense(60,activation='relu'))
model.add(Dense(60,activation='relu'))
model.add(Dense(1,activation='sigmoid'))

model.compile(loss='binary_crossentropy',optimizer='adam',metrics=['accuracy'])
model.fit(x,y,epochs=30,batch_size=10)

print(type(x), x.shape)
j = 0
for i in range(len(y)):
    if y[i] == 0:
        j+=1
print("total {}, died {}".format(len(y),j))
print("percentage of died {:.0%}".format(j/len(y)))
