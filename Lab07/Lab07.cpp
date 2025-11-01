// Lab07.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cmath>
#define PI 3.14159265358979323846264338327950288

using namespace std;

// Equations here:
double degreesToRadians(double degree)
{
    double radians = (degree * PI) / 180;
    return radians;
}

double radiansToDegrees(double radians)
{
    double degree = (radians * 180) / PI;
    return degree;
}

double verticalComponent(double speed, double angle)
{
    double vertical = speed * cos(angle);
	return vertical;
}

double horizontalComponent(double speed, double angle)
{
    double horizontal = speed * sin(angle);
    return horizontal;
}

double distanceFormula(double initialDistance, double velocity, double time, double equationAcceleration)
{
    double distance = initialDistance + (velocity * time) + (0.5 * equationAcceleration * (time * time));
	return distance;
}

double kinematicsEquation(double initialVelocity, double equationAcceleration, double time)
{
    double velocity = initialVelocity + (equationAcceleration * time);
    return velocity;
}

// Assignment functions:

// Inertia function, passed
void inertia(double initialSpeed, double initialAngle)
{
    double distance = 0.0;
    double altitude = 0.0;

    double angleInRadians = degreesToRadians(initialAngle);
    double dx = horizontalComponent(initialSpeed, angleInRadians); // s * sin(a)
    double dy = verticalComponent(initialSpeed, angleInRadians);   // s * cos(a)

    // run for 20 seconds (exactly 20 iterations)
    for (int time = 1; time <= 20; ++time)
    {
        distance += dx;
        altitude += dy;
    }

    cout << "Distance: " << distance << "m"
        << " Altitude: " << altitude << "m" << endl;
}

// Acceleration function, passed
void acceleration(double constantGravity)
{
    double distance = 0.0;
    double altitude = 0.0;
    double initialSpeed = 827.0;
    double initialAngle = 75.0;
    double angleInRadians = degreesToRadians(initialAngle);
    double dx = horizontalComponent(initialSpeed, angleInRadians);
    double dy = verticalComponent(initialSpeed, angleInRadians);
    for (int time = 1; time <= 20; ++time)
    {
        distance = distanceFormula(distance, dx, 1.0, 0.0);
        altitude = distanceFormula(altitude, dy, 1.0, constantGravity);
        dy = kinematicsEquation(dy, constantGravity, 1.0);
    }
    cout << "Distance with gravity: " << distance << "m"
		<< " Altitude with gravity: " << altitude << "m" << endl;
}

// Main fuction
int main()
{
    cout << "Hello Dragon Snails!\n";
	inertia(827.0, 75.0);
	acceleration(-9.8);
}
