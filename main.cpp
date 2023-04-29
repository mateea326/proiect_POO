#include <iostream>
#include <cstring>
#include <vector>
#include <cstdlib>
#include <limits>
#include <cmath>

#include "Song.h"
#include "Artist.h"
#include "Album.h"
#include "Playlist.h"
#include "Audio.h"

int main()
{
    std::cout << "My Playlist:" << '\n';
    Playlist p;

    Artist artist1("Kendrick Lamar");
    Artist artist2("Daniel Caesar");
    Artist artist3("Frank Ocean");
    Artist artist4("Fleetwood Mac");
    Artist artist5("Grimes");
    Artist artist6("Tyler, the Creator");
    FeaturedArtist featured_artist6(artist6, "Kali Uchis");
    Artist artist7("Lana del Rey");
    Artist artist8("Mac DeMarco");

    Album album1("good kid, m.A.A.d city");
    Album album2("Get You");
    Album album3("Blonde");
    Album album4("Rumours (Super Deluxe)");
    Album album5("Art Angels");
    Album album6("Flower Boy");
    Album album7("Honeymoon");
    Album album8("Here Comes The Cowboy");

    Song song1("Money Trees", artist1, album1);
    Song song2("Japanese Denim", artist2, album2);
    Song song3("Pink + White", artist3, album3);
    Song song4("Dreams", artist4, album4);
    Song song5("Kill V. Maim", artist5, album5);
    Song song6("See You Again", featured_artist6, album6);
    Song song7("Art Deco", artist7, album7);
    Song song8("Heart to Heart", artist8, album8);

    song1.set_time(6.26);
    song2.set_time(4.30);
    song3.set_time(3.04);
    song4.set_time(4.17);
    song5.set_time(4.07);
    song6.set_time(3.00);
    song7.set_time(4.55);
    song8.set_time(3.31);

    p.add_song(song1);
    p.add_song(song2);
    p.add_song(song3);
    p.add_song(song4);
    p.add_song(song5);
    p.add_song(song6);
    p.add_song(song7);
    p.add_song(song8);

    for (int i = 0; i < 8; i++)
        std::cout << i + 1 << ") " << p[i] << '\n';

    std::cout << '\n';
    std::cout << "Choose what you want to do:" << '\n';
    std::cout << "Play a song (1)" << '\n';
    std::cout << "Shuffle playlist (2)" << '\n';
    std::cout << "Add a song (3)" << '\n';
    std::cout << "Download playlist (4)" << '\n';
    std::cout << "Make the playlist collaborative (5)" << '\n';
    std::cout << "Listen to a podcast instead (6)" << '\n';
    std::cout << "Listen by genre (7)" << '\n';

    int choice;
    std::cin >> choice;
    if (choice == 1)
    {
        std::cout << "Choose the song number:" << '\n';
        int index;
        std::cin >> index;
        index--;
        if (index < 0 || index >= 9)
            throw std::out_of_range("Index out of bounds");
        std::cout << "Now Playing: " << p[index] << '\n';
        std::cout << "By: ";
        if (index == 5)
            featured_artist6.print();
        else
            std::cout << p[index].get_artist();
        std::cout << '\n';
        std::cout << "From album: " << p[index].get_album() << '\n';
        std::cout << "Duration: " << p[index].get_time() << " minutes" << '\n';
        std::cout << "Skip song? y/n" << '\n';

        char answer;
        std::cin >> answer;

        while (answer == 'y')
        {
            if (index == 7)
            {
                std::cout << "There are no more songs left" << '\n';
                break;
            }
            else
            {
                p.skip_song(index);
                index++;
                std::cout << "Skip song? y/n" << '\n';
                std::cin >> answer;
            }
        }
    }
    else if (choice == 2)
    {
        // alege o melodie random din playlist
        srand((unsigned)time(NULL));
        int random_index = rand() % 8;
        std::cout << "Now Playing: " << p[random_index] << '\n';
        std::cout << "By: ";
        if (random_index == 5)
            featured_artist6.print();
        else
            std::cout << p[random_index].get_artist();
        std::cout << '\n';
        std::cout << "From album: " << p[random_index].get_album() << '\n';
        std::cout << "Duration: " << p[random_index].get_time() << " minutes" << '\n';
    }

    else if (choice == 3)
    {
        std::string input_song;
        std::cout << "Enter song name:" << '\n';
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::getline(std::cin, input_song);

        Artist artist9;
        std::cout << "Enter artist name:" << '\n';
        std::cin >> artist9;

        Album album9;
        std::cout << "Enter album name:" << '\n';
        std::cin >> album9;

        Song song9(input_song, artist9, album9);

        float input_song_time;
        std::cout << "Enter the song's duration:" << '\n';
        std::cin >> input_song_time;
        // conversie pentru secunde, la 60 de secunde se mai face un minut in caz de input gresit
        if (input_song_time - floor(input_song_time) >= 0.6)
            input_song_time += 0.4;
        song9.set_time(input_song_time);

        p.add_song(song9);

        std::cout << '\n';
        std::cout << "Now Playing: " << p[8] << '\n';
        std::cout << "By: " << p[8].get_artist() << '\n';
        std::cout << "From album: " << p[8].get_album() << '\n';
        std::cout << "Duration: " << p[8].get_time() << " minutes" << '\n';
    }
    else if (choice == 4)
    {
        std::cout << "--Playlist downloaded--" << '\n';
        std::cout << "Number of songs in playlist: " << Song::get_total_songs() << '\n';
        std::cout << "Playlist duration: " << floor(Playlist::total_duration(p)) << " minutes and "
                  << (Playlist::total_duration(p) - floor(Playlist::total_duration(p))) * 100 << " seconds";
    }

    else if (choice == 5)
    {
        std::string your_name;
        std::cout << "Enter your name: " << '\n';
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::getline(std::cin, your_name);
        if (your_name == "")
            throw std::runtime_error("User name cannot be empty");
        CollaborativePlaylist cp;
        cp.share_song(your_name);
    }
    else if (choice == 6)
    {
        std::string podcast_name;
        std::string podcast_host;
        int nr_of_eps;
        std::cout << "Enter the name of the podcast: " << '\n';
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::getline(std::cin, podcast_name);

        std::cout << "Enter the host of the podcast: " << '\n';
        std::getline(std::cin, podcast_host);

        std::cout << "Enter the number of episodes: " << '\n';
        std::cin >> nr_of_eps;

        try
        {
            if (nr_of_eps < 1)
            {
                throw std::invalid_argument("Number of episodes must be greater than or equal to 1.");
            }

            Podcast pod(podcast_name, podcast_host, nr_of_eps);
            std::cout << "--Now listening to: " << '\n';
            pod.print_details();
            int pod_index = 1;

            std::cout << " Episode " << pod_index << "/" << pod.get_nr_of_ep() << '\n';
            std::cout << "Next episode? (y/n)" << '\n';

            char pod_answer;
            std::cin >> pod_answer;
            while (pod_answer == 'y')
            {
                pod_index++;
                if (pod_index > pod.get_nr_of_ep())
                {
                    std::cout << "There are no more episodes left" << std::endl;
                    break;
                }
                else
                {
                    std::cout << "Now playing episode " << pod_index << "/" << pod.get_nr_of_ep() << '\n';
                    std::cout << "Next episode? (y/n)" << '\n';
                    std::cin >> pod_answer;
                }
            }
        }
        catch (const std::invalid_argument &e)
        {
            std::cout << "Error: " << e.what() << std::endl;
        }
    }
    else if (choice == 7)
    {
        std::string genre;
        std::string name;
        std::string artist;
        std::string album;

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        std::cout << "Enter genre: " << '\n';
        std::getline(std::cin, genre);
        std::cout << "Enter name: " << '\n';
        std::getline(std::cin, name);
        std::cout << "Enter artist: " << '\n';
        std::getline(std::cin, artist);
        std::cout << "Enter album: " << '\n';
        std::getline(std::cin, album);

        if (genre == "Pop")
            PopSong(name, artist, album);
        else if (genre == "Rock")
            RockSong(name, artist, album);

        Audio *audio = new Melody(name, artist, genre); // upcasting
        audio->start();                                 // polimorfism la execuție (dynamic dispatch)
        std::cout << std::endl;
        audio->stop();
        std::cout << std::endl;

        std::cout << std::endl;

        Melody *melody = dynamic_cast<Melody *>(audio); // downcasting
        melody->start();
        std::cout << std::endl;
        melody->stop();
        std::cout << std::endl;
        delete audio;
    }
    else
        std::cout << "Invalid number" << '\n';

    return 0;
}