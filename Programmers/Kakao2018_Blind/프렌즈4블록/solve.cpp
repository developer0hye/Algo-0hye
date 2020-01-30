#include <iostream>
#include <string>
#include <vector>

using namespace std;


int solution(int m, int n, vector<string> board) {
    int answer = 0;
    
    for(;;)
    {
        vector<pair<int, int>> top_left_pos_erase_blocks;

        for(int cur_m = 0; cur_m < m-1; cur_m++)
            for(int cur_n = 0; cur_n < n-1; cur_n++)
            {

                if(board[cur_m][cur_n] == ' ')continue;

                bool remove_flag = true;

                for(int ngb_m : {cur_m, cur_m+1} )
                {
                    for(int ngb_n : {cur_n, cur_n+1} )
                    {
                        if(board[ngb_m][ngb_n] != board[cur_m][cur_n])
                        {
                            remove_flag = false;
                            break;
                        }    
                    }
                    if(remove_flag==false) break;
                }
                if(remove_flag == true)top_left_pos_erase_blocks.push_back({cur_m, cur_n});
            }
            
            if(top_left_pos_erase_blocks.empty())
            {
                break;
            }
            else
            {
                for(pair<int, int> top_left_pos_erase_block: top_left_pos_erase_blocks)
                {
                    for(int ngb_m : {top_left_pos_erase_block.first, top_left_pos_erase_block.first+1} )
                    {
                        for(int ngb_n : {top_left_pos_erase_block.second, top_left_pos_erase_block.second+1} )
                        {
                            board[ngb_m][ngb_n] = ' ';
                        }
                    }
                }
                
                for(int cur_n = 0; cur_n < n; cur_n++)
                    for(int cur_m = m-1; cur_m >= 0; cur_m--)
                    {
                        if(board[cur_m][cur_n]==' ')
                        {
                            for(int top_cur_m = cur_m-1; top_cur_m >= 0; top_cur_m--)
                            {
                                if(board[top_cur_m][cur_n] != ' ') 
                                {
                                    swap(board[cur_m][cur_n], board[top_cur_m][cur_n]);
                                    break;
                                }
                            }
                        }
                    }
            }
    }

    for(int cur_m = 0; cur_m < m; cur_m++)
        for(int cur_n = 0; cur_n < n; cur_n++)
        {
            if(board[cur_m][cur_n]==' ')
            {
                answer++;
            }
        }
        
    
    return answer;
}

int main()
{
    int m, n;
    cin>>m>>n;

    vector<string> map(m);

    for(int i = 0; i < m; i++) cin >> map[i];
    cout << solution(m, n, map);
    
    return 0;
}
