#include "pch.h"
#include <iostream>

using namespace std;

class ComplexNum
{
	double real, imag;
public:
	double var;
	ComplexNum();
	ComplexNum(double real, double imag);
	~ComplexNum();
	//double GetComplexReal();
	//double GetComplexImag();
	void print_complex();
	ComplexNum operator + (ComplexNum & copy);
	ComplexNum operator - (ComplexNum & copy);
	ComplexNum operator * (ComplexNum & copy);
	ComplexNum operator / (ComplexNum & copy);
};

ComplexNum::ComplexNum()
{
	cout << "Введите действительное число: ";
	cin >> real;
	cout << "Введите мнимое число: ";
	cin >> imag;
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

ComplexNum ComplexNum::operator+(ComplexNum & copy)
{
	return ComplexNum(real + copy.real, imag + copy.imag);
}

ComplexNum ComplexNum::operator - (ComplexNum & copy)
{
	return ComplexNum(real - copy.real, imag - copy.imag);
}

ComplexNum ComplexNum::operator* (ComplexNum & copy)
{
	return ComplexNum(real * copy.real - imag * copy.imag, imag * copy.real + real * copy.imag);
}

ComplexNum ComplexNum::operator / (ComplexNum & copy)
{
	double znam = copy.real * copy.real + copy.imag * copy.imag;
	return ComplexNum((real * copy.real + imag * copy.imag) / znam, (copy.real * imag - real * copy.imag) / znam);
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

	ComplexNum sum(0,0);
	sum = numberZ1 + numberZ2;
	cout << "Сумма комплексных чисел: Z1 + Z2 = ";
	sum.print_complex();

	cout << "\n";
	
	ComplexNum razn(0,0);
	razn = numberZ1 - numberZ2;
	cout << "Разность комплексных чисел: Z1 - Z2 = ";
	razn.print_complex();

	cout << "\n";

	ComplexNum proizv(0,0);
	proizv = numberZ1 * numberZ2;
	cout << "Произведение комплексных чисел: Z1 * Z2 = ";
	proizv.print_complex();

	cout << "\n";

	ComplexNum del(0, 0);
	del = numberZ1 / numberZ2;
	cout << "Деление комплексных чисел: Z1 / Z2 = ";
	del.print_complex();

	cout << "\n";

	system("pause");
	return 0;
}