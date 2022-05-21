class Solution {
private:
    bool neg = false;
    bool leading_char = false;
    int get_index_of_first_num(string s){
        for (int i=0;i<s.size();++i)
            if (s[i]>='0' && s[i]<='9')
                return i;
        return -1;
    }
    int get_index_of_first_char(string s){
        for (int i=0;i<s.size();++i)
            if ((s[i]<'0' || s[i]>'9') && s[i]!=' ' && s[i]!='-' && s[i]!='+')
                return i;
        return -1;
    }
    int get_sign_index(string s){
        for (int i=0;i<s.size();++i){
            if (s[i]=='-'){
                neg = true;
                return i;
            }else if (s[i]=='+'){
                return i;
            }
        }
        return -1;
    }
    string get_num(string s, int st, int en){
        string res = "";
        bool first_non_zero_num = false;
        for (int i=st;i<en;++i){
            if (!first_non_zero_num && s[i]=='0'){
                continue;
            }
            if (s[i]>='0' && s[i]<='9'){
                first_non_zero_num = true;
                res = res + s[i];
            }else{
                return res;
            }
        }
        return res;
    }
public:
    int myAtoi(string s) {
        int first_num_index = get_index_of_first_num(s);
        if (first_num_index == -1)
            return 0;
        
        int sign_index = get_sign_index(s);
        if (sign_index != first_num_index-1 && sign_index!=-1){
            if (sign_index<first_num_index){
                return 0;
            }else{
                neg = false;
            }
        }
        
        int first_char_index = get_index_of_first_char(s);
        if (first_char_index<first_num_index && first_char_index!=-1)
            return 0;
        
        // cout << "sdada" << endl;
        string res_num = get_num(s, first_num_index, (first_char_index!=-1)?first_char_index:s.size());
        // cout << res_num << endl;
        int num = 0;
        long long tmp = 0;
        for (int i=0;i<res_num.size();++i){
            tmp = tmp *10 + (res_num[i]-'0');
            if (!neg){
                if (tmp <= INT_MAX){
                    num = (int)tmp;
                }else{
                    num = INT_MAX;
                    break;
                }
            }else{
                if (-1*tmp >= INT_MIN){
                    num = (int)(-1*tmp);
                }else{
                    num = INT_MIN;
                    break;
                }
            }
            
        }
        // if (neg && num == INT_MAX ){
        //     num = INT_MIN;
        // }else if (neg){
        //     num *= -1;
        // }
        return num;
    }
};