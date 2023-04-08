#include <iostream>

#include "Playlist.h"
#include "MyString.h"
#include "Vector.hpp"
#include "Song.h"

Playlist::Playlist()
{
    Vector<MyString> aux;
    playlist = aux;
}

Playlist::Playlist(Vector<MyString> &p)
{
    for (int i = 0; i < p.size; i++)
        playlist.push(p[i]);
}

Playlist::~Playlist()
{
}

void Playlist::add_song(Song &song)
{
    playlist.push(song);
}

MyString &Playlist::operator[](int i) const
{
    return playlist[i];
}

void Playlist::skip_song(int i)
{
    if (i <= 5)
    {
        std::cout << "Now Playing: " << playlist[i] << '\n';
    }
    else
        std::cout << "There are no more songs left in the playlist" << '\n';
}