#pragma once
#include <string>
#include <iostream>
using namespace std;
class DateTime
{
public:
	DateTime(int year = 0, int month = 0, int day = 0, int hour = 0, int minute = 0, int second = 0);
	DateTime(const DateTime& dt);
	DateTime& operator=(const DateTime& dt);
	~DateTime();
	void setYear(int year);
	void setMonth(int month);
	void setDay(int day);
	void setHour(int hour);
	void setMinute(int minute);
	void setSecond(int second);
	int getYear() const;
	int getMonth() const;
	int getDay() const;
	int getHour() const;
	int getMinute() const;
	int getSecond() const;
	bool operator==(const DateTime& dt) const;
	bool operator!=(const DateTime& dt) const;
	bool operator>(const DateTime& dt) const;
	bool operator<(const DateTime& dt) const;
	bool operator>=(const DateTime& dt) const;
	bool operator<=(const DateTime& dt) const;
	DateTime operator-(const DateTime& dt) const;
	DateTime operator+(const DateTime& dt) const;
	string toString() const;
	int ToMinutes() const;

	static void EnterDateTime(DateTime& dt);

	friend ostream& operator<<(ostream& os, const DateTime& dt) {
		os << dt.toString();
		return os;
	}

private:
	int year;
	int month;
	int day;
	int hour;
	int minute;
	int second;
};

DateTime::DateTime(int year, int month, int day, int hour, int minute, int second)
{
	setYear(year);
	setMonth(month);
	setDay(day);
	setHour(hour);
	setMinute(minute);
	setSecond(second);
}

DateTime::DateTime(const DateTime& dt)
{
	setYear(dt.getYear());
	setMonth(dt.getMonth());
	setDay(dt.getDay());
	setHour(dt.getHour());
	setMinute(dt.getMinute());
	setSecond(dt.getSecond());

}

DateTime& DateTime::operator=(const DateTime& dt)
{
	setYear(dt.getYear());
	setMonth(dt.getMonth());
	setDay(dt.getDay());
	setHour(dt.getHour());
	setMinute(dt.getMinute());
	setSecond(dt.getSecond());
	return *this;
}

DateTime::~DateTime()
{
}

void DateTime::setYear(int year)
{
	this->year = year;
}

int DateTime::getYear() const
{
	return year;
}

void DateTime::setMonth(int month)
{
	this->month = month;
}

int DateTime::getMonth() const
{
	return month;
}

void DateTime::setDay(int day)
{
	this->day = day;
}

int DateTime::getDay() const
{
	return day;
}

void DateTime::setHour(int hour)
{
	this->hour = hour;
}

int DateTime::getHour() const
{
	return hour;
}

void DateTime::setMinute(int minute)
{
	this->minute = minute;
}

int DateTime::getMinute() const
{
	return minute;
}

void DateTime::setSecond(int second)
{
	this->second = second;
}

int DateTime::getSecond() const
{
	return second;
}

bool DateTime::operator==(const DateTime& dt) const
{
	return year == dt.year && month == dt.month && day == dt.day && hour == dt.hour && minute == dt.minute && second == dt.second;
}

bool DateTime::operator!=(const DateTime& dt) const
{
	return !(*this == dt);
}

bool DateTime::operator>(const DateTime& dt) const
{
	return (year > dt.year) 
		|| (year == dt.year && month > dt.month) 
		|| (year == dt.year && month == dt.month && day > dt.day) 
		|| (year == dt.year && month == dt.month && day == dt.day && hour > dt.hour) 
		|| (year == dt.year && month == dt.month && day == dt.day && hour == dt.hour && minute > dt.minute) 
		|| (year == dt.year && month == dt.month && day == dt.day && hour == dt.hour && minute == dt.minute && second > dt.second);
}

bool DateTime::operator<(const DateTime& dt) const
{
	return !(*this > dt || *this == dt);
}

bool DateTime::operator>=(const DateTime& dt) const
{
	return !(*this < dt);
}

bool DateTime::operator<=(const DateTime& dt) const
{
	return !(*this > dt);
}

DateTime DateTime::operator-(const DateTime& dt) const
{
	int year = this->year - dt.year;
	int month = this->month - dt.month;
	int day = this->day - dt.day;
	int hour = this->hour - dt.hour;
	int minute = this->minute - dt.minute;
	int second = this->second - dt.second;
	return DateTime(year, month, day, hour, minute, second);
}

DateTime DateTime::operator+(const DateTime& dt) const
{
	int second = this->second + dt.second;
	int carry = second / 60;
	second %= 60;
	int minute = this->minute + dt.minute + carry;
	carry = minute / 60;
	minute %= 60;
	int hour = this->hour + dt.hour + carry;
	carry = hour / 24;
	hour %= 24;
	int day = this->day + dt.day + carry;
	carry = day / 30;
	day %= 30;
	int month = this->month + dt.month + carry;
	carry = month / 12;
	month %= 12;
	int year = this->year + dt.year + carry;
	return DateTime(year, month, day, hour, minute, second);

}

string DateTime::toString() const
{
	string repr = "";
	repr += to_string(year) + "-";
	repr += to_string(month) + "-";
	repr += to_string(day) + " ";
	repr += to_string(hour) + ":";
	repr += to_string(minute) + ":";
	repr += to_string(second);
	return repr;
}

int DateTime::ToMinutes() const
{
	return year * 365 * 24 * 60 + month * 30 * 24 * 60 + day * 24 * 60 + hour * 60 + minute;
}

void DateTime::EnterDateTime(DateTime& dt)
{
	int year, month, day, hour, minute, second;
	cout << "Enter year: ";
	cin >> year;
	cout << "Enter month: ";
	cin >> month;
	cout << "Enter day: ";
	cin >> day;
	cout << "Enter hour: ";
	cin >> hour;
	cout << "Enter minute: ";
	cin >> minute;
	cout << "Enter second: ";
	cin >> second;
	dt = DateTime(year, month, day, hour, minute, second);
}
