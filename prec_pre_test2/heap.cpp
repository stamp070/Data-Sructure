#include <iostream>
using namespace std;
class heap
{
public:
    int arry[100];
    heap()
    {
        arry[0] = 0;
    }
    void push(int data)
    {
        arry[0]++;
        arry[arry[0]] = data;

        int i = arry[0];
        while (i > 1 && arry[i / 2] > arry[i])
        {
            swap(arry[i / 2], arry[i]);
            i /= 2;
        }
    }
    int Delete()
    {
        int temp = arry[1];
        arry[1] = arry[arry[0]];
        arry[0] -= 1;
        int i = 1;
        while (i <= arry[0])
        {
            int left = i * 2;
            int right = i * 2 + 1;
            if (left <= arry[0] && arry[left] < arry[i] && arry[left] <= arry[right])
            {
                swap(arry[i], arry[left]);
                i = left;
            }
            else if (right <= arry[0] && arry[right] < arry[i] && arry[right] < arry[left])
            {
                swap(arry[i], arry[right]);
                i = right;
            }
            else
            {
                break;
            }
        }
        return temp;
    }
};
int main()
{
    heap h;
    h.push(5);
    h.push(3);
    h.push(7);
    h.push(2);
    h.push(1);
    h.push(9);
    for (int i = 0; i < 6; i++)
    {
        cout << h.Delete() << " ";
    }
    return 0;
}