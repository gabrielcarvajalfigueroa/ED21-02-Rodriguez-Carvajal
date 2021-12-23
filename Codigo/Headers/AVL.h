#include <opencv2/opencv.hpp>
class AVL
{
public:
    int d;
    cv::Mat im;
    struct AVL* l;
    struct AVL* r;
};

