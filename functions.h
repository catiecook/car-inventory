
//
//  cook_functions.h
//  PA3_prep
//
//  Created by Catie Cook on 11/7/15.
//  Copyright © 2015 Catie Cook. All rights reserved.
//

#ifndef cook_functions_h
#define cook_functions_h


#include <cstdlib>
#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>
#include <vector>
#include "vehicle.h"

using namespace std;


//*************** PROTOTYPES ****************************

void displayInvent(vector <vehicle>& invent);
vector <vehicle> addInvent(vector <vehicle>& invent);
vector <vehicle> editInvent(vector <vehicle>& invent);
vector <vehicle> deleteInvent(vector <vehicle>& invent);
vector <vehicle> sortInvent(vector <vehicle>& invent);
vector <vehicle> readInvent(vector <vehicle>& invent);
void writeInvent(vector <vehicle>& invent);
void searchInvent(vector <vehicle>& invent);


//************** FUNCTION DEFINITIONS *********************

void displayInvent(vector <vehicle>& invent)
{
    ofstream inFile;
    inFile.open("inventory.dat");
    
    if (invent.empty())
    {
        cout << "There are no entries yet, select Add Entry or Read from File in main menu." << endl << endl
        << "Press ENTER to return back to main menu." << endl;
        
        cin.ignore(1024, '\n');
        cin.get();
    }
    
    else
    {
        cout << fixed << showpoint << setprecision(2);
        
        for(int i = 0; i < invent.size(); i++)
        
            {
                cout << "Vehicle: #" << i + 1 << endl;
                cout << "\t\tVIN: #" << invent[i].getVin() << endl;
                cout << "\t\tMake: " << invent[i].getMake() << endl;
                cout << "\t\tModel: " << invent[i].getModel() << endl;
                cout << "\t\tYear: " << invent[i].getYear() << endl;
                cout << "\t\tPrice: " << invent[i].getPrice() << endl;
            }
    }
    inFile.close();
}

vector <vehicle> addInvent(vector <vehicle>& invent)
{

    string ivin, imake, imodel, choice;
    int iyear;
    double iprice;
    
    do
    {
    cout << "Add entries to the inventory" << endl;

        cout << "\nEnter the Vehicle VIN\n";
        cin >> ivin;
        
        cout <<"\nEnter the Vehicle make\n";
        cin >> imake;

        cout <<"\nEnter the Vehicle model \n";
        cin >> imodel;
        
        cout <<"\nEnter the Vehicle year\n";
        cin >> iyear;
        
        cout << "\nEnter the Vehicle price\n";
        cin >> iprice;
        
        invent.push_back(vehicle(ivin, imake, imodel, iyear, iprice));
       
    cout <<"Wahoo! The vehicle was added to inventory." << endl;
    cout << "Would you like to continue adding vehicles to the inventory? Yes, or No?\n" << endl;
    cin >> choice;
    
    } while(choice != "No");
    
    cout << "Press enter to return to Main Menu" << endl;
    cin.ignore(1024, '\n');
    cin.get();
    
    return invent;

}


vector <vehicle> editInvent(vector <vehicle>& invent)
{
    int choice = 0, car, iyear, iprice, i = 0; //menu = 0;
    /*const int
            VIN = 1,
            MODEL = 2,
            MAKE = 3,
            YEAR = 4,
            PRICE =5,
            EXIT = 6;*/
    
    string ivin, imodel, imake;
    
    if (invent.empty())
    {
        cout << "There are no entries yet, select Add Entry or Read from File in main menu." << endl << endl
        << "Press ENTER to return back to main menu." << endl;
        
        cin.ignore(1024, '\n');
        cin.get();
        return invent;
    }
    
    else
    {
        cout <<"Choose the number of a vehile to edit" << endl; //display the inventory for the user to pick from
    
            for(int i = 0; i < invent.size(); i++) //loop and display for as many iterations as there are items in inventory
        
                {
                    cout << i+ 1 << ". ";
                    cout << "\tVehicle with VIN # " << i << invent[i].getVin() << endl;
                }
    
        cin >> car;
    
    
        cout <<"Choose an operation to preform" << endl;
    
            cout <<"\t1. " <<"Edit VIN" << endl;
            cout <<"\t2. " <<"Edit Make" << endl;
            cout <<"\t3. " <<"Edit Model" << endl;
            cout <<"\t4. " <<"Edit Year" << endl;
            cout <<"\t5. " <<"Edit Price" << endl;
            cout <<"\t6. " <<"Exit" << endl;
    
        cin >> choice;
    
    if(choice==1)
        {
            cout <<"Vehicle's current VIN#: " << invent[i].getVin() << endl;
            cout <<"What is the new VIN?" << endl;
            cin >> ivin;
            invent[car-1].setVin(ivin);
            cout <<"Now, the VIN is: " << invent[i].getVin() << endl;
            //break;
        }
   
        if(choice==2)
        {
            cout <<"Vehicle's current Make: " << invent[i].getMake() << endl;
            cout <<"What is the new Make?" << endl;
            cin >> imake;
            invent[car-1].setMake(imake);
            cout <<"Now, the Make is: " << invent[i].getMake() << endl;
            //break;
        }
            
        if(choice==3)
        {
            cout <<"Vehicle's current Model: " << invent[i].getModel() << endl;
            cout <<"What is the new Model?" << endl;
            cin >> imodel;
            invent[car-1].setModel(imodel);
            cout <<"Now, the Model is: " << invent[i].getModel() << endl;
            //break;
        }
            
        if(choice==4)
        {
            cout <<"Vehicle's current Year: " << invent[i].getYear() << endl;
            cout <<"What is the new Year?" << endl;
            cin >> iyear;
            invent[car-1].setYear(iyear);
            cout <<"Now, the Year is: " << invent[i].getYear() << endl;
            //break;
        }
            
        if(choice==5)
        {
            cout <<"Vehicle's current Price: " << invent[i].getPrice() << endl;
            cout <<"What is the new Price?" << endl;
            cin >> iprice;
            invent[car-1].setPrice(iprice);
            cout <<"Now, the Price is: " << invent[i].getPrice() << endl;
            
            //break;
        }
            
       if(choice==6)
        {
            cout <<"Exiting";
           // break;
        }
    
    }
    return invent;
    

}

vector <vehicle> deleteInvent(vector <vehicle>& invent) // THIS IS NOT DONE YET
{
    
    int number, i;
    
    if (invent.empty())
    {
        cout << "There are no entries yet, select Add Entry or Read from File in main menu." << endl << endl
        << "Press ENTER to return back to main menu." << endl;
        
       cin.ignore(1024, '\n');
        cin.get();
        return invent;
    }
    
   else
       
    cout << "Select a vehicle to delete.\n";
    
    for(i = 0; i < invent.size(); i++)
        
    {
        cout << "Vehicle: #" << i + 1 << endl;
        cout << "VIN: " << invent[i].getVin() << endl;
        cout << "Make: " << invent[i].getMake() << endl;
        cout << "Model: " << invent[i].getModel() << endl;
        cout << "Year: " << invent[i].getYear() << endl;
        cout << "Price: " << invent[i].getPrice() << endl;
        cout << endl << "- - - - - - - - - - - -" << endl;
    }
   
    cin >> number;
    
     if (number < invent.size() +1)
        {
            for ( int i = number -1; i < invent.size() -1; i++)
            {
            invent[i] = invent[ i+ 1];
            }
       
    
    invent.pop_back();
    
            cout <<"Item deleted" << endl;
        }
    
     else
        {
        cout << "Please enter a valid number form the list." << endl;
    
    }

return invent;
}

   vector <vehicle> sortInvent(vector <vehicle>& invent) //taken largely from last assignment
{
    if (invent.empty())
         {
             cout << "There are no entries yet, select Add Entry or Read from File in main menu." << endl << endl
             << "Press ENTER to return back to main menu." << endl;
             
             cin.ignore(1024, '\n');
            cin.get();
             return invent;
         }
    
    else
    {
        cout << "\nSorting the contents of the inventory list by VIN number.\n" << endl;
        
        bool swap;
        vehicle temp;
        vehicle temp2;
        
        do
        {
            swap = false;
            for (int count = 0; count < invent.size() - 1; count++)
            {
                if (invent[count].getVin() > invent[count + 1].getVin())
                {
                    temp = invent[count];
                    temp2 = invent[count + 1];
                    invent[count] = temp2;
                    invent[count + 1] = temp;
                    swap = true;
                }
            }
        } while (swap);
        
        cout <<"Sort successful" <<endl;
        
        return invent;
    }
}

     /*
    else
    {
        sort(invent.begin(), invent.end());
        cout <<"The inventory was sorted by VIN." << endl << endl;
        cout <<"Press ENTER to return to main menu." << endl << endl;
        cin.ignore(1024, '\n');
        cin.get();
        
        return invent;
    }
}*/

vector <vehicle>readInvent(vector <vehicle>& invent)
{
    string ivin, imake, imodel;
    int iyear;
    double iprice;
    
    fstream inFile;                                     //Link file to inputFile
    inFile.open ("inventory.dat");
    
    if (invent.empty())
    {
        cout << "There are no entries yet, select Add Entry or Read from File in main menu." << endl << endl
        << "Press ENTER to return back to main menu." << endl;
        
        cin.ignore(1024, '\n');
        cin.get();
        return invent;
    }

    
    if (inFile)
    {
               while (!inFile.eof())
               {
                   inFile >> ivin;
                   inFile >> imake;
                   inFile >> imodel;
                   inFile >> iyear;
                   inFile >> iprice;
                   inFile.ignore(1, '\n');
                   invent.push_back(vehicle(ivin, imake, imodel, iyear, iprice));
               }
        
        cout <<"The items were added successfully.\n" << endl;
        cout <<"Press ENTER to return to main menu." << endl;
        
        cin.ignore(1024, '\n');
        cin.get();
        inFile.close(); // close file
        return invent;
       
    }
    
    else
    {
        cout <<"File could not be opened." << endl <<"Press ENTER to return to main menu." << endl;
        cin.ignore(1024, '\n');
        cin.get();
        return invent;
    }
}


void writeInvent(vector <vehicle>& invent)
{
    
     ofstream outFile;
     outFile.open("inventory.dat");
    
    if(outFile)
    {
        cout <<" File opened" << endl;
    
         for(int i = 0; i < invent.size(); i++)
             
         {
             outFile << fixed << showpoint << setprecision(2);
             outFile << invent[i].getVin() << endl;
             outFile << invent[i].getMake() << endl;
             outFile << invent[i].getModel() << endl;
             outFile << invent[i].getYear() << endl;
             outFile << invent[i].getPrice() << endl;
         }
     }
   
     cout <<"\nThe data was successfully added to the file.\n\n";
     outFile.close();
}

void searchInvent(vector <vehicle>& invent) //Search by Model of car
{
    string model;
    
   // invent = sortInvent(invent); //Sort inventory for the search

    cout <<"Enter the model of the car you would like to search for." << endl;
        cin >> model;
    
        if (invent.empty())
            {
            cout << "The vector is empty." << endl << endl;
            cout << "Press ENTER to return to main menu." << endl << endl;
            }
    
    for(int i = 0; i < invent.size(); i++)
        {
        if (invent[i].getModel() == model)
            {
            cout << "The " << model <<" was found at inventory place #" << i + 1 << endl;
            }
            
    /*
    if ( std::find(invent.begin(), invent.end(), model) != invent.end())
    {
        cout <<"The " << model <<" was found in the vector." << endl << endl;
    } */
    
        if(invent[i].getModel() != model)
            {
                cout <<"Sorry, we could not find that specific vehicle." << endl;
            }
            
        }
}





#endif /* cook_functions_h */
