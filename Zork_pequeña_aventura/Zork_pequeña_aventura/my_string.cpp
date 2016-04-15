#define _CRT_SECURE_NO_WARNINGS
#include "my_string.h"
#include "dinamic_array.h"
#include <string.h>
#include <stdio.h>

//clean, shrink to fit


my_string::my_string(const char* str) 
{
	int len = strlen(str);
	buffer = new char[len + 1];
	reserved_memory = len + 1;
	strcpy_s(buffer, len + 1, str);
}

my_string::my_string()
{
	buffer = new char[100];
	reserved_memory = 100;
}

my_string::my_string(const my_string& str)
{
	int len = strlen(str.buffer);
	buffer = new char[len + 1];
	reserved_memory = len + 1;
	strcpy_s(buffer, len + 1, str.buffer);
}

my_string::~my_string()
{
	delete[] buffer;	
}

unsigned int my_string::lenght() const
{
	return strlen(buffer);
}

const char* my_string::c_str()const
{
	return buffer;
}

bool my_string::empty()const
{
	return strlen(buffer) == 0;
}

bool my_string::operator==(const my_string& str) const
{
	if (strcmp(buffer, str.buffer)) return false;
	return true;
}

bool my_string::operator==(const char* str) const
{
	if (strcmp(buffer, str)) return false;
	return true;
}

void my_string::operator+=(const my_string& str)
{

	int final_lenght = lenght() + str.reserved_memory;
	

	if (str.lenght() + 1 > reserved_memory)
	{
		char* temp_buf = new char[final_lenght];
		strcpy_s(temp_buf, lenght() + 1, buffer);

		delete[] buffer;
		reserved_memory = final_lenght;
		buffer = temp_buf;	
		
	}
	 buffer = strcat(buffer, str.buffer);
}

void my_string::operator+=(const char* str)
{
	int len = strlen(buffer) + strlen(str);
	

	char* temp_buf = new char[len + 1];
	strcpy_s(temp_buf, len + 1, buffer);
	buffer = new char[len + 1];
	buffer = strcat(temp_buf, str);
}

my_string my_string::operator+(const my_string& str) const
{

	int len = strlen(buffer);
	int len2 = strlen(str.buffer);
	char* temp_buf = new char[len + len2 + 1];

	my_string result(temp_buf);
	strcpy(result.buffer, buffer);
	strcat(result.buffer, str.buffer);

	return result;
}

my_string my_string::operator+(const char* str) const
{

	
	int len2 = strlen(str);
	char* temp_buf = new char[lenght() + len2 + 1];

	my_string result(temp_buf);
	strcpy(result.buffer, buffer);
	strcat(result.buffer, str);

	return result;
}

void my_string::operator=(const my_string& str)
{

	if (str.lenght() + 1 > reserved_memory)
	{
		delete[]buffer;
		reserved_memory = str.lenght() + 1;
		buffer = new char[reserved_memory];
		
	}
	
	strcpy_s(buffer,reserved_memory, str.buffer);

}

unsigned int my_string::capacity() const
{
	return reserved_memory;
}

void my_string::clean()
{
	buffer[0] = '\0';

}

void my_string::shrink_to_fit(){
	unsigned int len = lenght() + 1;

	if (len < reserved_memory)
	{
		reserved_memory = len;
		char* temp_buf = new char[len];
		strcpy_s(temp_buf, len, buffer);

		delete[] buffer;
		buffer = new char[len];
		strcpy_s(buffer, len, temp_buf);
	}
}

void my_string::tokenize(const char* break_buffer)
{
	char* phrase_member = strtok(buffer, break_buffer);
	phrase.push_back(phrase_member);
	while ((phrase_member = strtok(NULL, break_buffer)) != NULL)
	{
		phrase.push_back(phrase_member);
	}

}

dynamic_array <char*> my_string::GetVector() const
{
	return phrase;
}