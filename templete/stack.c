#include<iostream>
#include<vector>
#include<stack>

using namespace std;

int main()
{
    stack<int> initStack;

    initStack.push(100);
    for(int i = 0;i<10;i++)
    {
        initStack.push(i);
    }
    int a = initStack.top();
    cout << "stack size:" << initStack.size() << endl;
    initStack.pop();
    cout << "stack size:" << initStack.size() << endl;
    cout << "top:" << a << endl;
    cout << "is empty:?" << initStack.empty();

    return 0;
}
