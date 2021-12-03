#include "Historia2.h"
#include <opencv2/opencv.hpp>
#include <vector>
#include "LinkedList.h"



using namespace cv;
using namespace std;


Historia2::Historia2()
{
	double scale = 2;

	CascadeClassifier faceCascade;
	faceCascade.load("\\Users\\gcarv\\librerias\\opencv\\build\\etc\\haarcascades\\haarcascade_frontalface_alt.xml");

	string path = "Familia2.jpg";
	Mat foto_familia = imread(path);

	Mat grayscale;
	cvtColor(foto_familia, grayscale, COLOR_BGR2GRAY);
	resize(grayscale, grayscale, Size(grayscale.size().width / scale, grayscale.size().height / scale));

	vector<Rect> faces;
	faceCascade.detectMultiScale(grayscale, faces, 1.1, 3, 0, Size(30, 30));




	LinkedList listacaras = LinkedList();

	for (Rect area : faces)
	{

		Rect roi(Point(cvRound(area.x * scale), cvRound(area.y * scale)),
			Point(cvRound((area.x + area.width - 1) * scale), cvRound((area.y + area.height - 1) * scale)));


		listacaras.add(foto_familia(roi));


	}

	listacaras.show();

	cout << "Cantidad de caras en la linked list: " << listacaras.size() << endl;

}