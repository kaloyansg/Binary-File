#pragma once
#include <iostream>

class Customer
{
	char* name;
	int id;
	int age;

public:
	Customer();
	Customer(char*, int, int);
	Customer(const Customer&);
	Customer& operator=(const Customer&);
	~Customer();

	void setName(const char*);
	void addName(const char*);

	void setId(int);
	void setAge(int);

	const char* getName() const;

	friend std::ostream& operator<<(std::ostream&, const Customer&);
};