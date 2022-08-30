#include <bits/stdc++.h>

using namespace std;

int main(){
    string str = "1234";
    string tmp = "0101";

    sort(tmp.begin(), tmp.end());

    do{
        for(int i=0; i<str.size(); i++)
            if(tmp[i]=='1') cout << str[i]<<' ';
        
        cout <<"\n";
    }while(next_permutation(tmp.begin(), tmp.end()));

    return 0;
}