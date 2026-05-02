#ifndef LRU_CACHE_H
#define LRU_CACHE_H

#include <unordered_map>
#include <list>
#include <string>
#include <mutex>

using namespace std;

class LRUCache {
private:
    int capacity;

    list<pair<string, string>> cacheList; 

    unordered_map<string, list<pair<string, string>>::iterator> cacheMap;

    mutex cacheMutex;

public:
    LRUCache(int cap);

    bool get(const string& key, string& value);
    void put(const string& key, const string& value);
};

#endif