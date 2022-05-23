#ifndef HEADER_H
#define HEADER_H
#include <iostream>
class University
{


    private:
    
    std::string _universityName{};   
    int _lecturerCount{};
    int _studentCount{};                   // Data Members
    int _bookcount{};
    std::string* _directorName = nullptr;     

    public:
    
    University()
    {
        _directorName = new std::string[20];
    }
    University(std::string name) : _universityName(name) {};
    University(University& ob)
    {
        this -> _bookcount = ob._bookcount;
        this -> _universityName = ob._universityName;
        this -> _studentCount = ob._studentCount;
        this -> _lecturerCount = ob._lecturerCount;
        this -> _directorName = ob._directorName;
    }
    University(const University& ob)
    {
        this -> _bookcount = ob._bookcount;
        this -> _universityName = ob._universityName;
        this -> _studentCount = ob._studentCount;
        this -> _lecturerCount = ob._lecturerCount;
        this -> _directorName = ob._directorName;
    }
    ~University()
    {
        delete[] _directorName;
        _directorName = nullptr;
        exit(0);
    }
    University& operator= (University& obj)
    {
        if(this != &obj)
        {
            _universityName = obj.getUniversityName();
            _lecturerCount = obj.getLecturerCount();
            _studentCount = obj.getStudentCount();
            _bookcount = obj.getBookCount();
            *_directorName = obj.getDirectorName();
        }
        return *this;
    }

    void setDirectorName(std::string);
    void setBookCount(int);
    void setUniversityName(std::string);
    void setStudentCount(int);
    void setLecturerCount(int);
    std::string getUniversityName();
    std::string& getDirectorName();                    // Member Functions
    int getStudentCount();
    int getLecturerCount();
    int getBookCount();
    void toString(University& obj);
};
#endif 