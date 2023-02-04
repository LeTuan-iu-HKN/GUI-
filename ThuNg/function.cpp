#include "function.h"

std::string convertDate(int date) {
	std::ostringstream str;
	str.fill('0');
	str.width(2);
	str << date % 100 << '/';

	str.width(2);
	str << (date / 100) % 100 << '/';

	str << date / 10000;

	return str.str();
}


