# 제곱 ㄴㄴ수

처음에 문제를 잘못 이해하고 제곱수가 아닌 수를 제곱 ㄴㄴ수로 보고 풀었다.

제곱 ㄴㄴ수의 정의는 **제곱수로 나누어지지 않는 수**이다.

제곱 ㄴㄴ수를 구하기 위해서는 주어진 두 값(min, max)의 범위에서 **제곱수로 나누어지는 수(=제곱 ㅇㅇ수)** 를 걸러내면된다.

제곱 ㅇㅇ수에 대해 좀 더 깊게 생각해보자면 제곱수로 나누어지는 수 => 제곱수의 배수인 수로 생각할 수 있다.

주어진 두 값의 범위에서 제곱수의 배수인 수를 모두 제외한 수는 제곱 ㄴㄴ 수이다.

아래의 반복문은 주어진 두 값의 범위에서 제곱수의 배수인 수를 구하고 이를 특정 메모리 공간(is_JEGOP_OO_NUMBER[ ])에 기록하는 과정이다.

```cpp

bool is_JEGOP_OO_NUMBER[1000001] = {false,};
.
.
.
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
```

* q_* 의 q 는 **q**uotient(몫) 의 앞글자이다.

is_JEGOP_OO_NUMBER[] 는 주어진 범위(min, max)에서 어떠한 수가 제곱ㅇㅇ수인지를 하기 위해 사용되는 배열이다.


q_min 과 q_max 는 min 과 max 를 제곱수(squared_n)로 나눈 **몫**이다. 

두 값(q_min 과 q_max)은 제곱수(squared_n)의 배수 중 현재 주어진 범위(min, max)안에 드는 제곱 ㅇㅇ 값 탐색시 최솟값과 최댓값의 범위를 한정 짓기 위해 계산되며 사용된다.

```is_JEGOP_OO_NUMBER[squared_n*q_n - min] = true;``` 이부분을 주목할 필요가 있다. 메모리에 해당수가 제곱ㅇㅇ수를 기록할 시에 값의 범위가 1~1,000,000,000,000 이기 때문에 이를 메모리에 저장하기 위해서는 어마어마한 양의 메모리가 필요하다. 

그러나, 우리는 min 값을 알고 max 값이 min 보다 최대 1,000,000 클 수 있음을 알기 때문에 값  시 min 을 값을 빼주면 어떠한 값이 입력되더라도 값의 범위를 0~1,000,000 속하게 만들 수 있다. 

아래의 코드는 주어진 범위에서 제곱ㅇㅇ수를 제외한 수를 구하는 과정이다.

```
    long long n_not_sqr_num = 0;

    for(long long n = 0; n < max - min + 1; n++)
    {
        if(is_JEGOP_OO_NUMBER[n]==false)
            ++n_not_sqr_num;
    }
```



## 고찰
- 문제 이해 능력을 기르자.
- 문제에서 다루는 수의 범위가 큰 경우 되도록 long long 자료형 만을 이용하여 문제를 풀자.

