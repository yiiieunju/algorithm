#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	int K;
	int arr[10];

	cin >> N >> K;

	for(int i=0; i<N; i++){
        cin >> arr[i];
	}

	int cnt = 0;
    for(int i=N-1; i>=0; i--){
        if(K/arr[i] > 0){
            cnt+=K/arr[i];
            K=K%arr[i];
        }
    }

    cout << cnt<<endl;
    //금액이 arr로 나눠지면 그 금액으로 K원을 만들 수 있음 개수 : /
    //K원을 arr로 만들고 남은 금액 : %


	return 0;
}
