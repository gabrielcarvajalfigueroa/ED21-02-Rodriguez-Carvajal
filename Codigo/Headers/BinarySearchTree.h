#pragma once
#include "opencv2/core.hpp"

using namespace cv;

class BinarySearchTree {

private:
    const int DIFFERENT = 1700;
    const int SIMILAR = 1300;
    /**
     * Contador para asignar identificadores a las caras
     */
    int counter;
    struct BinarySearchTreeNode* root;
    BinarySearchTreeNode* insert(BinarySearchTreeNode* node, Mat);
    double euclideanDistance(Mat, Mat);

public:
    BinarySearchTree();

    void insert(Mat);

    int getCounter(); // Get para obtener el total de personas identificadas

    //TODO: Falta hacer el destructor para eliminar cualquier el arbol complementamente
};