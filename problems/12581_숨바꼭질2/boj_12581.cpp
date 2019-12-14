#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main()
{
    int N, K;
    cin >> N >> K;

    int time[(int)(1e5)+1] = {0,}; //time[i] = i 위치에 도달하는데 걸린 최소 시간
    bool visited[(int)(1e5)+1] = {false,};

    queue<int> q;
    q.push(N);
    while(!q.empty())
    {
        int pos = q.front();
        q.pop();

        if(pos == K) break;
        if(visited[pos] == true) continue;
        
        visited[pos] = true;
        
        for(int new_pos:{pos-1, pos+1, pos*2})
        {
            if(new_pos < 0 || new_pos > 1e5) continue;
            
            if(visited[new_pos] == false && time[new_pos] == 0) 
            {
                q.push(new_pos);
                time[new_pos] = time[pos] + 1;
            }
        }
    }
    cout << time[K] << "\n";
    return 0 ;
}
