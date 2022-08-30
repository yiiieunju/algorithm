#include <bits/stdc++.h>

using namespace std;

int dp[500][500]={0};
//dfs풀이

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    int height = triangle.size();
    dp[0][0] = triangle[0][0];

    for(int i=1; i<triangle.size(); i++){
        for(int j=0; j<triangle[i].size(); j++){
            if(j==0){
                dp[i][j] = dp[i-1][j] +triangle[i][j];
            }
            else if(j==triangle[i].size()-1){
                dp[i][j] = dp[i-1][j-1] + triangle[i][j];
            }
            else{
                dp[i][j] = max(dp[i-1][j-1],dp[i-1][j]) + triangle[i][j];
            }
            answer = max(answer, dp[i][j]);
        }
    }

    // for(int i=0; i<triangle[height-1].size(); i++){
    //     answer = max(answer, dp[height-1][i]);
    // }
    return answer;
}

int main(){

    vector<vector<int>> triangle = {{7}, {3, 8}, {8, 1, 0}, {2, 7, 4, 4}, {4, 5, 2, 6, 5}};
    
    cout << solution(triangle);

    return 0;
}