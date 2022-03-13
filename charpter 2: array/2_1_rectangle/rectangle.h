#ifndef RECTANGLE_H
#define RECTANGLE_H
class rectangle
{
public:
    // rectangle();
    rectangle(int, int);
    // ~rectangle();
    int get_height();
    int get_width();

private:
    int height, width;
};
int rectangle::get_height() { return height; }
int rectangle::get_width() { return width; }
rectangle::rectangle(int h, int w)
{
    height = h;
    width = w;
}
#endif
