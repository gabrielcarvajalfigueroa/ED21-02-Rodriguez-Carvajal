#include "Historia1.h"
#include <opencv2/opencv.hpp>
#include <vector>


using namespace cv;
using namespace std;

Historia1::Historia1()
{
	double scale = 2; 

	CascadeClassifier faceCascade;
	faceCascade.load("\\Users\\gcarv\\librerias\\opencv\\build\\etc\\haarcascades\\haarcascade_frontalface_alt.xml");

	VideoCapture cap("Video-Practica.mp4");
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