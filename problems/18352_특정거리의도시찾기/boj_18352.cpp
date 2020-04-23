#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N; //도시의 개수 
int M; //도로의 개수
int K; //거리 정보
int X; //출발 도시 번호

//출발 도시 X 로 부터 *최단 거리*가 K인 도시의 번호를 하나씩 오름차순으로 출력 

vector<vector<int>> g;
vector<int> minimum_distance; // [i]: 출발 도시 K 부터 i 까지의 거리
vector<int> answers;

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> K >> X;

    g = vector<vector<int>>(N+1);
    minimum_distance = vector<int>(N+1, 1e8);

    for(int i = 0; i < M; i++)
    {
        int cityA, cityB;
        cin >> cityA >> cityB;

        g[cityA].push_back(cityB);
    }

    queue<int> city_queue;//FIFO
    city_queue.push(X);
    minimum_distance[X] = 0;

    while(!city_queue.empty())
    {
        int city = city_queue.front();
        city_queue.pop();

        for(int neighbor_city:g[city])
        {
            if(minimum_distance[neighbor_city] > minimum_distance[city] + 1)
            {
                minimum_distance[neighbor_city] = minimum_distance[city] + 1;
                city_queue.push(neighbor_city);
            }
        }
    }

    for(int i = 1; i < minimum_distance.size(); i++)
    {
        if(minimum_distance[i] == K)
        {
            answers.push_back(i);
        }
    }

    if(answers.size()==0) 
    {
        cout << -1;
    }
    else
    {
        for(int answer:answers)
        {
            cout << answer << endl;
        }
    }
    
    return 0;
}


