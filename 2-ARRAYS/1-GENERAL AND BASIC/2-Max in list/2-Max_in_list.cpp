#include<iostream>
#include<limits.h>
using namespace std;

int find_max(int arr[],int size){
    int max_elem = INT_MIN;

    for(int i=0;i<size;i++){
        if(arr[i] > max_elem){
            max_elem = arr[i];
        }
    }

    return max_elem;
}

int main(){
    int arr[] = {2,4,6,1,3,7,9,12,56,43,21};
    int size = 11;

    int max = find_max(arr,size);

    cout<<"Maximum element in array is: "<<max;
    return 0;
}