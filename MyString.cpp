#include <iostream>
#include "MyString.h"

int MyString::strlen(const char *s)
{
    int i = 0;
    while (*s != '\0')
        i++, s++;
    return i;
}

MyString::MyString()
{
    str = nullptr;
}

MyString::MyString(const char *str2)
{
    int length = strlen(str2);
    str = new char[length + 1];

    for (int i = 0; i < length; i++)
        str[i] = str2[i];

    str[length] = '\0';
}

MyString::MyString(const MyString &s)
{
   int length = strlen(s.str);
    str = new char[length + 1];

    for (int i = 0; i < length; i++)
        str[i] = s.str[i];

    str[length] = '\0';
}

MyString::~MyString()
{
    delete[] str;
}

void MyString::operator=(const MyString &s)
{
    delete[] str;
    int length = strlen(s.str);
    str = new char[length + 1];

    for (int i = 0; i < length; i++)
        str[i] = s.str[i];
    str[length] = '\0';
}

void MyString::add_ch(char new_ch)
{
    int length = strlen(str);
    char *str2 = new char[length + 2];
    for (int i = 0; i < length; i++)
        str2[i] = str[i];
    str2[length] = new_ch;
    str2[length + 1] = '\0';
    length++;
    delete[] str;
    str = str2;
}

void MyString::strcat(const char *str2)
{
    int length = strlen(str);
    int length2 = strlen(str2);
    char *str3 = new char[length + length2 + 1];
    for (int i = 0; i < length; i++)
        str3[i] = str[i];
    for (int i = 0; i < length2; i++)
        str3[length + i] = str2[i];
    str3[length + length2] = '\0';
    delete[] str;
    str = str3;
}

MyString::operator const char *() const
{
    return str;
}

std::ostream &operator<<(std::ostream &out, const MyString &s)
{
    out << s.str;
    return out;
}

std::istream &operator>>(std::istream &in, MyString &s)
{
    int i = 0;
    char ch;

    while (in.get(ch))
    {
        if (ch != '\n')
            s.str[i++] = ch;
        else
            break;
    }
    s.str[i] = '\0';
    return in;
}