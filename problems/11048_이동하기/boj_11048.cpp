#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;

    vector<vector<int>> candy_maze(N + 1, vector<int>(M+1));
    vector<vector<int>> dp_table(N + 1, vector<int>(M+1));

    for(int n = 1; n <= N; n++)
        for(int m = 1; m <= M; m++)
            cin >> candy_maze[n][m];
    
    
    for(int n = 1; n <= N; n++)
        for(int m = 1; m <= M; m++)
        {
            if(n==1 && m ==1) 
            {
                dp_table[1][1] = candy_maze[1][1];
            }
            else
            {
                int temp = 0;

                if(n > 1)           temp = dp_table[n-1][m];
                if(m > 1)           temp = max(temp, dp_table[n][m-1]);
                if(m > 1 && m > 1)  temp = max(temp, dp_table[n-1][m-1]);

                dp_table[n][m] = temp + candy_maze[n][m];
            }
        }
    
    cout << dp_table[N][M];

    return 0 ;
}
