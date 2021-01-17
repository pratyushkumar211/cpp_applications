#include <iostream>
using namespace std;


class Passenger{

    public:

    private:
        string name;
        int age;

};

class Train{
    public:
        double getTravelTime(){
            return travelTime;
        };
        void setTravelTime(double newTravelTime){
            if (1 < newTravelTime < 48){
                travelTime = newTravelTime;
            }else{
                cout << "Very less or high travel time entered in hours." << endl;
            };
        };
    private:
        string name, source, destination;
        double travelTime;
        int passenger_limit;
        Passenger *passenger_list;

    Train(string aName, string aSource, string aDestination,
          double Traveltime, int aPassengerLimit){
              name = aName;
              source = aSource;
              destination = aDestination;
              setTravelTime(Traveltime);
              passenger_limit = aPassengerLimit;
              passenger_list = new Passenger[aPassengerLimit];
          };

};

void main(){


}
