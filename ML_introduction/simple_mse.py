import numpy as np

fake_a_b = [3,76]

data = [[2,81],[4,93],[6,91],[8,97]]
x = [i[0] for i in data]
y = [i[1] for i in data]

def predict(x):
    return fake_a_b[0]*x+fake_a_b[1]

def mse(y, y_hat):
    return ((y-y_hat)**2).mean()

def mse_eval(y,predict_result):
    return mse(np.array(y), np.array(predict_result))

predict_result = []
for i in range(len(x)):
    predict_result.append(predict(x[i]))
    print("time : %f, score %.f, predict %f" % (x[i],y[i],predict(x[i])))

print("result : "+str(mse_eval(predict_result,y)))
