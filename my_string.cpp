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
	MyString& MyString::operator=(MyString other)
	{
		swap(other);
		return *this;
	}
	void MyString::insert(size_t pos, char ch)
	{
		assert(pos <= _size);
		if (_size == _capacity) {
			reserve(_capacity == 0 ? 4 : _capacity * 2);
		}
		memmove(_str + pos + 1, _str + pos, _size - pos + 1);
		_str[pos] = ch;
		++_size;
	}
	void MyString::insert(size_t pos, const char* str)
	{
		assert(pos <= _size);
		if (str == nullptr) {
			return ;
		}
		MyString temp(str);
		size_t len = strlen(str);
		if (len == 0) {
			return;
		}
		if (_size + len > _capacity)
		{
			size_t newcapacity = _capacity == 0 ? len : _capacity;
			while (newcapacity < _size + len) {
				newcapacity *= 2;
			}
			reserve(newcapacity);
		}
		memmove(_str + pos + len, _str + pos, _size - pos + 1);
		memcpy(_str + pos, str, len);
		_size += len;
	}
	void MyString::erase(size_t pos, size_t len)
	{
		assert(pos <= _size);
		if (pos == _size || len == 0) {
			return;
		}
		if (len == npos || len > _size - pos + 1) {
			_size = pos;
			_str[_size] = '\0';
			return;
		}
		memmove(_str + pos, _str + pos + len, _size - pos - len + 1);
		_size -= len;

	}
	MyString MyString::substr(size_t pos, size_t len)const
	{
		assert(pos <= _size);
		size_t reallen = len;
		if (len == npos || len > _size - pos) {
			reallen = _size - pos;
		}
		MyString temp;
		temp.reserve(reallen);
		if (reallen > 0) {
			memcpy(temp._str, _str + pos, reallen);
		}
		temp._size = reallen;
		temp._str[temp._size] = '\0';
		return temp;
	}