#include <iostream>
#include <queue>

using namespace std;

int main()
{
    int N, K;
    cin >> N >> K;
    queue<int> q;
    queue<int> josephus;

    for(int i = 1; i <= N; i++) q.push(i);

    int i = 0;
    while(!q.empty())
    {
        i++;
        int n = q.front();
        q.pop();

        if(i == K || q.size() == 0)
        {
            i = 0;
            josephus.push(n);
        }
        else
        {
            q.push(n);
        }
    }

    //출력
    cout << "<";
    while(!josephus.empty())
    {
        int n = josephus.front();
        cout << n;
        if (josephus.size() != 1) cout << ", ";
        josephus.pop();
    }
    cout << ">" << endl;
    return 0;
}
