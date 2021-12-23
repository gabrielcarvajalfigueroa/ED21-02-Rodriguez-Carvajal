#include "MenuRial.h"

#include "Historia1.h"
#include "Historia2.h"
#include "Historia3.h"
#include "Historia4.h"
#include "Historia5.h"
#include "Historia6.h"

#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>

using namespace cv; // importante para las funciones de la libreria
using namespace std;

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

MenuRial::MenuRial() {

	// 1-2  1eros numeros ancho y alto
	// 3 indica q es de 8 bits unsigned 3 channels
	// scalar da el color en RGB o BGR en este caso al parecer


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

			Historia1::Historia1();
		}
		else if (codigo == 71 || codigo == 103) {  //71 G mayuscula -- 103 g minuscula
			Historia2::Historia2();
		}
		else if (codigo == 76 || codigo == 108) { // 76 para L y l -- historia 3
			Historia3::Historia3();
		}
		else if (codigo == 74  || codigo == 106) { // 76 para J y j -- historia 4
			Historia4::Historia4();
		}
		else if (codigo == 72 || codigo == 104) { // Para H y h -- para acceder historia 5
			Historia5::Historia5();
		}
		else if (codigo == 68 || codigo == 100) { // 76 para D y d -- historia 6
			Historia6::Historia6();
		}

		destroyWindow("Menu Usuarios");
	} while (codigo != 48); // 48 es 0 en ascii




}


