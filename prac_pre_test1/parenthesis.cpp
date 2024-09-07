#include <stack>
#include <iostream>
using namespace std;

int main()
{
    stack<char> stack;
    string s;
    getline(cin, s);

    int count = 0;

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(' || s[i] == '{' || s[i] == '<' || s[i] == '[')
        {
            stack.push(s[i]);
        }
        if (s[i] == ')' || s[i] == '}' || s[i] == '>' || s[i] == ']')
        {
            if (s[i] == '>' && s[i + 1] == '>')
            {
                stack.pop();
                stack.pop();
                i++;
            }
            else
            {
                stack.pop();
            }
            count++;
        }
    }
    if (!stack.empty())
    {
        cout << "not matched" << endl;
    }
    cout << "match : " << count;
}