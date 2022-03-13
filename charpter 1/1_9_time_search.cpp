#include <iostream>
#include <ctime>
#include <sys/time.h>
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
    // int a[1001], n[20], j;
    int *a = new int[1001];
    int *n = new int[20];
    int j;
    const long r[20] = {300000, 300000, 200000, 200000, 100000, 100000, 10000, 8000, 8000, 5000, 5000, 25000, 15000, 15000, 10000, 7500, 7000, 6000, 5000, 5000};
    for (j = 1; j <= 1000; j++)
        a[j] = j;
    for (j = 0; j < 10; j++)
    {
        n[j] = 10 * j;
        n[j + 10] = 100 * (j + 1);
    }
    cout << "\tn\ttotal_time\trun_time" << endl;
    for (j = 0; j < 20; j++)
    {
        timeval tim;
        gettimeofday(&tim, NULL);
        double t1 = tim.tv_usec;
        for (long b = 1; b <= r[j]; b++)
        {
            int k = sequential_search(a, n[j], 0);
        }
        gettimeofday(&tim, NULL);
        double t2 = tim.tv_usec;
        double total_time = t2 - t1;
        float run_time = (float)(total_time) / (float)(r[j]);
        cout << "\t" << n[j] << "\t" << total_time << "\t\t" << run_time << endl;
    }
    cout << "Times are in hundredths of a second." << endl;
    delete[] a;
    delete[] n;
}

int main(void)
{
    TimeSearch();
    return 0;
}