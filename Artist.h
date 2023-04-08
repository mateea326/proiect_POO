#ifndef _ARTIST_H_
#define _ARTIST_H_
#include <iostream>
#include "MyString.h"

class Artist
{
    MyString artist_name;

public:
    Artist();

    Artist(const MyString &a);

    Artist(const Artist &a);

    ~Artist();

    void operator=(const Artist &a);

    friend std::ostream &operator<<(std::ostream &out, const Artist &a);
};

#endif