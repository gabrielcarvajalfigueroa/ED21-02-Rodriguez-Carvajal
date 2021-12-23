#include "Historia6.h"
#include <iostream>
#include <string>
#include "opencv2/objdetect.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/core.hpp"



#include "FaceDetector.h"
#include "ImageCoding.h"

#include "AVLtree.h"

using std::cout;
using std::endl;
using std::cin;
using std::string;


Historia6::Historia6() {
	

	// Crea el objeto para capturar video se le entrega el video utilizado
	cv::VideoCapture video("Video-Practica.mp4");



	Mat image; // imagen para trabjar
	AVLtree avlt; //Se declara el arbol que recibira las imagenes

	int frame = 1;

	int* frame_actual_avl = &avlt.frame_actual;

	while (1) {
		video.read(image);


		FaceDetector fdetector;
		ImageCoding icoding;
		Scalar color(0, 0, 255);

		auto facesMarkers = fdetector.detectFaceRectangles(image);

		// Codifico las caras detectadas
		icoding.setImage(image);
		auto faceCodingGray = icoding.codeGray(facesMarkers, true, Size(25, 25));
		// Muestro las caras codificadas
		Mat colorImage;
		Mat newSize;
		// Muestro las caras detectadas en la imagen original
		int widthImageInGrayColor = 40;
		int posX = 10;

		for (const auto& cf : faceCodingGray) {
			// Inserto la imagen en el arbol y obtengo el identificador
			*frame_actual_avl = frame;
			avlt.insert(cf);

			// Muestro la imagen codificada en la imagen original

			cvtColor(cf, colorImage, COLOR_GRAY2BGR);
			resize(colorImage, newSize, Size(widthImageInGrayColor, widthImageInGrayColor), INTER_LINEAR);
			newSize.copyTo(image(cv::Rect(posX, 10, newSize.cols, newSize.rows)));
			posX += widthImageInGrayColor + 10;


		}
		frame++;
	}


	video.release();

}
