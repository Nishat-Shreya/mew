#include<bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a); i<(b); i++)

int n;
double h=5;
double x[100], d[100][100], p[100];

void difference()
{
    FOR(j,1,n)
        FOR(i,0,n-j)
            d[i][j] = d[i+1][j-1] - d[i][j-1];
}

double forward(double val)
{
    double u = (val-x[0])/h;
    double y = d[0][0];
    double c = 1;

    FOR(k,1,n)
    {
        c = c*(u-k+1)/k;
        y += c*d[0][k];
    }

    return y;
}

void printPoly(double p[], int n)
{
    for(int i=n-1; i>=0; i--)
    {
        if(fabs(p[i])<1e-9)
            continue;

        if(i<n-1 && p[i]>0)
            cout<<" + ";

        if(p[i]<0)
            cout<<" - ";

        double c=fabs(p[i]);

        if(i==0)
            cout<<c;
        else
        {
            if(c!=1)
                cout<<c;

            cout<<"x";

            if(i>1)
                cout<<"^"<<i;
        }
    }

    cout<<endl;
}

void makePolynomial()
{
    p[2] = d[0][2]/(2*h*h);

    p[1] = d[0][1]/h
         - p[2]*(2*x[0]+h);

    p[0] = d[0][0]
         - p[1]*x[0]
         - p[2]*x[0]*x[0];
}

int main()
{
    cout<<"Enter number of data points: ";
    cin>>n;

    cout<<"\nEnter x and y values:\n";

    FOR(i,0,n)
        cin>>x[i]>>d[i][0];

    difference();

    cout<<"\n(a) Forward Difference Table:\n\n";

    FOR(i,0,n)
    {
        FOR(j,0,n-i)
            cout<<setw(10)<<d[i][j];

        cout<<endl;
    }

    makePolynomial();

    cout<<"\n(b) Polynomial:\n";
    cout<<"S(x) = ";
    printPoly(p,3);

    double s18=forward(18);
    double s17=forward(17);

    cout<<"\nS(18) = "<<s18<<endl;
    cout<<"S(17) = "<<s17<<endl;

    // Given S(25) = 950
    x[n]=25;
    d[n][0]=950;
    n++;

    difference();

    double new_s18=forward(18);

    cout<<"\nNew S(18) = "<<new_s18<<endl;

    cout<<"Truncation Error = "
        <<fabs(new_s18-s18)<<endl;
}