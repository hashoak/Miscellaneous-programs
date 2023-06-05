#include<iostream>
using namespace std;

void print(int s[9][9])
{
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++) cout<<s[i][j]<<" ";
        cout<<"\n";
    }
    cout<<"\n";
    return;
}

bool check(int s[9][9],int p,int q,int a)
{
    int i,j,n=p/3,m=q/3;
    for(i=0;i<9;i++)
    {
        if(s[i][q]==a) return 0;
    }
    for(j=0;j<9;j++)
    {
        if(s[p][j]==a) return 0;
    }
    for(i=n*3;i<n*3+3;i++)
    {
        for(j=m*3;j<m*3+3;j++)
        {
            if(s[i][j]==a) return 0;
        }
    }
    return 1;
}

void solve(int s[9][9],int p=0,int q=0)
{
    if(p==9)
    {
        print(s);
        return;
    }
    if(s[p][q]!=0)
    {
        if(q==8) solve(s,p+1,0);
        else solve(s,p,q+1);
        return;
    }
    for(int a=1;a<=9;a++)
    {
        int t[9][9];
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++) t[i][j]=s[i][j];
        }
        if(check(t,p,q,a))
        {
            t[p][q]=a;
            if(q==8) solve(t,p+1,0);
            else solve(t,p,q+1);
        }
    }
    return;
}

int main()
{
    int s[9][9];
    while(1)
    {
        cout<<"Type the numbers in the question with spaces. Fill empty cells with '0'.\n";
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++) cin>>s[i][j];
        }
        cout<<"\nPossible solution(s) is(are):\n";
        solve(s);
    }
    return 0;
}

// 0 0 0  6 7 2  0 0 8
// 6 0 0  8 0 1  7 0 0
// 8 2 0  5 0 0  3 6 1
//                      
// 0 0 0  4 1 5  8 0 7
// 3 7 4  9 0 0  0 5 0
// 1 8 0  0 6 3  9 0 0
//                      
// 0 0 6  1 5 7  2 0 0
// 0 0 0  2 0 0  0 0 0
// 2 0 0  0 9 0  5 0 0


// 5 3 1  6 7 2  4 9 8
// 6 4 9  8 3 1  7 2 5
// 8 2 7  5 4 9  3 6 1
// 
// 9 6 2  4 1 5  8 3 7
// 3 7 4  9 2 8  1 5 6
// 1 8 5  7 6 3  9 4 2
// 
// 4 9 6  1 5 7  2 8 3
// 7 5 3  2 8 4  6 1 9
// 2 1 8  3 9 6  5 7 4