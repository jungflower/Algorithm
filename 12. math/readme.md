# 수학

### 소수  
소수 = 1과 자기 자신으로만 나누어지는 수  
    = 약수가 2개인 수  
    = 2부터 N-1 까지의 수로 나누어지지 않는 수  
```cpp
bool isprime(int n){
    if(n == 1) return 0;
    for(int i = 2; i < n; ++i){
        if(n % i == 0)  return 0;
    }
    return 1;
}
```  
=> 시간복잡도: O(N)  

합성수 = 1과 자기 자신을 제외한 다른 약수를 가지고 있는 수  

