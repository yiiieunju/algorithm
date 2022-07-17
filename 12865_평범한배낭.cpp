#include <bits/stdc++.h>

using namespace std;

int dp[102][100003];


int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, K; //N 물품의 수, K 무게

    cin >> N >>K;


    vector<pair<int,int>> v;
    v.push_back({0,0});

	for(int i=1; i<=N; i++){
        int W, V;   // W : 물건의 무게, V:물건의 가치
        cin >> W >> V;
        v.push_back({W,V});
	}

	//napsack
	for(int i=1; i<= N; i++){
	    int W = v[i].first;
	    int V = v[i].second;
        for(int j=0; j<K+1; j++){
             //현재 배낭의 무게가 해당 차례의 물건을 넣지 못하는 무게이면 이전차례 물건의 가치를 넣어준다.
            if(j < W) dp[i][j]=dp[i-1][j];
            else dp[i][j] = max(dp[i-1][j-W]+V, dp[i-1][j]);
        }
	}


    cout << dp[N][K];
	return 0;
}
