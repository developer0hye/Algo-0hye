#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int T;
   
    cin >> T;

    for(int i = 0; i < T; i++)
    {
        int x1, y1, r1, x2, y2, r2;
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

        int d = pow(x1-x2,2) + pow(y1-y2,2);
        int r1_sub_r2 = pow(r1-r2, 2);
        int r1_add_r2 = pow(r1+r2, 2);

        if(r1_add_r2 > d && r1_sub_r2 < d) cout << 2 << endl;
        else if(r1_add_r2 == d || r1_sub_r2 == d && d != 0) cout << 1 << endl;
        else if(d < r1_sub_r2 || d > r1_add_r2) cout << 0 << endl;
        else cout << -1 << endl;
    }

    return 0;
}
