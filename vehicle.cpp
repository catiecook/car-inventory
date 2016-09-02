//
//  main.cpp
//  PA3_prep
//
//  Created by Catie Cook on 11/7/15.
//  Copyright © 2015 Catie Cook. All rights reserved.
//



#include "vehicle.h"
#include <iostream>
#include <string>
#include <cctype>

using namespace std;

//******** MEMBER FUNCTION DEFINITIONS **********

vehicle::vehicle(string ivin, string imake, string imodel, int iyear, double iprice)
{
    vin = ivin;
    make = imake;
    model = imodel;
    year = iyear;
    price = iprice;
}

vehicle::vehicle()
{
    vin = " ";
    make = " ";
    model = " ";
    year = 0;
    price = 0.0;
}

string vehicle::getVin()
{
    return vin;
}

string vehicle::getMake()
{
    return make;
}

string vehicle::getModel()
{
    return model;
}

int vehicle::getYear()
{
    return year;
}

double vehicle::getPrice()
{
    return price;
}

void vehicle::setVin(string ivin)
{
    vin = ivin;
}

void vehicle::setMake(string imake)
{
    make = imake;
}

void vehicle::setModel(string imodel)
{
    model = imodel;
}

void vehicle::setYear(int iyear)
{
    year = iyear;
}

void vehicle::setPrice(double iprice)
{
    price = iprice;
}



/*int main()

{
   
    
    
    return 0;
}
*/