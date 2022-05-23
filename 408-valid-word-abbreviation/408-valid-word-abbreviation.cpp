class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        int pt = 0;
        int num = 0;
        for (auto c: abbr){
            if (num==0 && c=='0')
                return false;
            if (num>0 && (c<'0' || c>'9')){
                pt += num; 
                num = 0;
            }else if (c>='0' && c<='9'){
                num *= 10;
                num += (c-'0');
                continue;
            }
            if (pt>word.size() || word[pt]!=c)
                return false;
            ++pt;
        }
        pt += num;
        if (pt==word.size())
            return true;
        return false;
    }
};