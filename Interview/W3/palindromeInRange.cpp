#include <bits/stdc++.h>
using namespace std;

bool isPalindromeNumber(int n)
    {
        int rev=0;
        for(int i=n; i>0; i/=10)
        {
            rev= rev*10 + i%10;
        }
        return n==rev;
    }

int main()
{
    int l,h;
    cout<<"Enter Low Limit: ";
    cin>>l;
    cout<<endl;

    cout<<"Enter High Limit: ";
    cin>>h;
    cout<<endl;

    vector<int> ans;


    for(int i=l; i<=h; i++)
    {
        if(i<10) ans.push_back(i);
        else if( isPalindromeNumber(i) ) ans.push_back(i);
    }

    for(int num: ans)
    {
        cout<<num<<" ";
    }
    return 0;

}