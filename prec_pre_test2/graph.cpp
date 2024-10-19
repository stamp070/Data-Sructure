#include <iostream>
#include <stack>
#include <queue>
using namespace std;
class graph
{
public:
    int arry[100][100];
    int iter;
    graph(int n)
    {
        iter = n;
        for (int i = 0; i < 100; i++)
        {
            for (int j = 0; j < 100; j++)
            {
                arry[i][j] = 0;
            }
        }
    }
    void addEdge(int i, int j, int data)
    {
        arry[i][j] = data;
        arry[j][i] = data;
    }
    void bft(int start)
    {
        bool visited[100] = {false};
        queue<int> q;
        q.push(start);
        visited[start] = true;

        while (!q.empty())
        {
            int node = q.front();
            q.pop();

            cout << node << " ";
            for (int i = 0; i < iter; i++)
            {
                if (arry[node][i] != 0 && !visited[i])
                {
                    visited[i] = true;
                    q.push(i);
                }
            }
        }
    }
    void dft(int start)
    {
        bool visited[100] = {false};
        stack<int> s;
        s.push(start);

        while (!s.empty())
        {
            int node = s.top();
            s.pop();

            if (!visited[node])
            {
                cout << node << " ";
                visited[node] = true;

                for (int i = maxnode - 1; i >= 0; i--)
                {
                    if (arry[node][i] != 0 && !visited[i])
                    {
                        s.push(i);
                    }
                }
            }
        }
    }
};
int main()
{
    graph g(5);

    g.addEdge(0, 1, 1);
    g.addEdge(0, 2, 1);
    g.addEdge(1, 2, 1);
    g.addEdge(1, 3, 1);
    g.addEdge(2, 3, 1);
    g.addEdge(2, 4, 1);

    cout << "Breadth-First Traversal\n";
    g.bft(0);
    cout << endl;

    cout << "Depth-First Traversal\n";
    g.dft(0);

    return 0;
}
