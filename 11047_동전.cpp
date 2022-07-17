#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, K;
	int sum=0;

	cin >>N >>K;

	int arr[N];
	for(int i=0; i<N; i++)
        cin >>arr[i];

	for(int i=N-1; i>=0; i--){
        sum+= K/arr[i]; //큰 동전을 최대 몇 개 사용 가능 한 지
        K=K%arr[i]; // 큰동전을 사용해 표현한 나머지 금액
	}

	cout << sum;


	return 0;
}
