#ifndef _ALBUM_H_
#define _ALBUM_H_
#include <iostream>
#include <string>

class Album
{
    std::string album_name;

public:
    Album();

    Album(const std::string &alb);

    ~Album();

    void operator=(Album &alb);

    bool operator==(const Album &alb) const;

    friend std::ostream &operator<<(std::ostream &out, const Album &alb);

    friend std::istream &operator>>(std::istream &in, Album &alb);
};

#endif