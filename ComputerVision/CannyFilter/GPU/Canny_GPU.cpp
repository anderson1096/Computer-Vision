#include <stdio.h>
#include <opencv2/core/core.hpp>
#include <opencv2/contrib/contrib.hpp>
#include <opencv2/objdetect/objdetect.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/gpu/gpu.hpp>

using namespace std;
using namespace cv;


int main(int argc, char  **argv) {

  //Comprobando si hay una GPU compatible
  if (gpu::getCudaEnabledDeviceCount() == 0){
    printf("No hay dispositivo CUDA\n");
    return -1;
  }
  char *imageName = argv[1];
  //Cargando la imagen
  Mat src = imread(imageName);
  if(argc != 2 || !src.data){
    printf("Imagen no cargada\n");
    return -1;
  }
  gpu::GpuMat gray_gpu, src_gpu, edges_gpu;
  //Copiando la imagen cargada a la GPU
  src_gpu.upload(src);
  //Convirtiendo a escala de grises
  gpu::cvtColor(src_gpu, gray_gpu, CV_BGR2GRAY);
  //Aplicando Canny
  gpu::Canny(gray_gpu, edges_gpu, 50, 150, 3);
  //Recuperando la imagen (copiando los resultados de la GPU a la CPU)
  Mat edges;
  edges_gpu.download(edges);
  //Mostrando resultados
  imshow("Canny en GPU", edges);
  waitKey();

  return 0;
}
