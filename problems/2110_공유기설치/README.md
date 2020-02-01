# 공유기 설치


## 실수한 점

이분 탐색 시, left 와 right 를 업데이트 할 때 right=mid-1, left=mid+1  +1,-1 을 칼 같이 해주어야 한다.

그렇지 않은 경우, right 과 left 의 값이 업데이트 되지 않고 하나의 값으로 수렴하게 될 수 있다.

ex) 

left == 8, right == 9

mid = (8+9)/2 = 8

```
left = mid or right = mid
```

위의 경우에 left 와 right 가 계속 8이 되어 변하지 않음.

while(left <= right) 조건에 따라, 무한 루프에 빠지게 됨.
