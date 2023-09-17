#include <iostream>
#include <stack>
#include <queue>

using namespace std;

int main()
{
    int num;
    int cur_num;
    int len;
    int flag;
    stack<int> stack;
    queue<char> queue;
    
    scanf("%d", &num);
    len = num;
    cur_num = 1;
    flag = 0;
    for (int i = 0; i < len; i++)
    {
        scanf("%d", &num);
        if (!flag)
        {
            if (num >= cur_num || (!stack.empty() && stack.top() == num))
            {
                while (num >= cur_num)
                {
                    stack.push(cur_num++);
                    queue.push('+');
                }
                stack.pop();
                queue.push('-');
            }
            else
                flag = 1;
        }
    }
    if (flag)
        printf("NO\n");
    else
    {
        while (!queue.empty())
        {
            printf("%c\n", queue.front());
            queue.pop();
        }
    }
    return 0;
}