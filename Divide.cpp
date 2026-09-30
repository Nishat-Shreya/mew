#include<bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a); i<(b); i++)

int n;
double x[100], d[100][100];

void difference()
{
    FOR(j,1,n)
        FOR(i,0,n-j)
            d[i][j] = (d[i+1][j-1]-d[i][j-1])
                    / (x[i+j]-x[i]);
}

double divided(double val)
{
    double y = d[0][0];
    double c = 1;

    FOR(k,1,n)
    {
        c = c*(val-x[k-1]);
        y += c*d[0][k];
    }

    return y;
}

void printPolynomial()
{
    cout<<"y = "<<d[0][0];

    FOR(i,1,n)
    {
        if(d[0][i]>=0)
            cout<<" + "<<d[0][i];
        else
            cout<<" - "<<fabs(d[0][i]);

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

    cout<<"\n(a) Divided Difference Table:\n\n";

    FOR(i,0,n)
    {
        FOR(j,0,n-i)
            cout<<setw(12)<<d[i][j];

        cout<<endl;
    }

    cout<<"\n(b) Polynomial :\n";
    printPolynomial();

    double s18=divided(18);
    double s7=divided(7);

    cout<<"\nS(18) = "<<s18<<endl;
    cout<<"S(7) = "<<s7<<endl;

    // Given S(25) = 950
    x[n]=25;
    d[n][0]=950;
    n++;

    difference();

    double new_s18=divided(18);

    cout<<"\nNew S(18) = "<<new_s18<<endl;

    cout<<"Truncation Error = "
        <<fabs(new_s18-s18)<<endl;
}