//
//  cook_vehicle.h
//  PA3_prep
//
//  Created by Catie Cook on 11/7/15.
//  Copyright © 2015 Catie Cook. All rights reserved.
//

#ifndef cook_vehicle_h
#define cook_vehicle_h

#include <string>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

//*********** CLASS DEFINITION ************

class vehicle
{
    private:
        string vin;
        string make;
        string model;
        int year;
        double price;
    
    public:
    vehicle(string ivin, string imake, string imodel, int iyear, double iprice);
    vehicle();
    string getVin();
    string getMake();
    string getModel();
    int getYear();
    double getPrice();
    void setVin(string);
    void setMake(string);
    void setModel(string);
    void setYear(int);
    void setPrice(double);
    
};

//vector <vehicle> invent;



#endif /* cook_vehicle_h */
