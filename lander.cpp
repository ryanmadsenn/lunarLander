//
//  lander.cpp
//  Lab03
//
//  Created by Ryan Madsen on 10/7/22.
//

#include <stdio.h>
#include <iostream>
#include "lander.h"

using namespace std;
    lander::lander() : position(position), fuel(fuel), directionRadians(directionRadians), 
        velocityX(velocityX), velocityY(velocityY), totalVelocity(totalVelocity), thrust(thrust), weight(weight) {}

    void lander::Thrust() {}
    void lander::rotate() {}
    
    Point lander::getPosition() {
        return position;
        }
    
    double lander::getDirectionRadians() {
        return directionRadians;
        }
    
    double lander::getVelocityX() {
        return velocityX;
        }
    
    double lander::getVelocityY() {
        return velocityY;
        }
    
    double lander::getTotalVelocity() {
        return velocityY;
        }

