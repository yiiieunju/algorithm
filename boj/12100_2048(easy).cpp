#include <bits/stdc++.h>

using namespace std;

#define LEFT 0
#define UP 1
#define RIGHT 2
#define DOWN 3

int N;
int resMax = -0xffffff;

int move_block(int step, int board[][20]){
    if(step >=5){
        int maxNum = 0;
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                if(maxNum < board[i][j])
                    maxNum = board[i][j];
            }
        }
        return maxNum;
    }

    //next step gogo
    //dfs 전 원본을 넣어주기 위해서
    for(int dir=0; dir<4; dir++){
        
        // copy tmp
        int tmp[20][20];
        for(int i=0; i<N; i++)
            for(int j=0; j<N; j++)
                tmp[i][j] = board[i][j];
        
        //0이 아닌것 넣기
        //각 행or열 한 줄씩 가져와서 vector에 넣고 검사
        for(int i=0; i<N; i++){
            vector<int> notzero;
            for(int j=0; j<N; j++){
                //좌,우 - 가로
                if(dir == LEFT || dir == RIGHT)
                    if(board[i][j]!=0)
                        notzero.push_back(board[i][j]);
                //위,아래 - 세로
                else if(dir == UP || dir == DOWN)
                    if(board[j][i]!=0)
                        notzero.push_back(board[j][i]);
            }

            //오른쪽, 아래에서 가져오는건 끝에서부터 가져오니깐
            // 1 0 0 3 4 -> 0 0 1 3 4
            // 2 3 4 0 0 -> 0 0 2 3 4
            if(dir == RIGHT || dir == DOWN)
                reverse(notzero.begin(), notzero.end());


            //같으면 묶어서 넣기
            vector<int> combine;
            for(int k=0; k<notzero.size(); k++){
                if(k+1<notzero.size() && notzero[k]==notzero[k+1]){
                    combine.push_back(notzero[k]*2);
                    k++;
                }
                else
                    combine.push_back(notzero[k]);
            }

            //나머지 칸에 0넣기
            for(int k=combine.size(); k<N; k++){
                combine.push_back(0);
            }
            //오른쪽, 아래에서 reverse
            if(dir == RIGHT || dir == DOWN)
                reverse(notzero.begin(), notzero.end());

            //원본에다 넣어주기
            for(int j=0; j<N; j++){
                if(dir == LEFT || dir == RIGHT)
                    board[i][j] = combine[j];
                else
                    board[j][i] = combine[j];
            }
        }

        int retMax = move_block(step+1, board);
        if(retMax > resMax)
            resMax = retMax;

        //다시 board 복구
        int board[20][20];
        for(int i=0; i<N; i++)
            for(int j=0; j<N; j++)
                board[i][j] = tmp[i][j];
    }

    return resMax;
}


int main(){

    int board[20][20];
    cin >> N;
    
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            cin >> board[i][j];

    cout << move_block(0, board);

    return 0;
}