#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<int> dp(N+1, 0); //dp[i] = 숫자 i 가 1이 되도록 하는 최소 연산 실행 횟수
    dp[1] = 0;

    for(int i = 2; i <= N; i++)
    {
        //dp[i] = min(dp[i/2], dp[i/3], dp[i-1]) + 1
        int temp = dp[i-1];
        if(i%2 == 0) temp = min(temp, dp[i/2]);
        if(i%3 == 0) temp = min(temp, dp[i/3]);

        dp[i] = temp + 1;
    }
    cout << dp[N] << "\n";

    return 0;
}
