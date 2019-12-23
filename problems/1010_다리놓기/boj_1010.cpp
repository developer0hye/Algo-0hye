#include <iostream>
#include <vector>
using namespace std;

int memo[31][31] = {0,};

int dp(int n, int m)
{
    if(n==m) return 1;
    if(n==1) return m;
    if(memo[n][m] != 0) return memo[n][m];
    return memo[n][m] = dp(n-1, m-1) + dp(n, m-1);
}

int main()
{    
    int T;
    cin >> T;
    for(int t = 0; t < T; t++)
    {
        int N, M;
        cin >> N >> M; // N <= M
        cout <<dp(N, M) << "\n";
    }

    return 0;
}
