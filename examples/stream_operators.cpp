#include <iostream>
using namespace std;

class Date {
	friend ostream& operator<<(ostream& os, const Date& a);
	friend istream& operator>>(istream& is, Date& a);
public:
	Date(int year = 2026, int month = 1, int day = 1)
		:_year(year),
		_month(month),
		_day(day)
	{}
private:
	int _day;
	int _month;
	int _year;
};
ostream& operator<<(ostream& os, const Date& a)
{
	os << a._year << "-" << a._month << "-" << a._day;
	return os;
}
istream& operator>>(istream& is, Date& a)
{
	is >> a._year >> a._month >> a._day;
	return is;
}
int main()
{
	return 0;
}