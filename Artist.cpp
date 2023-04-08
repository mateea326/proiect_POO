#include <iostream>
#include "Artist.h"
#include "MyString.h"

Artist::Artist() : artist_name("") {}

Artist::Artist(const MyString &a) : artist_name(a)
{
}

Artist::Artist(const Artist &a) : artist_name(a.artist_name) 
{
}

void Artist::operator=(const Artist &a)
{
    artist_name = a.artist_name;
}

Artist::~Artist()
{
}

std::ostream &operator<<(std::ostream &out, const Artist &a)
{
    out << a.artist_name;
    return out;
}