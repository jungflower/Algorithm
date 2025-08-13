#include <iostream>
#include <queue>
using namespace std;

int heap[100005];
int sz = 0; // heap에 들어있는 원소의 수
int n;

void push(int x) {
    heap[++sz] = x;
    int idx = sz;
    while (idx != 1) {
        int parent = idx / 2;
        if (heap[parent] <= heap[idx]) break;
        swap(heap[parent], heap[idx]);
        idx = parent;
    }
}

void top() {
    if (sz == 0) cout << 0 << '\n';
    else cout << heap[1] << '\n';
}

void pop() {
    if (sz == 0)   return;
    heap[1] = heap[sz--];
    int idx = 1; // 현재 비교중인 노드의 인덱스
    // 왼쪽 자식 노드가 존재하는 동안 반복 = 현재 노드가 리프노드가 될 때까지
    while (2 * idx <= sz) {
        int lc = 2 * idx, rc = 2 * idx + 1; // 왼쪽, 오른쪽 자식
        int min_child = lc; // 두 자식 중 작은 인덱스를 담을 예정
        if (rc <= sz && heap[rc] < heap[lc])
            min_child = rc;
        // 현재노드가 min_child보다 더 작으면 더 내려갈 필요 없으니까 종료
        if (heap[idx] <= heap[min_child])    break;
        swap(heap[idx], heap[min_child]);
        idx = min_child;
    }

}

void test()
{
    priority_queue<int> pq; // 최대 힙
    // priority_queue<int, vector<int>, greater<int>>로 선언 시 최소 힙
    pq.push(10); pq.push(2); pq.push(5); pq.push(9); // (10, 2, 5, 9)
    cout << pq.top() << '\n'; // 10
    pq.pop(); // (2, 5, 9)
    cout << pq.size() << '\n'; // 3
    if(pq.empty())  cout << "PQ is empty \n";
    else    cout << "PQ is not empty\n";
    pq.pop(); // (2, 5)
    cout << pq.top() << '\n'; // 5
    pq.push(5); pq.push(15); // (2, 5, 5, 15)
    cout << pq.top() << '\n'; // 15
    
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    // cin >> n;
    // while (n--) {
    //     int x;
    //     cin >> x;
    //     if (x == 0) {
    //         top();
    //         pop();
    //     }
    //     else if (x > 0) {
    //         push(x);
    //     }
    // }

    test();

    return 0;
}