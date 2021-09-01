#include <iostream>
using namespace std;

void magic(const int n)
{
    const int magic_size = 51;
    int square[magic_size][magic_size], k, l;

    if ((n > magic_size) || (n < 1))
    {
        throw "Error!..n out of range!";
    }
    else if (!(n % 2))
    {
        throw "Error!..n is a even!";
    }

    for (int i = 0; i < n; i++)
    {
        fill(square[i], square[i] + n, 0);
    }
    square[0][(n - 1) / 2] = 1;

    int key = 2, i = 0;
    int j = (n - 1) / 2;
    while (key <= n * n)
    {
        if (i - 1 < 0)
        {
            k = n - 1;
        }
        else
        {
            k = i - 1;
        }
        if (j - 1 < 0)
        {
            l = n - 1;
        }
        else
        {
            l = j - 1;
        }
        if (square[k][l])
        {
            i = (i + 1) % n;
        }
        else
        {
            i = k;
            j = l;
        }
        square[i][j] = key;
        key++;
    }
    cout << "magic square of size " << n << endl;
    for (i = 0; i < n; i++)
    {
        copy(square[i], square[i] + n, ostream_iterator<int>(cout, "\t"));
        cout << endl;
    }
}
int main(void)
{
    int n;
    cout << "please enter a num, 1 <= num <= 51 and is a odd num" << endl;
    cin >> n;
    magic(n);
}