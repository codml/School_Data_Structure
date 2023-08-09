#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    int *arr;
    int num, n1, n2;
    
    cin >> num;
    arr = new int[num];
    memset(arr, 0, sizeof(int)*num);
    arr[0] = 1;
    for (int i = 0; i < num - 1; i++)
    {
        cin >> n1 >> n2;
        if (!arr[n1 - 1])
            arr[n1 - 1] = n2;
        if (!arr[n2 - 1])
            arr[n2 - 1] = n1;
    }
    for (int i = 1; i < num; i++)
        cout << arr[i] << endl;
    return 0;
}