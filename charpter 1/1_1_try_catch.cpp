#include <iostream>
using namespace std;

int DivZero(int a, int b, int c)
{
    if (a <= 0 || b <= 0 || c <= 0)
        throw "All parameters should be > 0";
    return a + b * c + b / c;
}
int main(void)
{
    try
    {
        cout << DivZero(2, 0, 4) << endl;
    }
    catch (char const* e)
    {
        cout << "The parameter to DivZero were 2, 0, and 4" << endl;
        cout << "An exception has been thrown" << endl;
        cout << e << endl;
        return 1;
    }
    return 0;
}