class AuthenticationManager {
private:
    map<string,int> token_to_time;
    int TTL;
public:
    AuthenticationManager(int timeToLive) {
        TTL = timeToLive;
        token_to_time.erase ( token_to_time.begin(), token_to_time.end() );
    }
    
    void generate(string tokenId, int currentTime) {
        token_to_time[tokenId] = currentTime;
    }
    
    void renew(string tokenId, int currentTime) {
        if (token_to_time.count( tokenId )){
            int expiration_date = token_to_time[tokenId] + TTL;
            if (currentTime<expiration_date)
                token_to_time[tokenId] = currentTime;
        }
    }
    
    int countUnexpiredTokens(int currentTime) {
        int ans = 0;
        map<string, int>::iterator it;
        for (it = token_to_time.begin(); it != token_to_time.end(); it++){
            int expiration_date = it->second + TTL;
            if (currentTime<expiration_date)
                ++ans;
        }
        return ans;
    }
};

/**
 * Your AuthenticationManager object will be instantiated and called as such:
 * AuthenticationManager* obj = new AuthenticationManager(timeToLive);
 * obj->generate(tokenId,currentTime);
 * obj->renew(tokenId,currentTime);
 * int param_3 = obj->countUnexpiredTokens(currentTime);
 */