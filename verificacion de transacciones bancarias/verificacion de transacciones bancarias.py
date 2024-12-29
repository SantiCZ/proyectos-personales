import pandas as pd
import numpy as np
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import StandardScaler
from sklearn.ensemble import RandomForestClassifier
from sklearn.metrics import classification_report, confusion_matrix, accuracy_score
import joblib

# Paso 1: Cargar el conjunto de datos
data = pd.read_csv('transactions.csv')

# Paso 2: Preprocesar los datos
print(data.isnull().sum())

X = data.drop('Class', axis=1)
y = data['Class']

X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.3, random_state=42)

scaler = StandardScaler()
X_train = scaler.fit_transform(X_train)
X_test = scaler.transform(X_test)

# Paso 3: Entrenar el modelo
model = RandomForestClassifier(n_estimators=100, random_state=42)
model.fit(X_train, y_train)

# Paso 4: Evaluar el modelo
y_pred = model.predict(X_test)
print('Accuracy:', accuracy_score(y_test, y_pred))
print('Confusion Matrix:\n', confusion_matrix(y_test, y_pred))
print('Classification Report:\n', classification_report(y_test, y_pred))

# Paso 5: Guardar el modelo
joblib.dump(model, 'fraud_detection_model.pkl')

# Paso 6: Cargar el modelo (ejemplo de uso futuro)
model = joblib.load('fraud_detection_model.pkl')

# Paso 7: Cargar y preprocesar nuevas transacciones
new_transactions = pd.read_csv('new_transactions.csv')

# Asegurate de que las nuevas transacciones tengan las mismas caracteristicas que el conjunto de entrenamiento original
# Normaliza las nuevas transacciones
new_transactions_scaled = scaler.transform(new_transactions)

# Predecir si las nuevas transacciones son fraudulentas o legitimas
predictions = model.predict(new_transactions_scaled)

# Mostrar las predicciones
print(predictions)
