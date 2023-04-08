#ifndef _SONG_H_
#define _SONG_H_
#include <iostream>
#include "MyString.h"
#include "Artist.h"
#include "Album.h"

class Song
{
    MyString song_name;
    Artist artist_name;
    Album album_name;
    float song_time;

public:
    Song();

    Song(const MyString &s, const Artist &a, const Album &alb);

    ~Song();

    void set_artist(Artist &artist);

    void set_album(Album &album);

    Artist get_artist() const;

    Album get_album() const;

    void set_time(float time);

    float get_time();

    void operator=(Song &s);

    operator MyString() const;

    friend std::ostream &operator<<(std::ostream &out, const Song &s);
};

#endif