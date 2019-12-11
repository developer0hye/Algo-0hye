#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare (pair<int, int>& a, pair<int, int>& b)
{
    return a.first < b.first;
}

int main()
{
    int N;
    cin >> N;

    for(int i = 0; i < N; i++)
    {
        int n_candidate;
        cin >> n_candidate;

        vector<pair<int, int>> candidates(n_candidate);

        for(int j = 0; j < n_candidate; j++)
            cin >> candidates[j].first >> candidates[j].second;

        sort(candidates.begin(), candidates.end(), compare);

        int nStaff = 1;
        int top_rank = candidates[0].second;
        for(int k = 1; k < candidates.size(); k++)
        {
            if (candidates[k].second < top_rank)
            {
                top_rank = candidates[k].second;
                nStaff++;
            }
        }
        cout << nStaff << "\n";
    }

    return 0;
}
