#include <iostream>
#include <string>
#include "Album.h"

Album::Album() : album_name("") {}

Album::Album(const std::string &alb) : album_name(alb)
{
}

void Album::operator=(Album &alb)
{
    album_name = alb.album_name;
}

Album::~Album()
{
}

bool Album::operator==(const Album &alb) const
{
    if (album_name == alb.album_name)
        return 1;
    return 0;
}

std::ostream &operator<<(std::ostream &out, const Album &alb)
{
    out << alb.album_name;
    return out;
}

std::istream &operator>>(std::istream &in, Album &alb)
{
    std::getline(in, alb.album_name);
    return in;
}
