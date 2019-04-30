#ifndef __STRING_MAKE_H__
#define __STRING_MAKE_H__

#include "MinibankingCommon.h"

namespace str {

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

		String& operator <<(const String& str);

		String& operator <<(const char * str);

		String& operator <<(const char str);

		String& operator << (String& (*fp)(String& str));

		void operator >> (String& str);

		~String();


	};


	String& endl(String& str);
	static String cout;
	static String cin;

}

#endif // !__STRING_MAKE_H__
