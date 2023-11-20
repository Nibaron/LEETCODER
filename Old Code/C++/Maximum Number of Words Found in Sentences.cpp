class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int res=0;
        for(int i=0; i<sentences.size(); i++)
         {
            int temp = count(sentences[i].begin(),sentences[i].end(),' ') + 1;
            if(temp>res)
              res = temp;
         }   
    return res;
    }
};