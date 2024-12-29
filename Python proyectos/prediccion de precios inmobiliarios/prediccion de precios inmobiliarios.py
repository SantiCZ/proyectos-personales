# Importar las bibliotecas necesarias
import pandas as pd
from sklearn.model_selection import train_test_split
from sklearn.linear_model import LinearRegression
from sklearn.metrics import mean_squared_error, r2_score

# Generar datos de ejemplo
data = {
    'size': [750, 800, 850, 900, 950, 1000, 1050, 1100, 1150, 1200],
    'location': ['urban', 'suburban', 'urban', 'suburban', 'urban', 'suburban', 'urban', 'suburban', 'urban', 'suburban'],
    'rooms': [3, 2, 3, 2, 4, 3, 4, 3, 5, 4],
    'price': [300000, 250000, 320000, 270000, 350000, 290000, 370000, 310000, 400000, 330000]
}
df = pd.DataFrame(data)

# Codificar la variable categórica 'location'
df = pd.get_dummies(df, columns=['location'], drop_first=True)

# Definir las características (X) y la variable objetivo (y)
X = df[['size', 'rooms', 'location_urban']]
y = df['price']

# Dividir los datos en conjuntos de entrenamiento y prueba
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=42)

# Crear y entrenar el modelo de regresión lineal
model = LinearRegression()
model.fit(X_train, y_train)

# Realizar predicciones
y_pred = model.predict(X_test)

# Evaluar el modelo
mse = mean_squared_error(y_test, y_pred)
r2 = r2_score(y_test, y_pred)

print(f'Error cuadrático medio (MSE): {mse}')
print(f'Coeficiente de determinación (R^2): {r2}')

# Mostrar los coeficientes del modelo
print('Coeficientes del modelo:')
print(f'Tamaño: {model.coef_[0]}')
print(f'Habitaciones: {model.coef_[1]}')
print(f'Ubicación (urbana): {model.coef_[2]}')
