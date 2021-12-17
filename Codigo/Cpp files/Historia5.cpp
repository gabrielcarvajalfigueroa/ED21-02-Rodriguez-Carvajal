#include "Historia5.h"
#include "opencv2\opencv.hpp"
#include "opencv2\highgui.hpp"


Historia5::Historia5() {

	// Crea el objeto para capturar video se le entrega el video utilizado
	cv::VideoCapture video("Video-Practica.mp4");

	// Esta variable guardara los distintos frames del Video-Practica.mp4 para copiarlos
	cv::Mat frame;

	// Se consigue la resolucion del frame para una funcion a utilizar posteriormente
	int frameWidth = video.get(cv::CAP_PROP_FRAME_WIDTH);
	int frameHeigth = video.get(cv::CAP_PROP_FRAME_HEIGHT);

	// Objeto para escribir el nuevo video
	// video tendra el nombre copiadeseguridad debido a la historia pedida
	cv::VideoWriter output("CopiaDeSeguridad.avi", cv::VideoWriter::fourcc('M', 'J', 'P', 'G'), 30, cv::Size(frameWidth, frameHeigth));

	// Se itera por todos los frames que entrega el video practica
	while (video.read(frame)){

		// Escribe el frame en la copia del video
		output.write(frame);
		
	}
	
	// se cierran ambos videos, actua como destructor para desocupar memoria
	output.release();
	video.release();
}
