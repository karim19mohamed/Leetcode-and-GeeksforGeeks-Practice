class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int mark[30];
        memset(mark, 0, sizeof(mark));
        for (auto c: ransomNote){
            int num = c - 'a';
            ++mark[num];
        }
        for (auto c: magazine){
            int num = c - 'a';
            --mark[num];
        }
        for (int i=0;i<30;++i){
            if (mark[i]>0)
                return false;
        }
        return true;
    }
};