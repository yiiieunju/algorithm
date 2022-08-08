#include <bits/stdc++.h>

using namespace std;

int dirX[] = {-1,0,1,0};
int dirY[] = {0,-1,0,1};
bool visited[4][3];

struct{
    int x;
    int y;
}typedef Hand;

Hand allocate_point(Hand hand, int num){

    if(num == 1) hand = {0,0};
    else if(num==2) hand={0,1};
    else if(num==3) hand = {0,2};

    else if(num==4) hand = {1,0};
    else if(num==5) hand={1,1};
    else if(num==6) hand={1,2};

    else if(num==7) hand={2,0};
    else if(num==8) hand={2,1};
    else if(num==9) hand={2,2};
    else hand={3,1};

    return hand;
}

int dist(Hand hand, int num){
    Hand point;
    point = allocate_point(point,num);
    int cnt =abs(point.x-hand.x)+abs(point.y-hand.y);
    return cnt;

}

string solution(vector<int> numbers, string hand) {
    string answer = "";

    Hand left_hand = {3,0}; //left
    Hand right_hand = {3,2}; //right

    for(auto num : numbers){
        if(num == 1 || num == 4 || num == 7){ //left
            left_hand = allocate_point(left_hand, num);
            answer+="L";
        }
        else if(num==3 || num==6 ||num==9){ //right
             right_hand = allocate_point(right_hand, num);
             answer+="R";
        }
        else{ //use closer one
            int l_dist = dist(left_hand,num);
            int r_dist = dist(right_hand,num);

            if(l_dist == r_dist){ //if sanme distance use its habit finger
                if(hand =="right"){
                    right_hand = allocate_point(right_hand, num);
                    answer+="R";
                }
                else{
                    left_hand = allocate_point(left_hand, num);
                    answer+="L";
                }
            }
            else{
                int closer = l_dist > r_dist ? 0 : 1; // left closer : 1, right_closer : 0
                if(closer==1){
                    left_hand = allocate_point(left_hand, num);
                    answer+="L";
                }else{
                    right_hand = allocate_point(right_hand, num);
                    answer+="R";
                }
            }
        }
    }
    return answer;
}

int main(){

    vector<int> numbers ={1, 3, 4, 5, 8, 2, 1, 4, 5, 9, 5};
    string hand = "right";

    solution(numbers, hand);
    return 0;
}