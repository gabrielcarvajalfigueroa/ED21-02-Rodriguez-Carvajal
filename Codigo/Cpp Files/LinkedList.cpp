#include "LinkedList.h"
#include <iostream>
#include <string>

/*
*	atributos:
*	Node* first;
*/

using namespace std;

LinkedList::LinkedList() {
	this->first = nullptr;
}

void LinkedList::add(cv::Mat cara) {
    Node* node = new Node(cara);
    if (this->first == nullptr) {
        this->first = node;
    }
    else {
        Node* aux = this->first;
        while (aux->next != nullptr) {
            aux = aux->next;
        }
        aux->next = node;
    }

}

int LinkedList::isEmpty() {
	return this->first == nullptr;
}


// revisar codigo puede que falle en ciertas situaciones
int LinkedList::size() {
    int count = 1;
    Node* aux = this->first;

    if (this->first == nullptr) {
        return 0;
    }

    while (aux->next != nullptr) {
        ++count;
        aux = aux->next;
    }


    return count;
}

void LinkedList::show() {
   

    // Muestra el top 5 y luego las destruye

    Node* aux = first;
    
    string top = "Top ";

    for (int i = 1; i <= 5; i++) {

        top = top + to_string(i);

        cv::resize(aux->cara, aux->cara, cv::Size(), 4, 4);
        cv::imshow(top, aux->cara);
        aux = aux->next;

        top = "Top ";


    }

    cv::waitKey(0);

    for (int i = 1; i <= 5; i++) {

        top = top + to_string(i);

        cv::destroyWindow(top);
        top = "Top ";
    }


}

 













