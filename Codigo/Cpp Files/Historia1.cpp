#include "Historia1.h"
#include <opencv2/opencv.hpp>
#include <vector>


using namespace cv;
using namespace std;

Historia1::Historia1() 
{
	double scale = 2; // revisar donde va esto

	CascadeClassifier faceCascade;
	faceCascade.load("\\Users\\gcarv\\librerias\\opencv\\build\\etc\\haarcascades\\haarcascade_frontalface_alt.xml");

	string path = "Familia2.jpg";
	Mat foto_familia = imread(path);

	Mat grayscale;
	cvtColor(foto_familia, grayscale, COLOR_BGR2GRAY);
	resize(grayscale, grayscale, Size(grayscale.size().width / scale, grayscale.size().height / scale));

	vector<Rect> faces;
	faceCascade.detectMultiScale(grayscale, faces, 1.1, 3, 0, Size(30, 30));

	
	for (Rect area : faces)
	{
		Scalar drawcolor = Scalar(0, 0, 255);
		rectangle(foto_familia, Point(cvRound(area.x * scale), cvRound(area.y * scale)),
			Point(cvRound((area.x + area.width - 1) * scale), cvRound((area.y + area.height - 1) * scale)), drawcolor);

		
	}


	// detecta mas de una cara
	imshow("foto familia", foto_familia);

	waitKey(0);

	destroyWindow("foto familia");
}
