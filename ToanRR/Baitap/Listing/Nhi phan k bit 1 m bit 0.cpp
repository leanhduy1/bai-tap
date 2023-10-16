//Liệt kê tất cả các xâu nhị phân độ dài 𝑛 có duy nhất một dãy 𝑘 bít 1 liên tiếp và duy nhất một dãy 𝑚 bít 0 liên tiếp


#include <bits/stdc++.h>

using namespace std;

int N;
int k,m;
int B[100];

int checkbit(int num, int x){
    int tmp = 0, cnt = 0;
    for(int i = 1; i <= N - num + 1; ++i){
        if(B[i] == x){
            cnt++;
            for(int j = i + 1; j <= N; ++j){
                if(B[j] == x)
                    cnt++;
                else 
                    break;
            }
            if(cnt > num) return 0;
            if(cnt == num){
                tmp++;
            }
            cnt = 0;
        }
        if(tmp > 1) return 0;
    }
    if(tmp == 1) return 1;
    else return 0;
}

void in(){
    if(!checkbit(k,1) || !checkbit(m,0)) return;
    for(int i = 1; i <= N; ++i)
        cout << B[i];
    cout << endl;
    return;
}

void init(){
    for(int i = 1; i <= N; ++i)
        B[i] = 0;
    return;
}

void genNext(){
    for(int i = N; i > 0; --i){
        if(B[i] == 1){
            B[i] = 0;
        }
        else{
            B[i] = 1;
            return;
        }
    }   
    return;
}


int isLast(){
    for(int i = 1; i <= N; ++i)
        if(B[i] != 1)
            return 0;
    return 1;
}


int main(){
    cin >> N >> k >> m;
    init();
    in();
    while(!isLast()){
        genNext();
        in();
    }
    return 0;
}
