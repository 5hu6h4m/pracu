#include<iostream>
using namespace std;

void merge(int arr[], int l, int m, int r){
    int i=l, j=m+1, k=0;
    int tmp[100];
    
    while(i<=m && j<=r){
        if(arr[i] < arr[j])
            tmp[k++] = arr[i++];
        else
            tmp[k++]=arr[j++];
    }
    
    while(i<=m) tmp[k++] = arr[i++];
    while(j<=r) tmp[k++] = arr[j++];
    
    for(int i=l,k=0; i<=r;i++,k++)
        arr[i] = tmp[k];
}

void merge_sort(int arr[], int l, int r){
    if (l<r){
        int m = (l+r)/2;
        merge_sort(arr,l,m);
        merge_sort(arr,m+1,r);
        merge(arr,l,m,r);
    }
}

int main(void){
    int n;
    cout<<"enter range of array : ";
    cin>>n;
    int arr[n];
    
    cout<<"Enter values for array :";
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    
    merge_sort(arr,0,n-1);
    
    cout<<"Sorted array : ";
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
}