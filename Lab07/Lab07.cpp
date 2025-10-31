// Lab07.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cmath>
#define PI 3.14159265358979323846264338327950288

double degreesToRadians(double degree)
{
    double radians = (degree * PI) / 180;
    return radians;
}

int main()
{
    std::cout << "Hello Dragon Snails!\n";
    std::cout << degreesToRadians(180) << std::endl;
}
