//
// Created by fenris on 11/15/22.
//
#include <iostream>

int main() {

    //the float we try to rationalize
    float alpha = 0.75555555555;

    //starting parameters, requires 0 < alpha < 1
    float upperA = 1, upperB = 1, lowerA = 0, lowerB = 1;

    //check if we have found a rationalization for alpha
    bool finished = false;
    while (!finished) {

        //alpha is between lower limit and the upper limit numerator + the lower limit numerator all over the upper limit denominator + the lower limit denominator
        if (alpha >= lowerA/lowerB && alpha <= (upperA+lowerA)/(upperB+lowerB)) {
            upperA += lowerA;
            upperB += lowerB;

        //alpha is between the upper limit and the upper limit numerator + the lower limit numerator all over the upper limit denominator + the lower limit denominator
        } else if (alpha >= (upperA+lowerA)/(upperB+lowerB) && alpha <= upperA/upperB) {
            lowerA += upperA;
            lowerB += upperB;
        }

        //check if we have found alpha
        if (alpha == (upperA/upperB)) {
            std::cout << "Alpha was rationalized to " << upperA << "/" << upperB;
            finished = true;
        } else if (alpha == (lowerA/lowerB)) {
            std::cout << "Alpha was rationalized to " << lowerA << "/" << lowerB;
            finished = true;
        }
    }

    return 0;
}