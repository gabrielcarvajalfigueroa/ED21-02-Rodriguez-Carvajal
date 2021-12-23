#include "Historia3.h"
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

/*
* Calcula los frames totales que tiene un video para luego poder dividir el video en cuatro partes casi iguales
* con el fin de poder trabajar con la cuarta parte que el usuario decida
* @param (std::string) nombre_video El nombre del video con el que se trabaja, se debe incluir el .mp4
*/
int calcularFramesTotales(std::string nombre_video) {
	cv::VideoCapture calcular(nombre_video);
	cv::Mat frame;
	int cont = 0;
	while (calcular.read(frame)){
		cont++;
	}
	calcular.release();

	return cont;

}

/*
* Se utiliza para describir lo que hace la historia por consola ya que en este caso no se uso una GUI
* @return (std::string) final retorna la descripcion de la historia para que el usuario la pueda utilizar con mas claridad
*/
std::string muchoTexto() {
	std:string texto = "Esta historia da la posibilidad de dividir el video en cuatro partes para que usted pueda trabajar con la q necesite";
	std::string texto2 = "\n asi que debera ingresar un num del 1 al 4 para poder trabajar con el cuarto que indique";
	std::string lineas = "------------------------------------------------------------------------------------------------";

	std::string final = lineas + "\n" + texto + texto2 + "\n" + lineas;
	return final;
}

Historia3::Historia3() {
	/*
	*  1) Establecer inicio y final
	*  2) Contar las personas que aparecieron
	*  3) Mostrar las personas que aparecieron
	*/

	// Crea el objeto para capturar video se le entrega el video utilizado
	cv::VideoCapture video("Video-Practica.mp4");

	// Se itera por todos los frames que entrega el video practica
	int cont = 0; // contador para saber en que frame va la secuencia
	cout << muchoTexto() << endl;
	cout << "Ingrese el cuarto en el que desea trabajar:" << endl;
	int cuartoATrabjar;
	cin >> cuartoATrabjar;
	int frames_totales = calcularFramesTotales("Video-Practica.mp4");

	cout << "El cuarto elegido fue: " << cuartoATrabjar << endl;
	cout << "El total de frames: " << frames_totales << endl;
	
	Mat image; // imagen para trabjar
	AVLtree avlt; //Se declara el arbol que recibira las imagenes

	
	while (1) { 
		video.read(image);
		
		// esta operacion deja trabajar en el ciclo que corresponda
		if ((( (cuartoATrabjar - 1) * frames_totales) / 4) <= cont) {
			//La magia
			// se cuenta la cantidad de personas que aparecieron en esa parte del video
			// Leemos todas las caras de los archivos de imágenes y las insertamos en el árbol
			
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
				avlt.insert(cf);
				
				// Muestro la imagen codificada en la imagen original
				
				cvtColor(cf, colorImage, COLOR_GRAY2BGR);
				resize(colorImage, newSize, Size(widthImageInGrayColor, widthImageInGrayColor), INTER_LINEAR);
				newSize.copyTo(image(cv::Rect(posX, 10, newSize.cols, newSize.rows)));
				posX += widthImageInGrayColor + 10;
				

			}
			// Para ver caras detectadas
			//Muestro las caras encontradas en la imaggen original
			
			for (const auto& fm : facesMarkers) {
				rectangle(image, fm, color, 4);
			}
			// Mostrar la imagen con las marcas (rectángulos) indicando la posición de la cara
			imshow("Detected Face", image);

			waitKey(20); 
		}
		if (cont == ((cuartoATrabjar * frames_totales) / 4)) {
			cout << "salio del ciclo" << endl;
			break;
		} 
		cout << cont << endl;
		cont++;
	}
	
	// Entrega el total de personas que aparecieron en la seccion del video para asi finalizar con la historia
	cout << "EL TOTAL DE PERSONAS IDENTIFICADAS FUE DE: " << avlt.cantNodos << endl;
	video.release();

}