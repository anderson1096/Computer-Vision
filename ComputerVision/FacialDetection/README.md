## Descripción General

  Usando el algoritmo de *HAAR* de la librería de OpenCV para la detección facial, se realizaron pruebas sobre 14 imagenes de diferentes dimensiones contrastando rendimiento entre la CPU (Intel NUC) y la GPU (Jetson TK1).

## Algoritmo

  Se utilizó la librería de OpenCV y más especificamente la _cascada de Haar_. Este algoritmo lo que hace es buscar sobre una imagen en escala de grises un conjunto de rectángulos que organizados en "cascada" podrían representar un rostro, los clasificadores son los siguientes:

  ![clasificadores](http://ironsistem.com/media/images/1_fl2yzEM..width-800.jpg "clasificadores")

  Ahora actuando sobre una imagen...

  ![proceso](http://robologs.net/wp-content/uploads/2014/05/haarcascade-300x300.jpg "proceso")

  El algoritmo tiene un porcentaje de acierto bastante alto, además solo hace el procedimiento sobre objetos que podrían ser rostros.

## Gráficas y Resultados

  Después de realizadas las pruebas sobre las 14 imagenes en los dos dispositivos, se tomaron los tiempos de ejecución ordenados ascendentemente según el tamaño de la imagen en pixeles, luego se generaron gráficas de tiempos y aceleración.

  | [Tiempos CPU][1]  | [Tiempos GPU][2] |   [Aceleración][3] |
  [1]: Imagenes/cpu.png
  [2]: Imagenes/gpu.png
  [3]: Imagenes/acel.png


Para mayor precisión sobre el tamaño de las imagenes o tiempos, los datos pueden ser observados en el archivo _Tiempos.xlsx_.
