#pragma once
#include "point.h"

class lander {
    
    class computer {
        double gravity = 1.625;
        
        void computeAccelerationThrust() {
            
        }
        
        void computeHorizontalComponent() {
            
        }
        
        void computeVerticalComponent() {
            
        }
        
        void computeVeloctiy() {
            
        }
        
        void computeDistance() {
            
        }
        
        void computeTotalVelocity() {
            
        }
    };
    
    
private:
    Point position;
    double fuel = 5000.0;
    double directionRadians;
    double velocityX;
    double velocityY;
    double totalVelocity;
    double thrust = 45000;
    double weight = 15103;
    computer computer;
    
    
    
public:
    lander() {}
    
    void Thrust() {}
    
    void rotate() {}
    
    Point getPosition() {
        return this->position;
    }
    
    double getFuel() {
        return this->fuel;
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
        return this->totalVelocity;
    }
    
    double getWeight() {
        return this->weight;
    }
    
    void setPosition() {}
    
    void setDirectionRadians() {}
    
    void setVelocityX() {}
    
    void setVelocityY() {}
    
    void setTotalVelocity() {}
    
};
