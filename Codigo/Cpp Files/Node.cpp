#include "Node.h"
#include <iostream>

/*
	atributos:
	Mat cara;
	Node* next;
*/

using std::cout;

Node::Node() {

}

//Constructor con el elemento
Node::Node(cv::Mat x) {
	this->cara = x;
	this->next = nullptr;
}



