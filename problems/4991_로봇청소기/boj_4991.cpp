#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef pair<int, int> point; // (y, x)

int W, H;
unsigned char room[20][20];
int local_minimum_distance_matrix[11][11];
bool visited[11] = {false};

const int INF = 1e5;

const int dy[4] = {1, -1, 0, 0};
const int dx[4] = {0, 0, 1, -1};

int global_minimum_distance = INF;
int num_destinations = 0;

int get_local_minimum_distance_bfs(point source, point destination)
{
    queue<pair<int, int>> robot_position_queue;
    robot_position_queue.push(source);

    int dp[20][20] = {0};

    for(int y = 0; y < H; y++)
        for(int x = 0; x < W; x++)
            dp[y][x] = INF;

    dp[source.first][source.second] = 0;

    while(!robot_position_queue.empty())
    {
        point cur = robot_position_queue.front();
        robot_position_queue.pop();
        for(int i = 0; i < 4; i++)
        {
            int ny = cur.first + dy[i];
            int nx = cur.second + dx[i];

            if(ny < 0 or ny >= H)continue;
            if(nx < 0 or nx >= W)continue;

            if(room[ny][nx] != 'x')
            {
                if(dp[ny][nx] > dp[cur.first][cur.second] + 1)
                {
                    dp[ny][nx] = dp[cur.first][cur.second] + 1;

                    if(ny == destination.first and nx == destination.second) continue;
                    robot_position_queue.push({ny, nx});
                }
            }
        }
    }

    return dp[destination.first][destination.second];
}


void get_global_minimum_distance_dfs(int distance, int i, int level)
{   
    if(level == num_destinations-1)
    {
        global_minimum_distance = min(global_minimum_distance, distance);
        return;
    }

    for(int j = 1; j < num_destinations; j++)
    {
        if(i != j and not visited[j])
        {
            if(global_minimum_distance > distance + local_minimum_distance_matrix[i][j])
            {
                visited[i] = true;
                get_global_minimum_distance_dfs(distance + local_minimum_distance_matrix[i][j], j, level + 1);
                visited[i] = false;
            }
        }
    }
}

int main()
{
    while(true)
    {
        cin >> W >> H;
        if(W == 0 and H == 0) break;

        pair<int, int> robot_initial_point;
        deque<pair<int, int>> destination_points;

        for(int y = 0; y < H; y++)
        {
            for(int x = 0; x < W; x++)
            {
                cin >> room[y][x];
                if(room[y][x] == 'o') robot_initial_point = {y ,x};
                else if(room[y][x] == '*') destination_points.push_back({y, x});
            }
        }

        destination_points.push_front(robot_initial_point);
        num_destinations = destination_points.size();

        bool answer_is_defined = true;

        for(int i = 0; i < num_destinations & answer_is_defined; i++)
        {
            local_minimum_distance_matrix[i][i] = 0;
            for(int j = i; j < num_destinations & answer_is_defined; j++)
            {
                local_minimum_distance_matrix[i][j] = get_local_minimum_distance_bfs(destination_points[i], destination_points[j]);
                local_minimum_distance_matrix[j][i] = local_minimum_distance_matrix[i][j];

                if(local_minimum_distance_matrix[i][j] == INF) answer_is_defined = false;
            }
        }

        if(not answer_is_defined) cout << -1 << endl;
        else
        {
            global_minimum_distance = INF;
            get_global_minimum_distance_dfs(0, 0, 0);
            cout << global_minimum_distance << endl;
        }
    }
    return 0;
}
