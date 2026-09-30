#include<bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=a;i<b;i++)

int n;
double x[100],d[100][100],h;

void difference()
{
    FOR(j,1,n)
        FOR(i,0,n-j)
            d[i][j]=d[i+1][j-1]-d[i][j-1];
}

double forward(double val)
{
    double u=(val-x[0])/h;
    double y=d[0][0],c=1;

    FOR(i,1,n)
    {
        c=c*(u-i+1)/i;
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
    cout<<"\nForward Difference Table:\n\n";

    FOR(i,0,n)
    {
        FOR(j,0,n-i)
            cout<<setw(10)<<d[i][j];
        cout<<endl;
    }
}

void printPolynomial()
{
    cout<<"\nPolynomial:\n";
    cout<<"y = "<<d[0][0];

    FOR(i,1,n)
    {
        double c=d[0][i];

        FOR(j,1,i+1)
            c/=j*h;

        if(fabs(c)<1e-9) continue;

        if(c>=0) cout<<" + "<<c;
        else cout<<" - "<<-c;

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

    h=x[1]-x[0];

    difference();
    printTable();

    double s1=forward(18);
    double s2=forward(17);

    cout<<"\nSolution 1 = "<<s1<<endl;
    cout<<"Solution 2 = "<<s2<<endl;

    cin>>x[n]>>d[n][0];
    n++;

    difference();

    double ns1=forward(18);
    double ns2=forward(17);

    cout<<"\nNew Solution 1 = "<<ns1<<endl;
    cout<<"New Solution 2 = "<<ns2<<endl;

    cout<<"\nError 1 = "<<error(s1,ns1)<<endl;
    cout<<"Error 2 = "<<error(s2,ns2)<<endl;

    printPolynomial();
}
