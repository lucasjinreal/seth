#include "src/net.h"
#include <iostream>
#include <vector>

#include "opencv2/highgui.hpp"
#include "opencv2/core.hpp"
#include "opencv2/opencv.hpp"

using namespace cv;
using namespace seth;
using namespace std;

int main() {
    vector<int> layer_neuron_num = {784, 100, 10};
    // Initialise Net and weights
    Net net;
    net.initNet(layer_neuron_num);
    net.initWeights(0, 0., 0.01);

    Scalar bias = Scalar(0.05);
    net.initBias(bias);
    getchar();

    return 0;
}