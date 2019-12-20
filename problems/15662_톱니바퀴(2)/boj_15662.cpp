#include <iostream>
#include <vector>
using namespace std;

void Rotation(vector<vector<int>>& gears, int n, int dir)
{
    if(dir == 0) return;

    vector<int> gears_copy = gears[n];

    if(dir == 1) // 시계 방향
    {
        for(int i = 0; i < 8; i++)
        {
            gears[n][(i+1)%8] = gears_copy[i];
        } 
    }
    else if(dir == -1) // 반시계 방향
    {
        for(int i = 0; i < 8; i++)
        {
            gears[n][i] = gears_copy[(i+1)%8];
        }
    }
}

int main()
{
    int T;
    cin >> T;
    
    vector<vector<int>> gears(T+1, vector<int>(8));
    for(int i = 1; i <= T; i++)
        for(int j = 0; j < 8; j++)
            scanf("%1d", &gears[i][j]);

    int K;
    cin >> K;
    for(int i = 0; i < K; i++)
    {
        int n, dir;
        cin >> n >> dir;
        
        vector<int> rot_tab(T+1, 0);
        rot_tab[n] = dir;
        
        //n to 1
        int most_recent_dir = dir;
        for(int g = n-1; g >= 1; g--)
        {
            if(gears[g+1][6] != gears[g][2])
            {
                most_recent_dir = (most_recent_dir == 1)? -1: 1;
                rot_tab[g] = most_recent_dir;
            }
            else break;
        }

        //n to T
        most_recent_dir = dir;
        for(int g = n+1; g <= T; g++)
        {
            if(gears[g-1][2] != gears[g][6])
            {
                most_recent_dir = (most_recent_dir == 1)? -1: 1;
                rot_tab[g] = most_recent_dir;
            }
            else break;
        }

        for(int g = 1; g <= T; g++)
        {
            Rotation(gears, g, rot_tab[g]);
        }
    }

    //12시 방향이 S극인 톱니바퀴 개수 출력
    int nSawToothS = 0;
    for(int i = 1; i <= T; i++)
        if(gears[i][0] == 1) nSawToothS++;
    
    cout << nSawToothS;
    
    return 0;
}
