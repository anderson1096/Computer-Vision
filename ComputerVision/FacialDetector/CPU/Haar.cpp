#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/objdetect/objdetect.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "iostream"
#include <stdio.h>
#include <time.h>

using namespace std;
using namespace cv;

CascadeClassifier face_cascade;
string faces_source = "/home/cctva/opencv/opencv-2.4.9/data/haarcascades/haarcascade_frontalface_alt.xml";

int main(int argc, char  **argv) {

  clock_t start, end;

  start = clock();
  vector<Rect> faces; //Vector para almacenar las caras detectadas
  char *imageName = argv[1];

  //Cargando el archivo xml para la detección de caras
  if(!face_cascade.load(faces_source)){
    cout << "Error : No se pudo cargar el archivo xml"<< endl;
    return -1;
  }

  //Cargando la Imagen

  Mat img = imread(imageName);
  if(img.empty()){
    cout << "Error: Imagen no cargada" << endl;
    return -1;
  }

  //Se pasa la imagen (frame) a escala de grises, para calcular menos datos.
  Mat gray;
  cvtColor(img, gray, CV_BGR2GRAY);
  equalizeHist(gray, gray);
  //imshow("Gray", gray);

  //Haciendo el procedimiento de detección facial
  face_cascade.detectMultiScale(gray, faces, 1.2, 3);

  //Pintando el rectangulo que señala la cara
  for (int i = 0; i < int(faces.size()); i++) {
    Rect r = faces[i];
    rectangle(img, Point(r.x, r.y), Point(r.x + r.width, r.y + r.height), CV_RGB(0, 255, 0));
  }

  end = clock();
  cout << "Tiempo CPU: " << (double)(end - start)/CLOCKS_PER_SEC << endl;

  //imshow("Detection", img);
  //waitKey();

  return 0;
}
