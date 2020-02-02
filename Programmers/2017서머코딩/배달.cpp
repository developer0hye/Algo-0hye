#include <iostream>
#include <vector>
using namespace std;

vector<vector<pair<int,int>>> g_road;
vector<pair<bool, int>> visited;
int g_K;
int g_answer;

void dfs(int src, int prev_src, int cumulative_distance){
    if(cumulative_distance <= g_K)  
    {
        if(visited[src].first==false)
        {
            visited[src].first=true;
            visited[src].second=cumulative_distance;
            g_answer++;
        }
        else
        {
            if(visited[src].second <= cumulative_distance) return;
            else visited[src].second = cumulative_distance;
        }
    }
    else if(cumulative_distance >= g_K) //이 마을 이후에 방문하는 마을은 모두 K 보다 먼 거리에 떨어져 있으므로 탐색 중지
    {
        return; 
    }
    
    for(int i = 0; i < g_road[src].size(); i++)
    {   
        int next_dst = g_road[src][i].first;
        
        if(next_dst != prev_src)
        {
            dfs(next_dst, src, cumulative_distance+g_road[src][i].second);
        }
    }
}

int solution(int N, vector<vector<int> > road, int K) {
    g_answer = 0;
    g_road = vector<vector<pair<int,int>>>(N+1);
    visited = vector<pair<bool,int>>(N+1, {false, 0});
    g_K = K;
    
    for(int i = 0; i < road.size(); i++)
    {
        int a = road[i][0];
        int b = road[i][1];
        int c = road[i][2];
        
        g_road[a].push_back({b, c});
        g_road[b].push_back({a, c});
    }
    
    dfs(1, 0, 0);

    return g_answer;
}
