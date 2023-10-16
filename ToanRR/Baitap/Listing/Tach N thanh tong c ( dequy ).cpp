// De bai tach N thanh tong cac so sao cho so hang sau khong be hon so hang truoc
// VD N = 4 1111 112 13 4
#include <bits/stdc++.h>

using namespace std;

int N;
int S;
int tmp = 1;
int A[100];


void in(){
    for(int i = 1; i <= N; ++i)
        if(A[i] != 0)
            cout << A[i];
    cout << endl;
    return;
}

void backTrack(int k){
    for(int i = tmp; i <= N; ++i){
        if(S+i <= N){
            A[k] = i;
            tmp = i;
            S += i;
            if(S == N){
                in();
            }
            else
                backTrack(k + 1);
            A[k + 1] = 0;
            S -= i;
        }
    }
    return;
}

int main(){
    cin >> N ;
    backTrack(1);
    return 0;
}
