#include <bits/stdc++.h>

using namespace std;

int answer = -1;

//dfs풀이
void dfs(vector<vector<int>> triangle, int h, int pos, int sum){
    if(h == triangle.size()-1){
        answer = max(answer, sum);
        return;
    }

    int left =  triangle[h+1][pos];
    int right = triangle[h+1][pos+1];


    dfs(triangle,h+1, pos, sum+left);
    dfs(triangle,h+1, pos+1, sum+right);
}

int solution(vector<vector<int>> triangle) {

    dfs(triangle,0,0,triangle[0][0]);
    
    return answer;
}

int main(){

    vector<vector<int>> triangle = {{7}, {3, 8}, {8, 1, 0}, {2, 7, 4, 4}, {4, 5, 2, 6, 5}};
    
    cout << solution(triangle);

    return 0;
}