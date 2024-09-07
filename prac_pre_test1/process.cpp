#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;
class process
{
public:
    int data;
    int arival;
    int service;
};
bool compare(const process &a, const process &b)
{
    return a.arival < b.arival;
}
int main()
{
    int n;
    cin >> n;
    vector<process> v(n); // array รับ ขนาด n
    stack<process> stack;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i].data;
        cin >> v[i].arival;
        cin >> v[i].service;
    }
    sort(v.begin(), v.end(), compare);
    stack.push(v[0]);
    int round = 0;
    int count = 1;
    while (!stack.empty())
    {
        process temp = stack.top();
        stack.pop();
        int tempservicetime = temp.service;
        for (int i = 0; i < temp.service; i++)
        {
            cout << temp.data << " : " << tempservicetime << endl;
            tempservicetime--;
            round++;
            if (round == v[count].arival)
            {
                stack.push(v[count]);
                count++;
            }
        }
    }
    return 0;
}