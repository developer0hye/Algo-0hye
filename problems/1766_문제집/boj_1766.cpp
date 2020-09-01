#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main()
{
    int N; //문제의 수(1<= N <= 32000)
    int M; //먼저 푸는 것이 좋은 문제에 대한 정보의 개수(1<= M <= 100000)

    cin >> N >> M;

    vector<vector<int>> g(N+1);
    priority_queue<int, vector<int>, greater<int>> q;//우선순위큐(FIFO), 내림차순
    vector<int> indegree(N+1, 0);
    
    // p_a 번 문제는 p_b 번 문제보다 먼저 푸는 것이 좋다. 정보를 그래프로 나타냄
    for(int i = 0; i < M; i++)
    {
        int p_a;
        int p_b;

        cin >> p_a >> p_b;
        g[p_a].push_back(p_b);//from: p_a, to: p_b
        indegree[p_b]++;
    }

    for(int i = 1; i <= N; i++)
        if(indegree[i]==0)
            q.push(i);
    
    while(!q.empty())
    {
        int problem = q.top();
        q.pop();
        cout << problem <<" ";

        for(auto next_problem:g[problem])
        {
            indegree[next_problem] -= 1;
            if(indegree[next_problem] == 0)
                q.push(next_problem);
        }
    }

    return 0;
}
