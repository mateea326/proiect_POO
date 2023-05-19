#include <iostream>
#include <string>
#include "Song.h"
#include "Artist.h"
#include "Album.h"

int Song::total_songs = 0;

Song::Song() : song_name(""), album_name(""), artist_name(""), song_time(0.0)
{
    total_songs++;
}

Song::Song(const std::string &s, const Artist &a, const Album &alb) : song_name(s), artist_name(a), album_name(alb)
{
    total_songs++;
}

Song::~Song()
{
}
void Song::set_artist(Artist &artist)
{
    artist_name = artist;
}

void Song::set_album(Album &album)
{
    album_name = album;
}

Artist Song::get_artist() const
{
    return artist_name;
}

Album Song::get_album() const
{
    return album_name;
}

void Song::set_time(float time)
{
    song_time = time;
}

float Song::get_time() const
{
    return song_time;
}

int Song::get_total_songs()
{
    return total_songs;
}

bool Song::operator==(const Song &s) const
{
    if (song_name == s.song_name && artist_name == s.artist_name && album_name == s.album_name)
        return 1;
    return 0;
}

std::ostream &operator<<(std::ostream &out, const Song &s)
{
    out << s.song_name;
    return out;
}
