#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int N, C;
    cin >> N >> C;
    
    vector<int> home(N);
    for(int i = 0; i < N; i++) cin >> home[i];
    sort(home.begin(), home.end());

    int left = 1, right = home[N - 1] - home[0];
    int mid;
    int answer;
    do
    {
        mid = (left+right)/2;
        int cnt = 1;
        int previous_installation_position = home[0];

        for(int i = 1; i < N; i++)
        {
            int d = home[i]-previous_installation_position;
            if(d >= mid)
            {
                cnt++;
                previous_installation_position = home[i];
            }
        }
        
        if(cnt < C) // 간격이 너무 넓어서 공유기를 다 설치 할 수 없음
        {
            // 더 좁은 간격으로 설치해보자
            right = mid-1;
        }
        else // 간격이 여유 있어서 공유기를 더 설치 할 수 있음
        {
            // 더 넓은 간격으로 설치해보자
            answer = mid;
            left = mid+1;
        }
    }while(left <= right);

    cout << answer;

    return 0;
}
