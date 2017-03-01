#pragma once
#include <string>
#include <stdexcept>


#include "Baby.h"

using namespace std;

class MedicalRecord {
public:
	// default constructor
	MedicalRecord() {
        length = 0;
        Count = 1;
        
	}

	// destructor
	~MedicalRecord() {  		//delete all the dynamic array that created
        delete []listWeight;
        delete []listName;
        delete []uniName;
        delete []nameCount;
	}
    
	// Load information from a text file with the given filename.
	void buildMedicalRecordfromDatafile(string filename) {
		ifstream myfile(filename);

		if (myfile.is_open()) {
			cout << "Successfully opened file " << filename << endl;
			string name;
			int weight;
			while (myfile >> name >> weight) {
                //cout << name << " " << weight << endl;
				Baby b(name, weight);       //call Baby.h file get use getName and getWeight function
				addEntry(b);                //call function to add name and weight to new array
			}
			myfile.close();
		}
		else                                //throw an error if cannot read file
			throw invalid_argument("Could not open file " + filename);
	}

	// return the most frequently appearing name in the text file
    string mostPopularName() {
        uniName[0] = listName[0];      			 //set the first name on unique name array to prevent error
        nameCount[0] = 0;              			 //set initial nameCount for uniName to prevent adding double
        for(int i=0; i<length; i++){       		 //loop go through each name on the list
            for(int n= 0; n<Count; n++)        		// loop go through each name on unique name list
            {	
                if(listName[i] == uniName[n]){              //if the names are the same,
                    nameCount[n] = nameCount[n] + 1;        //add 1 to repeated count for that name
                    check = true;                           //set check to be true and stop searching
                    break;
                }
                else{
                    check = false;                          //set check to be false if it does not match
                }
            }
            if(check == false)          		//if check is still false after searching
            {
                uniName[Count] = listName[i];   	//set new position on array for new unique name
                Count = Count + 1;              	//update the length of unique name array
                nameCount[Count] = 1;           	//set repetition for that name to be 1
            }
            check = false;                     		 //set check to be false again for new loop
        }
        int getCount = 0;
        for(int i=0; i< Count; i++)        		 //this get the highest nameCount in the list
        {
            if (nameCount[getCount] < nameCount[i]){
                getCount = i;              		 //get the position of most repeated name on the array
            }
        }
        return uniName[getCount];         	  //return the name at the most repeated position
    }
	

	// return the number of baby records loaded from the text file
	int numberOfBirths() {
		return length;         			 // return the length of array
	}

	// return the number of babies who had birth weight < 2500 grams
	int numberOfBabiesWithLowBirthWeight() {
        	int underWeight = 0;                    		//store under weight baby count
       		for(int i =0; i<length; i++ )           		//loop through the list name
        	{
            		if(listWeight[i]<2500)             			 //compare the weight and update the count
                	underWeight = underWeight+1;
        	}
		return underWeight;                  	   //how many babies are under 2500 grams
	}

	// return the number of babies who have the name contained in string s
	int numberOfBabiesWithName(string s) {
        int numBabies = 0;                  			//store repeated name count
        	for(int i=0; i<length; i++)       			  //loop through the list name
       		{
            		if(s == listName[i])           			 //compare the name and update the count
               		 numBabies = numBabies+1;
        	}
        	return numBabies;                  		 //return the count
	}

private:
    string* uniName = new string[1000]; 		//array store unique name with length of 1000
    int* nameCount = new int[1000];     		//array store how many time the name repeated
    int Count = 1;                      		//the length of unique name name count
    int length=0;                       		//the length of name in the list
    bool check;                        			 //use to check if unique name repeated in uniName array
    string* listName = new string[1000000]; 		//store the baby name copied from text file
    int* listWeight = new int [1000000];    		//store the baby weight from text file
	
    void addEntry(Baby b) {                 		//function use to add baby name and weight to new array by using Baby.h
        listName[length] = b.getName();    		 //call function getName and getWeight in Baby.h
        listWeight[length] = b.getWeight();
        length++;                           		//update the length when function being called
        
		// TO BE COMPLETED
	}

	// Add private member variables for your data structure along with any 
	// other variables required to implement the public member functions

};
