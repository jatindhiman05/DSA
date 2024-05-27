#include<iostream>
using namespace std;

void floyyd_traingle(int n){
    int k = 1;
    for(int row = 0; row< n;row++){
        for(int col = 0 ; col< row + 1;col++){
            cout<< k<<" ";
            k++;
        }
        cout<<endl;
    }
}

int main(){
    floyyd_traingle(6);
    return 0;
}