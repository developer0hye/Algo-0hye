#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> map;
vector<vector<bool>> visited;
int area;

void labeling(int x, int y)
{
    if( y >= map.size() ) return;
    if( y < 0 ) return;
    if( x >= map[0].size() ) return;
    if( x < 0 ) return;

    if( visited[y][x] ) return;

    visited[y][x] = true;

    if(map[y][x] == true)
    {
        area++;
        labeling(x + 1, y);
        labeling(x - 1, y);
        labeling(x, y + 1);
        labeling(x, y - 1);
    }
}

int main()
{
    int L;
    cin >> L;

    map.resize(L);
    for(int i = 0; i < L; i++)map[i].resize(L, false);

    visited.resize(L);
    for(int i = 0; i < L; i++)visited[i].resize(L, false);

    for(int y = 0;  y < L; y++)
        for(int x = 0;  x < L; x++)
            scanf("%1d", &map[y][x]);

    vector<int> areas;

    for(int y = 0; y < map.size(); y++)
        for(int x = 0; x < map[0].size(); x++)
        {
            if(map[y][x] && !visited[y][x])
            {
                area = 0;
                labeling(x, y);
                areas.push_back(area);
            }
        }

    cout << areas.size() << "\n";
    sort(areas.begin(), areas.end());
    for(int a:areas)
        cout << a << "\n";

    return 0;
}
