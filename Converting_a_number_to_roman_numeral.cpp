#include<iostream>
using namespace std;

string roman(int n)
{
    string r="";
    string s="IVXLCDM";
    int i=100;
    while(n>1000)
    {
        r+=s[6];
        n-=1000;
    }
    for(int c=4;c>=0;c-=2)
    {
        int q=n/i;
        if(q==9)
        {
            r=r+s[c]+s[c+2];
        }
        else if(q>4)
        {
            r+=s[c+1];
            for(int j=0;j<q-5;j++)
            {
                r+=s[c];
            }
        }
        else if(q==4)
        {
            r=r+s[c]+s[c+1];
        }
        else if(q>0)
        {
            for(int j=0;j<q;j++)
            {
                r+=s[c];
            }
        }
        n%=i;
        i/=10;
    }
    return r;
}

int main()
{
    int n;
    cin>>n;
    cout<<roman(n)<<"\n";
    return 0;
}