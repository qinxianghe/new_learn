//1.复现“传值导致递归”的编译错误
#include <iostream>
using namespace std;
class Date
{
public:
	Date(int year = 1990, int month = 1, int day = 1) {
		_year = year;
		_month = month;
		_day = day;
	}
	/*Date(Date a)
	{
		_year = a._year;
		_month = a._month;
		_day = a._day;
	}*/
	//上面这种是拷贝函数的经典错误，会导致无限调用拷贝函数
	Date(const Date& a)
	{
		_year = a._year;
		_month = a._month;
		_day = a._day;
		cout << "拷贝函数被调用了" << endl;
	}
	void Print() const {
		cout << _year << "-" << _month << "-" << _day << endl;
	}
	//上面这是第二题，你说的其他我没看懂
	Date& operator=(const Date& a)
	{
		if (this != &a) {
			_year = a._year;
			_month = a._month;
			_day = a._day;
		}
		return *this;
	}
private:
	int _year;
	int _month;
	int _day;
};

int main()
{
	return 0;
}