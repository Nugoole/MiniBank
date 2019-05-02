#ifndef __STRING_MAKE_H__
#define __STRING_MAKE_H__

#include "MinibankingCommon.h"
#include <fstream>



class String
{
private:
	int strLen;	//문자열의 길이
	char * str;	//문자열의 주소

public:
	String();

	String(const char * str);

	String(const String& str);

	void operator = (const String& str);

	String& operator += (const String& str);

	String& operator +(const String& str)const;

	bool operator ==(const String& str);

	~String();

	friend ostream& operator <<(ostream& ostm, const String& str);
	friend istream& operator >> (istream& istm, String& str);
};

ostream& operator <<(ostream& ostm, const String& str);

istream& operator >> (istream& istm, String& str);


#endif // !__STRING_MAKE_H__
