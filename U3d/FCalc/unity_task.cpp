// unity_task.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

class fraction
{
public:
	int num, den;
	fraction() {};
	fraction(int n, int d)
	{
		if (0 == d) throw domain_error("Denominator cannot be 0.");
		num = n;
		den = d;
	}
};

fraction add(const fraction& f1, const fraction& f2);
fraction mul(const fraction& f1, const fraction& f2);
fraction sub(const fraction& f1, const fraction& f2);
fraction div(const fraction& f1, const fraction& f2);

int _tmain(int argc, _TCHAR* argv[])
{
	cout << "Input fractions x/y in format \"x y\": " << endl;
	int val1, val2;
	cin >> val1 >> val2;
try {
		fraction f1(val1, val2);

		cin >> val1 >> val2;
		fraction f2(val1, val2);
	
		cout << endl << "Select operation (+, -, *, /): " << endl;
		char oper;
		cin >> oper;
	
		fraction result;
		switch(oper)
		{
		case '+':
			result = add(f1, f2);
			break;
		case '-':
			result = sub(f1, f2);
			break;
		case '*':
			result = mul(f1, f2);
			break;
		case '/':
			result = div(f1, f2);
			break;
		default:
			throw domain_error("Invalid operation entred.");
		}
	
		cout << endl << "Result = " << result.num << "/" << result.den << endl;
	
	}
	catch (domain_error e) {cout << e.what(); return 1;}

	return 0;
}

fraction add(const fraction& f1, const fraction& f2)
{
	fraction ret;
	ret.den = f1.den * f2.den;
	ret.num = (f1.num * (ret.den / f1.den)) + (f2.num * (ret.den / f2.den));
	return ret;
}

fraction mul(const fraction& f1, const fraction& f2)
{
	return fraction(f1.num * f2.num, f1.den * f2.den);
}

fraction sub(const fraction& f1, const fraction& f2)
{
	fraction ret;
	ret.den = f1.den * f2.den;
	ret.num = (f1.num * (ret.den / f1.den)) - (f2.num * (ret.den / f2.den));
	return ret;
}

fraction div(const fraction& f1, const fraction& f2)
{
	return fraction(f1.num * f2.den, f2.num * f1.den);
}