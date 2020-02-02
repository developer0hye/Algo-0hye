# 경사로

시뮬레이션 문제

내리막 길의 계단을 설치할때 설치 가능 여부를 검사하는 과정에서 실수 발생

오르막 길을 지나기 위한 계단을 설치할때는 오르막 길임을 **확인한 이전 지점**을 포함하여 **이전 L개의 계단까지**를 확인해야함

내리막 길을 지나기 위한 계단을 설치할때는 내리막 길임을 **확인한 지점** 을 포함하여 **다음 L 개의 계단까지**를 확인해야함


## Vertical 방향 오르막길 검사코드
```c++
if(i-L < 0)// 경사로를 놓다가 범위를 벗어나는 경우
{
    isRoad = false;
    break;
}

const int stair_floor_height = map[i-1][j];
for(int i_stair = i-1; i_stair >= i-L; i_stair--)
{
    if(map[i_stair][j] != stair_floor_height) // 낮은 지점의 칸의 높이가 모두 같지 않거나, L개가 연속되지 않은 경우
    {
        isRoad=false;
        break;
    }
    if(stair_is_installed[i_stair] == false) //경사로를 놓을 수 있는지 확인
        stair_is_installed[i_stair] = true;
    else //이미 경사로가 설치되어 있음
    {
        isRoad = false;
        break;
    }
}
```

## Vertical 방향 내리막길 검사코드
```c++
if(i+L-1 > N-1){isRoad = false; continue;}// 경사로를 놓다가 범위를 벗어나는 경우

const int stair_floor_height = map[i][j];
for(int i_stair = i; i_stair <= i+L-1; i_stair++)
{
    if(map[i_stair][j] != stair_floor_height) // 낮은 지점의 칸의 높이가 모두 같지 않거나, L개가 연속되지 않은 경우
    {
        isRoad=false;
        break;
    }
    if(stair_is_installed[i_stair] == false) //경사로를 놓을 수 있는지 확인
        stair_is_installed[i_stair] = true;
    else //이미 경사로가 설치되어 있음
    {
        isRoad = false;
        break;
    }
}
```


위 두 코드를 보면 j_stair 와 i_stair 의 검사 지점이 다른 것을 확인 할 수 있다.
