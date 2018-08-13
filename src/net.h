#ifndef NET_H
#define NET_H
#endif // NET_H
#pragma once

#include <iostream>

#include "opencv2/highgui.hpp"
#include "opencv2/core.hpp"

namespace seth {
    class Net {
    public:
        std::vector<int> layer_neuron_num;
        std::vector<cv::Mat> layer;
        std::vector<cv::Mat> weights;
        std::vector<cv::Mat> bias;

    public:
        Net() {};

        ~Net() {};

        //Initialize net:genetate weights matrices、layer matrices and bias matrices
        // bias default all zero
        void initNet(std::vector<int> layer_neuron_num_);

        //Initialise the weights matrices.
        void initWeights(int type = 0, double a = 0., double b = 0.1);

        //Initialise the bias matrices.
        void initBias(cv::Scalar &bias);

        //Forward
        void forward();

        //Forward
        void backward();

    protected:
        //initialise the weight matrix.if type =0,Gaussian.else uniform.
        void initWeight(cv::Mat &dst, int type, double a, double b);

        //Activation function
        cv::Mat activationFunction(cv::Mat &x, std::string func_type);

        //Compute delta error
        void deltaError();

        //Update weights
        void updateWeights();
    };
} // namespace seth