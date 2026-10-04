#include <iostream>
#include "mystring.h"
using namespace std;

int main()
{
    MyString s("hello world");

    cout << "s = [" << s.c_str() << "]" << endl;

    size_t pos1 = s.find('e');
    cout << "find('e') = " << pos1 << endl;

    size_t pos2 = s.find('l');
    cout << "find('l') = " << pos2 << endl;

    size_t pos3 = s.find('l', 4);
    cout << "find('l', 4) = " << pos3 << endl;

    size_t pos4 = s.find('z');
    if (pos4 == MyString::npos)
    {
        cout << "find('z') = npos" << endl;
    }

    size_t pos5 = s.find("world");
    cout << "find(\"world\") = " << pos5 << endl;

    size_t pos6 = s.find("abc");
    if (pos6 == MyString::npos)
    {
        cout << "find(\"abc\") = npos" << endl;
    }

    size_t pos7 = s.find("", s.size());
    cout << "find(\"\", s.size()) = " << pos7 << endl;

    s.clear();
    cout << "after clear: [" << s.c_str() << "]"
        << " size=" << s.size()
        << " cap=" << s.capacity() << endl;

    return 0;
}