#include <iostream>
#include <string>

using namespace std;

class Loser
{
    private:
        int k;
        int *loser;
    public:
        Loser(string *R, int sz)
        {
            k = sz;
            int winner, l;
            loser = new int [k];
            for (int i = 0; i < k; i++) loser[i] = -1;

            int j = k;
            int i;
            for (i = k-1; i >= k/2 && j != 1; i--)
            {
                if (R[j] > R[j-1])
                {
                    loser[i] = j;
                    winner = j - 1;
                }
                else{
                    loser[i] = j-1;
                    winner = j;
                }
                j -= 2;
				l = i/2;
                while (loser[l] != -1)
                {
                    if (R[loser[l]] < R[winner])
                    {
                        int temp = winner;
                        winner = loser[l];
                        loser[l] = temp;
                    }
                    l /= 2;
                }
                loser[l] = winner;
            }
            if (j == 1)
            {
                winner = 1;
                l = k/2;

                while (loser[l] != -1)
                {
                    if (R[loser[l]] < R[winner])
                    {
                        int temp = winner;
                        winner = loser[l];
                        loser[l] = temp;
                    }
                    l /= 2;
                }
                loser[l] = winner;
            }
        }
        ~Loser() { delete[] loser; }

        void print(string *R)
        {
            for (int i = 0; i < k; i++)
                cout << i << " : " << R[loser[i]] << endl;
        }
};

int main()
{
    string *arr;
    int num;

    cout << "write people num: ";
    cin >> num; 
    arr = new string[num + 1];
    cout << "write names" << endl;
    for (int i = 1; i<num + 1; i++)
        cin >> arr[i];
    Loser loser(arr, num);
    loser.print(arr);
    delete[] arr;
    return 0;
}