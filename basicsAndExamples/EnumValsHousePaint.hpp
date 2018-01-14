/*************************************************************************
 This file defines the enum Color and declares the HousePaint class 
 interface. The two get methods return a value of type Color and the 
 constructor and set methods take parameters of type Color.
*************************************************************************/
#ifndef ENUMVALSHOUSEPAINT_HPP
#define ENUMVALSHOUSEPAINT_HPP

enum Color { maroon, ivory, sage, periwinkle, chartreuse, cobalt, lemon, lavender, orange };

class HousePaint
{
private:
	Color siding;
	Color trim;
public:
	HousePaint(Color sColor, Color tColor);
	void setSiding(Color sColor);
	void setTrim(Color tColor);
	Color getSiding();
	Color getTrim();
};

#endif