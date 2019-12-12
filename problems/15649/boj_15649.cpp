#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> permutation;
vector<int> visited;

int N;
int M;

void func(int n)
{
    if(n == M)
    {
        for(int e:permutation)
        {
            cout << e << " ";
        }
        cout << "\n";
        return ;
    }

    for(int i = 1; i <= N; i++)
    {
        if(visited[i] == false)
        {
            visited[i] = true;
            permutation[n] = i;
            func(n+1);
            visited[i] = false;
        }
    }
}

int main()
{
    cin >> N >> M;

    visited.resize(N+1, false);
    permutation.resize(M, 0);

    func(0);

    return 0;
}
