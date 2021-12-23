#include<opencv2/opencv.hpp>
#include "AVL.h"
using namespace std;
using namespace cv;
class AVLtree {
public:
    int cantNodos = 0;
    AVL* root;
    int height(AVL*);
    int difference(AVL*);
    AVL* rr_rotat(AVL*);
    AVL* ll_rotat(AVL*);
    AVL* lr_rotat(AVL*);
    AVL* rl_rotat(AVL*);
    AVL* balance(AVL*);
    AVL* insert(AVL*, Mat);
    void insert(Mat);
    AVL* searchPreOrder(AVL*, Mat img);
    void inorder(AVL*);
    void show(AVL*, int);
    vector<Mat> getTop5(AVL*);
    AVLtree() {
        root = NULL;
    }
};
