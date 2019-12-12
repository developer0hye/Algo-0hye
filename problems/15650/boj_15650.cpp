#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> permutation;
vector<int> visited;

int N;
int M;

void func(int min, int n)
{
    if(n == M)
    {
        for(int e:permutation)
            cout << e << " ";
        cout << "\n";
        return ;
    }

    for(int i = min; i <= N; i++)
    {
        if(visited[i] == false)
        {
            visited[i] = true;
            permutation[n] = i;
            func(i+1, n+1);
            visited[i] = false;
        }
    }
}

int main()
{
    cin >> N >> M;

    visited.resize(N+1, false);
    permutation.resize(M, 0);

    func(1, 0);

    return 0;
}
