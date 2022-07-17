#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);


	int N, K;
	cin >> N >> K;

	int val[N];
	int dp[10001];


	for(int i=0; i<N; i++)
        cin >> val[i];

	dp[0] = 1;

	for(int i=0; i<N; i++){
        for(int j=val[i]; j<=K; j++){
                dp[j] += dp[j-val[i]];
        }
	}

	cout <<dp[K]<<endl;
	return 0;
}
