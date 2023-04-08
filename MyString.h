#ifndef _MYSTRING_H_
#define _MYSTRING_H_
#include <iostream>
class MyString
{
    char *str;

public:
    int strlen(const char *s);

    MyString();

    MyString(const char *str2);

    MyString(const MyString &s);

    ~MyString();

    void operator=(const MyString &s);

    void add_ch(char new_ch);

    void strcat(const char *str2);

    operator const char *() const;

    friend std::ostream &operator<<(std::ostream &out, const MyString &s);
    friend std::istream &operator>>(std::istream &in, MyString &s);
};

#endif