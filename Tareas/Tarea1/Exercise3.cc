#include <iostream>
#include <cassert>
#include <fstream>
#include <ctime>
#include <chrono> 
#include "Vector.h"

void Exercise3() {
    int opc;

    ofstream archivo("Testing.dat", ios::trunc);
    assert(archivo);
    

    cout << "0. Exit" << endl << "1. Capacity + 1" << endl << "2. Capacity + 2" << endl << "3. Capacity * 1.5" << endl << "4. Capacity * 2" << endl;

    do {
        cout << "There are four policies of resize, which one do you want to try: ";
        cin >> opc;

        if (opc == 1) {
            int opc2 = 0;

            Vector<int> testVector; // Reinicializar el vector aquí

            archivo << "\n\tResize + 1" << "\n" << "   Size   Capacity\n";

            auto start = chrono::high_resolution_clock::now();
            for (unsigned int i = 0; i < 100000; i++) {
                testVector.push_back1(rand() % 1000);
                if (i % 1000 == 0) {
                    archivo << "   " << testVector.size() << "   " << testVector.capacity() << endl;
                }
            }

            auto end = chrono::high_resolution_clock::now();
            auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);

            cout << "Ended! the execution time was: " << duration.count() << " milliseconds" << endl;

            cout << "Are you curious? do you want see the vector? \n 0. No \n 1. Si \n Option: ";
            cin >> opc2;

            if (opc2) {
                testVector.print();
            }

        } else if (opc == 2) {
            int opc2 = 0;

            Vector<int> testVector; // Reinicializar el vector aquí

            archivo << "\n\tResize + 2" << "\n" << "   Size   Capacity\n";

            auto start = chrono::high_resolution_clock::now();
            for (unsigned int i = 0; i < 100000; i++) {
                testVector.push_back2(rand() % 1000);
                if (i % 1000 == 0) {
                    archivo << "   " << testVector.size() << "   " << testVector.capacity() << endl;
                }
            }

            auto end = chrono::high_resolution_clock::now();
            auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);

            cout << "Ended! the execution time was: " << duration.count() << " milliseconds" << endl;

            cout << "Are you curious? do you want see the vector? \n 0. No \n 1. Si \n Opcion: ";
            cin >> opc2;

            if (opc2) {
                testVector.print();
            }

        } else if (opc == 3) {
            int opc2 = 0;

            Vector<int> testVector; // Reinicializar el vector aquí

            archivo << "\tResize * 1.5" << "\n" << "   Size   Capacity\n";

            auto start = chrono::high_resolution_clock::now();
            for (unsigned int i = 0; i < 100000; i++) {
                testVector.push_back3(rand() % 1000);
                if (i % 1000 == 0) {
                    archivo << "   " << testVector.size() << "   " << testVector.capacity() << endl;
                }
            }

            auto end = chrono::high_resolution_clock::now();
            auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);

            cout << "Ended! the execution time was: " << duration.count() << " milliseconds" << endl;

            cout << "Are you curious? do you want see the vector? \n 0. No \n 1. Si \n Opcion: ";
            cin >> opc2;

            if (opc2) {
                testVector.print();
            }

        } else if (opc == 4) {
            int opc2 = 0;

            Vector<int> testVector; // Reinicializar el vector aquí

            archivo << "\n\tResize * 2" << "\n" << "   Size   Capacity\n";

            auto start = chrono::high_resolution_clock::now();
            for (unsigned int i = 0; i < 100000; i++) {
                testVector.push_back4(rand() % 1000);
                if (i % 1000 == 0) {
                    archivo << "   " << testVector.size() << "   " << testVector.capacity() << endl;
                }
            }

            auto end = chrono::high_resolution_clock::now();
            auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);

            cout << "Ended! the execution time was: " << duration.count() << " milliseconds" << endl;

            cout << "Are you curious? do you want see the vector? \n 0. No \n 1. Si \n Opcion: ";
            cin >> opc2;

            if (opc2) {
                testVector.print();
            }
        } else if (opc != 0) {
            cout << "Incorrect Option!!" << endl;
        }

    } while (opc != 0);

    archivo.close();
}