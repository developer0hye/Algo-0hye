#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int cnt_virus_com_by_dfs(vector<vector<int>>& graph)
{
    int virus_cum = 0;
    
    vector<bool> visited(graph.size(), false);
    queue<int> computers;
    computers.push(1);

    while(!computers.empty())
    {
        int com_num = computers.front();
        computers.pop();
        visited[com_num] = true;
    
        for(int computer: graph[com_num])
        {
            if(visited[computer] == false)
            {
                visited[computer] = true;
                computers.push(computer);
                virus_cum++;
            }
        }
    }
    
    return virus_cum;
}
int main()
{
    int N, C;
    cin >> N >> C;

    vector<vector<int>> graph;
    graph.resize(N + 1);

    for(int i = 0; i < C; i++)
    {
        int com1, com2;

        cin >> com1 >> com2;
        graph[com1].push_back(com2);
        graph[com2].push_back(com1);
    }

    cout << cnt_virus_com_by_dfs(graph) << endl;

    return 0;
}
