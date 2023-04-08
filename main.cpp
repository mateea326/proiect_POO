#include <iostream>

#include "MyString.h"
#include "Vector.hpp"
#include "Song.h"
#include "Artist.h"
#include "Album.h"
#include "Playlist.h"

int main()
{
    std::cout << "Choose a song to listen to:" << std::endl;
    std::cout << "MY PLAYLIST" << std::endl;
    Playlist p;

    MyString s1("Money Trees");
    MyString s2("Japanese Denim");
    MyString s3("Pink + White");
    MyString s4("Dreams");
    MyString s5("Kill V. Maim");

    MyString a1("Kendrick Lamar");
    MyString a2("Daniel Caesar");
    MyString a3("Frank Ocean");
    MyString a4("Fleetwood Mac");
    MyString a5("Grimes");

    MyString alb1("good kid, m.A.A.d city");
    MyString alb2("Get You");
    MyString alb3("Blonde");
    MyString alb4("Rumours (Super Deluxe)");
    MyString alb5("Art Angels");

    Artist artist1(a1);
    Artist artist2(a2);
    Artist artist3(a3);
    Artist artist4(a4);
    Artist artist5(a5);

    Album album1(alb1);
    Album album2(alb2);
    Album album3(alb3);
    Album album4(alb4);
    Album album5(alb5);

    Song song1(s1, artist1, album1);
    Song song2(s2, artist2, album2);
    Song song3(s3, artist3, album3);
    Song song4(s4, artist4, album4);
    Song song5(s5, artist5, album5);

    song1.set_time(6.26);
    song2.set_time(4.30);
    song3.set_time(3.04);
    song4.set_time(4.17);
    song5.set_time(4.07);

    Vector<float> times;
    times.push(song1.get_time());
    times.push(song2.get_time());
    times.push(song3.get_time());
    times.push(song4.get_time());
    times.push(song5.get_time());

    Vector<Artist> artists;
    artists.push(song1.get_artist());
    artists.push(song2.get_artist());
    artists.push(song3.get_artist());
    artists.push(song4.get_artist());
    artists.push(song5.get_artist());

    Vector<Album> albums;
    albums.push(song1.get_album());
    albums.push(song2.get_album());
    albums.push(song3.get_album());
    albums.push(song4.get_album());
    albums.push(song5.get_album());

    p.add_song(song1);
    p.add_song(song2);
    p.add_song(song3);
    p.add_song(song4);
    p.add_song(song5);

    for (int i = 1; i <= 5; i++)
        std::cout << i << ") " << p[i - 1] << "  " << '\n';

    int index;
    std::cin >> index;
    std::cout << "Now Playing: " << p[index - 1] << '\n';
    std::cout << "By: " << artists[index - 1] << '\n';
    std::cout << "From album: " << albums[index - 1] << '\n';
    std::cout << "Duration: " << times[index - 1] << " minutes" << '\n';
    std::cout << "Skip song? y/n" << std::endl;

    char answer;
    std::cin >> answer;
    if (answer == 'y')
        p.skip_song(index);
    return 0;
}