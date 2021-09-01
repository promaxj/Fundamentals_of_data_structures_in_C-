//1.6 the standard template library
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <numeric>
using namespace std;
void print_array(int *array, unsigned int len)
{
    for (int i = 0; i < len; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}
void selection_sort(int *array, int len)
{
    int min;
    for (int i = 0; i < len - 1; i++)
    {
        min = i;
        for (int j = i + 1; j < len; j++)
        {
            if (array[j] < array[min])
            {
                min = j;
            }
        }
        swap(array[i], array[min]);
    }

    // print_array(array, len);
}
void generate_list(int *array, unsigned int len)
{

    srand(time(NULL));
    for (int i = 0; i < len; i++)
    {
        array[i] = rand() % 10 + 1; // rand()%(max_value-min_value+1)+ min_value  and put this value to list

        for (int j = 0; j < i; j++) //compare value is it exist before?
        {
            if (array[i] == array[j]) //if value is exist before
            {
                i--;
                break;
            }
        }
    }
}
void permutations(unsigned char *a, const int m)
{
    do
    {
        copy(a, a + m, ostream_iterator<char>(cout, " "));
        cout << endl;
    } while (next_permutation(a, a + m));
}
int main(void)
{
    unsigned int array_len, search_num;

    // cout << "please enter a num for array length" << endl;
    // cin >> array_len;
    array_len = 3;
    int *a = new int[array_len];
    unsigned char *b = new unsigned char[array_len];
    generate_list(a, array_len);
    // cout << "sorting array:";
    selection_sort(a, array_len);
    cout << "array element is: ";
    for (int i = 0; i < array_len; i++)
    {
        b[i] = a[i] % 26 + 96;
        cout << b[i] << " ";
    }
    cout << endl
         << "permutations: " << endl;
    permutations(b, array_len);
    delete[] a;
    delete[] b;
    return 0;
}