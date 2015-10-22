#include "ObjectDetectorFactory.h"

using namespace cv;
using namespace std;

int main(int, char)
{
	Mat baseImage = imread("ninja.jpg");

	ObjectDetector* detector = ObjectDetectorFactory::getObjectDetector(12, 2);
	if(!detector->loadImage(baseImage))
		exit(1);

	
	Mat image = imread("stelle.jpg");
	
	if (image.size().height > 800 || image.size().width > 800)
	{
		Size s = image.size(), small;
		small.height = s.height / 3;
		small.width = s.width / 3;

		resize(image, image, small);
	}

	
	vector<vector<vector<Point>>> objects;
	int numberOfObjects = 0;

	Mat mask = detector->findObjectsInImage(image, 88, 90, &objects, &numberOfObjects);

	imshow("FINAL RESULT",mask);
	

	/*
	VideoCapture cap(0);
	if (!cap.isOpened())
	{
		return 0;
	}

	Mat image;

	for (;;)
	{
		cap >> image;

		Mat result = detector->findObjectsInImage(image, 85, 85);
		imshow("FINAL RESULT", result);

		if (waitKey(30) > 0)
			break;
	}
	*/

	waitKey(0);
	return 0;

}