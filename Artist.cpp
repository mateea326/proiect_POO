#include <iostream>
#include <string>
#include "Artist.h"

Artist::Artist() : artist_name("") {}

Artist::Artist(const std::string &a) : artist_name(a)
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

bool Artist::operator==(const Artist &a) const
{
    if (artist_name == a.artist_name)
        return 1;
    return 0;
}

std::ostream &operator<<(std::ostream &out, const Artist &a)
{
    out << a.artist_name;
    return out;
}

std::istream &operator>>(std::istream &in, Artist &a)
{
    std::getline(in, a.artist_name);
    return in;
}

FeaturedArtist::FeaturedArtist() : featured_artist_name("")
{
}

FeaturedArtist::FeaturedArtist(Artist &a, std::string fa) : Artist(a), featured_artist_name(fa)
{
}

FeaturedArtist::FeaturedArtist(const FeaturedArtist &fa) : featured_artist_name(fa.featured_artist_name)
{
}

FeaturedArtist::~FeaturedArtist()
{
}

std::ostream &operator<<(std::ostream &out, const FeaturedArtist &fa)
{
    out << fa.featured_artist_name;
    return out;
}

void FeaturedArtist::print() const
{
    std::cout << artist_name << " (feat. " << featured_artist_name << ")";
}