#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main()
{
    int time[(int)(1e5)+1] = {0,}; //time[i] = i 위치에 도달하는데 걸린 최소 시간
    int path[(int)(1e5)+1] = {0,}; //i 위치에 도달한 횟수
    bool visited[(int)(1e5)+1] = {false,}; //queue 에서 pop 되어 방문이 되었는지 여부

    int N, K;
    cin >> N >> K; path[N] = 1; visited[N] = true;

    queue<int> q;
    q.push(N);

    while(!q.empty())
    {
        int pos = q.front();
        q.pop();
        
        if(pos==K) break;

        for(int new_pos:{pos-1, pos+1, pos*2}) // 0 2 2
        {
            if(new_pos < 0 || new_pos > 1e5) continue;
            
            if(visited[new_pos] == false)
            {
                path[new_pos] = path[pos];
                time[new_pos] = time[pos] + 1;
                visited[new_pos] = true;
                q.push(new_pos);
            }
            else if(time[new_pos] == time[pos] + 1)
            {
                path[new_pos] += path[pos];
            }
        }
    }

    cout << time[K] << "\n";
    cout << path[K] << "\n";

    return 0 ;
}
