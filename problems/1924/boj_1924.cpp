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
    
    // 초기화를 잘해주자
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
