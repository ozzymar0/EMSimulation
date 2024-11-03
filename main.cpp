#include <iostream>
#include <fstream>
#include <cstdio>
#include <vector>
#include <string>
#include <cmath>
#include <chrono>
#include <thread>
#include "headers/globalops.h"
#include "headers/classes.h"
#include "headers/constants.h"
using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;

vector<Charge> charges;

void simulate(std::vector<Charge>& charges, double deltaTime, int maxIterations = 1000, double timeLimit = 10.0, double thresholdVelocity = 0.01) {
    double totalTime = 0.0;
    int iteration = 0;

    auto startTime = std::chrono::high_resolution_clock::now(); // Record the start time
    
    // Open Gnuplot
    FILE* gnuplotPipe = popen("gnuplot -persistent", "w");
    if (gnuplotPipe == nullptr) {
        cout << "Could not open Gnuplot pipe.\n";
        return;
    }
    
    // Initialize Gnuplot
    fprintf(gnuplotPipe, "set xrange [-1000:1000]\n");
    fprintf(gnuplotPipe, "set yrange [-1000:1000]\n");
    fprintf(gnuplotPipe, "set zrange [-1000:1000]\n");
    fprintf(gnuplotPipe, "set title 'Charge Simulation'\n");
    fprintf(gnuplotPipe, "set xlabel 'X'\n");
    fprintf(gnuplotPipe, "set ylabel 'Y'\n");
    fprintf(gnuplotPipe, "set zlabel 'Z'\n");
    fprintf(gnuplotPipe, "set grid\n");

    // Main simulation loop
    while (iteration < maxIterations && totalTime < timeLimit) 
    {
        auto iterationStartTime = std::chrono::high_resolution_clock::now(); // Time at the beginning of the iteration
        
        // Calculate forces and update accelerations, velocities, and positions
        for (auto& charge : charges) {
            vector<double> netForce(3, 0.0);

            for (auto& other : charges) 
            {
                if (&charge != &other) 
                {

                    vector<double> eForce = other.getEForce(charge);
                    vector<double> bForce = other.getBForce(charge);

                    for (size_t i = 0; i < netForce.size(); ++i) 
                    {
                        netForce[i] += eForce[i] + bForce[i];
                    }
                }
            }

            double mass = charge.getMass();
            vector<double> newAccel(3);
            for (size_t i = 0; i < netForce.size(); ++i) {
                newAccel[i] = netForce[i] / mass;
            }
            charge.setAccel(newAccel);
        }

        for (auto& charge : charges) {
            // Update velocity and position
            auto vel = charge.getVel();
            auto pos = charge.getPos();
            auto accel = charge.getAccel();
            
            for (size_t i = 0; i < 3; ++i) {
                vel[i] += accel[i] * deltaTime;
                pos[i] += vel[i] * deltaTime;
            }
        }

        // Write positions to a file for Gnuplot
        std::ofstream dataFile("charge_data.dat");
        for (auto& charge : charges) {
            auto pos = charge.getPos();
            dataFile << pos[0] << " " << pos[1] << " " << pos[2] << "\n"; // Write X, Y, Z
        }
        dataFile.close();

        // Tell Gnuplot to plot the data
        fprintf(gnuplotPipe, "splot 'charge_data.dat' with points pt 7 ps 1\n");
        fprintf(gnuplotPipe, "pause 0.1\n"); // Pause for a moment to allow the plot to update

        // Increment time and iteration
        totalTime += deltaTime;
        ++iteration;

        // Check for stopping condition: if all velocities are below the threshold
        bool allAtRest = true;
        for (auto& charge : charges) {
            auto vel = charge.getVel();
            for (double v : vel) {
                if (std::abs(v) > thresholdVelocity) {
                    allAtRest = false;
                    break;
                }
            }
            if (!allAtRest) break; // Exit the loop early if any charge is still moving
        }

        if (allAtRest) {
            cout << "Simulation ended: all charges are at rest.\n";
            break; // Exit the while loop if the condition is met
        }

        // Calculate elapsed time for this iteration
        auto iterationEndTime = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsedTime = iterationEndTime - iterationStartTime;

        // Sleep for the remainder of deltaTime, if necessary
        if (elapsedTime.count() < deltaTime) {
            std::this_thread::sleep_for(std::chrono::duration<double>(deltaTime - elapsedTime.count()));
        }
    }

    cout << "Simulation complete: " << iteration << " iterations over " << totalTime << " seconds.\n";
    
    // Close Gnuplot
    pclose(gnuplotPipe);
}

// Everything here is still a WIP, i'm working on creating the user inputs or going to make a gui to add charges
int main() {
    double deltaTime, maxIterations;
    cout << "Welcome to Ozzy's EM Simulation" << '\n';

    char input; 
    int i = 0;
    while ()
    {
        i++;
        cout << "Enter the charge for charge #" + i + ":";
        cin >>
    }



    simulate(charges, deltaTime, 1000, 10.0, 0.01);


    return 0;
}