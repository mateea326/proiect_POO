#ifndef _PLAYLIST_H_
#define _PLAYLIST_H_
#include <iostream>

#include "MyString.h"
#include "Vector.hpp"
#include "Song.h"

class Playlist
{
    Vector<MyString> playlist;
    int playlist_size;

public:
    Playlist();

    Playlist(Vector<MyString> &p);

    ~Playlist();

    void add_song(Song &song);

    MyString &operator[](int i) const;

    void skip_song(int i);
};

#endif