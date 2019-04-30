#include "String_make.h"

using namespace str;
String::String():strLen(0){
	str = new char;
	str[0] = '\0';
}

String::String(const char * str)
{
	this->strLen = strlen(str);
	this->str = new char[this->strLen + 1];
	strcpy(this->str, str);
}

String::String(const String& str)
{
	this->strLen = strlen(str.str);
	this->str = new char[this->strLen + 1];
	strcpy(this->str, str.str);
}


void String::operator = (const String& str)
{
	strLen = strlen(str.str);
	this->str = new char[strLen + 1];
	strcpy(this->str, str.str);
}


String& String::operator += (const String& str)
{
	char * temp = new char[this->strLen + str.strLen + 1];
	strcpy(temp, this->str);
	strcat(temp, str.str);

	delete this->str;
	this->str = new char[this->strLen + str.strLen + 1];
	strcpy(this->str, temp);

	delete temp;

	return *this;
}


String& String::operator +(const String& str)const
{
	char * tmp = new char[this->strLen + str.strLen + 1];
	strcpy(tmp, this->str);
	strcat(tmp, str.str);
	String temp(tmp);
	delete tmp;
	return temp;
}

bool String::operator ==(const String& str)
{
	return strcmp(this->str, str.str);
}

String& String::operator <<(const String& str)
{
	printf("%s", str.str);
	return *this;
}

String& String::operator <<(const char str)
{
	printf("%c", str);
	return *this;
}

String& String::operator <<(const char * str)
{
	printf("%s", str);
	return *this;
}

String& String::operator << (String& (*fp)(String& str))
{
	return fp(*this);
}

void String::operator >> (String& str)
{
	//std::cout << "input : ";
	char str_tmp[30];

	//std::cin.getline(str_tmp, 30);
	rewind(stdin);

	String tmp(str_tmp);
	str = tmp;
}

String::~String()
{
	if (str != NULL) {
		delete str;
	}
}

str::String& str::endl(String& str)
{
	str << '\n';
	rewind(stdout);

	return str;
}