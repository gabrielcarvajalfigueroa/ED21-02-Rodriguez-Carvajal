#pragma
#include <vector>
#include "AVL.h"
using namespace std;
using namespace cv;
class AVLtree {
public:
    vector<AVL*> vect;
    int frame_actual;
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
    void inorder(AVL*);
    AVLtree() {
        root = NULL;
    }
};
