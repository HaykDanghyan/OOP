#ifndef MUSIC_H
#define MUSIC_H
#include <vector>


class Song
{
    public :

    Song();
    ~Song();

    public : 

    u_short getYearOfIssue() const;
    u_int getSongDuration() const;
    std::string getSongName() const;
    std::string getSingerName() const;

    private :
    u_short yearOfIssue{};
    u_int songDuration{};
    std::string songName{};
    std::string singerName{};
};

class Musician
{
    public :

    Musician();
    ~Musician();

    public :

    u_short getBirthYear() const;
    std::string getMusicianName() const;
    std::string getMusicianSurname() const;
    std::string getMusicianNationality() const;
    std::vector<std::string> getAllSongs() const;
    
    private :

    u_short birthYear{};
    std::string musicianName{};
    std::string musicianSurname{};
    std::string nationality{};
    std::vector<std::string> allSongs;
};

struct 
{
    std::vector<Song> favouriteSongs;
    std::vector<Musician> favouriteMusicians;
} favourite ;

struct 
{
    std::vector<Song> cloudSongs;
    std::vector<Musician> cloudMusicians;

} cloud;

void player();
void insertSong();
void insertMusician();
void searchSong();
void searchMusician();
void addSong();
void removeSong();
void addToFavourite();
void removeFromFavourite();

#include "implementation.hpp"
#endif