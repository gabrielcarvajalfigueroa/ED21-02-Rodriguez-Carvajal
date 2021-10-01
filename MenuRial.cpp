#include "MenuRial.h"
#include "Historia1.h"
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>

using namespace cv; // importante para las funciones de la libreria
using namespace std;

MenuRial::MenuRial() {

	// 1-2  1eros numeros ancho y alto
	// 3 indica q es de 8 bits unsigned 3 channels
	// scalar da el color en RGB o BGR en este caso al parecer


	Mat img(512, 512, CV_8UC3, Scalar(255, 255, 255));

	// titulo 
	/*
		Funcion para crear rectangulo 1er Point() para la esquina izquiera de arrina
		2do Point() esquina derecha de abajo, scalar() == color
	*/
	rectangle(img, Point(60, 45), Point(460, 100), Scalar(0, 0, 0), 3);

	putText(img, "Sistema segurida ACME", Point(70, 80), FONT_HERSHEY_DUPLEX, 1, Scalar(0, 69, 255));

	// boton h1 (historia - 1)

	rectangle(img, Point(60, 230), Point(460, 285), Scalar(0, 0, 0), 3);

	putText(img, "Historia 1 - PRESS K", Point(70, 265), FONT_HERSHEY_DUPLEX, 1, Scalar(0, 69, 255));


	imshow("Menu Usuarios", img);


	int codigo = waitKey(0); // para q img no desaparezca

	if (codigo == 107) { // 107 ASCII para k MINUSCULA

		Historia1::Historia1();
	}
	else {
		destroyWindow("Menu Usuarios");
		imshow("Menu usuario", img);
		waitKey(0);
	}



}

