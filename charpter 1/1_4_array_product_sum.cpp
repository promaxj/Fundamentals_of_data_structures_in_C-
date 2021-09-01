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

    print_array(array, len);
}
void generate_list(int *array, unsigned int len)
{

    // cout << "array length is " << len << ", and value is 0~1000:" << endl;
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
    // print_array(array, len);
}
int product(int *a, int n)
{
    int initVal = 1;
    return accumulate(a, a + n, initVal, multiplies<int>());
}
int main(void)
{
    unsigned int array_len, search_num;

    // cout << "please enter a num for array length" << endl;
    // cin >> array_len;
    array_len = 5;
    int *a = new int[array_len];
    generate_list(a, array_len);
    cout << "sorting array:" << endl;
    selection_sort(a, array_len);
    cout << "product of array element: " << product(a, array_len) << endl;
    delete[] a;
    return 0;
}