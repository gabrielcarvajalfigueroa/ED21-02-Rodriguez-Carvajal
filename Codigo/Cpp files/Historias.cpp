#include "include/Historias.h"

void Historias::Historia1() {
	double scale = 2;

	CascadeClassifier faceCascade;
	faceCascade.load("haarcascade/haarcascade_frontalface_alt.xml");
	VideoCapture cap("images/Video-Practica.mp4");
	int codigo;

	Mat frame_del_video;
	while (true) {

		cap.read(frame_del_video);
		Mat grayscale;
		cvtColor(frame_del_video, grayscale, COLOR_BGR2GRAY);
		resize(grayscale, grayscale, Size(grayscale.size().width / scale, grayscale.size().height / scale));


		vector<Rect> faces;
		faceCascade.detectMultiScale(grayscale, faces, 1.1, 3, 0, Size(30, 30));


		for (Rect area : faces)
		{
			Scalar drawcolor = Scalar(0, 0, 255);
			rectangle(frame_del_video, Point(cvRound(area.x * scale), cvRound(area.y * scale)),
				Point(cvRound((area.x + area.width - 1) * scale), cvRound((area.y + area.height - 1) * scale)), drawcolor);
		}

		imshow("Historia 1", frame_del_video);

		codigo = waitKey(2);
		if (codigo == 48) { // Al apretar el 0 se logra cerrar el video
			break;
		}
	}
}

int getMax(vector<int> vect) {
	int mayor = 0;
	int idmayor = 0;
	for (int i = 0; i < vect.size(); i++) {
		if (vect[i] > mayor) {
			mayor = vect[i];
			idmayor = i;
		}
	}
	return idmayor;
}

void Historias::Historia2(vector<AVL*> v) {
	int mayor = 0;
	vector<int> mayores;
	vector<Mat> imagenesMayores;
	vector<Mat> top5;
	vector<int> top5int;
	for (AVL* img : v) {
		mayores.push_back(img->d);
		imagenesMayores.push_back(img->im);
	}
	for (int i = 0; i < 5; i++) {
		int id = getMax(mayores);
		top5.push_back(imagenesMayores[id]);
		top5int.push_back(mayores[id]);
		mayores[id] = 0;
	}
	for (int i = 0; i < top5.size(); i++) {
		stringstream ss;
		string str;
		ss << top5int[i];
		ss >> str;
		resize(top5[i], top5[i], Size(), 4.0, 4.0);
		putText(top5[i], str, Point(50,50), FONT_HERSHEY_DUPLEX, 1, Scalar(0, 69, 255));
		imshow(str, top5[i]);
		waitKey(0);
	}
}

/*
* Calcula los frames totales que tiene un video para luego poder dividir el video en cuatro partes casi iguales
* con el fin de poder trabajar con la cuarta parte que el usuario decida
* @param (std::string) nombre_video El nombre del video con el que se trabaja, se debe incluir el .mp4
*/
int calcularFramesTotales(std::string nombre_video) {
	cv::VideoCapture calcular(nombre_video);
	cv::Mat frame;
	int cont = 0;
	while (calcular.read(frame)) {
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

void Historias::Historia3() {
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
	FaceDetector fdetector;
	ImageCoding icoding;
	Scalar color(0, 0, 255);

	while (1) {
		video.read(image);

		// esta operacion deja trabajar en el ciclo que corresponda
		if ((((cuartoATrabjar - 1) * frames_totales) / 4) <= cont) {
			//La magia
			// se cuenta la cantidad de personas que aparecieron en esa parte del video
			// Leemos todas las caras de los archivos de imágenes y las insertamos en el árbol

			

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

void Historias::Historia4(vector<AVL*> v) {
	vector<int> maxs;
	for (AVL* a : v) {
		maxs.push_back(a->d);
	}
	
	int max = getMax(maxs);
	imshow("Top 1", v[max]->im);
}

void Historias::Historia5() {
	// Crea el objeto para capturar video se le entrega el video utilizado
	VideoCapture video("images/Video-Practica.mp4");

	// Esta variable guardara los distintos frames del Video-Practica.mp4 para copiarlos
	Mat frame;

	// Se consigue la resolucion del frame para una funcion a utilizar posteriormente
	int frameWidth = video.get(CAP_PROP_FRAME_WIDTH);
	int frameHeigth = video.get(CAP_PROP_FRAME_HEIGHT);

	// Objeto para escribir el nuevo video
	// video tendra el nombre copiadeseguridad debido a la historia pedida
	cv::VideoWriter output("CopiaDeSeguridad.avi", VideoWriter::fourcc('M', 'J', 'P', 'G'), 30, Size(frameWidth, frameHeigth));

	// Se itera por todos los frames que entrega el video practica
	while (video.read(frame)) {

		// Escribe el frame en la copia del video
		output.write(frame);

	}

	// se cierran ambos videos, actua como destructor para desocupar memoria
	output.release();
	video.release();
}

void Historias::Historia6() {
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
