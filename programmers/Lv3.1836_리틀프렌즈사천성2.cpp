#include <bits/stdc++.h>

using namespace std;

struct{
    int x;
    int y;
    int dir;
    int cnt;
}typedef Point;

map<char,Point> m;
int M, N;
vector<string> Board;

string solution(int m, int n, vector<string> board) {
    string answer = "";
    M=m;
    N=n;
    Board = board;

    for(int i=0; i<board.size(); i++){
        for(int j=0; j<board[i].size(); j++){
            if(isalpha(board[i][j]))
                m[board[i][j]].push_back({i,j,0,0});
        }
    }   

    turn();

    return answer;
}

int main(){

    // int m=3;
    // int n=3;
    
    // vector<string> board = {"DBA",
    //                         "C*A",
    //                         "CDB"};

    int m=2;
    int n=4;
    M=m; N=n;
    vector<string> board = {"NRYN",
                            "ARYA"};

    // int m=5;
    // int n=5;
    // vector<string> board = { "FGHEI", "BAB..", "D.C*.", "CA..I", "DFHGE" };
    //  answer : ABCDFHGIE

// ABCDFGHIE  g h i
    cout << solution(m,n,board);
    return 0;
}