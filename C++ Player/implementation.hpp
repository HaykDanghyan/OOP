Song::Song()
{
    std::cout << "Please enter the song name : ";
    std::cin >> songName;
    std::cout << "Please enter the singer name : ";
    std::cin >> singerName;
    std::cout << "Please enter the duration of the song " << songName << " : ";
    std::cin >> songDuration;
    std::cout << "Please enter the year of issue : ";
    std::cin >> yearOfIssue;
}

u_short Song::getYearOfIssue() const {return yearOfIssue;}

u_int Song::getSongDuration() const {return songDuration;}

std::string Song::getSongName() const {return songName;}

std::string Song::getSingerName() const {return singerName;}

Song::~Song(){}

Musician::Musician()
{
    u_int count = 0;
    std::string song{};
    std::cout << "Please enter the musician name : ";
    std::cin >> musicianName;
    std::string str{};
    do
    {
        std::cout << "Do your musician have surname or no ? (yes/no) : ";
        std::cin >> str;
    }
    while(str != "yes" && str != "no");
    if(str == "yes")
    {
        std::cout << "Please enter the surname of musician " << musicianName << " : ";
        std::cin >> musicianSurname;
    }
    std::cout << "Please enter the nationality of " << musicianName << " " << musicianSurname << " : ";
    std::cin >> nationality;
    std::cout << "Please enter the year of birth of " << musicianName << " " << musicianSurname << " : ";
    std::cin >> birthYear;
    std::cout << "Please enter the count of songs of " << musicianName << " " << musicianSurname << " : ";
    std::cin >> count;
    for(int i = 0; i < count; i++)
    {
        std::cout << "Song #" << i + 1 << " : ";
        std::cin >> song;
        allSongs.push_back(song);
    }
}

u_short Musician::getBirthYear() const {return birthYear;}

std::string Musician::getMusicianName() const {return musicianName;}

std::string Musician::getMusicianSurname() const {return musicianSurname;}

std::string Musician::getMusicianNationality() const {return nationality;}

std::vector<std::string> Musician::getAllSongs() const {return allSongs;}

Musician::~Musician(){}
void player()
{
    u_int choice = 0;
again:    std::cout << "Please enter the operation you want to do\n" << 
    "[1] Insert Song [2] Insert Musician [3] Search Song\n[4] Search Musician [5] Add Song [6] Remove Song\n[7] Add to Favourites : ";
    std::cin >> choice;
    std::string str{};
    if(choice <= 0 || choice > 7)
    {
        goto again;
    }
    switch(choice)
    {
        case 1:
        insertSong();
        break;
        case 2:
        insertMusician();
        break;
        case 3:
        searchSong();
        break;
        case 4:
        searchMusician();
        break;
        case 5:
        addSong();
        break;
        case 6:
        removeSong();
        break;
        case 7:
        addToFavourite();
        default:
        break;
    }
    do
    {
        std::cout << "Do you want to do any operations again(yes/no) : ";
        std::cin >> str;
    }
    while(str != "yes" && str != "no");
    if(str == "no")
    {
        std::cout << "Goodbye !" << std::endl;
        std::exit(0);
    }
    else{goto again;}
}
void insertSong()
{
    u_int count = 0;
    std::cout << "Please enter the count of songs to add in your CLOUD : ";
    std::cin >> count;
    for(int i = 0; i < count; i++)
    {
        Song song;
        cloud.cloudSongs.push_back(song);
        std::cout << "The song " << song.getSongName() << " added to your cloud SUCCESSFULLY !" << std::endl;
    }
}
void insertMusician()
{
    u_int count = 0;
    std::cout << "Please enter the count of musicians to add in your CLOUD : ";
    std::cin >> count;
    for(int i = 0; i < count; i++)
    {
        Musician musician;
        cloud.cloudMusicians.push_back(musician);
        std::cout << "The musician " << musician.getMusicianName() << " added to your cloud SUCCESSFULLY !" << std::endl;
    }
}

void searchSong()
{
    std::string songName{};
    std::cout << "Please enter the song name you want to search : ";
    std::cin >> songName;
    for(int i = 0; i < favourite.favouriteSongs.size(); i++)
    {
        if(songName == favourite.favouriteSongs[i].getSongName())
        {
            std::cout << "Song " << songName << " is located in Favourites" << std::endl;
            std::cout << "The singer name of " << songName << " : " << favourite.favouriteSongs[i].getSingerName() << std::endl;
            std::cout << songName << " song duration : " << favourite.favouriteSongs[i].getSongDuration() << std::endl;
            std::cout << "Year of issue of " << songName << " : " << favourite.favouriteSongs[i].getYearOfIssue() << std::endl;
            return;
        }
    }
    for(int i = 0; i < cloud.cloudSongs.size(); i++)
    {
        if(songName == cloud.cloudSongs[i].getSongName())
        {
            std::cout << "Song " << songName << " is located in Cloud" << std::endl;
            std::cout << "The singer name of " << songName << " : " << cloud.cloudSongs[i].getSingerName() << std::endl;
            std::cout << songName << " song duration : " << cloud.cloudSongs[i].getSongDuration() << std::endl;
            std::cout << "Year of issue of " << songName << " : " << cloud.cloudSongs[i].getYearOfIssue() << std::endl;
            return;
        }
    }
    std::cout << "Found nothing by " << songName << std::endl;
}

void searchMusician()
{
    std::string name{};
    std::cout << "Please enter the name of musician: ";
    std::cin >> name;
    for (size_t i = 0; i < cloud.cloudMusicians.size(); i++)
    {
        if (cloud.cloudMusicians[i].getMusicianName() == name)
        {
            std::cout << "Musician " << name << "is located in Cloud" << std::endl;
            std::cout << "Surname : " << cloud.cloudMusicians[i].getMusicianSurname() << std::endl;
            std::cout << "Birth year:  " << cloud.cloudMusicians[i].getBirthYear() << std::endl;
            std::cout << "Nationality : " << cloud.cloudMusicians[i].getMusicianNationality() << std::endl;
            std::cout << "List of songs : " << std::endl;
            for (size_t i = 0; i < cloud.cloudMusicians[i].getAllSongs().size(); i++)
            {
                std::cout << "Song no" << i + 1 << " " << cloud.cloudMusicians[i].getAllSongs()[i]; 
            }
            return;
        }
    }
    for (size_t i = 0; i < favourite.favouriteMusicians.size(); i++)
    {
        if (favourite.favouriteMusicians[i].getMusicianName() == name)
        {
            std::cout << "Musician " << name << " is located in Favourites" << std::endl;
            std::cout << "Surname : " << favourite.favouriteMusicians[i].getMusicianSurname() << std::endl;
            std::cout << "Birth year : " << favourite.favouriteMusicians[i].getBirthYear() << std::endl;
            std::cout << "Nationality : " << favourite.favouriteMusicians[i].getMusicianNationality() << std::endl;
            std::cout << "List of songs :" << std::endl;
            for (size_t i = 0; i < favourite.favouriteMusicians[i].getAllSongs().size(); i++)
            {
                std::cout << "Song #" << i + 1  << " " << favourite.favouriteMusicians[i].getAllSongs()[i]  << std::endl; 
            }
            return;
        }
    }
}

void addSong()
{
    std::cout << "Enter the information about your song\n";
    Song song;
    cloud.cloudSongs.push_back(song);
    std::cout << "The song " << song.getSongName() << " added to your cloud SUCCESSFULLY !" << std::endl;
}

void removeSong()
{
    std::string songName{};
    std::cout << "Please enter the song name which you want to remove : ";
    std::cin >> songName;
    for(int i = 0; i < cloud.cloudSongs.size(); i++)
    {
        if(cloud.cloudSongs[i].getSongName() == songName)
        {
            cloud.cloudSongs.erase(cloud.cloudSongs.begin() + i);
            std::cout << "The song " << songName << " has removed from your cloud SUCCESSFULLY !";
        }
    }
    std::cout << "Found nothing by " << songName << std::endl; 
}

void addToFavourite()
{
    std::string tmp {};
    do
    {
       std::cout << "What do you want to add in 'Favourite' section ? (musician/song) : ";
       std::cin >> tmp;
    }
    while(tmp != "musician" && tmp != "song");
    if(tmp == "song")
    {
        std::cout << "Please enter the information about the song\n";
        Song song;
        favourite.favouriteSongs.push_back(song);
        std::cout << "Song added to your Favourites SUCCESSFULLY !" << std::endl;
    }
    if(tmp == "musician")
    {
        std::cout << "Please enter the information about the musician\n";
        Musician musician;
        favourite.favouriteMusicians.push_back(musician);
        std::cout << "Musican added to your Favourites SUCCESSFULLY !" << std::endl;
    }
}