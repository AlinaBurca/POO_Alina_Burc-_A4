#include "Number.h"
#include<iostream>
#include<string>

using namespace std;

Number::Number() {

}

Number::Number( const char *numar, int b) {
	int i;
	value = new char[20];
	for ( i = 0; i <= strlen(numar) - 1; i++)
		value[i] = numar[i];
	value[i] = '\0';
  base = b;	

}
// copy consturcor
Number::Number( Number& other) {

	value = other.value;
	base = other.base;
}
//move consturctor
Number::Number(Number&& other) {
	value = other.value;
	base = other.base;
	other.value = nullptr;
	other.base = 0;
}
Number::~Number() {
	delete[] value;
	
}
void Number::SwitchBase(int newBase) {

	int power = 1;
	int nr = 0;
	for (int i = strlen(value) - 1; i >= 0; i--) {
		int digit = 0;
		if (value[i] >= '0' && value[i] <= '9')
			digit = value[i] - '0'; 
		else
			if (value[i] >= 'A' && value[i] <= 'F')
				digit = value[i] - 'A' + 10;
		nr += digit * power;
		power *= base;
	}

	value = new char[100];
	int i = 0, j;
	char copie;
	while (nr > 0)
	{
		int digit = nr % newBase;
		if (digit >= 0 && digit <= 9)
			value[i++] = digit + '0';
		else
			value[i++] = digit + 'A' - 10;
		nr = nr / newBase;

	}
	value[i] = '\0';
	for (j = 0; j < i / 2; j++)
	{
		copie = value[j];
		value[j] = value[i - j - 1];
		value[i - j - 1] = copie;
	}
	this->base = newBase;
}
	  

void Number::Print() {

	cout<<"Acesta este numarul: "<< this->value;
	cout<< " cu baza: " << this->base;
	cout << endl;
}

int Number::GetDigitsCount() {

	int count = 0;
	while (value[count] != 0)
		count++;
	return count;
}

int Number::GetBase() const {
	return this->base;
}

Number operator+(  const Number& n1, const Number& n2) {

	int b1 = n1.GetBase();
	int b2 = n2.GetBase();
	int b;
	char *nr =new char[20];
	if (b1 > b2)
		b = b1;
	else
		b = b2;
		
	int nr1=0, nr2=0, sum = 0;
	nr1 = n1.BazaZece();
	nr2 = n2.BazaZece();
	cout << nr1;
	cout << nr2;

		sum = nr1 + nr2;
		
		cout << endl;
		Number suma;
		suma.value = new char[20];
		int i = 0;
		while (sum > 0) {
			int digit = sum % b;
			if (digit >= 0 && digit <= 9)
				suma.value[i++] = digit + '0';
			else
				suma.value[i++] = digit + 'A' - 10;
			sum = sum / b;

		}
		suma.value[i]='\0';
		for (int j = 0; j < i / 2; j++)
		{
			int copie = suma.value[j];
			suma.value[j] = suma.value[i - j - 1];
			suma.value[i - j - 1] = copie;
		}
		suma.base = b;
		return suma;
}

	

Number operator-( const Number &n1, const Number& n2) {
	int b1 = n1.GetBase();
	int b2 = n2.GetBase();
	int b;
	char* nr = new char[20];
	if (b1 > b2)

		b = b1;
	else
		b = b2;

	int nr1 = 0, nr2 = 0, dif = 0;

	nr1 = n1.BazaZece();
	nr2 = n2.BazaZece();

	dif = nr1 - nr2;
	
	Number diff;
	diff.value = new char[20];
	int i = 0;
	while (dif > 0) {
		int digit = dif % b;
		if (digit >= 0 && digit <= 9)
			diff.value[i++] = digit + '0';
		else
			diff.value[++i] = digit + 'A' - 10;
		dif = dif / b;

	}
	diff.value[i] = '\0';
	for (int j = 0; j < i / 2; j++)
	{
		int copie = diff.value[j];
		diff.value[j] = diff.value[i - j - 1];
		diff.value[i - j - 1] = copie;
	}
	
	diff.base = b;
	return diff;
}
Number& Number::operator+=(Number& n) {
	*this = *this + n;
	return *this;
}
Number& Number::operator-=(Number& n) {
	*this = *this - n;
	return *this;
}
   

Number& Number::operator=(Number&& n) { //move assigment
	 

	if (this != &n) {
		int length = strlen(n.value);
		delete[] value;
		this->value = new char[length + 1];
		this->value[length] = '\0';
		for (int i = 0; i < length; i++) {
			this->value[i] = n.value[i];
		}
		this->base = n.base;
		
	}
	return *this;

}

Number& Number::operator=(int numar)
{
	int i = 0;
	delete[] value;
	this->value = new char[100];
	this->base = 10;
	while (numar > 0)
	{
		int digit = numar % base;
		if (digit >= 0 && digit <= 9)
			value[i++] = digit + '0';
		else
			value[i++] = digit + 'A' - 10;
		numar = numar / base;
	}
	value[i] = '\0';
	int j;
	for (j = 0; j < i / 2; j++)
	{
		int copie = value[j];
		value[j] = value[i - j - 1];
		value[i - j - 1] = copie;
	}

	return (*this);
}

Number& Number::operator=(const char* numar)
{
	int i = 0;
	delete[] value;
	this->value = new char[100];
	int l = strlen(numar);
	for (i = 0; i < l; i++)
	{
		value[i] = numar[i];
	}
	this->value[i] = '\0';
	char maxx;
	maxx = 0;
	for (i = 0; i <= l-1; i++)
	
		if (numar[i] > maxx) maxx = numar[i];
	

	if (maxx <= '1' && maxx <= '9')
		this->base = maxx - '0' + 1;
	else
		this->base = maxx - 'A' + 10 + 1;


	return(*this);
}

bool Number::operator<(const Number& n) {
	
	
	int nr1 = 0, nr2 = 0, l1, l2;
	l1 = strlen(value);
	l2 = strlen(n.value);
	int power = 1;

	for (int i = l1 - 1; i >= 0; i--) {
		int digit = 0;
		if (value[i] >= '0' && value[i] <= '9')
			digit = value[i] - '0'; 
		else
			if (value[i] >= 'A' && value[i] <= 'F')
				digit = value[i] - 'A' + 10;
		nr1 += digit * power;
		power *= base;
	}
	power = 1;
	for (int i = l2 - 1; i >= 0; i--) {
		int digit = 0;
		if (n.value[i] >= '0' && n.value[i] <= '9')
			digit = n.value[i] - '0'; 
		else
			if (n.value[i] >= 'A' && n.value[i] <= 'F')
				digit = n.value[i] - 'A' + 10;
		nr2 += digit * power;
		power *= n.base;
	}
	if (nr1 < nr2) return true;
	return false;

}
bool Number::operator>(const Number& n) {


	int nr1 = 0, nr2 = 0, l1, l2;
	l1 = strlen(value);
	l2 = strlen(n.value);
	int power = 1;

	for (int i = l1 - 1; i >= 0; i--) {
		int digit = 0;
		if (value[i] >= '0' && value[i] <= '9')
			digit = value[i] - '0'; 
		else
			if (value[i] >= 'A' && value[i] <= 'F')
				digit = value[i] - 'A' + 10;
		nr1 += digit * power;
		power *= base;
	}
	power = 1;
	for (int i = l2 - 1; i >= 0; i--) {
		int digit = 0;
		if (n.value[i] >= '0' && n.value[i] <= '9')
			digit = n.value[i] - '0'; 
		else
			if (n.value[i] >= 'A' && n.value[i] <= 'F')
				digit = n.value[i] - 'A' + 10;
		nr2 += digit * power;
		power *= n.base;
	}

	if (nr1 < nr2) return true;
	return false;
	
	
}

bool Number::operator<=(const Number& n) {
	int nr1 = 0, nr2 = 0, l1, l2;
	l1 = strlen(value);
	l2 = strlen(n.value);
	int power = 1;

	for (int i = l1 - 1; i >= 0; i--) {
		int digit = 0;
		if (value[i] >= '0' && value[i] <= '9')
			digit = value[i] - '0'; 
		else
			if (value[i] >= 'A' && value[i] <= 'F')
				digit = value[i] - 'A' + 10;
		nr1 += digit * power;
		power *= base;
	}
	power = 1;
	for (int i = l2 - 1; i >= 0; i--) {
		int digit = 0;
		if (n.value[i] >= '0' && n.value[i] <= '9')
			digit = n.value[i] - '0';
		else
			if (n.value[i] >= 'A' && n.value[i] <= 'F')
				digit = n.value[i] - 'A' + 10;
		nr2 += digit * power;
		power *= n.base;
	}


	if (nr1 <= nr2)
		return true;
	return false;

}
bool Number::operator>=(const Number& n) {
	int nr1 = 0, nr2 = 0, l1, l2;
	l1 = strlen(value);
	l2 = strlen(n.value);
	int power = 1;

	for (int i = l1 - 1; i >= 0; i--) {
		int digit = 0;
		if (value[i] >= '0' && value[i] <= '9')
			digit = value[i] - '0'; 
		else
			if (value[i] >= 'A' && value[i] <= 'F')
				digit = value[i] - 'A' + 10;
		nr1 += digit * power;
		power *= base;
	}
	power = 1;
	for (int i = l2 - 1; i >= 0; i--) {
		int digit = 0;
		if (n.value[i] >= '0' && n.value[i] <= '9')
			digit = n.value[i] - '0'; 
		else
			if (n.value[i] >= 'A' && n.value[i] <= 'F')
				digit = n.value[i] - 'A' + 10;
		nr2 += digit * power;
		power *= n.base;
	}
	
	if (nr1 >= nr2)
		return true;
	return false;

}
bool Number::operator==(const Number& n) {

	int nr1 = 0, nr2 = 0, l1, l2;
	l1 = strlen(value);
	l2 = strlen(n.value);
	int power = 1;

	for (int i = l1 - 1; i >= 0; i--) {
		int digit = 0;
		if (value[i] >= '0' && value[i] <= '9')
			digit = value[i] - '0'; 
		else
			if (value[i] >= 'A' && value[i] <= 'F')
				digit = value[i] - 'A' + 10;
		nr1 += digit * power;
		power *= base;
	}
	power = 1;
	for (int i = l2 - 1; i >= 0; i--) {
		int digit = 0;
		if (n.value[i] >= '0' && n.value[i] <= '9')
			digit = n.value[i] - '0'; 
		else
			if (n.value[i] >= 'A' && n.value[i] <= 'F')
				digit = n.value[i] - 'A' + 10;
		nr2 += digit * power;
		power *= n.base;
	}
	if (nr1 < nr2) return true;
	return false;

}
bool Number::operator!=(const Number& n) {
	int nr1 = 0, nr2 = 0, l1, l2;
	l1 = strlen(value);
	l2 = strlen(n.value);
	int power = 1;

	for (int i = l1 - 1; i >= 0; i--) {
		int digit = 0;
		if (value[i] >= '0' && value[i] <= '9')
			digit = value[i] - '0'; 
		else
			if (value[i] >= 'A' && value[i] <= 'F')
				digit = value[i] - 'A' + 10;
		nr1 += digit * power;
		power *= base;
	}
	power = 1;
	for (int i = l2 - 1; i >= 0; i--) {
		int digit = 0;
		if (n.value[i] >= '0' && n.value[i] <= '9')
			digit = n.value[i] - '0'; 
		else
			if (n.value[i] >= 'A' && n.value[i] <= 'F')
				digit = n.value[i] - 'A' + 10;
		nr2 += digit * power;
		power *= n.base;
	}


	if (nr1 != nr2)
		return true;
	return false;
}

char Number::operator[](int index) {

	if (index >= 0 && index <= strlen(this->value))
		return value[index];

}

Number& Number::operator--() {

	int k = 0;
	int l = strlen(value);
	for (int i = 1; i <= l - 1; i++)
	{
		value[k] = value[i];
		k++;
	}
	value[l - 1] = NULL;
	return (*this);
}
Number& Number::operator--(int nr) {

	value[strlen(value) - 1] = NULL;
	return (*this);
}

int Number::BazaZece() const
{
	int nr = 0;
	int l = strlen(value);
	int power = 1;

	for (int i = l - 1; i >= 0; i--) {
		int digit = 0;
		if (value[i] >= '0' && value[i] <= '9')
			digit = value[i] - '0'; 
		else
			if (value[i] >= 'A' && value[i] <= 'F')
				digit = value[i] - 'A' + 10;
		nr += digit * power;
		power *= base;
	
	}
	return nr;
}