#include <bits/stdc++.h>

using namespace std;

int m,n,N;
int binary[20] = {0};

void binarySort(int k){
	int low = k, high = N - 1;
	while(low < high){
		if(binary[low] == 1){
			int tmp = binary[high];
			binary[high] = binary[low];
			binary[low] = tmp;
			high--;
		}
		low++;
	}
}

void init(){
	for(int i = 0 ; i < N; ++i){
		if(i >= m) binary[i] = 1;
	}
	return;
}

void print(){
	for(int i = 0; i < N; ++i){
		cout << binary[i];
	}
	cout << endl;
	return;
}

void genNext(){
	for(int i = N - 2; i >= 0; --i){
		if(binary[i] == 0 && binary[i+1] == 1) {
			binary[i] = 1;
			binary[i+1] = 0;
			binarySort(i+1);
			break;
		}
	}
	return;
}

int isFinal(){
	for(int i = 0; i < N; ++i){
		if(binary[i] != 1 && i < n) return 0;
	}
	return 1;
}



int main(){
	cin >> m >> n;
	N = m+n;
	int cnt = 1;
	init();
	while(!isFinal()){
		print();
		genNext();
		cnt++;
	}
	print();
	cout << cnt;
	return 0;
}
