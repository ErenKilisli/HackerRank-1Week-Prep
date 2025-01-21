#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> Enqueue(vector<int>& queue, int n)
{
    queue.push_back(n);  

    return queue;
}

vector<int> Dequeue(vector<int>& queue) 
{
    queue.erase(queue.begin());

    return queue;
}

void print (vector<int>& queue) 
{
    if (!queue.empty()) {
        cout << queue.front() << endl; 
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int input;
    std::cin >> input;
    
    vector<int> queue;
    for (int i = 0; i < input; i++) 
    {
        int type;
        std::cin >> type;
        if(type == 1) 
        {
            int x;
            cin >> x;
            Enqueue(queue, x);
        }
        else if (type == 2) 
        {
            Dequeue(queue);
        }
        else if (type == 3)
        {
            print(queue);
        }
    }
    
    return 0;
}
