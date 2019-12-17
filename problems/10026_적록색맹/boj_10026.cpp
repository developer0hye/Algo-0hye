#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void dfs(const vector<vector<char>>& map, vector<vector<bool>>& visited, char c, int i, int j)
{
    if(i < 0) return;
    if(j < 0) return;
    if(i >= map.size()) return;
    if(j >= map.size()) return;
    
    if(visited[i][j] == false && map[i][j] == c)
    { 
        visited[i][j] = true;
        dfs(map, visited, c, i+1, j);
        dfs(map, visited, c, i-1, j);
        dfs(map, visited, c, i, j+1);
        dfs(map, visited, c, i, j-1);
    }
}

int nBlobs(const vector<vector<char>>& map)
{
    vector<vector<bool>> visited(map.size(), vector<bool>(map.size(), false));

    int nblobs = 0;
    for(int i = 0; i < map.size(); i++)
    {
        for(int j = 0; j < map.size(); j++)
        {
            if(visited[i][j] == false)
            {
                nblobs++;
                dfs(map, visited, map[i][j], i, j);
            }
        }
    }

    return nblobs;
}

int main()
{
    // 있으면 문제 틀림
    // ios_base::sync_with_stdio(false);
	// cin.tie(0);
	// cout.tie(0);
    
    int N;
    cin >> N;
    
    vector<vector<char>> map(N, vector<char>(N));
    vector<vector<char>> color_blindness_map(N, vector<char>(N));

    for(int i = 0; i < N; i++)
    {
        scanf("%s", &map[i][0]);
        for(int j = 0; j < N; j++)
            color_blindness_map[i][j] = (map[i][j] == 'G')? 'R': map[i][j]; //색맹이면 G 를 R 로 판단
    }

    cout << nBlobs(map) << " " << nBlobs(color_blindness_map) << endl;

    return 0;
}
