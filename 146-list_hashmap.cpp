/*
146. LRU Cache

http://www.cnblogs.com/x1957/p/3485053.html
http://www.cplusplus.com/reference/list/list/splice/

Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and set.

get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
set(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.
*/

/*
get:
Time: O(1)
Space: O(1)

set:
Time: O(1)
Space: O(1)
*/

class CacheNode{
public:
    int key;
    int val;

    CacheNode(int k, int v) {
        key = k;
        val = v;
    }
};

class LRUCache{
public:
    LRUCache(int capacity) {
        size = capacity;
    }
    
    int get(int key) {
        if(CacheMap.find(key) == CacheMap.end()) return -1;
        list<CacheNode>::iterator it = CacheMap[key];
        CacheList.splice(CacheList.begin(), CacheList, it);
        return it->val;
    }
    
    void set(int key, int value) {
        if(CacheMap.find(key) == CacheMap.end()) {
            if(CacheList.size() == size) {
                CacheMap.erase(CacheList.back().key);
                CacheList.pop_back();
            }
            CacheList.push_front(CacheNode(key, value));
            CacheMap[key] = CacheList.begin();
        } else {
            list<CacheNode>::iterator it = CacheMap[key];
            it->val = value;
            CacheList.splice(CacheList.begin(), CacheList, it);
        }
    }
    
private:
    int size;
    list<CacheNode> CacheList;
    unordered_map<int, list<CacheNode>::iterator> CacheMap;
};
