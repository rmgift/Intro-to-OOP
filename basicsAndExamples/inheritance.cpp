/***********************************************************
          shape				Base Class
	|             |
rectangle      triangle		Derived Class
    |
 square						Derived Class
***********************************************************/
#include <iostream>
#include <cmath>
using namespace std;

enum {NOCOLOR, PURPLE, RED, BLUE, GREEN, BLACK, CYAN, MAGENTA, YELLOW};

class shape
{
private:
	int side_Count;
	int color;
public:
	shape()
	{
		this->side_Count = -1;	// by default we should have an invalid shape
		this->color = NOCOLOR;
	}
	shape(int sides)
	{
		this->side_Count = sides;
	}
	double area()
	{
		if (side_Count == -1)
		{
			return -17;
		}
		else
		{
			return 14;
		}
	}
	double perimeter()
	{
		return 0;
	}
};

class triangle : public shape	// says class triangle inherits public shape
{
//private:
	//double side1;
	//double side2;
	//double side3;
protected:
	double side1;
	double side2;
	double side3;
public:
	triangle() : shape(3)		// means side count is three
	{
		this->side1 = 0;
		this->side2 = 0;
		this->side3 = 0;
	}
	triangle(double side1, double side2, double side3) : shape(3)
	{
		this->side1 = side1;
		this->side2 = side2;
		this->side3 = side3;
	}

	// use semi-perimeter area formula = sqrt(s(s-a)(s-b)(s-c))
	double area()
	{
		double s = this->perimeter() / 2;
		return sqrt(s * (s - this->side1) * (s - this->side2) * (s - this->side3));
	}

	double perimeter()		// use the same signature to redefine the one from the parent class
	{						// if you use different signatures then you're simply overloading
		return this->side1 + this->side2 + this->side3;
	}
};

class rectangle : public shape	// says class triangle inherits public shape
{
//private:
	//double side1;
	//double side2;
protected:
	double side1;
	double side2;
public:
	rectangle() : shape(4)		// means side count is three
	{
		this->side1 = 0;
		this->side2 = 0;
	}
	rectangle(double side1, double side2) : shape(4)
	{
		this->side1 = side1;
		this->side2 = side2;
	}

	double area()
	{
		return this->side1 * this->side2;
	}

	double perimeter()		// use the same signature to redefine the one from the parent class
	{						// if you use different signatures then you're simply overloading
		return this->side1 * 2 + this->side2 * 2;
	}
};

class square : public rectangle
{
private:
public:
	square() : rectangle()
	{
		this->side1 = 0;		// to access these, rectangle and shape must be made protected
		this->side2 = 0;		// these were not needed though because rectangle already created them
	}

	square(double side) : rectangle(side, side)
	{
		this->side1 = side;
		this->side2 = side;
	}

	square operator=(const square &RHS)
	{
		rectangle::operator=(RHS);
		// additional necessary stuff
	}

	// these next two functions return are not normal because their not doing anything different from rectangle 
	double area()
	{
		return rectangle::area();	// this allows us to directly call rectangles area function
	}

	double perimeter()
	{
		return rectangle::perimeter();
	}
};

int main()
{
	shape s;
	triangle t(5, 12, 13);
	rectangle r(8, 12.5);
	square q(10);

	cout << "Area of shape s: " << s.area() << endl;
	cout << "Perimeter of shape s: " << s.perimeter() << endl;

	cout << "Area of shape t: " << t.area() << endl;
	cout << "Perimeter of shape t: " << t.perimeter() << endl;

	cout << "Area of shape r: " << r.area() << endl;
	cout << "Perimeter of shape r: " << r.perimeter() << endl;

	cout << "Area of shape q: " << q.rectangle::area() << endl;		// this will also call rectangles area function
	cout << "Perimeter of shape q: " << q.perimeter() << endl;

	cin.get();
	return 0;
}