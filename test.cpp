#include <iostream>

using namespace std;

int main()
{
    int num;

    while (true)
    {
        cout << "insert num: ";
        cin >> num;
        if (num == -1)
            break;
        cout << 3 + ((num % 5) / 3) - (num / 5) << endl;
    }
    return 0;
}