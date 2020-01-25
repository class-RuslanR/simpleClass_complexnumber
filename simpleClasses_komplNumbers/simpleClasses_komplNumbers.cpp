#include "pch.h"
#include <iostream>
#include <math.h>

using namespace std;

class ComplexNum
{
	double real, imag;
public:
	ComplexNum();
	ComplexNum(double real);
	ComplexNum(double real, double imag);
	~ComplexNum();
	//double GetComplexReal();
	//double GetComplexImag();
	void print_complex();
	ComplexNum operator + (ComplexNum & temp);
};

ComplexNum::ComplexNum()
{
	cout << "Введите действительное число: ";
	cin >> real;
	cout << "Введите мнимое число: ";
	cin >> imag;
};

ComplexNum::ComplexNum(double real)
{
	this->real = real;
	imag = 0;
}

ComplexNum::ComplexNum(double real, double imag)
{
	this->real = real;
	this->imag = imag;
}

ComplexNum::~ComplexNum()
{

}

/*double ComplexNum::GetComplexReal()
{
	cout << "Введите действительное число: ";
	cin >> real;
	return real;
}

double ComplexNum::GetComplexImag()
{
	cout << "Введите мнимое число: ";
	cin >> imag;
	return imag;
}*/

void ComplexNum::print_complex()
{
	if (imag <= 0)
	{
		cout << real << imag<< "i\n";
	}
	else
	{
		cout << real << "+" << imag << "i\n";
	}
}

ComplexNum ComplexNum::operator+(ComplexNum & temp)
{
	temp.real = real + temp.real;
	temp.imag = imag + temp.imag;
	return temp;
}

int main()
{
	setlocale(LC_ALL, "ru");

	ComplexNum numberZ1, numberZ2;
	//numberZ1.GetComplexReal();
	//numberZ1.GetComplexImag();
	numberZ1.print_complex();

	//numberZ2.GetComplexReal();
	//numberZ2.GetComplexImag();
	numberZ2.print_complex();

	ComplexNum numberZ3(0, 0);
	numberZ3 = numberZ1 + numberZ2;
	cout << "Сумма комплексных чисел: Z1 + Z2 = ";
	numberZ3.print_complex();
	



	system("pause");
	return 0;
}