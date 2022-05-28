class Solution {
public:
    string largestWordCount(vector<string>& messages, vector<string>& senders) {
        map<string,int> m;
        for (int i=0;i<messages.size();++i){
            m[senders[i]]++;
            for(auto c:messages[i]){
                if (c==' '){
                    m[senders[i]]++;
                }
            }
        }
        string ans = "";
        int cnt = -1;
        for (auto s:senders){
            if (m[s]>cnt){
                ans = s;
                cnt = m[s];
            }else if (m[s]==cnt && s>ans){
                ans = s;
            }
        }
        return ans;
    }
};