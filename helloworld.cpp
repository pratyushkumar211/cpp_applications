#include <iostream>
#include <string>
using namespace std;

int main(){

    string name;
    cout << "Hello World!" << endl;
    cout << "Please enter your name: \n"; 
    getline(cin, name); 
    cout << "Hello, " << name << "\n"; 
  
    return 0; 
}