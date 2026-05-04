#include<iostream>
using namespace std;

struct Job{
    char id;
    int deadline;
    int profit;
};

int main(void){
    int n;
    cout<<"Enter Nnumber of Jobs : ";
    cin>>n;
    
    Job jobs[n];
    
    cout<<"Enter Job_id, deadline, profit : \n";
    for(int i=0; i<n; i++)
        cin>>jobs[i].id>>jobs[i].deadline>>jobs[i].profit;
    
    //sort jobs by profit (bubble sort)
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-i-1; j++){
            if(jobs[j].profit < jobs[j+1].profit){
                swap(jobs[j],jobs[j+1]);
            }
        }
    }
    
    int slot[10]={0}; //time slots
    char result[10];
    
    int total_profit=0;
    
    for(int i=0; i<n; i++){
        for(int j=jobs[i].deadline; j>0; j--){
            if(slot[j]==0){
                slot[j]=1;
                result[j]=jobs[i].id;
                total_profit += jobs[i].profit;
                break;
            }
        }
    }
    
    cout<<"Selected Jobs : \n";
    for(int i=1; i<10; i++){
        if(slot[i])
            cout << result[i] << " ";
    }
    
    cout<<"\nTotal Profit : "<<total_profit;
    return 0;
    
}