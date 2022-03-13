#ifndef RECTANGLE_H
#define RECTANGLE_H

class Rectangle
{
private:
    double length;
    double width;

public:
    Rectangle(double, double);
    double getLength() const;
    double getWidth() const;
};

Rectangle::Rectangle(double l, double w)
{
    length = l;
    width = w;
}

double Rectangle::getWidth() const { return width; }
double Rectangle::getLength() const { return length; }

#endif