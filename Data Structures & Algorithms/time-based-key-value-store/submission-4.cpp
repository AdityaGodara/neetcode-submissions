class TimeMap {
public:
    map<string, map<int, string>> mp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key][timestamp] = value; 
    }
    
    string get(string key, int timestamp) {
        if(mp.find(key)==mp.end()) return "";

        auto& inner = mp[key];
        auto it = inner.upper_bound(timestamp);
        if(it == inner.begin()) return "";
        it--;
        return it->second;
    }
};
