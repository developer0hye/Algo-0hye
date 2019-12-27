#include <iostream>
#include <vector>
#include <cstdint>
#include <algorithm>
using namespace std;

int main()
{
    const int dir[3] = {-1, 0, 1};
    int N, M;
    int min_fuel_cost;
    cin >> N >> M;

    vector<vector<int>> fuel_cost_map(N+1, vector<int>(M+2));
    vector<vector<vector<int>>> dp(N+1, std::vector<std::vector<int>>(M+2, std::vector<int>(3, 1e9)));
    //dp[i][j][k] (i, j) 위치에 K 방향으로 도달하는데 필요한 최소 연료 비용
    for(int n = 1; n <= N; n++)
        for(int m = 1; m <= M; m++)
            cin >> fuel_cost_map[n][m];

    for(int m = 1; m <= M; m++)
        dp[1][m][0] = dp[1][m][1] = dp[1][m][2] = fuel_cost_map[1][m];

    for(int n = 1; n <= N-1; n++)
        for(int m = 1; m <= M; m++)
            for(int prev_dir = 0; prev_dir < 3; prev_dir++)
                for(int next_dir = 0; next_dir < 3; next_dir++)
                {
                    if(next_dir == prev_dir) continue;
                    int nm = m+dir[next_dir];
                    dp[n+1][nm][next_dir] = min(dp[n][m][prev_dir] + fuel_cost_map[n+1][nm], dp[n+1][nm][next_dir]);
                }

    min_fuel_cost = 1e9;
    for(int m = 1; m <= M; m++)
        for(int i = 0; i < 3; i++)
            min_fuel_cost = min(min_fuel_cost, dp[N][m][i]);
    cout << min_fuel_cost;

    return 0;
}
