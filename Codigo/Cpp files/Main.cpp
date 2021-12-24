#include<iostream>
#include<sstream>
#include "include/Historias.h"
#define pow2(n) (1 << (n))
using namespace std;
using namespace cv;

void Titulo(Mat img) {

	// titulo 
	/*
		Funcion para crear rectangulo 1er Point() para la esquina izquiera de arriba
		2do Point() esquina derecha de abajo, scalar() == color
	*/
	rectangle(img, Point(60, 5), Point(460, 60), Scalar(0, 0, 0), 3);

	putText(img, "Sistema segurida ACME", Point(70, 40), FONT_HERSHEY_DUPLEX, 1, Scalar(0, 69, 255));
}

void BotonH1(Mat img) {

	// boton h1 (historia - 1)

	rectangle(img, Point(60, 135), Point(460, 190), Scalar(0, 0, 0), 3);

	putText(img, "Historia 1 - PRESS K", Point(70, 170), FONT_HERSHEY_DUPLEX, 1, Scalar(0, 69, 255));
}

void BotonH2(Mat img) {
	// boton h2 (historia - 2)

	rectangle(img, Point(60, 200), Point(460, 255), Scalar(0, 0, 0), 3);

	putText(img, "Historia 2 - PRESS G", Point(70, 235), FONT_HERSHEY_DUPLEX, 1, Scalar(0, 69, 255));
}

void BotonH3(Mat img) {
	// boton h3 (historia - 3)

	rectangle(img, Point(60, 265), Point(460, 320), Scalar(0, 0, 0), 3);

	putText(img, "Historia 3 - PRESS L", Point(70, 300), FONT_HERSHEY_DUPLEX, 1, Scalar(0, 69, 255));
}

void BotonH4(Mat img) {
	// boton h4 (historia - 4)

	rectangle(img, Point(60, 330), Point(460, 385), Scalar(0, 0, 0), 3);

	putText(img, "Historia 4 - PRESS J", Point(70, 365), FONT_HERSHEY_DUPLEX, 1, Scalar(0, 69, 255));
}

void BotonH5(Mat img) {
	// boton h5 (historia - 5)

	rectangle(img, Point(60, 395), Point(460, 450), Scalar(0, 0, 0), 3);

	putText(img, "Historia 5 - PRESS H", Point(70, 430), FONT_HERSHEY_DUPLEX, 1, Scalar(0, 69, 255));
}

void BotonH6(Mat img) {
	// boton h5 (historia - 5)

	rectangle(img, Point(60, 460), Point(460, 515), Scalar(0, 0, 0), 3);

	putText(img, "Historia 6 - PRESS D", Point(70, 495), FONT_HERSHEY_DUPLEX, 1, Scalar(0, 69, 255));
}

void Escape(Mat img) {
	// boton para el escape

	rectangle(img, Point(60, 70), Point(460, 125), Scalar(0, 0, 0), 3);

	putText(img, "PRESS ZERO TO ESCAPE", Point(70, 105), FONT_HERSHEY_DUPLEX, 1, Scalar(0, 69, 255));
}


int main() {
	VideoCapture video("images/Video-Practica.mp4");

	FaceDetector fdetector;
	ImageCoding icoding;
	Historias h;
	Scalar color(0, 0, 255);

	Mat image; // imagen para trabjar
	AVLtree avlt; //Se declara el arbol que recibira las imagenes

	int limite = 0;
	while (limite<500) {	//Aquí se limitan los frames del video a trabajar
		video.read(image);
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

		for (Mat cf : faceCodingGray) {
			avlt.insert(cf);
		}
		limite++;

	}
	avlt.inorder(avlt.root);
	vector<AVL*> imgs = avlt.vect;

	Mat img(512, 512, CV_8UC3, Scalar(255, 255, 255));

	Titulo(img);

	BotonH1(img);
	BotonH2(img);
	BotonH3(img);
	BotonH4(img);
	BotonH5(img);
	BotonH6(img);

	Escape(img);

	int codigo;

	do {
		imshow("Menu Usuarios", img);


		codigo = waitKey(0); // para q img no desaparezca

		if (codigo == 107 || codigo == 75) { // 107 ASCII para k MINUSCULA 75 para Mayuscula

			h.Historia1();
		}
		else if (codigo == 71 || codigo == 103) {  //71 G mayuscula -- 103 g minuscula
			h.Historia2(imgs);
		}
		else if (codigo == 76 || codigo == 108) { // 76 para L y l -- historia 3
			h.Historia3();
		}
		else if (codigo == 74 || codigo == 106) { // 76 para J y j -- historia 4
			h.Historia4(imgs);
		}
		else if (codigo == 72 || codigo == 104) { // Para H y h -- para acceder historia 5
			h.Historia5();
		}
		else if (codigo == 68 || codigo == 100) { // 76 para D y d -- historia 6
			h.Historia6();
		}

		destroyWindow("Menu Usuarios");
	} while (codigo != 48); // 48 es 0 en ascii
    return 0;
}
