#pragma once
#include "Node.h"

class LinkedList
{

public:
	Node* first;

	LinkedList();

	void add(cv::Mat cara);

	int isEmpty();

	int size();

	void show();

	
};

