#include <clocale>
#include <iostream>

using namespace std;

int NOD(int a, int b)
{
	if (b == 0)
	{
		return a;
	}
	return NOD(b, a % b);
}

int preobrazovanie1(double x)
{
	int cel = (int)x;
	double drob = x - cel;

	int Xzn = 0;
	double temp = drob;
	while (temp > 0.0)
	{
		temp *= 10;
		Xzn++;
		if (temp - (int)temp == 0)
		{
			break;
		}
		if (Xzn > 10)
		{
			cout << "Слишком много знаков после запятой" << endl;
			return 1;
		}
	}
	int numerator = (int)(drob * pow(10, Xzn));
	int denominator = (int)pow(10, Xzn);

	int sokr = NOD(numerator, denominator);
	numerator /= sokr;
	denominator /= sokr;
	if (cel == 0)
	{
		cout << "Обыкновенная дробь: " << numerator << "/" << denominator << endl;
	}
	else
	{
		cout << "Обыкновенная дробь: " << cel * denominator + numerator << "/" << denominator << endl;
	}
}

double preobrazovanie1(double a, double b)
{
	double z = a / b;
	cout << z;
	return 0.0;
}

int main()
{
	setlocale(LC_ALL, "Ru");
	int opr;
	cout << "Какой вид преобразования вы хотите использовать?" << endl;
	cout << "Для преобразования десятичной дроби в обыкновенную введите '1'" << endl;
	cout << "Для преобразования обыкновенной дроби в десятичную введите '2'" << endl;
	cin >> opr;
	if (opr == 1)
	{
		double x;
		cout << "Введите десятичную дробь: ";
		cin >> x;
		preobrazovanie1(x);
	}
	if (opr == 2)
	{
		double a;
		double b;
		cout << "Введите числитель: " << endl;
		cin >> a;
		cout << "Введите знаменатель: " << endl;
		cin >> b;
		preobrazovanie1(a, b);
	}
	return 0;
}