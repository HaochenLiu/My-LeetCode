/*
146. LRU Cache
http://www.cnblogs.com/x1957/p/3485053.html
http://www.cplusplus.com/reference/list/list/splice/

Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and set.

get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
set(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.
*/

struct CacheNode{
    int key;
    int value;
    CacheNode(int k , int v) : key(k), value(v){}
};
class LRUCache{
public:
    LRUCache(int capacity) {
        size = capacity;
    }
    
    int get(int key) {
        if(cacheMap.find(key) != cacheMap.end()) {
            auto it = cacheMap[key];
            cacheList.splice(cacheList.begin(), cacheList , it);
            cacheMap[key] = cacheList.begin();
            return cacheList.begin()->value;
        } else {
            return -1;
        }
    }
    
    void set(int key, int value) {
        if (cacheMap.find(key) != cacheMap.end()) {
            auto it = cacheMap[key];
            cacheList.splice(cacheList.begin(), cacheList , it);
            cacheMap[key] = cacheList.begin();
            cacheList.begin()->value = value;
        } else {
            if(cacheList.size() == size) {
                cacheMap.erase(cacheList.back().key);
                cacheList.pop_back();
            }
            cacheList.push_front(CacheNode(key, value));
            cacheMap[key] = cacheList.begin();
        }
    }
private:
    int size;
    list<CacheNode> cacheList;
    unordered_map<int, list<CacheNode>::iterator > cacheMap;
};
