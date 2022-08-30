#include <bits/stdc++.h>

using namespace std;

int N, M;

// void rotate2(vector<vector<int>>& key){
//     vector<vector<int>> tmp(M,vector<int>(M,0));

//     for(int i=0; i<M; i++)
//         for(int j=0; j<M; j++)
//             tmp[i][j]=key[M-j-1][i];

//     for(int i=0; i<M; i++)
//         for(int j=0; j<M; j++)
//             key[i][j]=tmp[i][j];
// }

void rotate(vector<vector<int>>& key){

    vector<vector<int>> rotkey(M,vector<int>(M,0));
    copy(key.begin(), key.end(),rotkey.begin());
    key.clear();
    
    for(int i=0; i<M; i++){
        vector<int> tmp;
        for(int j=0; j<M; j++)
            tmp.push_back(rotkey[M-j-1][i]);
        key.push_back(tmp);
    }
}


bool check(int x, int y, vector<vector<int>> key,vector<vector<int>> board){

    for(int i=x; i<x+M; i++){
        for(int j=y; j<y+M; j++){
            board[i][j] += key[i-x][j-y];
        }
    }
    
    for(int i=M; i<M+N; i++){
        for(int j=M; j<M+N; j++){
            if(board[i][j]!=1) return false;
        }
    }

    return true;
}


bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    bool answer = false;
    M = key.size();
    N = lock.size();

    vector<vector<int>> board(M*2+N, vector<int>(M*2+N,0));

    for(int i=M; i<M+N; i++){
        for(int j=M; j<M+N; j++){
            board[i][j] = lock[i-M][j-M];
        }
    }

    for(int i=0; i<M+N; i++){
        for(int j=0; j<M+N; j++){
            //rotate
            for(int r=0; r<4; r++){
                rotate(key);
                if(check(i,j,key,board)){
                    answer = true;
                    break;
                }
            }
            if(answer) break;
        }
        if(answer) break;
    }
    return answer;
}

int main(){

    vector<vector<int>> key={{0, 0, 0},
                             {1, 0, 0}, 
                             {0, 1, 1}};
    vector<vector<int>> lock={{1, 1, 1}, {1, 1, 0}, {1, 0, 1}};

    cout << solution(key, lock);
    return 0;
}