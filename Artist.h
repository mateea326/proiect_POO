#ifndef _ARTIST_H_
#define _ARTIST_H_
#include <iostream>
#include <string>

class Artist
{
protected:
    std::string artist_name;

public:
    Artist();

    Artist(const std::string &a);

    Artist(const Artist &a);

    ~Artist();

    void operator=(const Artist &a);

    bool operator==(const Artist &a) const;

    friend std::ostream &operator<<(std::ostream &out, const Artist &a);

    friend std::istream &operator>>(std::istream &in, Artist &a);
};

class FeaturedArtist : public Artist
{
    std::string featured_artist_name;

public:
    FeaturedArtist();

    FeaturedArtist(Artist &a, std::string fa);

    FeaturedArtist(const FeaturedArtist &fa);

    ~FeaturedArtist();

    friend std::ostream &operator<<(std::ostream &out, const FeaturedArtist &fa);

    void print() const;
};

#endif