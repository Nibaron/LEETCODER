#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    vector<char> findMiddle(string sen)
    {
        vector<char> ans;
        int n= sen.size();
        string temp="";
        for(int i=0; i<n; i++)
        {
            while(sen[i] >='A' && sen[i]<='Z')
            {
                temp.push_back(sen[i++]);
            }

            if(temp.size() > 0)
            {
                int mid= temp.size()/2;
                ans.push_back(temp[mid]);
                temp="";
            }
        }
        return ans;
    }

};

int main()
{
    string sen= "NIBARON KUMAR DAS";
    Solution obj;
    vector<char> ans;
    ans= obj.findMiddle(sen);

    for(auto ch: ans)
    { 
        cout<<ch<<" ";
    }
    cout<<endl;

    return 0;
}