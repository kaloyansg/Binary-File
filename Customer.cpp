#include "Customer.h"
#pragma warning (disable:4996)

Customer::Customer()
{
	name = new char[5];
	strcpy(name, "Name");
	id = -1;
	age = 0;
}

Customer::Customer(char* name, int id, int age)
{
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
	this->id = id;
	this->age = age;
}

Customer::Customer(const Customer& other)
{
	name = new char[strlen(other.name) + 1];
	strcpy(name, other.name);
	id = other.id;
	age = other.age;
}

Customer& Customer::operator=(const Customer& other)
{
	if (this == &other)
		return *this;

	char* temp = new char[strlen(other.name) + 1];
	strcpy(temp, other.name);

	delete[]name;
	name = temp;
	id = other.id;
	age = other.age;

	return *this;
}

Customer::~Customer()
{
	delete[] name;
	name = nullptr;
}

void Customer::setName(const char* newName)
{
	char* temp = new char[strlen(newName) + 1];
	strcpy(temp, newName);
	delete[] name;
	name = temp;
}

void Customer::addName(const char* newName)
{
	char* temp = new char[strlen(newName) + 1];
	strcpy(temp, newName);
	name = temp;
}

void Customer::setId(int n)
{
	id = n;
}

void Customer::setAge(int n)
{
	age = n;
}

const char* Customer::getName() const
{
	return name;
}

std::ostream& operator<<(std::ostream& out, const Customer& cust)
{
	out << cust.name << " " << cust.id << " " << cust.age;
	return out;
}
