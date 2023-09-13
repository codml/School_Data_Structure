#include "w1_stack_cal.h"
#include <string>

string infixToPostfix(string s)
{
    Stack<char> stack(100);
    string postfixExpression = "";

    for (int i = 0; s[i]; i++)
    {
        if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || s[i] == '(' || s[i] == ')')
        {
            if (stack.isEmpty())
                stack.push(s[i]);
            else
            {
				switch (s[i])
				{
				case '(':
					stack.push(s[i]);
					break;
				
				case ')':
					while (stack.top() != '(')
						postfixExpression.push_back(stack.pop());
					stack.pop();
					break;
				
				case '+':
				case '-':
					while (stack.top() != '(')
						postfixExpression.push_back(stack.pop());
					stack.push(s[i]);
					break;
				
				case '*':
				case '/':
					while (stack.top() == '*' || stack.top() == '/')
						postfixExpression.push_back(stack.pop());
					stack.push(s[i]);
					break;
				}
            }
        }
		else
			postfixExpression.push_back(s[i]);
    }
	while (!stack.isEmpty())
		postfixExpression.push_back(stack.pop());
	return postfixExpression;
}

double calculatePostfix(string s)
{
	Stack<int> stack(100);
	char right, left;

	for (int i = 0; s[i]; i++)
	{
		if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/')
		{
			right = stack.pop();
			left = stack.pop();
			switch (s[i])
			{
			case '+':
				stack.push(left + right);
				break;
			case '-':
				stack.push(left - right);
				break;
			case '*':
				stack.push(left * right);
				break;
			case '/':
				stack.push(left / right);
				break;	
			}
		}
		else
			stack.push(s[i] - '0');
	}
	return stack.top();
}

int main()
{
	string s1;

	cin >> s1;
	cout << "result is: " << calculatePostfix(infixToPostfix(s1)) << endl;
	return 0;
}