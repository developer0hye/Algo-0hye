#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

vector<string> tokenize_getline(string& data, const char delimiter = ' ') 
{
	vector<string> result;
	string token;
	stringstream ss(data);

	while (getline(ss, token, delimiter)) {
		result.push_back(token);
	}

	return result;
}

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N; //학생 수
    int M; //학생마다 가질 수 있는 최대 블록 수 
    int H; //만들어야될 탑의 높이

    // 학생들이 가진 블록으로 높이가 H인 탑 완성
    // 단, 어떤 학생의 블록은 사용하지 않아도 되며 한 학생당 최대 1개의 블록만을 사용할 수 있다.

    cin >> N >> M >> H;
    cin.ignore(1,'\n');
    
    vector<vector<int>> blocks = vector<vector<int>>(N + 1); 


    // dp[n]][h]: n 번째 학생이 h 높이의 탑을 쌓을 수 있는 경우의 수
    vector<vector<int>> dp(N + 1, vector<int>(H + 1, 0)); 

    for(int n = 1; n <= N; n++)
    {   
        string inputs;
        getline(cin, inputs, '\n');

        vector<string> str_heights;
        str_heights = tokenize_getline(inputs, ' ');

        dp[n][0] = 1;
        for(string str_height:str_heights)
        {
            int height = stoi(str_height);
            blocks[n].push_back(height);
            
            // n 번째 학생을 제외하고 나머지 학생들이 0 놓은 경우 1 개 미리 추가
            dp[n][height] = 1;  
        }
    }

    // 1번째 학생이 놓을 수 있는 tower 의 경우의 수는 이미 위 반복문에서 계산됨
    for(int n = 2; n <= N; n++)
    {
        /* n번째 학생이 block을 사용하지 않았을 때 임의의 높이 h 에 해당하는 타워를
        만들 수 있는 경우의 수 = 
        
        n-1 번째 학생이 임의의 높이 h 에 해당하는 타워를 만들 수 있는 경우의 수 
        + 1(if n번째 학생이 임의의 높이 h 에 해당하는 블럭을 가진 경우) or 0(else) */

        for(int prev_tower_h = 1; prev_tower_h <= H; prev_tower_h++)
        {
            dp[n][prev_tower_h] += dp[n-1][prev_tower_h];
        }

        for(int prev_tower_h = 1; prev_tower_h <= H; prev_tower_h++)
        {
            // n-1 번째 학생이 높이 prev_tower_h 에 해당하는 타워를 만들 수 없으면 패스
            if(dp[n-1][prev_tower_h] == 0) continue;
            

            /* n-1 번째 학생이 높이 prev_tower_h 에 해당하는 타워를 만들 수 있으면,
            n 번째 학생이 추가로 block 을 쌓아서 높이 new_tower_h 에 해당하는 타워를 만듦,
            경우의 수 = 

            n 번째 학생이 높이 new_tower_h 에 해당하는 타워를 만들 수 있는 경우의 수 
            + n-1 번째 학생이 높이 prev_tower_h 에 해당하는 타워를 만들 수 있는 경우의 수  */
            
            for(int block_h:blocks[n])
            {
                int new_tower_h = prev_tower_h + block_h;
                if(new_tower_h > H) continue;

                dp[n][new_tower_h] += dp[n-1][prev_tower_h];
                dp[n][new_tower_h] = dp[n][new_tower_h]%10007;
            }
        }
    }

    cout << dp[N][H];
    return 0;
}
