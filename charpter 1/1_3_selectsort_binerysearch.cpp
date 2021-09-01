#include <iostream>
#include <cstdlib>
#include <ctime>
#define COMPARE(x, y) ((x) < (y) ? (-1) : ((x) == (y)) ? 0 \
                                                       : 1)
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

    cout << "array length is " << len << ", and value is 1~1000:" << endl;
    srand(time(NULL));
    for (int i = 0; i < len; i++)
    {
        array[i] = rand() % 1000 + 1; // rand()%(max_value-min_value+1)+ min_value  and put this value to list

        for (int j = 0; j < i; j++) //compare value is it exist before?
        {
            if (array[i] == array[j]) //if value is exist before
            {
                i--;
                break;
            }
        }
    }
    print_array(array, len);
}
// use recursive way
int binsearch(int *array, int searchnum, int left, int right)
{
    if (left <= right)
    {
        int middle = (left + right) / 2;
        if (searchnum < array[middle])
        {
            return binsearch(array, searchnum, left, middle - 1);
        }
        else if (searchnum > array[middle])
        {
            return binsearch(array, searchnum, middle + 1, right);
        }
        else
        {
            cout << "target num is on the list no." << middle + 1 << endl;
            return 0;
        }
    }
    cout << "there is no this number!!!" << endl;
    return 0;
}
// int binsearch(int *array, int searchnum, int left, int right)
// {
//     int middle;
//     while (left <= right)
//     {
//         middle = (left + right) / 2;
//         switch (COMPARE(array[middle], searchnum))
//         {
//         case -1:
//             left = middle + 1;
//             break;
//         case 0:
//             cout << "target num is on the list no." << middle + 1 << endl;
//             return 0;
//         case 1:
//             right = middle - 1;
//         }
//     }
//     cout << "there is no this number!!!" << endl;
//     return 0;
// }
int main(void)
{
    unsigned int array_len, search_num;

    cout << "please enter a num for array length" << endl;
    cin >> array_len;
    int *a = new int[array_len];
    generate_list(a, array_len);
    cout << "After selection sorting:" << endl;
    selection_sort(a, array_len);
    cout << "find a num on array use binery search, please select a num." << endl;
    cin >> search_num;
    binsearch(a, search_num, 0, array_len);
    delete[] a;
    return 0;
}