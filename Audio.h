#ifndef _AUDIO_H_
#define _AUDIO_H_
#include <iostream>
#include <string>

// interfata pt obiecte audio

class Audio
{
public:
    virtual void start() = 0;
    virtual void stop() = 0;
    virtual ~Audio();
};

// clasa de baza abstracta

class Audio_Object
{
protected:
    std::string title;
    std::string person;

public:
    Audio_Object(const std::string &t, const std::string &p);
    virtual void set_title(const std::string &t);
    virtual void set_person(const std::string &p);
    virtual std::string get_title() const;
    virtual std::string get_person() const;
    virtual void print_details() = 0;
    virtual ~Audio_Object();
};

class Melody : public Audio_Object, public Audio
{
    std::string genre;

public:
    Melody(const std::string &title, const std::string &person, const std::string &gen);
    void set_genre(const std::string &g);
    std::string get_genre() const;
    void print_details() override;
    void start() override;
    void stop() override;
};

class Podcast : public Audio_Object, public Audio
{
    int nr_of_episodes;

public:
    Podcast(const std::string &title, const std::string &person, int nr_of_ep);
    void set_nr_of_ep(int nr);
    int get_nr_of_ep() const;
    void print_details() override;
    void start() override;
    void stop() override;
};

#endif