#include <iostream>
#include <windows.h>
#include "Exercise1.cc"
#include "Exercise2.cc"
#include "Exercise3.cc"


int main() {

    int opc;

    do
    {   
        cout << "\nEnter the option do you want: "; 
        cin >> opc;

        if(opc == 0){
            cout << "The end!" << endl;
        } else if (opc == 1){
            Exercise1();
        } else if(opc == 2){
            Exercise2();
        } else if(opc == 3){
            int option = 0;
            Exercise3();
            cout << "Later of execute, do you want see the graphs of datas? \n 0. No \n 1. Si \n Option: " ;
            cin >> option;
            if(option){
                const char* url = "https://colab.research.google.com/drive/1JLIZkQCdo5Ihqa_1uOkUo17RiVjO9fOl?authuser=1#scrollTo=NBhoejnhPJM7";
                ShellExecuteA(0, "open", url, NULL, NULL, SW_SHOWNORMAL);
            }
        } else if(opc == 4){
            
        } else if(opc == 5){
            
        } else cout << "Invalid option!" << endl;

    } while (opc != 0);

}