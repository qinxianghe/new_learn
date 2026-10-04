//以下是new02.cpp的内容
#include<iostream>
#include "new02.h"
#include <string>
namespace MyNamespace
{

	Counter::Counter(int v ) : value(v){}
	void Counter::inc() {
		++value;
	}
	int Counter::get() const {
		return value;
	}


}
using namespace std;
//第五题
struct S1 { char a; int b; short c; };
struct S2 { int b; short c; char a; };
int a;
string s;
union test
{
	int a;
	char b;
};
int main()
{
/*	new02::Counter c;
	c.get(); //0
	c.inc();*/
	cout << sizeof(S1) << alignof(S1) << offsetof(S1,a) <<endl;
	cout << sizeof(S1) << alignof(S1) << offsetof(S1, b) << endl;
	cout << sizeof(S1) << alignof(S1) << offsetof(S1, c) << endl;

	cout << sizeof(S2) << alignof(S2) << offsetof(S2, a) << endl;
	cout << sizeof(S2) << alignof(S2) << offsetof(S2, b) << endl;
	cout << sizeof(S2) << alignof(S2) << offsetof(S2, c) << endl;

	//结果是 
	//1240
	//1244
	//	1248
	//	846
	//	840
	//	844
	// 按道理来说，S2的内存布局使得它的大小应该是12字节，S1的内存布局使得它的大小应该是8字节，但实际结果却是S1占用16字节，S2占用12字节。这是因为编译器为了满足对齐要求，在S1中插入了3个字节的填充，使得b成员从偏移量4开始，而c成员从偏移量8开始。而在S2中，由于a成员在最后，所以没有填充，b成员从偏移量0开始，c成员从偏移量4开始。因此，S1的大小为16字节，而S2的大小为12字节。
	//但是打印的内容我不明白为什么是这样，还有就是alignof和offsetof我也不知道是什么

	//第六题
	//cin >> a;
	//getline(cin >> ws, s);

	//大小端
	test t;
	t.a = 1;
	char* p = (char*)&t.a;
	if (*p) {
		cout << "little" << endl;
	}
	else {
		cout << "big" << endl;
	}
	return 0;
}

