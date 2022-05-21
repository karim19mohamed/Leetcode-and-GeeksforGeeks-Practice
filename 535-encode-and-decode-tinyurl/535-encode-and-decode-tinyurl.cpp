class Solution {
private:
    map<string,string> encode_map;
    map<string,string> decode_map;
    int id = 0;
public:
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        string ret = "http://tinyurl.com/"+to_string(id);
        encode_map[longUrl] = ret;
        decode_map[ret] = longUrl;
        return ret;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        string ret = decode_map[shortUrl];
        return ret;
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));