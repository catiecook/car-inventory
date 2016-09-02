//
//  main.cpp
//  PA3_prep
//
//  Created by Catie Cook on 11/7/15.
//  Copyright © 2015 Catie Cook. All rights reserved.
//


#include "functions.h"
#include "vehicle.h"
#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;


int main ()

{
   
    vector <vehicle> invent;

    int choice;
    
    const int
            DISPLAY = 1,
            ADD = 2,
            EDIT = 3,
            DELETE = 4,
            SORT = 5,
            SEARCH = 6,
            READ = 7,
            WRITE = 8,
            EXIT = 9;
    
    do
    {
        
    cout <<"\n******** MAIN MENU ********" << endl;
    cout <<"Choose an option below\n" << endl;
    cout <<"\t1. Display Inventory" << endl;
    cout <<"\t2. Add to Inventory" << endl;
    cout <<"\t3. Edit Existing Inventory" << endl;
    cout <<"\t4. Delete Item in Inventory" << endl;
    cout <<"\t5. Sort Inventory" << endl;
    cout <<"\t6. Search Inventory" << endl;
    cout <<"\t7. Read from Inventory" << endl;
    cout <<"\t8. Write Inventory to File" << endl;
    cout <<"\t9. Exit Program" << endl;
    cout <<"***************************\n" << endl;
    cin >> choice;
    
    if ((choice >0) && (choice < 9))
    {
    switch(choice)
        {
        case DISPLAY:
            
            {
            cout <<"\n*****DISPLAY INVENTORY*****" << endl;
            //invent = readInvent(invent);
            displayInvent(invent);
            
            
            //link the file and display the vector elements it contains.
            //call function that closes and saves file
        
            break;
            }
            
        case ADD:
            
            {
            cout <<"\n*****ADD INVENTORY*****" << endl;
            
            invent = addInvent(invent);
            
            
            //call function that links and opens file
            //Add a new vehicle to the inventory, similar to how we added a new book in alst assignment
            //call a function that saves and closes file
            
            break;
            }
            
        case EDIT:
            
            {
           cout <<"\n*****EDIT INVENTORY*****" << endl;
           invent = editInvent(invent);
            //call function that links and opens file for writing to - - use fstream or ofstream opperator
            //Update an existing vehicle in inventory
            
            break;
            }
            
        case DELETE:
            
            {
            cout <<"\n*****DELETE INVENTORY*****"<< endl;
             //Sort so everything is in order
            invent = deleteInvent(invent);
            //call function that links and opens file
            //Deete a vehicle, use same method as las assignment
            //show user the options to delete, and use a if/else statements to chose which one to delete
            //call function to save and close file
            
            break;
            }
            
        case SORT:
            
            {
            cout <<"\n*****SORTING INVENTORY*****" << endl;
            invent = sortInvent(invent);
           
            //call function that links and opens file
            //Selection sort the VIN numbers
            //call function to save and close file
            
            break;
            }
            
        case SEARCH:
            
            {
            cout<<"\n*****SEARCH INVENTORY*****" << endl;
            
            searchInvent(invent);
            
            //call function that links and opens file
            //binary search for model of car implimented here
            //call function to save and close file
            
            break;
            }
            
        case READ:
            
            {
            cout <<"\n*****READING INVENTORY*****" << endl;
            
            invent = readInvent(invent);
            
            //call function that links and opens file
            //Read back the current inventory on file
            //call function to save and close file
            
            break;
            }
            
        case WRITE:
            
            {
            cout <<"\n*****WRITE INVENTORY TO FILE*****" << endl;
            
            writeInvent(invent);
            //cout << "EXITING NOW" << endl;
            //choice = 9;
            cout << "Press ENTER to return to main menu." << endl << endl;
            
            //call function that links and opens new file called inventory.dat
            //write everything to a new file called inventory.dat
            //call function that saves and closes file 
            
            break;
            }
            
       case EXIT: //EXIT
            
            {
            
            cout << "\n*****EXITING*****" << endl;
            break;
            }
    
        }
        
    }
        
    } while (choice !=9);
    
    return 0;
}