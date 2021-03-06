#include "include/Date.h"

Date::Date()
{
	_day = 1;
	_month = 1;
	_year = 1;
}

Date::Date(int d, int m, int y)
{
	_day = d;
	_month = m;
	_year = y;
}

string Date::toString()
{
	stringstream builder;

	if (_day < 10)
		builder << "0";
	builder << _day << "/";
	if (_month < 10)
		builder << "0";
	builder << _month << "/" << _year;

	string result = builder.str();
	return result;
}

bool Date::checkLeapYear()
{
	return (((_year % 4 == 0) && (_year % 100 != 0)) || (_year % 400 == 0));
}

int Date::dateInMonth()
{
	int days = 0;

	switch (_month)
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		days = 31;
		break;
	case 4:
	case 6:
	case 9:
	case 11:
		days = 30;
		break;
	case 2:
		if (this->checkLeapYear())
		{
			days = 29;
		}
		else
		{
			days = 28;
		}
		break;
	}

	return days;
}

bool Date::isDate()
{
	if (_year < 0)
	{
		return false;
	}

	if (_month < 1 || _month > 12)
	{
		return false;
	}

	if (_day < 1 || _day > this->dateInMonth())
	{
		return false;
	}

	return true;
}

Date Date::parseDate(string str)
{
	auto date = String::split(str, "/");

	Date result;

	result.setDay(Number::tryParseInt(date[0]));
	result.setMonth(Number::tryParseInt(date[1]));
	result.setYear(Number::tryParseInt(date[2]));

	return result;
}

bool Date::operator==(const Date& other)
{
	return (_day == other._day && _month == other._month && _year == other._year);
}