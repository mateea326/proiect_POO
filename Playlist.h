#ifndef _PLAYLIST_H_
#define _PLAYLIST_H_
#include <iostream>
#include <string>
#include <vector>
#include "Song.h"

class Playlist
{
protected:
    std::vector<Song> playlist;

    void get_playlist_creator();

public:
    Playlist();

    Playlist(std::vector<Song> &p);

    ~Playlist();

    bool check_song(const Song &song);

    void add_song(const Song &song);

    const Song &operator[](int i) const;

    void skip_song(int i);

    static float total_duration(const Playlist &playlist);
};

class CollaborativePlaylist : public Playlist
{
public:
    CollaborativePlaylist();

    ~CollaborativePlaylist();

    void share_song(const std::string &user);
};

class my_exception : public std::exception
{
public:
    my_exception(const std::string &msg);
    const char *what() const noexcept override;

private:
    std::string message;
};

#endif