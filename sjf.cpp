# include<iostream>
# include<vector>
using namespace std;
int mat[10][6];
int main()
{
    int n,arr,bur,tempa,tempb;
    cout<<"Enter the no of processes:";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cout<<"Enter arrival time :";
        cin>>arr;
        mat[i][0]=arr;
        cout<<"Enter burst time :";
        cin>>bur;
        mat[i][1]=bur;
    }
    for(int i=0;i<n;i++)
    {
        if(mat[i][0]==0)
        {
            tempa=mat[0][0];
            tempb=mat[0][1];
            mat[0][0]=mat[i][0];
            mat[0][1]=mat[i][1];
            mat[i][0]=tempa;
            mat[i][1]=tempb;
            break;
        }
    }
    int j;
    for(int i=2;i<n;i++)
    {
        int key=mat[i][1];
        int keyarr=mat[i][0];
        j=i-1;
        while(j>=1 && mat[j][1]>key)
        {
            mat[j+1][1]=mat[j][1];
            mat[j+1][0]=mat[j][0];
            j=j-1;
        }
        mat[j+1][1]=key;
        mat[j+1][0]=keyarr;
    }
    mat[0][2]=0;
    mat[0][3]=mat[0][1];
    for(int i=1;i<n;i++)
    {
        mat[i][2]=mat[i-1][2]+mat[i-1][1];
        mat[i][3]=mat[i][1]+mat[i-1][3];
    }
    for(int i=0;i<n;i++)
    {
        mat[i][4]=mat[i][3]-mat[i][0];
        mat[i][5]=mat[i][2]-mat[i][0];
    }
    float avg_tat=0,avg_wt=0;
    for(int i=0;i<n;i++)
    {
        avg_tat=avg_tat+mat[i][4];
        avg_wt=avg_wt+mat[i][5];
    }
    cout<<endl;
    cout<<"Average turn around time"<<avg_tat*1.0/n<<endl;
    cout<<"Average waiting time"<<avg_wt*1.0/n<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<mat[i][0]<<" "<<mat[i][1]<<" "<<mat[i][2]<<" "<<mat[i][3]<<" "<<mat[i][4]<<" "<<mat[i][5]<<endl;
    }
    return 0;
}