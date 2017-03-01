#pragma once
#include <string>

using namespace std;

// class that contains information related to a single birth or baby name
class Baby {
public:
	Baby() {  // default constructor
	};

	Baby(string s, int w) { // constructor
        	name = s;           //copy the name and weight
      		weight = w;
	}

	// a "getter" method
	int getWeight() {       //return the weight
		return weight;
	}

	// a "getter" method
	string getName() {
		return name;        //return the name
	}

private:
	string name;    //store the name
	int weight;     //store the weight
};
