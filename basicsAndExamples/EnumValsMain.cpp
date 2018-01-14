/*************************************************************************
*
*************************************************************************/
#include <iostream>
#include "EnumValsHousePaint.hpp"
using std::cin;
using std::cout;
using std::endl;

int main()
{
	HousePaint hp(cobalt, ivory);
	if (hp.getTrim() == ivory)
		std::cout << "trim is ivory" << std::endl;
	if (hp.getSiding() == cobalt)
		std::cout << "siding is cobalt" << std::endl;

	cin.get();
	return 0;
}