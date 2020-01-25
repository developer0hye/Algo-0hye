#include <iostream>
#include <numeric>

using namespace std;

int main()
{
    long long N;
    cin >> N;

    long long dp[101][10] = {0,};
    // dp[i][j] 는 i 자리수의 j 로 시작하는 숫자의 계단 수
    // dp[i][j] = i-1 자리수의 j-1 로 시작하는 숫자의 계단 수 + i

    long long mod = 1000000000;

    for (int i = 0; i < 10; i++)
        dp[1][i] = 1;
    
    for (int i = 2; i <= N; i++){
        dp[i][0] = dp[i - 1][1] % mod;
        for (int j = 1; j <= 8; j++){
            dp[i][j] = dp[i - 1][j - 1]% mod + dp[i - 1][j + 1]% mod;
        }
        dp[i][9] = dp[i - 1][8] % mod;
    }

    long long sum = 0;
    for(int i = 1; i <= 9; i++)
        sum += dp[N][i]% mod;
    cout << sum% mod;

    return 0;
}
