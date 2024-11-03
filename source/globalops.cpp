#include "headers/globalops.h"
#include<iostream>
#include <vector>
#include <string>
#include <cmath>
using std::cout;
using std::cin;
using std::endl;


double modulus(vector<double> v)
{
    return sqrt(pow(v.at(0), 2) + pow(v.at(1), 2) + pow(v.at(2), 2));
}

vector<double> unitize(vector<double> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        v.at(i) /= modulus(v);
    }

    return v;
}

double getDistance(vector<double> a, vector<double> b)
{
    return sqrt(pow((a.at(0) - b.at(0)), 2) + pow((a.at(1) - b.at(1)), 2) + pow((a.at(2) - b.at(2)), 2));
}

vector<double> displacement(vector<double> a, vector<double> b)
{
        vector<double> v(3);

        for(int i = 0; i < v.size(); i++)
        {
            v.at(i) = a.at(i) - b.at(i);
        }

        return v;
}

double dotProduct(vector<double> a, vector<double>b)
{

    double product = 0;

    for (int i = 0; i < 3; i++)
        product = product + a.at(i) * b.at(i);
    return product;
}

vector<double> crossProduct(vector<double> a, vector<double> b)
{
    vector<double> c = {0, 0, 0};

    c.at(0) = a.at(1) * b.at(2) - a.at(2) * b.at(1);
    c.at(1) = a.at(2) * b.at(0) - a.at(0) * b.at(2);
    c.at(2) = a.at(0) * b.at(1) - a.at(1) * b.at(0);

    return c;
}