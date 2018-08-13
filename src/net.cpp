#include "net.h"
#include <iostream>

using namespace seth;

void Net::initNet(std::vector<int> layer_neuron_num_) {
    layer_neuron_num = layer_neuron_num_;
    //Generate every layer.
    layer.resize(layer_neuron_num.size());
    for (int i = 0; i < layer.size(); i++) {
        layer[i].create(layer_neuron_num[i], 1, CV_32FC1);
    }
    std::cout << "Generate layers, successfully!" << std::endl;
    //Generate every weights matrix and bias
    weights.resize(layer.size() - 1);
    bias.resize(layer.size() - 1);
    for (int i = 0; i < (layer.size() - 1); ++i) {
        weights[i].create(layer[i + 1].rows, layer[i].rows, CV_32FC1);
        //bias[i].create(layer[i + 1].rows, 1, CV_32FC1);
        bias[i] = cv::Mat::zeros(layer[i + 1].rows, 1, CV_32FC1);
    }
    std::cout << "Generate weights matrices and bias, successfully!" << std::endl;
    std::cout << "Initialise Net, done!" << std::endl;
}

void Net::initWeight(cv::Mat &dst, int type, double a, double b) {
    if (type == 0) {
        randn(dst, a, b);
    } else {
        randn(dst, a, b);
    }
}

//initialise the weights matrix.
void Net::initWeights(int type, double a, double b) {
    //Initialise weights cv::Matrices and bias
    for (int i = 0; i < weights.size(); ++i) {
        initWeight(weights[i], 0, 0., 0.1);
    }
}