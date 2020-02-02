#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int N, L;
    cin >> N >> L;
    
    vector<vector<int>> map(N, vector<int>(N));
    vector<bool> stair_is_installed(N, false);

    for(int i = 0; i < N; i++)for(int j = 0; j < N; j++)cin>>map[i][j];

    int nWay = 0;

    //check horizontal road
    for(int i = 0; i < N; i++)
    {
        bool isRoad = true;
        int previous_step_height = map[i][0];
        
        std::fill(stair_is_installed.begin(), stair_is_installed.end(), false);
        for(int j = 1; j < N; j++)
        {
            int d_height = map[i][j]-previous_step_height;
            previous_step_height = map[i][j];
            if(d_height==1)//오르막 길
            {
                if(j-L < 0)// 경사로를 놓다가 범위를 벗어나는 경우
                {
                    isRoad = false;
                    break;
                }

                const int stair_floor_height = map[i][j-1];
                for(int j_stair = j-1; j_stair >= j-L; j_stair--)
                {
                    if(map[i][j_stair] != stair_floor_height) // 낮은 지점의 칸의 높이가 모두 같지 않거나, L개가 연속되지 않은 경우
                    {
                        isRoad=false;
                        break;
                    }
                    if(stair_is_installed[j_stair] == false) //경사로를 놓을 수 있는지 확인
                        stair_is_installed[j_stair] = true;
                    else //이미 경사로가 설치되어 있음
                    {
                        isRoad = false;
                        break;
                    }
                }
            }
            else if(d_height==-1)//내리막 길
            {
                if(j+L-1 > N-1){isRoad = false; continue;}// 경사로를 놓다가 범위를 벗어나는 경우

                const int stair_floor_height = map[i][j];
                for(int j_stair = j; j_stair <= j+L-1; j_stair++)
                {
                    if(map[i][j_stair] != stair_floor_height) // 낮은 지점의 칸의 높이가 모두 같지 않거나, L개가 연속되지 않은 경우
                    {
                        isRoad=false;
                        break;
                    }

                    if(stair_is_installed[j_stair] == false) //경사로를 놓을 수 있는지 확인
                        stair_is_installed[j_stair] = true;
                    else //이미 경사로가 설치되어 있음
                    {
                        isRoad = false;
                        break;
                    }
                }
            }
            else if(abs(d_height) > 1) // 낮은 칸과 높은 칸의 높이 차이가 1이 아닌 경우
            {
                isRoad = false;
                break;
            }
        }
        if(isRoad)
        {
            nWay++;
        }
    }

    //check vertical road
    for(int j = 0; j < N; j++)
    {
        bool isRoad = true;
        int previous_step_height = map[0][j];
        
        std::fill(stair_is_installed.begin(), stair_is_installed.end(), false);
        for(int i = 1; i < N; i++)
        {
            int d_height = map[i][j]-previous_step_height;
            previous_step_height = map[i][j];
            if(d_height==1)//오르막 길
            {
                if(i-L < 0)// 경사로를 놓다가 범위를 벗어나는 경우
                {
                    isRoad = false;
                    break;
                }

                const int stair_floor_height = map[i-1][j];
                for(int i_stair = i-1; i_stair >= i-L; i_stair--)
                {
                    if(map[i_stair][j] != stair_floor_height) // 낮은 지점의 칸의 높이가 모두 같지 않거나, L개가 연속되지 않은 경우
                    {
                        isRoad=false;
                        break;
                    }
                    if(stair_is_installed[i_stair] == false) //경사로를 놓을 수 있는지 확인
                        stair_is_installed[i_stair] = true;
                    else //이미 경사로가 설치되어 있음
                    {
                        isRoad = false;
                        break;
                    }
                }
            }
            else if(d_height==-1)//내리막 길
            {
                if(i+L-1 > N-1){isRoad = false; continue;}// 경사로를 놓다가 범위를 벗어나는 경우

                const int stair_floor_height = map[i][j];
                for(int i_stair = i; i_stair <= i+L-1; i_stair++)
                {
                    if(map[i_stair][j] != stair_floor_height) // 낮은 지점의 칸의 높이가 모두 같지 않거나, L개가 연속되지 않은 경우
                    {
                        isRoad=false;
                        break;
                    }
                    if(stair_is_installed[i_stair] == false) //경사로를 놓을 수 있는지 확인
                        stair_is_installed[i_stair] = true;
                    else //이미 경사로가 설치되어 있음
                    {
                        isRoad = false;
                        break;
                    }
                }
            }
            else if(abs(d_height) > 1) // 낮은 칸과 높은 칸의 높이 차이가 1이 아닌 경우
            {
                isRoad = false;
                break;
            }
        }

        if(isRoad)
        {
            nWay++;
        }
    }

    cout << nWay;

    return 0;
}
