// Useful operations (on vectors, etc)

#include <vector>
#include <string>
#include <cmath>
using std::string;
using std::vector;

// Returns magnitude of a vector
double modulus(vector<double> v);

// Returns a unit vector
vector<double> unitize(vector<double> v);

// Calculates and returns distance between 2 vectors
double getDistance(vector<double> a, vector<double> b);

// Returns displacement vector between 2 vectors (VEC A - VEC B, so facing TOWARDS B)
vector<double> displacement(vector<double> a, vector<double> b);

// Returns dot product of 2 vectors
double dotProduct(vector<double> a, vector<double>b);

// Returns cross product of 2 vectors
vector<double> crossProduct(vector<double> a, vector<double> b);