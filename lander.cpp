//
//  lander.cpp
//  Lab03
//
//  Created by Ryan Madsen on 10/7/22.
//

#include <stdio.h>
#include <iostream>
#include "point.h"

using namespace std;

class lander {
private:
    Point position;
    double fuel = 5000.0;
    double directionRadians;
    double velocityX;
    double velocityY;
    double totalVelocity;
    double thrust;
    double weight;

public:
    void Thrust() {}
    void rotate() {}
    
    Point getPostion() {
        return this->position;
    }
    
    double getDirectionRadians() {
        return this->directionRadians;
    }
    
    double getVelocityX() {
        return this->velocityX;
    }
    
    double getVelocityY() {
        return this->velocityY;
    }
    
    double getTotalVelocity() {
        return this->velocityY;
    }

    
    
    
    
};
