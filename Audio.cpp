#include <iostream>
#include <string>
#include "Audio.h"

Audio::~Audio()
{
}

Audio_Object::Audio_Object(const std::string &t, const std::string &p) : title(t), person(p)
{
}

void Audio_Object::set_title(const std::string &t)
{
    title = t;
}

void Audio_Object::set_person(const std::string &p)
{
    person = p;
}

std::string Audio_Object::get_title() const
{
    return title;
}

std::string Audio_Object::get_person() const
{
    return person;
}

Audio_Object::~Audio_Object()
{
}

Melody::Melody(const std::string &title, const std::string &person, const std::string &gen) : Audio_Object(title, person), genre(gen)
{
}

void Melody::set_genre(const std::string &g)
{
    genre = g;
}

std::string Melody::get_genre() const
{
    return genre;
}

void Melody::print_details()
{
    std::cout << "Melody playing: " << title << " by " << person;
}
void Melody::start()
{
    std::cout << "Starting melody: " << title << " by " << person;

}
void Melody::stop()
{
    std::cout << "Stopping melody: " << title << " by " << person;
}

Podcast::Podcast(const std::string &title, const std::string &person, int nr_of_ep)
    : Audio_Object(title, person), nr_of_episodes(nr_of_ep)
{
}

void Podcast::set_nr_of_ep(int nr)
{
    nr_of_episodes = nr;
}

int Podcast::get_nr_of_ep() const
{
    return nr_of_episodes;
}

void Podcast::print_details()
{
    std::cout << "Podcast playing: " << title << " by " << person;
}
void Podcast::start()
{
    std::cout << "Starting podcast: " << title << " by " << person;
}
void Podcast::stop()
{
    std::cout << "Stopping podcast: " << title << " by " << person;
}
