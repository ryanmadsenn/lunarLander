#pragma once
#include "point.h"

using namespace std;

class Lander {
private:
    const double weight = 15103.000;
    const double thrust = 45000.000;
    const double gravity = -1.625;
    Point position = Point(200.0, 200.0);
    double fuel = 5000.0;
    double angle = 0.0;
    double velocityX;
    double velocityY;
    bool isLanded = false;
    
    void setPosition(Point point) {
        this->position = point;
    }
    
    void setVelocityX(double velocityX) {
        this->velocityX = velocityX;
    }
    
    void setVelocityY(double velocityY) {
        this->velocityY = velocityY;
    }
    
    
public:
    Lander(Point position) {
        this->position.setX(position.getX());
        this->position.setY(position.getY());
    }
    
    void applyThrust() {
        velocityX += (sin(angle) * (thrust / weight)) / 30;
        velocityY += (cos(angle) * (thrust / weight)) / 30;
        fuel -= 10;
    }
    
    void applyInertia() {
        position.addX(velocityX);
        position.addY(velocityY);
    }
    
    void applyGravity() {
        velocityY += gravity / 30;
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
    
    bool getLanded() {
        return this->isLanded;
    }
    
    void setLanded(bool landed) {
        this->isLanded = landed;
    }
    
    void setAngle(double angle) {
        this->angle = angle;
    }
    
    void resetLander() {
        Point point = Point(random(0,400), 400);
        this->setPosition(point);
        this->setAngle(0.0);
        this->setLanded(false);
        this->setVelocityX(0.0);
        this->setVelocityY(0.0);
        this->fuel = 5000;
    }
};
