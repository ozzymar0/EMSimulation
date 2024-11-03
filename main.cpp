#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include "headers/globalops.h"
#include "headers/classes.h"
#include "headers/constants.h"
using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;

int main() {
    cout << "Hello world" << endl;

    PointCharge negative("+", 1, 0, 0, 0);
    
    cout << negative.getMagnitude() << endl;

    return 0;
}