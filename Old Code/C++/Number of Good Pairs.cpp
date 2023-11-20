class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int n=0;
        map<int,int> m;
        for (int i=0; i< nums.size(); i++)
        {
            m[nums[i]]++;     
        }
        for (int i=0; i< m.size(); i++)
        {
            m[i]=(m[i]*(m[i]-1))/2;
            n+=m[i];
        }
        return n;
    }
};