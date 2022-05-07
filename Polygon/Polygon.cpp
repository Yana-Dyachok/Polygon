/* Створити абстрактний клас “Багатокутник”. Клас повинен містити методи для обчислення периметра, знаходження площі і ін. 
Побудувати похідний клас “Трикутник” і прямокутник, що містить також методи для знаходження довжин медіан, висот трикутника, прямокутника*/
#include <iostream>
#include<math.h>
using namespace std;

class  Polygon{ //базовий клас
protected:
	virtual double getArea() = 0; // віртуальна функція
	virtual double getPerimetr() = 0;//віртуальна функція
};


class Triangle : public Polygon {
protected:
	double AB, BC, CA;// сторони трикутника
	double Median;//медіана трикутника
	double Height; //висота трикутника
	double p;//напівпериметр трикутника
	public:
	Triangle(int AB, int BC, int CA) {
		this->AB = AB;
		this->BC = BC;
		this->CA = CA;
	}


	double MedianT() {//метод знаходження медіани трикутника
		Median = (sqrt(2 * pow(AB, 2) + 2 * pow(BC, 2) + 2 * pow(CA, 2))) / 2;
		return Median;
	 }


	double HeightT() {//метод знаходження висоти трикутника
		p = (AB + BC + CA) / 2;
		Height = 2/AB* (sqrt(p * (p-AB)*(p-BC)*(p-CA)));
		return Height;
	}


	double getArea() override
	{	return (Height*AB)/2;
	}


	double getPerimetr() override
	{	return p*2;
	}


	~Triangle() {};
};


class Rectangle : public Polygon {
protected:
	double AB, BC;//сторони прямокутника
	double d;//діагональ прямокутника
public:
	Rectangle(int AB, int BC) {
		this->AB = AB;
		this->BC = BC;
	}


	double HeightR() {
		return AB;//висота прямокутника- одна із його сторін
	}


	double Diagonal() {//метод знаходження діагоналі прямокутника
		d = sqrt(pow(AB, 2) + pow(BC, 2));
		return d;
	}


	double getArea() override
	{
		return AB*BC;
	}


	double getPerimetr() override
	{
		return (AB+BC)*2;
	}


	~Rectangle() {};
};


int main()
{
	Rectangle B(4,5);
	Triangle A(3,4,5);
	cout << "Median of triangle=   " << A.MedianT()<<endl;
	cout << "Height of triangle=   " << A.HeightT()<< endl;
	cout << "Perimetr of triangle= " << A.getPerimetr()<< endl;
	cout << "Area of triangle=     " << A.getArea()<< endl;
	cout <<"Diagonal of rectangle= " << B.Diagonal()<< endl;
	cout << "Height of rectangle=  " << B.HeightR()<< endl;
	cout << "Perimetr of rectangle=" << B.getPerimetr()<< endl;
	cout << "Area of rectangle=    " << B.getArea() << endl;
}          