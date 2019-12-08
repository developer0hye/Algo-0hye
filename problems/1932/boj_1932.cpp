#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int N;
    cin >> N;

    vector< vector<int> > triangle;
    triangle.resize(N);

    vector< vector<int> > dp_sum;
    dp_sum.resize(N);

    for(int i = 0; i < N; i++)
    {
        int n_values = i + 1;

        triangle[i].resize(n_values);
        dp_sum[i].resize(n_values);

        for(int j = 0; j < n_values; j++)
        {
            cin >> triangle[i][j];
        }
    }

    dp_sum[0][0] = triangle[0][0];

    for(int i = 1; i < N; i++)
    {
        for(int j = 0; j < dp_sum[i].size(); j++)
        {   
            int temp;
            
            if (j == 0) temp = dp_sum[i-1][0];
            else if (j == dp_sum[i].size()-1) temp = dp_sum[i-1][dp_sum[i-1].size()-1];
            else temp = max(dp_sum[i-1][j-1], dp_sum[i-1][j]);

            dp_sum[i][j] = temp + triangle[i][j];
        }
    }
    
    vector<int>& max_value_candidates = dp_sum[N-1];
    cout << *max_element(max_value_candidates.begin(), max_value_candidates.end());

    return 0;
}
