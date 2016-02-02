#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>
#include <vector>
class Properties;
using namespace std;

class Person{
	string firstName, secondName, lastName, egn, address;
	static int id;
	int objId;
public:
	//Setters declaration
	void setFirstName(string first);
	void setSecondName(string second);
	void setLastName(string last);
	void setEgn(string egnumber);
	void setAddress(string addr);

	//Getters declaration
	string getFirstName();
	string getSecondName();
	string getLastName();
	string getEgn();
	string getAddress();

	//Overloading '<<' operator
	friend ostream &operator<<(ostream &output,
		Person &person)
	{
		output << endl;
		output << "First name: " << person.getFirstName() << endl;
		output << "Second name: " << person.getSecondName() << endl;
		output << "Last name: " << person.getLastName() << endl;
		output << "EGN: " << person.getEgn() << endl;
		output << "Address: " << person.getAddress() << endl;
		output << "--------------------------";
		output << endl;
		return output;
	}

	//Class Member Functions
	void showInfo();
	static void showAllRegisteredUsers(vector<Person> &people);
	static Person userNewRegistration();
	static bool userExists(string egn, vector<Person> &people);
	static Person getUserByEGN(string egn, vector<Person> &people);
	static void enterPropertiesPerUserByEGN(vector<Person> &allPpl, vector<Properties> &allProps);

	//Constructors declaration
	Person();
	Person(string first, string second, string third, string egn, string address);

	//Destructor
	~Person();

};

//Global Function for the class
bool nameValidator(string name);

#endif // PERSON_H
