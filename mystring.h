#pragma once
#include <iostream>
#include <cstring>
#include <cassert>
#include <cstddef>
#include <string>
class MyString {
public:
	typedef char* iterator;
	typedef const char* const_iterator;
	MyString();
	MyString(const char* str);
	~MyString();
	MyString(const MyString& str);
	void swap( MyString& other);
	size_t size() const;
	size_t capacity() const;
	bool empty() const;
	const char* c_str() const;
	iterator begin();
	iterator end();
	const_iterator begin() const;
	const_iterator end() const;
	void reserve(size_t n);
	void resize(size_t n, char ch = '\0');
	char& operator[](size_t pos);
	const char& operator[](size_t pos) const;

	void push_back(char ch);
	void append(const char* str);

	MyString& operator+=(char ch);
	MyString& operator+=(const char* str);
	MyString& operator=(MyString other);
	void clear();
	size_t find(char ch, size_t pos = 0) const;
	size_t find(const char* sub, size_t pos = 0) const;
	void insert(size_t pos, char ch);
	void insert(size_t pos, const char* str);
	static const size_t npos;
private:
	char* _str = nullptr;
	size_t _size = 0;
	size_t _capacity = 0;
	
};
