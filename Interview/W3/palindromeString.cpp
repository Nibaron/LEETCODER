#include <bits/stdc++.h>
using namespace std;

string reversed(string str)
    {
        int l=0, r=str.size()-1;

        while(l<r)
        {
            swap(str[l++], str[r--]);
            
        }
    return str;
    }

int main()
{
    string str="abba";
    string revStr= reversed(str);
    if( str == revStr ) cout<<"True";
    else cout<<"False";
     
    return 0;

}