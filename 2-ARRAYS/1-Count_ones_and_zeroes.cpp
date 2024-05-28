#include<iostream>
using namespace std;

pair<int,int> count_zeroes_and_ones(int arr[],int size){

    int countZeroes = 0 , countOnes = 0;
    for(int i=0;i<size;i++){
        if(arr[i] == 0){
            countZeroes++;
        }else{
            countOnes++;
        }
    }

    return {countZeroes,countOnes};
}

int main(){
    int arr[] = {1,1,1,0,0,0,1,0,0,1,1,0,0,0,1};
    int size = sizeof(arr)/sizeof(int);

    pair<int,int> p = count_zeroes_and_ones(arr,size);

    cout<<"No. of Zeroes in list: "<<p.first<<endl;
    cout<<"No. of Ones in list: "<<p.second<<endl;
    return 0;
}