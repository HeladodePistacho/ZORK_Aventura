#ifndef _STRING_H_
#define _STRING_H_

#include <string.h>
#include <stdio.h>
#include "dinamic_array.h"


//Array de cadenas para el strtok.

class my_string
{
private:

	 char* buffer = nullptr;
	 unsigned int reserved_memory;
	
public:

	my_string(const char* str);
	my_string();
	my_string(const my_string& str);
	~my_string();

	unsigned int lenght() const;
	const char* c_str() const;
	bool empty() const;

	bool operator==(const my_string& str) const;
	bool operator==(const char* str) const;
	void operator+=(const my_string& str);
	void operator+=(const char* str);
	my_string operator+(const my_string& str)const;
	my_string operator+(const char* str) const;
	void operator=(const my_string& str);
	void operator=(const char* str);

	void clean();
	void shrink_to_fit();

	unsigned int capacity() const;

	void tokenize(const char* break_buffer, char* action, dynamic_array<char*>& divided);
	void tokenize(const char* break_buffer, dynamic_array<char*>& divided);

	

};

#endif
