#include<bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=a;i<b;i++)

int n;
double x[100],d[100][100];

void difference()
{
    FOR(j,1,n)
        FOR(i,0,n-j)
            d[i][j]=(d[i+1][j-1]-d[i][j-1])
                    /(x[i+j]-x[i]);
}

double divide(double val)
{
    double y=d[0][0],c=1;

    FOR(i,1,n)
    {
        c*=val-x[i-1];
        y+=c*d[0][i];
    }

    return y;
}

double error(double a,double b)
{
    return fabs(a-b);
}

void printTable()
{
    cout<<"\nDivided Difference Table:\n\n";

    FOR(i,0,n)
    {
        FOR(j,0,n-i)
            cout<<setw(12)<<d[i][j];
        cout<<endl;
    }
}

void printPolynomial()
{
    cout<<"\nPolynomial:\n";
    cout<<"y = "<<d[0][0];

    FOR(i,1,n)
    {
        if(fabs(d[0][i])<1e-9) continue;

        if(d[0][i]>=0)
            cout<<" + "<<d[0][i];
        else
            cout<<" - "<<-d[0][i];

        FOR(j,0,i)
            cout<<"(x-"<<x[j]<<")";
    }

    cout<<endl;
}

int main()
{
    cin>>n;

    FOR(i,0,n)
        cin>>x[i]>>d[i][0];

    difference();
    printTable();

    double s1=divide(18);
    double s2=divide(17);

    cout<<"\nSolution 1 = "<<s1<<endl;
    cout<<"Solution 2 = "<<s2<<endl;

    cin>>x[n]>>d[n][0];
    n++;

    difference();

    double ns1=divide(18);
    double ns2=divide(17);

    cout<<"\nNew Solution 1 = "<<ns1<<endl;
    cout<<"New Solution 2 = "<<ns2<<endl;

    cout<<"\nError 1 = "<<error(s1,ns1)<<endl;
    cout<<"Error 2 = "<<error(s2,ns2)<<endl;

    printPolynomial();
}
