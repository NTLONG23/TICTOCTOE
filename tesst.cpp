#include<iostream>
using namespace std;

int checksum[2][8] = {(0,0,0,0,0,0,0,0) ,(0,0,0,0,0,0,0,0)};
int  main(){
    for (int i = 0 ; i < 2 ; i ++ ){
        for (int j = 0 ; j < 8 ; j++){
            cout << checksum[i][j] << " " ;
        }
        cout << endl; }
}