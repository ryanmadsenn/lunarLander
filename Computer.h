#pragma once
#include <iostream>
using namespace std; 

class Computer {
private : 
	const double GRAVITY = 1.625; 
	double newPosition; 
public: 
	Computer(); 
	double computeAccelerationThrust(double thrust, double weight);
	double computeHorizontalComponent(); 
	double computeVerticalComponent();
	double computeVelocity(double velocity, double acceleration, double time);
	double computeDistance();
	double computeTotalVelocity(); 

};