class Solution {
private:
    void reverser(string &s, int st, int en){
        int cnt = 0;
        for (int i=st;i<(st+en)/2;++i){
            swap(s[i],s[en-1-cnt]);
            ++cnt;
        }
    }
    void remove_extra_spaces(string &s){
        while (s[0]==' ')
            s.erase (s.begin());
        while (s[s.size()-1]==' ')
            s.erase (s.begin()+(s.size()-1));
        for(int i=0;i<(int)s.size()-1;++i)
            if (s[i]==' ')
                while (s[i+1]==' ')
                    s.erase (s.begin()+i+1);
    }
    
public:
    string reverseWords(string s) {
        string words = s;
        remove_extra_spaces(words);
        int n = (int)words.size();
        reverser(words, 0, n);
        int st = -1, en = -1;
        for (int i=0;i<n;++i){
            if (words[i]==' '){
                en = i;
                // cout << st << " " << en << endl;
                reverser(words, st, en);
                st = -1;
                en = -1;
            }
            if (words[i]!=' ' && st==-1)
                st = i;
        }
        reverser(words, st, n);
        return words;
    }
};