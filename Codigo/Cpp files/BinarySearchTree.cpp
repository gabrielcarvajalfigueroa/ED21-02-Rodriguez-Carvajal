#include "opencv2/core.hpp"

#include "BinarySearchTree.h"
#include "BinarySearchTreeNode.h"

#include <iostream>

using namespace std;
using namespace cv;

BinarySearchTree::BinarySearchTree() {
    counter = 0;
    root = nullptr;
}

/**
 * Inserta la imagen en el arbol le asigna un identificador.
 *
 * @param image (Mat) imagen de tamaño 25x25 en gris
 */
void BinarySearchTree::insert(Mat image) {
    root = insert(root, image);
}

double BinarySearchTree::euclideanDistance(Mat img1, Mat img2) {
    return norm(img1, img2, NORM_L2);
}

BinarySearchTreeNode* BinarySearchTree::insert(BinarySearchTreeNode* node, Mat image) {
    // Tolerancia para considerar una imagen igual
    //Si el árbol no tiene hijos
    
    if (node == nullptr) {
        node = new BinarySearchTreeNode();
        node->key = ++counter;
        node->image = image;
        node->left = nullptr;
        node->right = nullptr;

        cout << "ID: " << node->key << endl;
        return node;
    }
    else if (SIMILAR < euclideanDistance(node->image, image)
        && DIFFERENT > euclideanDistance(node->image, image)) {
        node->left = insert(node->left, image);
    }
    else if (DIFFERENT <= euclideanDistance(node->image, image)) {
        node->right = insert(node->right, image);
    }
    else { //La cara es igual (menor a la distancia exigida para similar)
        cout << "Distancia euclidea (Igual): " << euclideanDistance(node->image, image) << endl;
        node->image = image; //Cambio la imagen por la nueva
        cout << "Cara igual" << endl;
    }
    
    cout << "Distancia euclidea: " << euclideanDistance(node->image, image) << endl;
    return node;
}
int BinarySearchTree::getCounter() {
    return counter;
}