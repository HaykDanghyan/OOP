#include "sortShape.h"

int main() 
{
	std::string line = "P 5 5 C 55 20 5 R 34 100.5 350.56 400 T 3.33 34.1 23 654 5 3";
	
	sort_shape_areas(line);

	Point p;

	std::string str = "3.33 5";
	
	get_area_and_insert(p , str);

	std::cout << str << std::endl;
}