#include <iostream>
#include "Album.h"
#include "MyString.h"

Album::Album() : album_name("") {}

Album::Album(const MyString &alb) : album_name(alb)
{
}

void Album::operator=(Album &alb)
{
    album_name = alb.album_name;
}

Album::~Album()
{
}

Album::operator MyString() const
{
    return MyString(album_name);
}

std::ostream &operator<<(std::ostream &out, const Album &alb)
{
    out << alb.album_name;
    return out;
}
