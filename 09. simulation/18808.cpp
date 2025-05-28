// 답지 보고 푼 것
#if 0
#include <iostream>
#include <vector>
using namespace std;

int n, m, k;
int notes[42][42];
int r, c;
int sticker[12][12];

// 1. 스티커 붙을 수 있는지 확인하는 함수
bool postable(int y, int x){
    for(int i=0; i < r; ++i){
        for(int j=0; j < c; ++j){
            // 이미 종이에 스티커가 붙어있고 모눈종이에 스티커가 있는 위치가 겹치는 경우
            if(notes[i+y][j+x] == 1 && sticker[i][j] == 1)  return false;
        }
    }

    // sticker 붙을 수 있는지 확인 끝났으니, 스티커 붙이기 ~
    for(int i=0; i < r; ++i){
        for(int j=0; j < c; ++j){
            if(sticker[i][j] == 1)  notes[y+i][x+j] = 1;
        }
    }

    return true;
}

// 90도 회전하는 함수
void rotate(){
    int tmp[12][12];

    for(int i=0; i < r; ++i){
        for(int j=0; j < c; ++j){
            tmp[i][j] = sticker[i][j];
        }
    }

    swap(r, c); // 행, 열 바꿈

    for(int i=0; i < r; ++i){
        for(int j=0; j < c; ++j){
            sticker[i][j] = tmp[c-j-1][i];
        }
    }
}


void solve(){
    cin >> n >> m >> k;
    while(k--){
        cin >> r >> c;
        for(int y=0; y < r; ++y){
            for(int x=0; x < c; ++x){
                cin >> sticker[y][x];
            }
        }  

        // 회전 4방향!
        for(int rot=0; rot < 4; ++rot){
            bool is_paste = false;
            for(int y=0; y <= n-r; ++y){
                if(is_paste)    break;
                for(int x=0; x <= m-c; ++x){
                    if(postable(y, x)){
                        is_paste = true;
                        break;
                    }
                }
            }
            if(is_paste)    break;
            rotate(); // 못붙이면 회전해보기
        }    
    }

    int cnt = 0;
    for(int y=0; y < n; ++y){
        for(int x=0; x < m; ++x){
            if(notes[y][x]) ++cnt;
        }
    }
    cout << cnt << '\n';
    return;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}

#endif

// 혼자 풀어보기
#include <iostream>
#include <vector>
using namespace std;

int n, m, k;
int notes[42][42];
int r, c;
int sticker[12][12];

// 스티커 붙일 수 있는지 판단하는 여부
bool postable(int y, int x){
    for(int i=0; i < r; ++i){
        for(int j=0; j < c; ++j){
            // 스티커가 이미 노트에 붙어있으며 스티커가 붙어야할 자리면 스티커 못붙임 
            if(notes[y+i][x+j] == 1 && sticker[i][j] == 1)  return false;
        }
    }
    return true;
}

// 스티커 붙이기
void stick(int y, int x){
    for(int i=0; i < r; ++i){
        for(int j=0; j < c; ++j){
            if(sticker[i][j] == 1){
                notes[y+i][x+j] = 1;
            }
        }
    }
    return;
}

// 스티커 회전
void rotate(){
    int tmp[12][12];
    for(int i=0; i < r; ++i){
        for(int j=0; j < c; ++j){
            tmp[i][j] = sticker[i][j];
        }
    }

    // 행, 열 전환
    swap(r, c);

    for(int i=0; i < r; ++i){
        for(int j=0; j < c; ++j){
            sticker[i][j] = tmp[c-j-1][i];
        }
    }
}

void solve(){
    bool is_paste = false;
    // 0도, 90도, 180도, 270도 회전
    for(int rot=0; rot < 4; ++rot){
        for(int y=0; y <= n-r; ++y){
            for(int x=0; x <= m-c; ++x){
                if(postable(y, x)){
                    is_paste = true;
                    stick(y, x);
                    break;
                }
            }
            if(is_paste)    break;
        }
        if(is_paste)    break;
        rotate();
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> k;
    while(k--){
        cin >> r >> c;
        for(int i=0; i < r; ++i){
            for(int j=0; j < c; ++j){
                cin >> sticker[i][j];
            }
        }
        solve();
    }

    int cnt = 0;
    for(int i=0; i < n; ++i){
        for(int j=0; j < n; ++j){
            if(notes[i][j]) ++cnt;
        }
    }
    cout << cnt << '\n';
    return 0;
}