#include <iostream>
using namespace std;

namespace railClasses{

    const int maxArraySize = 200;

    class Passenger{

        public:
            
            int getAge(){
                return age;
            };
            
            string getName(){
                return name;
            };
            
            Passenger(){
                name = "No name";
                age = 0;
            };

            Passenger(string aName, int age){
                name = aName;
                setAge(age);
            };

        private:
            string name;
            int age;
            
            void setAge(int newAge){
                if (10 < age < 100){
                    age = newAge;
                }else{
                    age = 0;
                    cout << "Very less or high age entered, age set to zero." << endl;
                };
            };
    };

    class Train{

        public:

            double getTravelTime(){
                return travelTime;
            };        
                        
            string getName(){
                return name;
            };
            
            string getSource(){
                return source;
            };
            
            string getDestination(){
                return destination;
            };

            int getNumRegisteredPassenger(){
                return numRegisteredPassenger;
            };

            void addPassenger(Passenger &passenger){
                passengerList[numRegisteredPassenger] = passenger;
                numRegisteredPassenger += 1;
            };

            Train(){
                name = "No name";
                source = "No Source";
                destination = "No Destination";
                setTravelTime(1);
            };

            Train(string aName, string aSource, string aDestination, double travelTime){
                name = aName;
                source = aSource;
                destination = aDestination;
                setTravelTime(travelTime);
            };
        
        private:
            
            string name, source, destination;
            double travelTime;
            int passengerLimit = 100;
            int numRegisteredPassenger = 0;
            Passenger passengerList[100];

            void setTravelTime(double newTravelTime){
                if (1. < newTravelTime < 48.){
                    travelTime = newTravelTime;
                }else{
                    travelTime = 1;
                    cout << "Very less or high travel time entered in hours." << endl;
                };
            };

    };
}