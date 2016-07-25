## Descripción General

  Usando el algoritmo de *HAAR* de la librería de OpenCV para la detección facial, se realizaron pruebas sobre 15 imagenes de diferentes dimensiones contrastando rendimiento entre la CPU (Intel NUC) y la GPU (Jetson TK1).

## Algoritmo

  Se utilizó la librería de OpenCV y más especificamente la _cascada de Haar_. Este algoritmo lo que hace es buscar sobre una imagen en escala de grises un conjunto de rectángulos que organizados en "cascada" podrían representar un rostro, los clasificadores son los siguientes:

  ![clasificadores](http://ironsistem.com/media/images/1_fl2yzEM..width-800.jpg "clasificadores")

  Ahora actuando sobre una imagen...

  ![proceso](http://robologs.net/wp-content/uploads/2014/05/haarcascade-300x300.jpg "proceso")

  EL algoritmo tiene un porcentaje de acierto bastante alto, además solo hace el procedimiento sobre objetos que podrían ser rostros.
