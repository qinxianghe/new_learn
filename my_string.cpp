#include "mystring.h"
const size_t MyString::npos = -1;
	MyString::MyString()
		:_size(0), _capacity(0) {
		_str = new char[1];
		_str[0] = '\0';
	}
	MyString::MyString(const char* str)
	{
		assert(str);
		_size = strlen(str);
		_capacity = _size;
		_str = new char[_capacity + 1];
		strcpy_s(_str,_capacity+1, str);
	}
	MyString::~MyString()
	{
		delete[] _str;
		_str = nullptr;
		_size = 0;
		_capacity = 0;
	}
	void MyString::swap( MyString& other)
	{
		std::swap(_str, other._str);
		std::swap(_size, other._size);
		std::swap(_capacity, other._capacity);
	}
	MyString::MyString(const MyString& str)
	{
		MyString temp(str._str);
		swap(temp);
	}
	size_t MyString::size() const
	{
		return _size;
	}
	size_t MyString::capacity() const
	{
		return _capacity;
	}
	bool  MyString::empty() const
	{
		return _size == 0;
	}
	const char* MyString::c_str() const
	{
		return _str;
	}
	MyString::iterator MyString::begin()
	{
		return _str;
	}
	MyString::iterator MyString::end()
	{
		return _str + _size;
	}
	MyString::const_iterator MyString::begin() const
	{
		return _str;
	}
	MyString::const_iterator MyString::end() const
	{
		return _str + _size;
	}
	void MyString::reserve(size_t n)
	{
		if (n > _capacity) {
			char* temp = new char[n + 1];
			strcpy_s(temp, n + 1, _str);
			delete[] _str;
			_str = temp;
			_capacity = n;
		}
	}
	void MyString::resize(size_t n, char ch )
	{
		if (n <= _size) {
			_str[n] = '\0';
			_size = n;
		}
		else {
			MyString::reserve(n);
			for (size_t i = _size; i < n; i++)
			{
				_str[i] = ch;
			}
			_str[n] = '\0';
			_size = n;
		}
	}
	char& MyString::operator[](size_t pos)
	{
		assert(pos < _size);
		return _str[pos];
	}
	const char& MyString::operator[](size_t pos) const
	{
		assert(pos < _size);
		return _str[pos];
	}
	void MyString::push_back(char ch)
	{
		if (_size == _capacity) {
			reserve(_capacity == 0 ? 4 : _capacity * 2);
		}
		_str[_size] = ch;
		_size++;
		_str[_size] = '\0';
	}
	void MyString::append(const char* str)
	{
		assert(str);
		size_t len = strlen(str);
		if ((_size + len) > _capacity){
			reserve(_size + len);
		}
		strcpy_s(_str + _size, _capacity - _size + 1, str);
		_size += len;
	}
	MyString& MyString::operator+=(char ch)
	{
		push_back(ch);
		return *this;
	}
	MyString& MyString::operator+=(const char* str)
	{
		append(str);
		return *this;
	}
	void MyString::clear()
	{
		_size = 0;
		_str[0] = '\0';
	}
	size_t MyString::find(char ch, size_t pos ) const
	{
		if (pos >= _size) {
			return npos;
		}
		for (size_t i = pos; i < _size; i++) {
			if (_str[i] == ch) {
				return i;
			}
		}
		return npos;
	}
	size_t MyString::find(const char* sub, size_t pos) const
	{
		if (sub == nullptr) {
			return npos;
		}
		if (pos >= _size) {
			return npos;
		}
		char* p = strstr(_str + pos, sub);
		if (p == nullptr) {
			return npos;
		}
		return p - _str;
	}