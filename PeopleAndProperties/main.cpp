#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include "Person.h"
#include "Properties.h"

using namespace std;

//----------START OF EXECUTION----------
int main()
{
	int choice;
	vector<Person> people;
	vector<Properties> allProperties;
	ofstream file;
	do{
		cout << "\n\tMENU\n\n1. Register user\n2. Show all users\n3. Enter properties per user (EGN required)\n";
		cout << "4. Show all users with their properties\n5. Write users and their properties info to file\n";
		cout << "6. Show users with matching address and property\n7. Show person's properties (EGN required)\nYour choice:";
		cin >> choice;
		switch (choice){
		case 1:
			people.push_back(Person::userNewRegistration());
			break;
		case 2:
			Person::showAllRegisteredUsers(people);
			break;
		case 3:
			Person::enterPropertiesPerUserByEGN(people, allProperties);
			break;
		case 4:
			Properties::showAllPropertiesAndTheirOwners(allProperties);
			break;
		case 5:
			Properties::writeInfoToFile(file, allProperties);
			break;
		case 6:
			Properties::showUsersWithMatchingAddressAndProperty(allProperties);
			break;
		case 7:
			Properties::showPersonsPropertiesByEGN(allProperties);
			break;
		default:
			cout << "Invalid choice! Try again" << endl;
			break;
		}
	} while (true);
	return 0;
}


