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

// Acceleration function
// Now introduce gravity at a constant -9.8m/s2. 
// This will require you to update the velocity based on the acceleration due to gravity. 
// First, update the position using the distance formula. Next, after the position is updated, update the velocity. 
// Use the distance formula and the kinematics equation to compute the new position (with (x,y) instead of s) and velocity (with (dx, dy) instead of v). 
// Notice how our horizontal distance is unaffected, but our altitude has decreased significantly.
void acceleration(double constantGravity)
{
}

// Main fuction
int main()
{
    cout << "Hello Dragon Snails!\n";
	inertia(827.0, 75.0);
	acceleration(-9.8);
}
