#include "Person.h"
#include "Properties.h"
#include <iostream>
#include <string>

using namespace std;

//Setters definition
void Person::setFirstName(string first){
	if (nameValidator(first))
		firstName = first;
	else {
		cout << "Invalid first name parameter! \nDefault value will be set. You can change it later." << endl;
		firstName = "Not specified";
	}
}

void Person::setSecondName(string second){
	if (nameValidator(second))
		secondName = second;
	else {
		cout << "Invalid second name parameter! \nDefault value will be set. You can change it later." << endl;
		secondName = "Not specified";
	}
}

void Person::setLastName(string last){
	if (nameValidator(last)){
		lastName = last;
	}
	else{
		cout << "Invalid last name parameter! \nDefault value will be set. You can change it later." << endl;
		lastName = "Not specified";
	}
}

void Person::setEgn(string egnumber){
	egn = egnumber;
}

void Person::setAddress(string addr){
	address = addr;
}

//Getters definition
string Person::getFirstName(){
	return firstName;
}

string Person::getSecondName(){
	return secondName;
}

string Person::getLastName(){
	return lastName;
}

string Person::getEgn(){
	return egn;
}

string Person::getAddress(){
	return address;
}

//Basic Member Functions
void Person::showInfo(){
	cout << endl;
	cout << "First name: " << getFirstName() << endl;
	cout << "Second name: " << getSecondName() << endl;
	cout << "Last name: " << getLastName() << endl;
	cout << "EGN: " << getEgn() << endl;
	cout << "Address: " << getAddress() << endl;
	cout << endl;
}

void Person::showAllRegisteredUsers(vector<Person> &people){
	cout << "\nList of registered users:\n";
	vector<Person>::iterator it;
	for (it = people.begin(); it != people.end(); ++it) {
		cout << *it;
	}
}

Person Person::userNewRegistration(){
	string firstName;
	string secondName;
	string lastName;
	string address;
	string egn;

	cin.ignore();

	cout << "\nYou choose to register a new user:\nEnter first name: ";
	getline(cin, firstName);
	cout << "Enter second name: ";
	getline(cin, secondName);
	cout << "Enter last name: ";
	getline(cin, lastName);
	cout << "Enter address: ";
	getline(cin, address);
	cout << "Enter EGN: ";
	getline(cin, egn);

	Person *person = new Person(firstName, secondName, lastName, egn, address);

	cout << "User registered successfully!\n" << endl;

	return *person;
}

bool Person::userExists(string egn, vector<Person> &people){
	if (!egn.empty()){
		vector<Person>::iterator itterate;
		for (itterate = people.begin(); itterate != people.end(); ++itterate) {
			if ((itterate->getEgn().compare(egn)) == 0){
				return 1;
			}
		}
	}
	return 0;
}

Person Person::getUserByEGN(string egn, vector<Person> &people){
	if (!egn.empty()){
		for (unsigned i = 0; i<people.size(); i++){
			if ((people.at(i).getEgn().compare(egn)) == 0){
				return people.at(i);
			}
		}
	}
	Person defaultP;
	return defaultP;
}

void Person::enterPropertiesPerUserByEGN(vector<Person> &allPpl, vector<Properties> &allProps){

	cout << "You choose to register some properties (5 max).\nEnter the EGN of the owner:";
	string egn;
	cin >> egn;

	if (Person::userExists(egn, allPpl)){
		Properties properties;//Creating property
		properties.setOwner(Person::getUserByEGN(egn, allPpl));//setting owner
		cout << "The user has been found.\nHis details are:\n";
		properties.getOwner().showInfo();
		int numOfCurrProps = 0;
		string property;
		char *propertyInfo;
		while (numOfCurrProps < MAX_PROPERTIES){

			cout << "Enter " << numOfCurrProps + 1 << " property ('EXIT' if u wanna stop entering) : ";

			if (cin.peek() == '\n')
				cin.ignore();
			getline(cin, property);

			if (property.compare("EXIT") == 0) break;

			propertyInfo = new char[property.size() + 1];
			copy(property.begin(), property.end(), propertyInfo);
			propertyInfo[property.size()] = '\0';
			properties.addPropertyAtIndex(propertyInfo, numOfCurrProps);
			numOfCurrProps++;
		}
		allProps.push_back(properties);
	}
	else{
		cout << "The user does not exists!" << endl;
	}
}

//Constructors definition
Person::Person(){

	setFirstName("Not specified");
	setSecondName("Not specified");
	setLastName("Not specified");
	setEgn("Not specified");
	setAddress("Not specified");
}

//Static variable initialization
int Person::id = 0;

Person::Person(string first, string second, string third, string egn, string address){
	setFirstName(first);
	setSecondName(second);
	setLastName(third);
	setEgn(egn);
	setAddress(address);
}

//Destructors definition
Person::~Person(){}

//Global Functions 
bool nameValidator(string name){
	if (name.empty() || (name.npos != name.find_first_of("0123456789"))) return 0;
	return 1;
}
