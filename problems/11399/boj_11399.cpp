#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<int> people(N);
    for(int i = 0; i < N; i++) cin >> people[i];
    sort(people.begin(), people.end());

    int cumulative_sum = 0;
    int sum = 0;
    for(int time : people) 
    {
        cumulative_sum += sum + time;
        sum += time;
    }
    cout << cumulative_sum << endl;
    return 0;
}
