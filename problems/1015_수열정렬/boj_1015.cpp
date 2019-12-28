#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int N;
    cin >> N;

    vector<pair<int,int>> p(N);
    vector<int> answer(N); 
    
    for(int i = 0; i < N; i++)
    {
        cin >> p[i].first;
        p[i].second = i;
    }

    sort(p.begin(), p.end());
    
    for(int i = 0; i < N; i++) answer[p[i].second] = i;
    for(int i = 0; i < N; i++) cout << answer[i] << " ";

    return 0;
}
