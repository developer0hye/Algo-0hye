# 2007년

2007년은 내가 초등학교 6학년때이다.

문제의 난이도는 낮으나 푸는 데 시간이 조금 걸렸다.

그 이유는 ndays 변수를 0으로 초기화 하지 않은채로 해당 변수에 특정 값을 누적시켰다. 내 빌드 환경에서는 초기화되지 않은 변수는 0으로 초기화 됐기에 이러한
문제점이 발생할 줄은 꿈에도 몰랐다... 초기화를 잘해주자.
```cpp
#include <iostream>
#include <string>
using namespace std;

int main()
{
    const string DAYS[] = { "MON",
                            "TUE",
                            "WED",
                            "THU",
                            "FRI",
                            "SAT",
                            "SUN"};
    
    const int MonthMaxDay[] = {0, //dommy month 
                                31, //1월
                                28, //2월
                                31, //3월
                                30, //4월
                                31, //5월
                                30, //6월
                                31, //7월
                                31, //8월
                                30, //9월
                                31, //10월
                                30 //11월
                                };

    int month, day;
    cin >> month >> day;

    int ndays = 0;
    // 입력 받은 월과 일을 1~365일 단위로 변환
    for(int i = 1; i < month; i++)
        ndays += MonthMaxDay[i];
    ndays += day;

    //1월 1일로 부터 입력 받은 m월 d일이 며칠 지났는지 계산
    //ndays 에 따라 규칙적으로 요일을 알아낼 수 있음
    ndays -= 1;

    cout << DAYS[ndays%7] << "\n"; 
    

    return 0;
}
```

## 고찰
값의 초기화를 잘해주자.
