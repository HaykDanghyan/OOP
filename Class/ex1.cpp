// Define struct at least 3 different data fields. 
// Including pointer type as a data member, which allocates data on dynamic storage, 
// that is does new inside a constructor (whatever type you want e.g. [int, float, std::string, yourType or some ptr]). 
// Lets say int _id, std::string _name and char* _additionalInformation
// Write constructors with parameters that initialize data members. (try to use list initialization and delegating constructors)
// Write copy constructors, both [const T& and T&] which copies all the members.
// Create an object of your defined struct myObject_1 and initialize with values.
// Provide getters and setters so that you can change its data members. (do not change members directly)
// Create another object and copy it, so that it can use a copy constructor.
// Write copy assignment operator and use it as well
// Write destructor for the class
// At the end create a method called toString() which prints all data members of your object.


#include <iostream>
#include "class.h"
int main()
{
    University myObject_1;
    std::string str{};
    int book = 0 , lecturer = 0 , student = 0;
    std::cout << "Please enter the University name : ";
    std::getline(std::cin , str);
    myObject_1.setUniversityName(str);
    std::string director_name{};
    std::cout << "Please enter the " << myObject_1.getUniversityName() << " university director name : ";
    std::getline(std::cin , director_name);
    myObject_1.setDirectorName(director_name);
    do
    {
        std::cout << "Please enter the count of lecturers in " << myObject_1.getUniversityName() << " : ";
        std::cin >> lecturer;
    } 
    while (lecturer < 0);
    myObject_1.setLecturerCount(lecturer);
    do
    {
        std::cout << "Please enter the count of books in " << myObject_1.getUniversityName() << " : ";
        std::cin >> book;
    } 
    while (book < 0);
    myObject_1.setBookCount(book);
    do
    {
        std::cout << "Please enter the count of students in " << myObject_1.getUniversityName() << " : ";
        std::cin >> student;
    }
    while (student < 0);
    
    myObject_1.setStudentCount(student);
    University copyObj = myObject_1;
    std::cout <<  "\nCopying the object ..." << std::endl;
    myObject_1.toString(myObject_1);
    std::cout << "\n\n\n" << std::endl;
    copyObj.toString(copyObj);
    return 0;
}
int University::getBookCount()
{
    return  _bookcount;
}
int University::getLecturerCount()
{
    return  _lecturerCount;
}
int University::getStudentCount()
{
    return  _studentCount;
}
std::string University::getUniversityName()
{
    return  _universityName;
}
std::string& University::getDirectorName()
{
    return *_directorName;
}
void University::toString(University& obj)
{
    std::cout << "University Name : " <<  obj.getUniversityName() << std::endl;
    std::cout << "The " << obj.getUniversityName() << " university director : " << obj.getDirectorName() << std::endl;
    std::cout << "Count of Students in  " << obj.getUniversityName() << " : " <<  obj.getStudentCount() << std::endl;
    std::cout << "Count of Lecturers in " << obj.getUniversityName() << " : " << obj.getLecturerCount() << std::endl;
    std::cout << "Count of Books in " << obj.getUniversityName() << " : " << obj.getBookCount() << std::endl;
}
void University::setLecturerCount(int count)
{
    _lecturerCount = count;
}
void University::setStudentCount(int stud_count)
{
    _studentCount = stud_count;
}
void University::setUniversityName(std::string str)
{
    _universityName = str;
}
void University::setBookCount(int book)
{
    _bookcount = book;
}
void University::setDirectorName(std::string name)
{
    *_directorName = name;
}