/*************************************************************************
 This file includes "HousePaint.hpp", and thus has access to the enum
 Color type
*************************************************************************/
#include "EnumValsHousePaint.hpp"

HousePaint::HousePaint(Color sColor, Color tColor)
{
	setSiding(sColor);
	setTrim(tColor);
}

void HousePaint::setSiding(Color sColor)
{
	siding = sColor;
}

void HousePaint::setTrim(Color tColor)
{
	trim = tColor;
}

Color HousePaint::getSiding()
{
	return siding;
}

Color HousePaint::getTrim()
{
	return trim;
}