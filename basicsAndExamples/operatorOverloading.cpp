/**********************************************************
basics of overloading
returning const values
unary operators
member vs. friend
**********************************************************/
#include <iostream>
using namespace std;

class integer
{
private:
	int val;
public:
	// the next five functions are the ones you should always define
	integer(int value)
	{
		this->val = value;
	}

	integer()
	{
		this->val = 0;
	}

	integer& operator=(const integer &RHS)// return by reference
	{
		this->val = RHS.val;

		return *this;
	}
	integer(integer &value)
	{
		this->val = value.val;
	}
	
	~integer()
	{
		// intentionally left empty
	}

	int value()
	{
		return this->val;
	}
	
	int value() const	// this is an example of a function overload
	{
		return this->val;
	}

	void setValue(int value)
	{
		this->val = value;
	}

	// ++i is pre-increment
	integer& operator++()
	{
		++(this->val);

		return *this;	// we want to return this one
	}

	// i++ is post-increment
	integer& operator++(int ignored)
	{
		integer returned = integer(this->val);

		++(this->val);

		return returned;
	}

	friend const integer operator-(const integer&, const integer&);	// I can not define this here, simply a prototype

	// input/output is always overloaded as a friend
	// output streams are infinite, they have no end, so you can not make a copy of it
	friend ostream& operator<<(ostream &outs, const integer &foo);	// well put things in outs and return outs
	friend istream& operator>>(istream &in, integer &foo); // not const because we need to chang eit

	// when overlaoding as an operator:
	// integer b;
	// b.operator*(c);  this is equivalent, but not exact syntax
	// this is the way YOU SHOULD do this
	const integer operator*(const integer &RHS)
	{
		return integer(this->val * RHS.val);	//this takes the place of LHS
	}
};

ostream& operator<<(ostream &outs, const integer &foo)
{
	outs << foo.val;

	return outs;
}

istream& operator>>(istream &in, integer &foo)
{
	in >> foo.val;

	return in;
}

// friend function -- can access variables directly
const integer operator-(const integer &LHS, const integer &RHS) // have access to everything in class
{
	return integer(LHS.val - RHS.val);	// creates an anonymous object
}

// this has nothing to do with the integer class and has to use accessor's to use integer class
const integer operator+(const integer &LHS, const integer &RHS)
{
	return integer(LHS.value() + RHS.value());
}

int main()
{
	integer a(3);
	integer b(7);

	integer c = a + b;

	// this is what we have
	cout << "a: " << a.value() << "   b: " << b.value() << endl;

	// this is what we want
	// cout << "a: " << a << "   b: " << b << endl;

	cout << "c = " << c.value() << endl;
	cout << "c - a = " << (c - a).value() << endl;	// same as creating a forth integer and calling it
	cout << "c * a: " << (c * a).value() << endl;

	cin.get();
	return 0;
}