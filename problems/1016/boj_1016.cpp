#include <iostream>
#include <cmath>

using namespace std;

bool is_JEGOP_OO_NUMBER[1000001] = {false,};

int main()
{
    long long min, max;
    cin >> min >> max;
    
    for(long long n = 2; n*n <= max; n++)
    {
        const long long squared_n = n*n;

        long long q_min = (long long)(min/squared_n);
        if(q_min*squared_n < min) q_min += 1;

        long long q_max = (long long)(max/squared_n);
        if(q_max*squared_n > max) q_max -= 1;
        
        for(long long q_n = q_min; q_n <= q_max; q_n++)
            is_JEGOP_OO_NUMBER[squared_n*q_n - min] = true;
    }

    long long n_not_sqr_num = 0;

    for(long long n = 0; n < max - min + 1; n++)
    {
        if(is_JEGOP_OO_NUMBER[n]==false)
            ++n_not_sqr_num;
    }

    cout << n_not_sqr_num <<endl;

    return 0;
}
