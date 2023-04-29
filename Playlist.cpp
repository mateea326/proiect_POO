#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include "Playlist.h"
#include "Song.h"

Playlist::Playlist()
{
}

Playlist::Playlist(std::vector<Song> &p)
{
    for (int i = 0; i < p.size(); i++)
        playlist.push_back(p[i]);
}

Playlist::~Playlist()
{
}

void Playlist::get_playlist_creator()
{
    std::cout << "Playlist made by: Mat & ";
}

bool Playlist::check_song(const Song &song)
{
    for (int i = 0; i < playlist.size(); i++)
         if (playlist[i] == song) 
            return 0;
    return 1;
}

void Playlist::add_song(const Song &song)
{
    if (check_song(song) == 0)
    {
        throw my_exception("Song is already added to the playlist");
    }

    playlist.push_back(song);
}

const Song &Playlist::operator[](int i) const
{
    if (i < 0 || i >= playlist.size())
    {
        throw std::out_of_range("Index out of bounds");
    }

    return playlist[i];
}

void Playlist::skip_song(int i)
{
    try
    {
        if (i + 1 < 0 || i + 1 >= playlist.size())
        {
            throw std::out_of_range("Index out of bounds");
        }

        std::cout << "Now Playing: " << playlist[i + 1] << '\n';
        std::cout << "By: " << playlist[i + 1].get_artist() << '\n';
        std::cout << "From album: " << playlist[i + 1].get_album() << '\n';
        std::cout << "Duration: " << playlist[i + 1].get_time() << " minutes" << '\n';
    }
    catch (const std::out_of_range &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

float Playlist::total_duration(const Playlist &p)
{
    float total_duration = 0;

    for (int i = 0; i < p.playlist.size(); i++)
    {
        total_duration += p.playlist[i].get_time();
        if (total_duration - floor(total_duration) >= 0.6)
            total_duration += 0.4;
    }

    return total_duration;
}

CollaborativePlaylist::CollaborativePlaylist()
{
}

CollaborativePlaylist::~CollaborativePlaylist()
{
}

void CollaborativePlaylist::share_song(const std::string &user)
{
    get_playlist_creator();
    if (user == "")
    {
        throw std::runtime_error("User name cannot be empty");
    }
    std::cout << user << std::endl;
}

my_exception::my_exception(const std::string &msg) : message(msg)
{
}

const char *my_exception::what() const noexcept
{
    return message.c_str();
}
