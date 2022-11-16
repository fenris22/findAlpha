//
// Created by fenris on 11/15/22.
//
#include <iostream>

int main() {

    float alpha = 0.75555555555;

    float upperA = 1;
    float upperB = 1;

    float lowerA = 0;
    float lowerB = 1;

    bool finished = false;

    while (!finished) {
        if (alpha >= lowerA/lowerB && alpha <= (upperA+lowerA)/(upperB+lowerB)) {
            upperA += lowerA;
            upperB += lowerB;
        } else if (alpha >= (upperA+lowerA)/(upperB+lowerB) && alpha <= upperA/upperB) {
            lowerA += upperA;
            lowerB += upperB;
        }

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