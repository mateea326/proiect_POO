#include <iostream>
#include "Song.h"
#include "MyString.h"
#include "Artist.h"
#include "Album.h"

Song::Song() : song_name("song_name"), album_name("album_name"), artist_name("artist_name"), song_time(0.0)
{
}

Song::Song(const MyString &s, const Artist &a, const Album &alb) : song_name(s), artist_name(a), album_name(alb)
{
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

float Song::get_time()
{
    return song_time;
}

Song::operator MyString() const
{
    return MyString(song_name);
}

std::ostream &operator<<(std::ostream &out, const Song &s)
{
    out << s.song_name;
    return out;
}