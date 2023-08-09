#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    int *arr, *grade;
    int num, n1, n2;
    
    cin >> num;
    arr = new int[num];
    grade = new int[num];
    memset(arr, 0, sizeof(int)*num);
    memset(grade, 0, sizeof(int)*num);
    grade[0] = 1;
    for (int i = 0; i < num - 1; i++)
    {
        cin >> n1 >> n2;
        if (grade[n1 - 1] == 0 && grade[n2 - 1] == 0)
        {
            arr[n1 - 1] = n2;
            arr[n2 - 1] = n1;
        }
        else if (grade[n1 - 1])
        {
            grade[n2 - 1] = grade[n1 - 1] + 1;
            if (arr[n2 - 1])
                grade[arr[n2 - 1] - 1] = grade[n2 - 1] + 1;
            arr[n2 - 1] = n1;
        }
        else
        {
            grade[n1 - 1] = grade[n2 - 1] + 1;
            if (arr[n1 - 1])
                grade[arr[n1 - 1] - 1] = grade[n1 - 1] + 1;
            arr[n1 - 1] = n2;
        }
    }
    for (int i = 1; i < num; i++)
        cout << arr[i] << '\n';
    return 0;
}