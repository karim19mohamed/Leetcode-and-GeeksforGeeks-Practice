#include <bits/stdc++.h>
class Solution {
private:
    bool col_check(string IP){
        int num=0;
        for (int i=0;i<IP.size();++i) if (IP[i]==':') ++num;
        return num==7;
    }
    bool IP6_char_check(string IP){
        for (int i=0;i<IP.size();++i){
            if (!( (IP[i]>='a' && IP[i]<='f') || (IP[i]>='A' && IP[i]<='F') || (IP[i]>='0' && IP[i]<='9') || IP[i]==':') )
                return false;
        }
        return true;
    }
    bool IP6_section_size(string IP){
        int s=0;
        for (int i=0;i<IP.size();++i){
            if (s>4) return false;
            if (IP[i]==':'){
                if (s==0) return false;
                s=0;
            } else{
                ++s;
            }
        }
        return (s<=4 && s!=0);
    }
    bool dot_check(string IP){
        int num=0;
        for (int i=0;i<IP.size();++i) if (IP[i]=='.') ++num;
        return num==3;
    }
    bool IP4_char_check(string IP){
        for (int i=0;i<IP.size();++i){
            if (!( (IP[i]>='0' && IP[i]<='9') || IP[i]=='.') )
                return false;
        }
        return true;
    }
    bool IP4_section_size(string IP){
        int s=0;
        for (int i=0;i<IP.size();++i){
            if (IP[i]=='.'){
                if (s==0) return false;
                s=0;
            } else{
                ++s;
            }
        }
        return (s<=3 && s!=0);
    }
    bool IP4_num_check(string IP){
        if (IP[0]=='0' && IP[1]!='.') return false;
        string num="";
        for (int i=0;i<IP.size();++i){
            if (IP[i]=='.'){
                if (IP[i+1]=='0'){
                    if (i+2!=IP.size()){
                        if (IP[i+2]!='.') return false;
                    }
                }
                int tmp=std::stoi(num);
                if (tmp<0 || tmp>255) return false;
                num="";
            }else{
                num+=IP[i];
            }
        }
        int tmp=std::stoi(num);
        return (tmp<0 || tmp>255)? false : true;
    }
    
    
public:
    
    string validIPAddress(string IP) {
        //cout<<col_check(IP)<<dot_check(IP)<< endl;
        if (col_check(IP)){
            if (IP6_char_check(IP) && IP6_section_size(IP)) return "IPv6";
        }else if (dot_check(IP)){
            if (IP4_char_check(IP)&&IP4_section_size(IP)&&IP4_num_check(IP)) return "IPv4";
        }
        return "Neither";
    }
};















