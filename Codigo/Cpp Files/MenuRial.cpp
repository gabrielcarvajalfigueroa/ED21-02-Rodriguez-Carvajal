#include "MenuRial.h"

#include "Historia1.h"
#include "Historia2.h"

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
	rectangle(img, Point(60, 45), Point(460, 100), Scalar(0, 0, 0), 3);

	putText(img, "Sistema segurida ACME", Point(70, 80), FONT_HERSHEY_DUPLEX, 1, Scalar(0, 69, 255));
}

void BotonH1(Mat img) {

	// boton h1 (historia - 1)

	rectangle(img, Point(60, 230), Point(460, 285), Scalar(0, 0, 0), 3);

	putText(img, "Historia 1 - PRESS K", Point(70, 265), FONT_HERSHEY_DUPLEX, 1, Scalar(0, 69, 255));
}

void BotonH2(Mat img) {
	// boton h2 (historia - 2)

	rectangle(img, Point(60, 330), Point(460, 385), Scalar(0, 0, 0), 3);

	putText(img, "Historia 2 - PRESS G", Point(70, 365), FONT_HERSHEY_DUPLEX, 1, Scalar(0, 69, 255));
}

void Escape(Mat img) {
	// boton para el escape

	rectangle(img, Point(60, 150), Point(460, 205), Scalar(0, 0, 0), 3);

	putText(img, "PRESS ZERO TO ESCAPE", Point(70, 185), FONT_HERSHEY_DUPLEX, 1, Scalar(0, 69, 255));
}

MenuRial::MenuRial() {

	// 1-2  1eros numeros ancho y alto
	// 3 indica q es de 8 bits unsigned 3 channels
	// scalar da el color en RGB o BGR en este caso al parecer


	Mat img(512, 512, CV_8UC3, Scalar(255, 255, 255));

	Titulo(img);

	BotonH1(img);
	BotonH2(img);

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

		destroyWindow("Menu Usuarios");
	} while (codigo != 48); // 48 es 0 en ascii
	



}



