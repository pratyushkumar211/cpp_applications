#include <iostream>
#include <string>
#include <fstream>
#include "railClasses.h"
using namespace std;
using namespace railClasses;

bool runApp = true;
int numPassengers = 0;
Passenger passengerList[maxArraySize];
int numTrains = 0;
Train trainList[maxArraySize];

string getMessage(){
    // Get message to print to the console.
    string message;
    message = "What would you like to do? \n";
    message += "Create Passenger (Enter 1). \n";
    message += "Create Train (Enter 2). \n";
    message += "Print all Passengers (Enter 3). \n";
    message += "Print all Trains (Enter 4). \n";
    message += "End Application (Enter 5). \n";
    return message;
};

void createPassenger(){
    string name;
    int age;
    // Create Passenger.
    cout << "Enter Passenger name: " << endl;
    getline(cin, name);
    cout << "Enter Passenger age:" << endl;
    cin >> age;
    // Create a passenger and add to the passenger list.
    passengerList[numPassengers] = Passenger(name, age);
    numPassengers += 1;
};

void createTrain(){
    // Create Train.
    string name, source, destination;
    int travelTime;
    // Create Passenger.
    cout << "Enter Train Name: " << endl;
    getline(cin, name);
    cout << "Enter Train Source: " << endl;
    getline(cin, source);
    cout << "Enter Train Destination: " << endl;
    getline(cin, destination);
    cout << "Enter Train Travel Time: " << endl;
    cin >> travelTime;
    // Create a train and add to the train list.
    trainList[numTrains] = Train(name, source, destination, travelTime);
    numTrains += 1;
};

ostream& operator << (ostream &out, Passenger &passenger){
    // Overloading << operator.
    out << "Name: " << passenger.getName() << ", Age: " << passenger.getAge() << endl;
    return out;
};

void printAllPassengers(ostream &out){
    // Print all the passengers in the system.
    if (numPassengers > 0){
        for (int i=1; i<=numPassengers; i++){
            out << passengerList[i-1].getName() << ", " << passengerList[i-1].getAge() << endl;
        };
    };
};

void printAllTrains(ostream &out){
    // Print all the trains in the system.
    if (numTrains > 0){
        for (int i=1; i<=numTrains; i++){
            out << "Train Number :" << i << endl;
            out << "Name: " << trainList[i-1].getName() << endl;
            out << "Source: " << trainList[i-1].getSource() << endl;
            out << "Destination: " << trainList[i-1].getDestination() << endl;
        };
    };
};

void endApplication(){
    // Load the list of passengers and trains if file available.
    string fileName = "railway.txt";
    ofstream file;
    file.open(fileName);
    printAllPassengers(file);
    printAllTrains(file);
    file.close();
};

void processUserInput(int userInput){
    // Process the user input.
    switch (userInput){
        case 1:
            createPassenger();
            break;
        case 2:
            createTrain();
            break;
        case 3:
            printAllPassengers(cout);
            break;
        case 4:
            printAllTrains(cout);
            break;
        case 5:
            runApp = false;
            break;
        default:
            cout << "Invalid Input." << endl;
    };
};

int main(){
    // Main function to run the desktop application.
    int numUserInput = 0;
    int maxUserInput = 50;
    int userInput;
    
    // Print message and run the application.
    cout << "Welcome to the Railway Reservation System!" << endl;
    while (runApp && numUserInput < maxUserInput){
        cout << getMessage();
        cin >> userInput;
        cin.ignore();
        processUserInput(userInput);
        numUserInput += 1;
    };
    endApplication();
    return 0;
}