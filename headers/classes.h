// Includes all classes

#include <vector>
#include <string>
using std::string;
using std::vector;

// Defines a point charge and properties of a point charge
class Charge {
    public:
        // Initializing attributes of a point charge, sign, magnitude, position, and velocity
        Charge(string sign, double magnitude, double x, double y, double z);

        Charge(string sign, double magnitude, double x, double y, double z, double vx, double vy, double vz); 

        // Returns the electrostatic force acting ON CHARGE P as a vector
        vector<double> getEForce(Charge p);

        // Returns the magnetic force acting ON CHARGE P as a vector
        vector<double> getBForce(Charge p);

        // Sets the position of the charge
        void setPos(vector<double> pos);

        // Sets the velocity of the charge
        void setVel(vector<double> vel);

        // Sets the acceleration of the charge
        void setAccel(vector<double> accel);

        // Accessor method for sign of the charge
        string getSign();

        // Accessor method for magnitude of the charge
        double getMagnitude();

        // Accessor method for mass of the charge
        double getMass();

        // Accessor method for position of the charge
        vector<double> getPos();

        // Accessor method for position of the charge
        vector<double> getVel();

        //Accessor method for acceleration of the charge
        vector<double> getAccel();

    // Declaring attributes of a point charge
    private:
        char sign;
        double magnitude;
        double time;
        vector<double> position;
        vector<double> velocity;
        
};
