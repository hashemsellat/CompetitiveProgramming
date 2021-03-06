#include<bits/stdc++.h>
using namespace std;
#define mat vector<vector<int> >
#define int long long int
#define endl '\n'
const int MOD=1e9;
mat mult(mat &a,mat &b)
{
    //n*n
    int n=a.size();
    mat ret(n,vector<int>(n,0));

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            for(int k=0; k<n; k++)
            {
                ret[i][j]+=a[i][k]*b[k][j];
                ret[i][j]%=MOD;
            }
        }
    }
    return ret;
}

mat powMat(mat a,int p)
{
    int n=a.size();
    mat ret(n,vector<int>(n,0));
    for(int i=0; i<n; i++)
        ret[i][i]=1;
    if(p<=0)
        return ret;
    if(p%2)
    {
        mat tmp=powMat(a,p-1);
        return mult(a,tmp);
    }
    else
    {
        mat tmp=powMat(a,p/2);
        return mult(tmp,tmp);
    }
}
void prnt(mat &a)
{
    int n=a.size();
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
            cout<<a[i][j]<<" ";
        cout<<endl;
    }
    cout<<endl;
}
int c[20],b[20];
main()
{
    int C;
    ios_base::sync_with_stdio(false);
    cin>>C;
    while(C--)
    {
        int k,n;
        cin>>k;
        for(int i=0; i<k; i++)
            cin>>b[i];
        for(int i=0; i<k; i++)
            cin>>c[i];
        mat l(k,vector<int>(k,0));
        for(int i=0; i<k; i++)
        {
            l[0][i]=b[i];
        }
        mat r(k,vector<int>(k,0));
        for(int i=1; i<k; i++)
        {
            r[i][i-1]=1;
        }
        for(int j=0; j<k; j++)
        {
            r[j][k-1]=c[k-1-j];
        }
        // prnt(l);
        // prnt(r);
        cin>>n;
        if(n>=k)
        {
            mat tmp=powMat(r,n-k);
            //  prnt(tmp);
            mat ret=mult(l,tmp);
            //  cout<<"..........."<<endl;
            //  prnt(ret);
            //   cout<<"..........."<<endl;
            cout<<ret[0][k-1]<<endl;
        }
        else
        {
            cout<<b[n-1]<<endl;
        }

    }
}
