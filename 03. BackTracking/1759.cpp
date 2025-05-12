// 1759 암호 만들기 
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int L, C;
char res[20];
int isused[20];
vector<char> letter;

// 모음 여부와 자음2개 이상인지 판단하는 함수 
bool isvowel_word(){
    bool vowel_flag = false;
    int cnt=0; // 자음 수
    bool flag = false;
    for(int i=0; i < L; ++i){
        char vowel = res[i];
        if(vowel == 'a' || vowel == 'e' || vowel == 'i' 
            || vowel == 'o' || vowel == 'u')
                vowel_flag = true;
        else{
            ++cnt;
        }
    }
    if(cnt >= 2 && vowel_flag)  flag = true;
    return flag;    
}

void func(int k, int start){
    if(k == L){
        if(isvowel_word()){
            for(int i=0; i < L; ++i){
                cout << res[i];
            }
            cout << '\n';
        }
        return;
    }

    for(int i=start; i < C; ++i){
        res[k] = letter[i];
        func(k+1, i+1); // i+1로 다음 인덱스부터 탐색
    }

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> L >> C;
    letter.resize(C);

    for(int i=0; i < C; ++i){
        cin >> letter[i];
    }
    sort(letter.begin(), letter.end());         
    func(0, 0);
    return 0;
}