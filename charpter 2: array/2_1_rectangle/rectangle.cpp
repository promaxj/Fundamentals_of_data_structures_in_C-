#include <iostream>
#include "rectangle.h"
using namespace std;

int main(void)
{
    rectangle r(1, 2), s(5, 6);
    rectangle *t = &s;

    if (r.get_height() * r.get_width() > t->get_height() * t->get_width())
    {
        cout << " r ";
    }
    else
    {
        cout << " s ";
    }
    cout << "has the greater area" << endl;
}