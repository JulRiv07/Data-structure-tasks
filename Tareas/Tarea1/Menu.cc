#include <iostream>
#include "Exercise1.cc"

int main() {

    int opc;

    do
    {   
        cout << "Enter the option do you want: "; 
        cin >> opc;

        if(opc == 0){
            cout << "The end!" << endl;
        } else if (opc == 1){
            testExercise1();
        } else if(opc == 2){
    
        } else if(opc == 3){
            
        } else if(opc == 4){
            
        } else if(opc == 5){
            
        } else cout << "Invalid option!" << endl;

    } while (opc != 0);

}