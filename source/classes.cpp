#include "headers/classes.h"
#include "headers/globalops.h"
#include "headers/constants.h"
#include <cmath>
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

class Charge {
    public:
        Charge(char sign, double magnitude, double x, double y, double z) 
        {
            this->sign = sign;
            this->magnitude = magnitude;
            position = {x, y, z};
            velocity = {0, 0, 0};
            acceleration = {0, 0, 0};
        }

        Charge(char sign, double magnitude, vector<double> position, vector<double> velocity, vector<double> acceleration) 
        {
            this->sign = sign;
            this->magnitude = magnitude;
            this->position = position;
            this->velocity = velocity;
            this->acceleration = acceleration;
        }
        
        vector<double> getEForce(Charge p)
        {
            double eMag = (this->getCharge() * p.getCharge()) / (4 * M_PI * epsilonNaught * pow(getDistance(this->getPos(), p.getPos()), 2));

            vector<double> r(3);

            for(int i = 0; i < 3; i++)
            {
                r.at(i) = p.getPos().at(i) - this->getPos().at(i);
            }

            r = unitize(r);

            for(int i = 0; i < 3; i++)
            {
                r.at(i) *= eMag;
            }

            return r;
        }

        vector<double> getBForce(Charge p)
        {
            double scalar = (mewNaught * this->getCharge()) / (4 * M_PI * pow(getDistance(this->getPos(), p.getPos()), 2));

            vector<double> r(3);

            for (int i = 0; i < 3; i++)
            {
                r.at(i) = p.getPos().at(i) - this->getPos().at(i);
            }

            
            r = crossProduct(this->getVel(), unitize(r));
            
            for(int i = 0; i < 3; i++)
            {
                r.at(i) *= scalar;
            }

            return r;
        }

        void setPos(vector<double> pos)
        {
            this->position = pos;
        }

        void setVel(vector<double> vel)
        {
            this->velocity = vel;
        }

        void setAccel(vector<double> accel)
        {
            this->acceleration = accel;
        }

        double getCharge()
        {
            if (sign == '+') 
                return magnitude;
            else
                return -1 * magnitude;
        }

        char getSign()
        {
            return sign;
        }

        double getMagnitude()
        {
            return magnitude;
        }

        double getMass()
        {
            return mass;
        }


        vector<double> getPos()
        {
            return position;
        }

        vector<double> getVel()
        {
            return velocity;
        }

        vector<double> getAccel()
        {
            return acceleration;
        }



    private:
        char sign;
        double magnitude;
        double mass;
        vector<double> position;
        vector<double> velocity;
        vector<double> acceleration;
        
};