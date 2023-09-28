// Đề bài Liệt kê các đường đi từ đỉnh dưới cùng bên trái tới đỉnh trên cùng bên phải của 1 hình chữ nhật kích thước m*n (chỉ được di chuyển sang phải và đi lên)
// Coi bước di chuyển sang ngang là 0 và đi lên là 1 --> mỗi cách đi được thể hiện bằng 1 chuỗi nhị phân
// Thuật toán đổi chỗ từng cặp 0 1 và sắp xếp lại các bước đi đằng sau thỏa mãn ưu tiên bước sang ngang trước (sự tăng nhỏ nhất) để sinh ra 1 cặp mới
// Nháp 01101 ---> 01110 
// 	01110 ---> 10110 ---> 10011

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
