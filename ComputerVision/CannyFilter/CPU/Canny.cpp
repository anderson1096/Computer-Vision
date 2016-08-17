#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <stdio.h>
#include <time.h>

using namespace std;
using namespace cv;

int main(int argc, char **argv){
  clock_t start, end;
  //definiendo las imagenes que usaremos
  Mat src, edges, gray;

  //Cargando las imagenes
  char *imageName = argv[1];
  start = clock();
  src = imread(imageName);
  if(src.empty()){
    printf("Imagen no cargada\n");
    return -1;
  }

  //Pasando la imagen cargada a escala de Grises
  cvtColor(src, gray, CV_BGR2GRAY);

  //Haciendo la detección de Bordes
  Canny(gray, edges, 50, 150, 3);
  end = clock();
  printf("Tiempo CPU: %.5f\n",(double)(end - start)/CLOCKS_PER_SEC);
  //imshow("Filtro Canny", edges);
  //waitKey();

  return 0;
}
