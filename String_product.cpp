#include<iostream>
#include<string>
using namespace std;

string ssum(string a,string b)
{
    string s="";
    int cf=0,sum,i;
    int la=a.length(),lb=b.length();
    if(la>=lb)
    {
        for(i=1;i<=la;i++)
        {
            int x;
            if(lb>=i)
            {
                x=int(b[lb-i]-'0');
            }
            else
            {
                x=0;
            }
            sum=cf+int(a[la-i]-'0')+x;
            cf=sum/10;
            s=to_string(sum%10)+s;
        }
    }
    if(lb>la)
    {
        for(i=1;i<=lb;i++)
        {
            int x;
            if(la>=i)
            {
                x=int(a[la-i]-'0');
            }
            else
            {
                x=0;
            }
            sum=cf+x+int(b[lb-i]-'0');
            cf=sum/10;
            s=to_string(sum%10)+s;
        }
    }
    if(cf)
    {
        s=to_string(cf)+s;
    }
    return s;
}

string sproduct(string a,string b)
{
    string p="";
    int la=a.length(),lb=b.length();
    for(int i=1;i<=lb;i++)
    {
        string s="";
        int cf=0,sum,n1=int(b[lb-i]-'0');
        for(int j=1;j<=la;j++)
        {
            sum=cf+n1*(int(a[la-j]-'0'));
            cf=sum/10;
            s=to_string(sum%10)+s;
        }
        if(cf)
        {
            s=to_string(cf)+s;
        }
        for(int k=1;k<i;k++)
        {
            s+="0";
        }
        p=ssum(p,s);
    }
    return p;
}

int main()
{
    while(1)
    {
        string a,b;
        cin>>a>>b;
        cout<<"product="<<sproduct(a,b)<<"\n";
    }
    return 0;
}