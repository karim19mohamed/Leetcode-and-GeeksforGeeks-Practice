class Solution {
private:
    map <string,bool> m;
    map <string,int> num;
public:
    vector<string> getFolderNames(vector<string>& names) {
        
        for (int i=0;i<names.size();++i){
            if (m[names[i]]){
                int k=1;
                string tmp;
                if (num[names[i]]) k = num[names[i]];
                tmp=names[i]+"("+to_string(k)+")";
                while (m[tmp]){
                    ++k;
                    tmp=names[i]+"("+to_string(k)+")";
                }
                num[names[i]]=k+1;
                names[i]=tmp;
            }
            
            m[names[i]]=1;
        }
        return names;
    }
};