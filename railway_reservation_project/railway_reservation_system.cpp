#include <iostream>
#include <string>
#include <fstream>
#include "railClasses.h"
using namespace std;
using namespace railClasses;

bool runApp = true;
int numPassengers = 0;
Passenger passengerList[400];
int numTrains = 0;
Train trainList[20];

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

/*
void startApplication(){
    // Load the list of passengers and trains if file available.
    string fileName = "railway_data.dat";
    ofstream file;
    Passenger passenger;
    passenger = Passenger("Pratyush", 18);
    file.open(fileName, ios::binary);
    file << 2;
    file.close();
};

void endApplication(){
    // Save the list of passengers and trains to a file and close.


};
*/

void printAllPassengers(){
    // Print all the passengers in the system.
    if (numPassengers == 0){
        cout << "No Passengers added yet." << endl;
    }else{
        for (int i=1; i<=numPassengers; i++){
            cout << "Passenger Number :" << i << endl;
            cout << "Name: " << passengerList[i-1].getName() << endl;
            cout << "Age: " << passengerList[i-1].getAge() << endl;
        };
    };
};

void printAllTrains(){
    // Print all the trains in the system.
    if (numTrains == 0){
        cout << "No Trains added yet." << endl;
    }else{
        for (int i=1; i<=numTrains; i++){
            cout << "Train Number :" << i << endl;
            cout << "Name: " << trainList[i-1].getName() << endl;
            cout << "Source: " << trainList[i-1].getSource() << endl;
            cout << "Destination: " << trainList[i-1].getDestination() << endl;
        };
    };
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
            printAllPassengers();
            break;
        case 4:
            printAllTrains();
            break;
        case 5:
            runApp = false;
            break;
        default:
            cout << "Invalid Input." << endl;
    };
};

/*

Add passenger to a train. 
Print all trains/passengers and passengers in a particular train.

Save data when application is ended and start from there. 

*/


int main(){
    // Main function to run the desktop application.
    int numUserInput = 0;
    int maxUserInput = 6;
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
    return 0;
}