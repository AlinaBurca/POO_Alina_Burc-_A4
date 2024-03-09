#include "Number.h"
#include <iostream>
#include <string.h>
using namespace std;
int main()
{
	//Number n1("1011", 2);// n1=11;
	//Number n2("10", 10);
	//Number n3;
	//n3 = n1 + n2;
	//n3.Print();

	/*number n2("734", 8);

	number n3("ff", 16);

	n3.switchbase(10);
	n3.print();
	n1.print();
	n2.print();

	number n4;

	n4 = n1 + n2;
	n4.print();*/
	Number n1("10110010", 2);

	Number n2("734", 8);

	Number n3("ff", 16);


	printf("n1 has %d digits and it is written in base %d\n", n1.GetDigitsCount(), n1.GetBase());

	for (int tr = 0; tr < n1.GetDigitsCount(); tr++)

	{

		printf("n1[%d]=%c\n", tr, n1[tr]);

	}

	n1.Print();

	n2.Print();

	n1 = (n2 + n3) - n1; // after this n1 will be in base 16

	n1.SwitchBase(10);

	n1.Print();

	n2.SwitchBase(10);
	n2.Print();


	if (n1 > n2)
		cout << n1.value << " este mai mare decat " << n2.value;
	else
		cout << n2.value << " este mai mare decat " << n1.value;
	cout << endl;


	Number n4;
	n4 = 12345; // n4 will be in base 10

	n1 = 255; // n1 will be 11111111 (value 255 from base 10 in base 2)

	n4 += n1;

	n4.Print();


	n4 = "13579"; // n4 mentains its base (10) and will be 13579

	n4.Print();

	--n4; // the first digit from n4 will be remove ==> n4 becomes 3579

	n4.Print();

	n4--; // the last digit from n4 will be remove ==> n4 becomes 357

	n4.Print();

	Number n9("678", 16);
	Number n10("123", 10);

	(n9 + n10).Print();
	Number n11;
	n11 = n9 + n10;
	--n11--;
	n11.Print();

	return 0;
}



