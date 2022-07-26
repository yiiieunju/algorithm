#include <bits/stdc++.h>

using namespace std;

stack<int> s;
int cnt=0;

void pop_doll(vector<vector<int>> &board, int pos){

    int selected=0;
    int N = board.size();

    for(int i=0; i<N; i++){
        selected = board[i][pos];
        if(selected==0) continue;

        
        cout << selected<<endl;
        
        //집어넣을 것과 안에 stack의 제일 top 값이 같다면 push하지 않고 pop
        if(!s.empty() && s.top()==selected){
            s.pop(); 
            cnt+=2;
            board[i][pos] = 0;
            cout <<"pop!"<<endl;
            break;
        }
        else{
            s.push(selected);
            board[i][pos] = 0;
            break;
        }
    }

}

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;

    for(int i=0; i<moves.size(); i++)
        pop_doll(board,moves[i]-1);
    answer=cnt;
    
    return answer;
}

int main(){

    vector<vector<int>> board;
    vector<int> moves;

    board = {
            {0,0,0,0,0},
            {0,0,1,0,3},
            {0,2,5,0,1},
            {4,2,4,4,2},
            {3,5,1,3,1}
            };
    moves = {1,5,3,5,1,2,1,4};


    solution(board,moves);

    cout << cnt;

    return 0;
}