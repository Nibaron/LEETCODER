class Solution {
public:
    int romanToInt(string s) {
        int sum=0;
    vector<char> ss;
    for (int i=0; i<s.length();i++)
     {
         ss.push_back(s[i]);
         switch(ss[i])
         {
         case 'I':
            sum+=1;
            break;
        case 'V':
            sum+=5;
            break;
        case 'X':
           sum+=10;
           break;
        case 'L':
           sum+=50;
           break;
        case 'C':
           sum+=100;
           break;
        case 'D':
           sum+=500;
           break;
        case 'M':
           sum+=1000;
           break;
         }
     }
    for (int i=1; i<s.length();i++)
     {
        if((ss[i]=='V'|| ss[i]=='X') && ss[i-1]=='I')
            sum-=1+1;
        if((ss[i]=='L'|| ss[i]=='C') && ss[i-1]=='X')
            sum-=10+10;
        if((ss[i]=='D'|| ss[i]=='M') && ss[i-1]=='C')
            sum-=100+100;
     }
        return sum;
    }
};