#pragma once
#include "point.h"

class lander {
public:
    Point position;
    double fuel = 5000.0;
    double directionRadians;
    double velocityX;
    double velocityY;
    double totalVelocity;
    double thrust;
    double weight;
public:
    lander(); 
    void Thrust();
    void rotate(); 
    Point getPosition();
    double getDirectionRadians(); 
    double getVelocityX(); 
    double getVelocityY(); 
    double getTotalVelocity(); 
    double getFuel(); 
};