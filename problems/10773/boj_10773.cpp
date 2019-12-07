#include <iostream>
#include <stack>

using namespace std;

int main()
{
    int k;
    cin >> k;

    stack<int> s;

    for(int i = 0; i < k; i++)
    {
        int n;
        cin >> n;

        if(n==0)
            s.pop();
        else
            s.push(n);
    }

    int sum = 0;

    while(!s.empty())
    {
        sum += s.top();
        s.pop();
    }

    cout << sum << endl;
    
    return 0;
}
