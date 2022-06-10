#include "sortShape.h"

void divided_in_lines(const std::string& in_shapes_str, std::vector<std::string>& lines) 
{
	int index = 0;
	std::string line = "";

	while (index != in_shapes_str.size()) 
	{
		if (in_shapes_str[index] == 'P' || in_shapes_str[index] == 'C' || in_shapes_str[index] == 'R' || in_shapes_str[index] == 'T') 
		{
			line += in_shapes_str[index];
			index++;

			for (int i = index; i < in_shapes_str.size(); ++i) 
			{
				if (in_shapes_str[i] == 'P' || in_shapes_str[i] == 'C' || in_shapes_str[i] == 'R' || in_shapes_str[i] == 'T')
				{
					break;
				}
				line += in_shapes_str[i];
			}

			lines.push_back(line);
			line = "";
		}

		index++;
	}
}

std::string sort_shape_areas(const std::string& in_shapes_str) 
{
	std::vector<std::string> lines;

	divided_in_lines(in_shapes_str, lines);

	for (int i = 0; i < lines.size(); ++i) 
	{
		std::cout << lines[i] << std::endl;
	}

	return "!";
}

std::string Figure::toString(float num) const
{
    return std::to_string(num);
}

float Point::calculate_area() const
{
    return 0;
}

float Circle::calculate_area() const
{
    const float PI = 3.14;
    float result = pow(radius , 2) * PI;
	return result;
}

float Rectangle::calculate_area() const
{
    float width = y2 - y;
	float length = x2 - x;
    float result = width * length;

	return result;
}

float Triangle::calculate_area() const
{
    float p = x1 - x3;
	float s = y2 - y3;
	float r = x2 - x3;
	float q = y1 - y3;

	return p * s - r * q / 2;
}

void get_area_and_insert(const Point& point , std::string& s)
{
    std::string tmp = point.toString(point.calculate_area()) + " Point ";

    for(int i = 0; i < s.size(); ++i)
    {
        tmp += s[i];
    } 

    tmp += "\n";

    s = tmp;
}

void get_area_and_insert(const Circle& circle , std::string& s)
{
    std::string tmp = circle.toString(circle.calculate_area()) + " Circle ";
    
    for(int i = 0; i < s.size(); ++i)
    {
        tmp += s[i];
    }

    tmp += "\n";

    s = tmp;
}

void get_area_and_insert(const Rectangle& rectangle , std::string& s)
{
    std::string tmp = rectangle.toString(rectangle.calculate_area()) + " Rectangle ";

    for(int i = 0; i < s.size(); ++i)
    {
        tmp += s[i];
    }

    tmp += "\n";

    s = tmp;
}

void get_area_and_insert(const Triangle& triangle , std::string& s)
{
    std::string tmp = triangle.toString(triangle.calculate_area()) + " Triangle ";

    for(int i = 0; i < s.size(); ++i)
    {
        tmp += s[i];
    }

    tmp += "\n";

    s = tmp;
}