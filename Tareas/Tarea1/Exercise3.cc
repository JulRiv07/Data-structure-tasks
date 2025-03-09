/*  
    ---------------------------------------------------------Dynamic Array Resizing Analysis:---------------------------------------------------------
    
    > Write a program that pushes a large amount of random numbers into your vector implementation. 
      Display the size and capacity of the vector after every 1000 insertions. Graph the results, 
      and analyze the growth of the capacity. Perform this experiment with the growth policies considered in class.

*/

#include <iostream>    // Include the standard input/output stream library for console operations.
#include <cassert>     // Include the assertion library for runtime checks.
#include <fstream>     // Include the file stream library for file input/output operations.
#include <ctime>       // Include the time library for time-related functions.
#include <chrono>      // Include the chrono library for high-resolution time measurements.
#include "Vector.h"      // Include the custom Vector class definition from the "Vector.h" header file.

using namespace std;

void Exercise3() {
    ofstream archivo("ResizeTracking.dat", ios::trunc); // Open the file for writing, truncating existing content
    assert(archivo); // Ensure the file was opened successfully

    int opc2 = 0;
    int resizePolicies[] = {1, 2, 3, 4}; // Array of resize policies to test

    for (int policy : resizePolicies) { // Loop through each resize policy
        Vector<int> testVector; // Create a new Vector for each policy

        archivo << "\n\tResize Policy " << policy << "\n" << "  Size   Capacity\n"; // Write the policy header to the file

        auto start = chrono::high_resolution_clock::now(); // Start timing the policy execution
        for (unsigned int i = 0; i < 100000; i++) { // Loop to add 100,000 random elements
            int randomValue = rand() % 1000; // Generate a random value

            if (policy == 1) { // Apply resize policy 1
                testVector.push_back1(randomValue);
                // Check if a resize occurred and log the size and capacity
                if (testVector.Size() > testVector.Capacity() - 1) {
                    archivo << "  " << testVector.Size() + 1 << "    " << testVector.Capacity() + 1 << endl; // Log the new size and capacity
                }
            } else if (policy == 2) { // Apply resize policy 2
                testVector.push_back2(randomValue);
                // Check if a resize occurred and log the size and capacity
                if (testVector.Size() > testVector.Capacity() - 1) {
                    archivo << "  " << testVector.Size() + 1 << "    " << testVector.Capacity() + 2 << endl; // Log the new size and capacity
                }
            } else if (policy == 3) { // Apply resize policy 3
                testVector.push_back3(randomValue);
                // Check if a resize occurred and log the size and capacity
                if (testVector.Size() > testVector.Capacity() - 1) {
                    archivo << "  " << testVector.Size() + 1 << "    " << testVector.Capacity() * 1.5 << endl; // Log the new size and capacity
                }
            } else if (policy == 4) { // Apply resize policy 4
                testVector.push_back4(randomValue);
                // Check if a resize occurred and log the size and capacity
                if (testVector.Size() > testVector.Capacity() - 1) {
                    archivo << "  " << testVector.Size() + 1 << "    " << testVector.Capacity() * 2 << endl; // Log the new size and capacity
                }
            }
        }

        auto end = chrono::high_resolution_clock::now(); // Stop timing
        auto duration = chrono::duration_cast<chrono::milliseconds>(end - start); // Calculate execution time

        cout << "Policy " << policy << " Ended! Execution time: " << duration.count() << " milliseconds" << endl; // Output execution time
    }

    cout << "Are you curious? Do you want to see the vector? \n 0. No \n 1. Yes \n Option: "; // Ask if the user wants to see the vector
    cin >> opc2;

    if (opc2 == 1) { // If the user wants to see the vector
        // Show the vector from the last tested policy
        Vector<int> tempVector;
        if (resizePolicies[3] == 1) tempVector.push_back1(0);
        else if (resizePolicies[3] == 2) tempVector.push_back2(0);
        else if (resizePolicies[3] == 3) tempVector.push_back3(0);
        else if (resizePolicies[3] == 4) tempVector.push_back4(0);

        tempVector.print(); // Print the vector
    } else if (opc2 == 0) { // If the user does not want to see the vector
        cout << "Okay, no problem." << endl;
    } else { // If the user enters an invalid option
        cout << "Invalid option." << endl;
    }

    archivo.close(); // Close the file
}
