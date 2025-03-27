//find the second largest element in an array without sorting
#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;


//the dumb approach
int getSecondLargest_dumb(vector<int> arr){
    int largest = arr[0], secondLargest;
    for(int i = 1; i < arr.size(); i++){
        if(arr[i] > largest) largest  = arr[i];
    }
    arr.erase(remove(arr.begin(), arr.end(), largest), arr.end());
    if(arr.size() == 0){
        return -1;
    }else{
        secondLargest = arr[0];
        for(int i = 1; i < arr.size(); i++){
            if(arr[i] > secondLargest) secondLargest  = arr[i];
        }
    }
    return secondLargest;
}

//optimal
int getSecondLargest(vector<int> &arr){
    if(arr.size() < 2) return -1;

    int largest = INT_MIN;
    int secondLargest = INT_MIN;

    for(int i = 0; i < arr.size(); i++){
        if(arr[i] > largest){
            secondLargest = largest;
            largest = arr[i];
        }
        else if(arr[i] > secondLargest && arr[i] != largest){
            secondLargest = arr[i];
        }
    }
    if(secondLargest == INT_MIN) return -1;
    else return secondLargest;
}

int main(){
    vector<int> arr = {3, 2, 1, 5, 2};
    cout << getSecondLargest_dumb(arr);
    cout << getSecondLargest(arr);
    return 0;
}