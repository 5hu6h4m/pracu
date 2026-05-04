#include<iostream>
using namespace std;

struct Pair{
    int min;
    int max;
};

Pair find_min_max(int arr[], int low, int high){
    Pair p, left, right;
    
    //only one element
    if (low==high){
        p.max=p.min=arr[low];
        return p;
    }
    
    //two elements
    if(high==low+1){
        if(arr[low]>arr[high]){
            p.min = arr[high];
            p.max = arr[low];
        }else{
            p.min = arr[low];
            p.max = arr[high];
        }
        return p;
    }
    
    //more than 2 elements
    int mid = (low+high)/2;
    left = find_min_max(arr,low,mid);
    right = find_min_max(arr,mid+1,high);
    p.min = (left.min < right.min) ? left.min : right.min;
    p.max = (left.max > right.max) ? left.max : right.max;
    
    return p;
}


int main(void){
    int n;
    cout<< "Enter range of array : ";
    cin >> n;
    
    int arr[n];
    cout << "Enter elements of array : ";
    for (int i=0; i<n; i++){
        cin >> arr[i];
    }
    
    Pair result = find_min_max(arr,0,n-1);
    cout<< "Minimum value is : " << result.min << endl;
    cout<< "Maximum value is : " << result.max;
}