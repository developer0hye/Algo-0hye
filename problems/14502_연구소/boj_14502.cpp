#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;
vector<vector<int>> initial_map;
vector<vector<bool>> initial_visited_map;
vector<pair<int, int>> wall_position_candidates; //(y, x)
queue<pair<int, int>> initial_virus_position; //(y, x)

pair<int, int> built_walls[3];
int max_safe_area_size = 0;

void dfs_build_wall(int search_idx, int built_wall_number)
{
    if(built_wall_number == 3)
    {
        vector<vector<int>> map = initial_map;
        vector<vector<bool>> visited_map = initial_visited_map;
        queue<pair<int, int>> virus_position_queue = initial_virus_position;

        //벽 설치
        for(pair<int, int> wall_position:built_walls)
        {
            map[wall_position.first][wall_position.second] = 1;
        }

        //바이러스 뿌리기_bfs
        while(!virus_position_queue.empty())
        {
            pair<int, int> virus_position = virus_position_queue.front();
            virus_position_queue.pop();

            for(int dy:{-1, 1})
            {
                int ny = virus_position.first + dy; 
                if(ny >= 0 && ny <= N-1)
                {
                    if(not visited_map[ny][virus_position.second])
                    {
                        visited_map[ny][virus_position.second] = true;
                        
                        if(map[ny][virus_position.second] == 0)
                        {
                            map[ny][virus_position.second] = 2;
                            virus_position_queue.push({ny, virus_position.second});
                        }
                    }
                }
            }

            for(int dx:{-1, 1})
            {
                int nx = virus_position.second + dx; 
                if(nx >= 0 && nx <= M-1)
                {
                    if(not visited_map[virus_position.first][nx])
                    {
                        visited_map[virus_position.first][nx] = true;

                        if(map[virus_position.first][nx] == 0)
                        {
                            map[virus_position.first][nx] = 2;
                            virus_position_queue.push({virus_position.first, nx});
                        }
                    }
                }
            }
        }

        int safe_area_size = 0;

        for(int n = 0; n < N; n++)
            for(int m = 0; m < M; m++)
            {
                if(map[n][m] == 0) safe_area_size++;
            }
        
        max_safe_area_size = max(safe_area_size, max_safe_area_size);
        return;
    }

    for(int i = search_idx; i < wall_position_candidates.size(); i++)
    {
        built_walls[built_wall_number] = wall_position_candidates[i];
        dfs_build_wall(i+1, built_wall_number+1);
    }
}

int get_max_safe_area_size()
{
    dfs_build_wall(0, 0);
    return max_safe_area_size;
}


int main()
{
    cin >> N >> M;
    initial_map = vector<vector<int>>(N, vector<int>(M));
    initial_visited_map = vector<vector<bool>>(N, vector<bool>(M, false));

    for(int n = 0; n < N; n++)
        for(int m = 0; m < M; m++)
        {
            cin >> initial_map[n][m];
            if(initial_map[n][m] == 0) wall_position_candidates.push_back({n,m});
            else if(initial_map[n][m] == 2) initial_virus_position.push({n, m});
        }

    cout << get_max_safe_area_size();
    return 0;
}
