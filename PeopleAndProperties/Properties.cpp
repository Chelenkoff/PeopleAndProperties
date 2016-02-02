#include <iostream>
#include <fstream>
#include "Person.h"
#include "Properties.h"

using namespace std;

//Setters definition
void Properties::setOwner(Person p){
	owner = p;
}

//Getters definition
Person Properties::getOwner(){
	return owner;
}

char* Properties::getPropertiesAtIndex(int index){
	return propertiesArray[index];
}

//Constructors definition
Properties::Properties(){
	initializeProperties();
}

//Destructor definition
Properties::~Properties(){}




//Class function members
void Properties::initializeProperties(){
	for (int index = 0; index < MAX_PROPERTIES; index++){
		propertiesArray[index] = NULL;
	}
}

void Properties::addPropertyAtIndex(char *property, int index){
	propertiesArray[index] = property;
}



void Properties::showAllPropertiesAndTheirOwners(vector<Properties> &all){
	cout << "-----------PROPERTIES AND THEIR OWNERS----------";
	vector<Properties>::iterator it;
	for (it = all.begin(); it != all.end(); ++it) {
		// Iterating through all the Properties
		it->getOwner().showInfo();

		cout << "List of properties that " << it->getOwner().getFirstName() << " owns:\n";
		for (int i = 0; i < MAX_PROPERTIES; i++){
			if (it->getPropertiesAtIndex(i) == NULL) break;
			cout << it->getPropertiesAtIndex(i) << endl;
		}
		cout << "------------------------";
	}
}

void Properties::writeInfoToFile(ofstream &fileToWrite, vector<Properties> &all){
	string filename;
	cout << "Enter filename: ";
	cin >> filename;
	filename += ".txt";
	fileToWrite.open(filename);
	if (fileToWrite.is_open()){
		vector<Properties>::iterator it;
		for (it = all.begin(); it != all.end(); ++it) {
			// Iterating through all the Properties
			fileToWrite << endl;
			fileToWrite << "First name: " << it->getOwner().getFirstName() << endl;
			fileToWrite << "Second name: " << it->getOwner().getSecondName() << endl;
			fileToWrite << "Last name: " << it->getOwner().getLastName() << endl;
			fileToWrite << "EGN: " << it->getOwner().getEgn() << endl;
			fileToWrite << "Address: " << it->getOwner().getAddress() << endl;
			fileToWrite << endl;
			fileToWrite << "List of properties that " << it->getOwner().getFirstName() << " owns:\n";
			for (int i = 0; i < MAX_PROPERTIES; i++){
				if (it->getPropertiesAtIndex(i) == NULL) break;
				fileToWrite << it->getPropertiesAtIndex(i) << endl;
			}
			fileToWrite << "----------------------\n";
		}
		fileToWrite.close();
	}
	else cout << "Unable to open file";
}

void Properties::showUsersWithMatchingAddressAndProperty(vector<Properties> &all){
	vector<Properties>::iterator it;
	cout << "List of users whose address matches their property:" << endl;
	for (it = all.begin(); it != all.end(); ++it) {
		// Iterating through all the Properties
		for (int i = 0; i < MAX_PROPERTIES; i++){
			if (it->getPropertiesAtIndex(i) == NULL) break;
			if (it->getOwner().getAddress().compare(it->getPropertiesAtIndex(i)) == 0){
				it->getOwner().showInfo();
				break;
			}
		}
		cout << "------------------------";
	}
}

void Properties::showPersonsPropertiesByEGN(vector<Properties> &all){
	cout << "Insert EGN: ";
	string egn;
	cin >> egn;
	bool userExists = false;

	vector<Properties>::iterator it;
	for (it = all.begin(); it != all.end(); ++it) {
		// Iterating through all the Properties
		if (it->getOwner().getEgn().compare(egn) == 0){
			userExists = true;
			cout << "List of properties that " << it->getOwner().getFirstName() <<" "<<it->getOwner().getSecondName()<<" "<<it->getOwner().getLastName()<< " owns:\n";
			for (int i = 0; i < MAX_PROPERTIES; i++){
				if (it->getPropertiesAtIndex(i) == NULL) break;
				cout << it->getPropertiesAtIndex(i) << endl;
			}
			cout << "------------------------";
			break;
		}
	}
	if (userExists == false) cout << "User does not exist!" << endl;
}

