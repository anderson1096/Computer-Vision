# Descripción General
Se realizó una detección de bordes, usando la líbreria OpenCV y más específicamente el algoritmo de Canny para contrastar rendimiento en dos plataformas, una GPU(Nvidia Jetson TK1) y un Intel NUC.

# Algoritmo
El **filtro de Canny**, fue inventado por John F. Canny en 1986. Este algoritmo utiliza una serie de etapas para detectar una alta cantidad de bordes, además usa los siguientes objetivos para realizar una detección óptima:

  - **Buena Detección:** El algoritmo debe marcar el mayor número de bordes en la imagen.
  - **Buena Localización:** La marca del borde debe estar lo más cerca posible al borde de la imagen real.
  - **Respuesta Mínima:** El borde de la imagen debe ser marcado una vez (evitar redundancia) además no se debe marcar bordes falsos generados por el ruido.

### Fases
  1. **Suavizar:** Básicamente se desenfoca la imagen para eliminar el ruido, esta etapa se realiza mediante el siguiente filtro gaussiano.

  ![Filtro Gaussiano](https://upload.wikimedia.org/math/a/6/3/a63d6900a46d84bb24942ab0123f3791.png)  

  2. **Gradientes:** En esta etapa se busca los cambios más notables en la imagen esto se hace mediante el operador de Sobel, que usa el gradiente. Se toman los gradientes en las dos coordenas, luego la magnitud y por último se halla la dirección de dicho gradiente.

    - En las coordenas X y Y:

    ![Sobel-OPerator](https://wikimedia.org/api/rest_v1/media/math/render/svg/d2d3c95c9afd9aca9343a0bef60123ff94263f5f)
    - La magnitud.

    ![Sobel](https://wikimedia.org/api/rest_v1/media/math/render/svg/23ae6772c5f58751fc6014b71d6adafb30a31c79)

    - La dirección.

    ![dir](https://wikimedia.org/api/rest_v1/media/math/render/svg/17d387c370ca3a77740f6e6c889d286e586a640e)

  3. **No supresión máxima:** El objetivo de este paso es obtener bordes de 1 pixel de grosor al considerar únicamente pixels cuya magnitud es máxima en bordes gruesos y descartar aquellos cuyas magnitudes no alcancen ese máximo.

  Luego de aplicar esta fase en el algoritmo la imagen quedaría así (_Izquierda_ Antes, _Derecha_ Despues de la fase):

  ![max](https://sites.google.com/site/graficacion22012/_/rsrc/1354505101511/ubaldino/algoritmo-de-canny/image3948.png?height=200&width=400)

  4. **Umbralización Doble:** En esta fase se eliminan los bordes que no estén en el umbral, es decir los bordes debiles. Para lo anterior se tiene un umbral máximo y mínimo, los bordes que sean mayor al umbral máximo se marcan como fuertes y los bordes con valor más pequeño al umbral mínimo seran eliminados de la imagen y los que esten entre el mínimo y el máximo se marcan como bordes débiles.

  5. **Seguimiento por Histeresis:** Finalmente los bordes fuertes son probablemente bordes pertenecientes a la imagen original, por lo tanto se conservan, pero los bordes debiles pueden ser causados por ruido o variación de color. Por lo tanto se hace un seguimiento para ver que bordes débiles están conectados a los bordes fuertes de la imagen los cuales serán los bordes que se conservarán los que no se conecten con un borde fuerte, serán suprimidos. Para esta etapa se realiza el seguimiento con (Binary Large Object) [BLOB](https://es.wikipedia.org/wiki/Binary_large_object).

## Gráficas y Resultados

  Después de realizadas las pruebas sobre las 15 imagenes en los dos dispositivos, se tomaron los tiempos de ejecución ordenados ascendentemente según el tamaño de la imagen en pixeles, luego se generaron gráficas de tiempos y aceleración. _**Aunque cabe aclarar que no hubo aceleración ya que la plataforma Intel NUC fue mucho mas rápida que la Jetson TK1.**_

  _**NOTA:**_ _Los datos del eje vertical hacen referencia al tiempo (s) y los del eje horizontal al número de la imagen._


  Para mayor precisión sobre el tamaño de las imagenes o tiempos, los datos pueden ser observados en el archivo **TiemposCanny.xlsx**.
