#ifndef SORTSHAPE_H
#define SORTSHAPE_H

#include <iostream>
#include <string>
#include <vector>
#include <cmath>

class Figure 
{
    public:

	std::string toString(float) const;
};

class Point : public Figure 
{
    private:

	float x{};
	float y{};

    public:

	float calculate_area() const;
};

class Circle : public Figure 
{
    private:

	float x{};
	float y{};
	float radius{};

    public:

	float calculate_area() const;
};

class Rectangle : public Figure 
{
    private:

	float x{};
	float y{};

	float x2{};
	float y2{};

    public:
	float calculate_area() const;
};

class Triangle : public Figure 
{
    private:

	float x1{};
	float y1{};

	float x2{};
	float y2{};

	float x3{};
	float y3{};

    public:

	float calculate_area() const;
};

void get_area_and_insert(const Point&, std::string&);
void get_area_and_insert(const Circle&, std::string&);
void get_area_and_insert(const Rectangle&, std::string&);
void get_area_and_insert(const Triangle&, std::string&);
void divided_in_lines(const std::string& in_shapes_str, std::vector<std::string>& lines); 
std::string sort_shape_areas(const std::string& in_shapes_str);

#include "impl.hpp"
#endif