# 정렬
### 기초 정렬
```cpp
int arr[10] = {3, 2, 7, 116, 62, 235, 1, 23, 55, 77};
int n = 10;
for(int i = n-1; i > 0; --i){
    int mxidx = 0;
    for(int j = 0; j <= i; ++j){
        if(arr[mxidx] < arr[j]) mxidx = j;
    }
    swap(arr[mxidx], arr[i]);
}
```

```cpp
int arr[10] = {3, 2, 7, 116, 62, 235, 1, 23, 55, 77};
int n = 10;
for(int i = n-1; i > 0; --i){
    swap(*max_element(arr, arr+i+1), arr[i]);
}
```

*버블 정렬*  
시간 복잡도:  $O(N^2)$  
 ```cpp
int arr[5] = {-2, 2, 4, 6, 13};
int n = 5;
for(int i=0; i < n; ++i){
    for(int j=0; j < n-1-i; ++j){
        if(arr[j] > arr[j+1])   swap(arr[j], arr[j+1]);
    }
}
 ```  

*merge sort*
시간 복잡도: $O(nlogn)$  
### 11728_배열합치기  
```cpp

```
