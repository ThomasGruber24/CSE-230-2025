// Lab07.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cmath>
#include <vector>
#define PI 3.14159265358979323846264338327950288
#define GRAVITY -9.8

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

double linearInterpolation(double r0, double r1, double d0, double d1, double d)
{
    return r0 + (r1 - r0) * ((d - d0) / (d1 - d0));
}


// ---------- Assignment ----------

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
void acceleration(double constantGravity, double initialSpeed, double initialAngle)
{
    double distance = 0.0;
    double altitude = 0.0;

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

double getGravity(double altitude, const vector<double>& altitudes, const vector<double>& gravities)
{
    if (altitude <= altitudes.front())
        return gravities.front();

    for (size_t i = 0; i < altitudes.size() - 1; ++i)
    {
        if (altitude >= altitudes[i] && altitude <= altitudes[i + 1])
        {
            return linearInterpolation(
                gravities[i],
                gravities[i + 1],
                altitudes[i],
                altitudes[i + 1],
                altitude
            );
        }
    }

    return gravities.back();
}


void gravity(double timeInterval, double initialSpeed, double initialAngle,
    const vector<double>& altitudes, const vector<double>& gravities)
{
    double impactDistance = 0.0;
    double impactAltitude = 0.0;
    double hangTime = 0.0;

    double angleRadians = degreesToRadians(initialAngle);
    double dx = horizontalComponent(initialSpeed, angleRadians);
    double dy = verticalComponent(initialSpeed, angleRadians);

    while (impactAltitude >= 0.0)
    {
        double g = -getGravity(impactAltitude, altitudes, gravities);

        impactDistance = distanceFormula(impactDistance, dx, timeInterval, 0.0);
        impactAltitude = distanceFormula(impactAltitude, dy, timeInterval, g);
        dy = kinematicsEquation(dy, g, timeInterval);

        hangTime += timeInterval;
    }

    cout << "Distance: " << impactDistance << " m"
        << "   Altitude: " << impactAltitude << " m"
        << "   Hang Time: " << hangTime << " s" << endl;
}
// Main fuction
int main()
{
    vector<double> altitudes = { 0.0, 1000.0, 2000.0, 3000.0, 4000.0, 5000.0, 6000.0, 7000.0, 8000.0, 9000.0, 10000.0, 15000.0, 20000.0, 25000.0, 30000.0, 40000.0, 50000.0, 60000.0, 70000.0, 80000.0 };
	vector<double> gravities = { 9.807, 9.804, 9.801, 9.797, 9.794, 9.791, 9.788, 9.785, 9.782, 9.779, 9.776, 9.761, 9.745, 9.730, 9.715, 9.684, 9.654, 9.624, 9.594, 9.564 };


    cout << "Hello Dragon Snails!\n";
	inertia(827.0, 75.0);
	acceleration(GRAVITY, 827.0, 75.0);
	groundImpact(0.01, GRAVITY, 827.0, 75.0);
    gravity(0.01, 827.0, 75.0, altitudes, gravities);


    return 0;
}
