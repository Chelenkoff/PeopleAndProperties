#ifndef PROPERTIES_H
#define PROPERTIES_H
#include "Person.h"

using namespace std;

//Constant values
const int MAX_PROPERTIES = 5;

class Properties{
	Person owner;
	char** propertiesArray = new char*[MAX_PROPERTIES];

public:
	//Setters declaration
	void setOwner(Person p);

	//Getters declaration
	Person getOwner();
	char *getPropertiesAtIndex(int index);


		
	//Class Member functions
	void initializeProperties();
	void addPropertyAtIndex(char *property, int index);
	static void showAllPropertiesAndTheirOwners(vector<Properties> &all);
	static void writeInfoToFile(ofstream &fileToWrite, vector<Properties> &all);
	static void showUsersWithMatchingAddressAndProperty(vector<Properties> &all);
	static void showPersonsPropertiesByEGN(vector<Properties> &all);

	//Constructor declaration
	Properties();

	//Destructor
	~Properties();
};

#endif // PROPERTIES_H
