import numpy as np
import pandas as pd
from sklearn.linear_model import LinearRegression
from sklearn.model_selection import train_test_split
from sklearn import metrics
import matplotlib.pyplot as plt

data = pd.read_csv("data2.csv")
# array = []
x = data[['TV','radio','newspaper']]
y= data.sales # EQUALS TO data['sales']
X_train,X_test,y_train,y_test = train_test_split(x,y,random_state=50)
linearreg = LinearRegression()
linearreg.fit(X_train,y_train)

y_predict = linearreg.predict(X_test)
print(np.sqrt(metrics.mean_squared_error(y_test,y_predict)))

plt.plot(X_test["TV"],y_predict,'k*')
plt.plot(X_test['TV'],y_test,'r.')
plt.show()

