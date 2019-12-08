#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, int>> memo(41);

pair<int, int> zero_one_called(int n)
{
    if(memo[n].first != -1 && memo[n].second != -1) return memo[n];
    else if(n == 0) return memo[0];
    else if(n == 1) return memo[1];

    pair<int, int> small_n1 = zero_one_called(n-1);
    pair<int, int> small_n2 = zero_one_called(n-2);

    memo[n].first = small_n1.first + small_n2.first;
    memo[n].second = small_n1.second + small_n2.second;

    return memo[n];
}

int main()
{
    int T;
    cin >> T;

    //first -> 0이 호출되는 횟수, second -> 1이 호출되는 횟수
    memo[0].first = 1;
    memo[0].second = 0;

    memo[1].first = 0;
    memo[1].second = 1;

    for(int i = 2; i < 41; i++)
    {
        memo[i].first = -1;  //해가 구해진 적 없다!
        memo[i].second = -1; //해가 구해진 적 없다!
    }

    for(int k = 0; k < T; k++)
    {
        int n;
        cin >> n;
        pair<int, int> answer = zero_one_called(n);

        cout << answer.first << " " << answer.second << "\n"; 
    }
    return 0;
}
