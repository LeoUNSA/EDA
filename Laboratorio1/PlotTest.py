import matplotlib.pyplot as plt
import os
import numpy as np
directorio = 'D:/Documentos/Code/EDA'
nombres_archivos = ['distancias_d10.txt', 'distancias_d50.txt', 'distancias_d100.txt',
                   'distancias_d500.txt', 'distancias_d1000.txt', 'distancias_d2000.txt', 'distancias_d5000.txt']
num_bins = 20  # Numero de intervalos
# Directorio de salida
directorio_salida = directorio
#Bucle para acceder y leer los archivos
for nombre_archivo in nombres_archivos:
    ruta_archivo = os.path.join(directorio, nombre_archivo)
    with open(ruta_archivo, 'r') as archivo:
        numeros = [float(linea.strip()) for linea in archivo.readlines()]
    # Calculando los intervalos automáticamente con numpy
    hist, bins = np.histogram(numeros, bins=num_bins)
    # Creando el histograma
    plt.hist(numeros, bins=bins, edgecolor='black')
    plt.title('Histograma de Frecuencias')
    plt.xlabel('Distancias')
    plt.ylabel('Frecuencia')
    # Propiedades de la imagen
    nombre_imagen = os.path.splitext(nombre_archivo)[0] + '_histograma.png'
    ruta_imagen = os.path.join(directorio_salida, nombre_imagen)
    plt.savefig(ruta_imagen)
    # Limpiando el histograma actual para empezar a generar el siguiente
    plt.clf()
print("Done.")
