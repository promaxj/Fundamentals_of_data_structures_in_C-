#include <iostream>
#include <ctime>
using namespace std;
int sequential_search(int *a, const int n, const int x)
{
    int i;
    for (i = 0; i < n && a[i] != x; i++)
        ;
    if (i == n)
        return -1;
    else
        return i;
}
void TimeSearch()
{
    int a[1001], n[20], j;
    for (j = 1; j <= 1000; j++)
    {
        a[j] = j;
    }
    for (j = 0; j < 10; j++)
    {
        n[j] = 10 * j;
        n[j + 10] = 100 * (j + 1);
    }
    cout << "\tn\ttime" << endl;
    for (j = 0; j < 20; j++)
    {
        long *start, *stop;
        time(start);
        long k = sequential_search(a, n[j], 0);
        time(stop);
        long run_time = stop - start;
        cout << "\t" << n[j] << "\t" << run_time << endl;
    }
    cout << "Times are in hundredths of a second." << endl;
}

int main(void)
{
    TimeSearch();
    return 0;
}
