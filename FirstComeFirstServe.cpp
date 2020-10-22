#include <iostream>
# include<vector>
using namespace std;
void sortibg(vector<int> &arrtime,vector<int> &burst)
{
    int i, key, j,keybur;  
    for (i = 1; i < arrtime.size(); i++) 
    {  
        key = arrtime[i];  
        keybur = burst[i];
        j = i - 1;  
        while (j >= 0 && arrtime[j] > key) 
        {  
            arrtime[j + 1] = arrtime[j];  
            burst[j+1]=burst[j];
            j = j - 1;  
        }  
        arrtime[j + 1] = key;  
        burst[j+1]=keybur;
    }  
}
int main() 
{
    int n;
    vector<int>arrtime,burst,response,gant;
    cout<<"Enter the number of processes:";
    cin>>n;
    int atime,btime;
    //INPUT
    for(int i=0;i<n;i++)
    {
        cout<<"Enter arrival time for process"<<i+1;
        cin>>atime;
        arrtime.push_back(atime);
        cout<<"Enter burst time for the process"<<i+1;
        cin>>btime;
        burst.push_back(btime);
    }
    //sort 
    sortibg(arrtime,burst);
    cout<<"\narrtime";
    for(int i=0;i<n;i++)
    {
     cout<<arrtime[i]<<" ";
    }


    gant.push_back(0);
    vector<int>c;
        c.push_back(0);
    for(int i=1;i<n;i++)
    {
     if(arrtime[i]>burst[i-1])
     {
     gant[i]=arrtime[i];
     c.push_back(arrtime[i]-burst[i-1]);
     }
     else
     {
     gant[i]=gant[i-1]+burst[i-1];
     c.push_back(0);
     }
    }
    vector<int> gantend;
    gantend.push_back(burst[0]);

    for(int i=1;i<n;i++)
        gantend[i]=gantend[i-1]+burst[i]+c[i];

    float avg_responsetime=0;
    
    cout<<"\n c";
    for(int i=0;i<n;i++)
    {
     cout<<c[i]<<" ";
    }
    cout<<"\n arrtime";
    for(int i=0;i<n;i++)
    {
     cout<<arrtime[i]<<" ";
    }
    cout<<"\n burst";
    for(int i=0;i<n;i++)
    {
     cout<<burst[i]<<" ";
    }
    cout<<"\n gant";
    for(int i=0;i<n;i++)
    {
     cout<<gant[i]<<" ";
    }
    cout<<"\n gantend";
    for(int i=0;i<n;i++)
    {
        cout<<gantend[i]<<" ";
    }
    cout<<"\n";

    for(int i=0;i<n;i++)
    {
        avg_responsetime=avg_responsetime+gant[i]-arrtime[i];
        cout<<"responsetime"<<i<<" "<<avg_responsetime<<"\n";
    }
    avg_responsetime=avg_responsetime/n;
    cout<<"\n average waiting time "<<avg_responsetime;
    float average_tat=0;
    for(int i=0;i<n;i++)
        average_tat=average_tat+gantend[i]-arrtime[i];
    average_tat=average_tat/n;
    cout<<"\n average turn around time "<<average_tat;
    int sum=0;
    for(int i=0;i<n;i++)
        sum=sum+c[i];
    float used_time=gantend[n-1]-sum;
    float cpu_utilization=(used_time/gantend[n-1]);
    cout<<"\ncpu_utilization "<<cpu_utilization*100;
    double throughput;
    cout<<"\n throughput "<<(n*1.0/gantend[n-1]);
    return 0;
}
