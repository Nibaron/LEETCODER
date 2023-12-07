#include<bits/stdc++.h>
using namespace std;

class solution{
    public:
    vector<int> prime(int l, int r)
    {   vector<int> ans;
        for(int i=l; i<=r; i++)
        {
            if(i==0 || i==1) continue;

            bool flag=true;
            for(int j=2; j<=i/2; j++)
            {
                if(i % j == 0)
                {
                    flag=false;
                    break;
                }
            }
            if(flag == true) 
            {
                ans.push_back(i);
            } 
        }
        return ans;
    }
};

int main()
{
    int l,r;
    cout<<"Enter low limit: ";
    cin>>l;
    cout<<endl<<"Enter high limit: ";
    cin>>r;

    vector<int>ans;
    solution obj;
    ans= obj.prime(l,r);

    for(int num: ans)
    {
        cout<<num<<" ";
    }
    return 0;
}