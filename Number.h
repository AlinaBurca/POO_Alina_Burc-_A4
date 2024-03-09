#pragma once
#include <stdio.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS
class Number
{
public:
	char *value;
	int base;

	// add data members
public:
	Number(); //default constructor
	Number( const char * numar, int b);
	Number( Number& other); // copy constructor
	Number(Number&& other);// move constructor
	~Number();
	
	friend Number operator+( const Number& n1,  const Number& n2);
	friend Number operator-(const Number& n1, const Number& n2);

	bool operator<(const Number& n);
	bool operator>(const Number& n);
	bool operator<=(const Number& n);
	bool operator>=(const Number& n);
	bool operator==(const Number& n);
	bool operator!=(const Number& n);

	char operator[](int index);
	Number& operator--();
	Number& operator--(int numar); 

	Number& operator=(Number&& n1); // move assingment operator
	Number& operator=(int numar);
	Number& operator=(const char* numar);
	Number& operator+=(Number& n);
	Number& operator-=(Number& n);


	void SwitchBase(int newBase);
	void Print();
	int GetDigitsCount();
	int GetBase() const; 
	int BazaZece() const;
};

