#include <iostream>
#include <string>
#include <fstream>
#include "railClasses.h"
using namespace std;
using namespace railClasses;

// A few global variables for the application.
bool runApp = true;
int numPassengers = 0;
Passenger passengerList[maxArraySize];
int numTrains = 0;
Train trainList[maxArraySize];
string passengersFilename = "passengers.txt";
string trainsFilename = "trains.txt";

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
            out << passengerList[i-1].getName() << "," << passengerList[i-1].getAge() << endl;
        };
    };
};

void printAllTrains(ostream &out){
    // Print all the trains in the system.
    if (numTrains > 0){
        for (int i=1; i<=numTrains; i++){
            out << trainList[i-1].getName();
            out << "," << trainList[i-1].getSource();
            out << "-" << trainList[i-1].getDestination();
            out << "," << trainList[i-1].getTravelTime() << endl;
        };
    };
};

void endApplication(){
    // Save everything to a file.
    ofstream file;

    // First save passengers.
    file.open(passengersFilename);
    printAllPassengers(file);
    file.close();

    // Next save trains.
    file.open(trainsFilename);
    printAllTrains(file);
    file.close();

};

void loadTrains(ifstream &file){
    string name, source, destination, travelTimeStr;
    double travelTime;
    file.open(trainsFilename);
    while(!getline(file, name, ',').eof()){
        getline(file, source, '-');
        getline(file, destination, ',');
        getline(file, travelTimeStr);
        travelTime = stod(travelTimeStr);
        trainList[numTrains] = Train(name, source, destination, travelTime);
        //cout << name << source << destination << travelTime << endl;
        numTrains += 1;
    };
    file.close();
};

void loadPassengers(ifstream &file){
    string line, name;
    int age;
    file.open(passengersFilename);
    while(!getline(file, name, ',').eof()){
        file >> age;
        file.ignore();
        passengerList[numPassengers] = Passenger(name, age);
        numPassengers += 1;
    };
    file.close();
};

void startApplication(){
    // Load data from files at the start of the application. 
    ifstream file;
    loadPassengers(file);
    loadTrains(file);
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
    startApplication();
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