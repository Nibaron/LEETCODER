#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    void swapwithTemp(int &a, int &b)
    {
        int temp;
        
        temp= a;
        a=b;
        b=temp;
    
    }

    void swapwithXOR(int &a, int &b)
    {
        
        a= a ^ b;
        b= a ^ b;
        a= a ^ b;
    }
    
};

int main()
{
    int a,b;
    cout << "Enter Value of A: ";
    cin >> a;
    cout << "Enter Value of B: ";
    cin >> b;
    
    class Solution ob1;
    ob1.swapwithXOR(a,b);
    
    cout<<" Value of A= "<<a<<endl;
    cout<<" Value of B= "<<b<<endl;

    return 0;
}
