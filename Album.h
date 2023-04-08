#ifndef _ALBUM_H_
#define _ALBUM_H_
#include <iostream>
#include "MyString.h"

class Album
{
    MyString album_name;

public:
    Album();

    Album(const MyString &alb);

    ~Album();

    void operator=(Album &alb);

    operator MyString() const;

    friend std::ostream &operator<<(std::ostream &out, const Album &alb);
};

#endif