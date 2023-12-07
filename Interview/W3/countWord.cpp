#include <bits/stdc++.h>
using namespace std;

int main()
{

    string str="I love Bd";
    int count=0;

    for(char ch: str)
    {
        if(ch == ' ') count++;
    }

    cout<< count+1;
    return 0;

}