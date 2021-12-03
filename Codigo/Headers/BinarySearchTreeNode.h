#pragma once
/**
 * Clase que almacena la imagen y el identificador de la cara
 */
class BinarySearchTreeNode {
public:
    int key;
    Mat image; // Imagen de tamaño 25x25
    BinarySearchTreeNode* left;
    BinarySearchTreeNode* right;
};