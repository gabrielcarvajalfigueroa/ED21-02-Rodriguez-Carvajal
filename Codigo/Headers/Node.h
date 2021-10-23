#pragma once

#include <opencv2/opencv.hpp>


class Node
{
public:
	cv::Mat cara;
	Node* next;

	Node();

	Node(cv::Mat x);

	

};

