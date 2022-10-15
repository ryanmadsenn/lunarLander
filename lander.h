#pragma once
#include "point.h"

using namespace std;

class Lander {
private:
    const double weight = 15103.000;
    const double thrust = 45000.000;
    const double gravity = -1.625;
    Point position;
    double fuel = 5000.0;
    double angle = 0.0;
    double velocityX;
    double velocityY;
    
    
public:
    Lander(Point position) {
        this->position.setX(position.getX() / 2);
        this->position.setY(position.getY() / 2);
    }
    
    void applyThrust() {
        velocityX += (sin(angle) * (thrust / weight)) / 10;
        velocityY += (cos(angle) * (thrust / weight)) / 10;
        fuel -= 10;
    }
    
    void applyInertia() {
        position.addX(velocityX);
        position.addY(velocityY);
    }
    
    void applyGravity() {
        velocityY += gravity / 10;
    }
    
    void rotate(string direction) {
        if (direction == "right") {
            this->angle += 0.1;
        } else if (direction == "left") {
            this->angle -= 0.1;
        }
        
        fuel -= 1;
    }
    
    Point getPosition() {
        return this->position;
    }
    
    double getAngle() {
        return this->angle;
    }
    
    double getTotalVelocity() {
        return sqrt(velocityX * velocityX + velocityY * velocityY);
    }
    
    double getFuel() {
        return this->fuel;
    }
    
};
