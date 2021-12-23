#include "AVLtree.h"
int AVLtree::height(AVL* t) {
    int h = 0;
    if (t != NULL) {
        int l_height = height(t->l);
        int r_height = height(t->r);
        int max_height = max(l_height, r_height);
        h = max_height + 1;
    }
    return h;
}
int AVLtree::difference(AVL* t) {
    int l_height = height(t->l);
    int r_height = height(t->r);
    int b_factor = l_height - r_height;
    return b_factor;
}
double euclideanDistance(Mat img1, Mat img2) {
    try {
        return norm(img1, img2, NORM_L2);
    }
    catch (Exception e) {
    }
    return 0;

}

AVL* AVLtree::rr_rotat(AVL* parent) {
    AVL* t;
    t = parent->r;
    parent->r = t->l;
    t->l = parent;
    cout << "Right-Right Rotation";
    return t;
}
AVL* AVLtree::ll_rotat(AVL* parent) {
    AVL* t;
    t = parent->l;
    parent->l = t->r;
    t->r = parent;
    cout << "Left-Left Rotation";
    return t;
}
AVL* AVLtree::lr_rotat(AVL* parent) {
    AVL* t;
    t = parent->l;
    parent->l = rr_rotat(t);
    cout << "Left-Right Rotation";
    return ll_rotat(parent);
}
AVL* AVLtree::rl_rotat(AVL* parent) {
    AVL* t;
    t = parent->r;
    parent->r = ll_rotat(t);
    cout << "Right-Left Rotation";
    return rr_rotat(parent);
}
AVL* AVLtree::balance(AVL* t) {
    int bal_factor = difference(t);
    if (bal_factor > 1) {
        if (difference(t->l) > 0)
            t = ll_rotat(t);
        else
            t = lr_rotat(t);
    }
    else if (bal_factor < -1) {
        if (difference(t->r) > 0)
            t = rl_rotat(t);
        else
            t = rr_rotat(t);
    }
    return t;
}
void AVLtree::insert(Mat im) {
    root = insert(root, im);
}
AVL* AVLtree::insert(AVL* r, Mat im) {
    if (r == NULL) {
        r = new AVL;
        r->d = 1;
        r->im = im;
        r->l = NULL;
        r->r = NULL;
        cantNodos++;
        return r;
    }
    AVL* coincidente = searchPreOrder(r, im);
    if (coincidente != NULL) {
        cout << "EQUISDEEEEE" << endl;
        coincidente->d++;
        cout << coincidente->d << endl;
    }
    else if (1 < r->d) {
        cout << "CHAOOOOO" << endl;
        r->l = insert(r->l, im);
        r = balance(r);
    }
    else if (1 >= r->d) {
        cout << "HOLAAAAA" << endl;
        r->r = insert(r->r, im);
        r = balance(r);
    } return r;
}

AVL* AVLtree::searchPreOrder(AVL* t, Mat img) {
    if (t == NULL)
        return NULL;
    if (euclideanDistance(t->im, img) <= 1300) return t;
    searchPreOrder(t->l, img);
    searchPreOrder(t->r, img);
}

void AVLtree::inorder(AVL* t) {//   b  
    if (t == NULL)              // a   c
        return;
    inorder(t->l);
    cout << t->d << " ";
    inorder(t->r);
}

void AVLtree::show(AVL* p, int l) {
    int i;
    if (p != NULL) {
        show(p->r, l + 1);
        cout << " ";
        if (p == root)
            cout << "Root -> ";
        for (i = 0; i < l && p != root; i++)
            cout << " ";
        cout << p->d;
        show(p->l, l + 1);
    }
}

vector<Mat> AVLtree::getTop5(AVL* t) {
    vector<Mat> vect;
    if (t == NULL)              // a   c
        return vect;
    getTop5(t->l);
    vect.push_back(t->im);
    getTop5(t->r);
    return vect;
}