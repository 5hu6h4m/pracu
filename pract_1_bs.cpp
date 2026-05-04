#include<iostream>
using namespace std;

int binary_search(int arr[], int n, int key){
    int low=0, high=n-1,mid;
    while(low<=high){
        mid = (high+low)/2;
        if(arr[mid]==key){
            return mid;
        }else if(arr[mid]<key){
            low=mid+1;
        }else{
            high=mid-1;
        }
    }
}

int main(void){
    int n,key;
    cout << "Enter range of array : ";
    cin >> n;

    int arr[n];

    cout << "Enter elements in sorted order : ";
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    cout << "Enter key to search : ";
    cin >> key;

    int result = binary_search(arr,n,key);

    if (result != -1){
        cout << "Key found in array at index : " << result;
    }else{
        cout << "Key not found !";
    }
}