// Lab07.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cmath>
#define PI 3.14159265358979323846264338327950288

using namespace std;

// ---------- Equations ----------
double degreesToRadians(double degree)
{
    return (degree * PI) / 180.0;
}

double radiansToDegrees(double radians)
{
    return (radians * 180.0) / PI;
}

double verticalComponent(double speed, double angle)
{
    return speed * cos(angle);
}

double horizontalComponent(double speed, double angle)
{
    return speed * sin(angle);
}

double distanceFormula(double initialDistance, double velocity, double time, double equationAcceleration)
{
    return initialDistance + (velocity * time) + (0.5 * equationAcceleration * (time * time));
}

double kinematicsEquation(double initialVelocity, double equationAcceleration, double time)
{
    return initialVelocity + (equationAcceleration * time);
}

// ---------- Assignment ----------:

// Inertia function, passed
void inertia(double initialSpeed, double initialAngle)
{
    double distance = 0.0;
    double altitude = 0.0;

    double angleInRadians = degreesToRadians(initialAngle);
    double dx = horizontalComponent(initialSpeed, angleInRadians); // s * sin(a)
    double dy = verticalComponent(initialSpeed, angleInRadians);   // s * cos(a)

    for (int time = 1; time <= 20; ++time)
    {
        distance += dx;
        altitude += dy;
    }

    cout << "Inertia -> Distance: " << distance << "m   Altitude: " << altitude << "m" << endl;
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

    cout << "Acceleration -> Distance: " << distance << "m   Altitude: " << altitude << "m" << endl;
}

//Ground Impact, passed (round up the decimal, it has 2 digits instead of the 1 that is on the assignment)
void groundImpact(double timeInterval, double gravity, double initialSpeed, double initialAngle)
{
	double impactDistance = 0.0;
	double impactAltitude = 0.0;
	double hangTime = 0.0;

	double angleInRadians = degreesToRadians(initialAngle);

	double dx = horizontalComponent(initialSpeed, angleInRadians);
	double dy = verticalComponent(initialSpeed, angleInRadians);

    while (impactAltitude >= 0.0)
    {
		impactDistance = distanceFormula(impactDistance, dx, timeInterval, 0.0);
		impactAltitude = distanceFormula(impactAltitude, dy, timeInterval, gravity);
		dy = kinematicsEquation(dy, gravity, timeInterval);
		hangTime += timeInterval;
    }

    cout << "distance: " << impactDistance << "m"
        << " altitude: " << impactAltitude << "m"
		<< " hang time: " << hangTime << "s" << endl;
}

// Main fuction
int main()
{
    cout << "Hello Dragon Snails!\n";
	inertia(827.0, 75.0);
	acceleration(-9.8);
	groundImpact(0.01, -9.8, 827.0, 75.0);

    return 0;
}
