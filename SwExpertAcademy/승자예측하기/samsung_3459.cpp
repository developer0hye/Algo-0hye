#include <iostream>
#include <vector>
using namespace std;

int main()
{
    long long T, N;

    scanf("%d", &T);


    long long results_alice_big_bob_small[60] = {1,};
    long long results_alice_small_bob_big[60] = {1,};
    long long turn_max_values[60] = {2, };

    for(int i = 1; i < 60; i++)
    {
        turn_max_values[i] = turn_max_values[i-1]<<1;

        if(i & 1 == 1) //turn alice
        {
            results_alice_big_bob_small[i] = (results_alice_big_bob_small[i-1]<<1)+ 1;
            results_alice_small_bob_big[i] = (results_alice_small_bob_big[i-1]<<1);
        }
        else //turn bob
        {
            results_alice_big_bob_small[i] = results_alice_big_bob_small[i-1]<<1;
            results_alice_small_bob_big[i] = (results_alice_small_bob_big[i-1]<<1)+1;
        }
    }

    for(long long t = 1; t <= T; t++)
    {   
        scanf("%lld", &N);

        if (N == 1) printf("#%d Bob\n", t);
        else if (N == 2 or N == 3) printf("#%d Alice\n", t);
        else
        {
            long long turn = 1;
            long long turn_min_value = 1;
            long long turn_max_value = 2;

            //alice 가 N 을 낼 수 있는 차례를 가지게 되면 alice 는 이기기 위해 작은 걸 내고 싶어함, 반대로 bob 은 큰 걸 내고 싶어함
            //bob 이 N 을 낼 수 있는 차례를 가지게 되면 bob 은 이기기 위해 작은 걸 내고 싶어함, 반대로 alice 는 큰 걸 내고 싶어함
            long long result_alice_big_bob_small = 1; //alice 가 큰 거, bob 이 작은 거 내야 될 때의 나오는 결과 값
            long long result_alice_small_bob_big = 1; //alice 가 작은 거, bob 이 큰 거 내야 될 때의 나오는 결과 값

            while(1)
            {              
                if(N < turn_max_values[turn]) break;
                turn += 1;
            }

            if(turn%2 == 1) //Alice 가 최종으로 말할 숫자 =results_alice_small_bob_big[turn] Alice 는 작은 숫자 만을 외치고, Bob 은 큰 숫자만 외쳤을때 나온 최종 값
            {
                if(N < results_alice_small_bob_big[turn])
                {
                    printf("#%d Bob\n", t);
                }
                else
                {
                    printf("#%d Alice\n", t);
                }
            }
            else //Bob 이 최종으로 말할 숫자 results_alice_big_bob_small[turn], Alice 는 큰 숫자 만을 외치고, Bob 은 작은 숫자만 외쳤을때 나온 최종 값
            {
                if(N < results_alice_big_bob_small[turn])
                {
                    printf("#%d Alice\n", t);
                }
                else
                {
                    printf("#%d Bob\n", t);
                }
            }
        }
    }

    return 0;
}
