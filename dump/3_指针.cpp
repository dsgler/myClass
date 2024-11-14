#include "iostream"
using namespace std;
int main()
{
    int *p = new int[10] {1,2,3,4,5,6,7,8,9,10};
    int *a = new int[2] {99,999};
    int *pnew = new int [12];
    int offset = 0;
    for (int i = 0;i <= 9;i++)
    {
        if( i == 1 || i == 3 )
        {
            pnew[i] = a[offset];
            offset++;
        }
        pnew[i + offset] = p[i];

    }
    delete [] p;
    int i = 0;
    while (i < 12)
    {
        cout << pnew[i] << endl;
        i++;
    }
    delete [] pnew;
    return 0;
}