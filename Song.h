#ifndef _SONG_H_
#define _SONG_H_
#include <iostream>
#include <string>
#include "Artist.h"
#include "Album.h"

class Song
{
    std::string song_name;
    Artist artist_name;
    Album album_name;
    float song_time;
    static int total_songs;

public:
    Song();

    Song(const std::string &s, const Artist &a, const Album &alb);

    ~Song();

    void set_artist(Artist &artist);

    void set_album(Album &album);

    Artist get_artist() const;

    Album get_album() const;

    void set_time(float time);

    float get_time() const;

    static int get_total_songs();

    bool operator==(const Song &s) const;

    friend std::ostream &operator<<(std::ostream &out, const Song &s);
};

class PopSong : protected Song
{
public:
    PopSong();

    PopSong(const std::string &s, const Artist &a, const Album &alb);

    ~PopSong();
};

class RockSong : protected Song
{
public:
    RockSong();

    RockSong(const std::string &s, const Artist &a, const Album &alb);

    ~RockSong();
};

#endif