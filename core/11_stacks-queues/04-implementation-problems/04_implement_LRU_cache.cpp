/*
Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.

Implement the LRUCache class:

    - LRUCache(int capacity): Initialize the LRU cache with positive size capacity.
    - int get(int key): Return the value of the key if the key exists, otherwise return -1.
    - void put(int key, int value): Update the value of the key if the key exists. Otherwise, add the
        key-value pair to the cache. If the number of keys exceeds the capacity from this operation,
        evict the least recently used key.

The functions get and put must each run in O(1) average time complexity.

Example 1:
Input: ["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
        [[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]

Output: [null, null, null, 1, null, -1, null, -1, 3, 4]

Explanation:
    LRUCache lruCache = new LRUCache(2);
    lruCache.put(1, 1); // cache is {1=1}
    lruCache.put(2, 2); // cache is {1=1, 2=2}
    lruCache.get(1);    // return 1
    lruCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
    lruCache.get(2);    // returns -1 (not found)
    lruCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
    lruCache.get(1);    // return -1 (not found)
    lruCache.get(3);    // return 3
    lruCache.get(4);    // return 4

Example 2:
Input: ["LRUCache","put","get"]
       [[1],[2,1],[2]

Output: [null, null, 1]

Explanation:
    LRUCache lruCache = new LRUCache(1);
    lruCache.put(2, 1); // cache is {2=1}
    lruCache.get(2);    // return 1
*/

#include <iostream>
#include <unordered_map>
#include <list>

using namespace std;

class LRUCache
{
private:
    int capacity;

    // {key, value}
    list<pair<int, int>> dll;

    // key -> iterator in list
    unordered_map<int, list<pair<int, int>>::iterator> mp;

public:
    LRUCache(int cap)
    {
        capacity = cap;
    }

    int get(int key)
    {
        // key not found
        if (mp.find(key) == mp.end())
        {
            return -1;
        }

        // move accessed node to front
        auto node = mp[key];

        int value = node->second;

        dll.erase(node);

        dll.push_front({key, value});

        mp[key] = dll.begin();

        return value;
    }

    void put(int key, int value)
    {
        // key already exists
        if (mp.find(key) != mp.end())
        {
            dll.erase(mp[key]);
        }

        // insert at front
        dll.push_front({key, value});

        mp[key] = dll.begin();

        // remove LRU
        if (dll.size() > capacity)
        {
            auto last = dll.back();

            int lru_key = last.first;

            dll.pop_back();

            mp.erase(lru_key);
        }
    }

    void display()
    {
        cout << endl
             << "Cache: [ ";
        for (auto it : dll)
        {
            cout << it.first << ":" << it.second << ", ";
        }
        cout << "]" << endl;
    }
};

int main()
{
    LRUCache cache(3);

    cache.put(1, 1);
    cache.put(2, 2);

    cache.display();

    cout << cache.get(1) << endl;

    cache.put(3, 3);

    cache.display();

    cout << cache.get(2) << endl;

    cache.put(4, 4);
    cache.display();
    cout << cache.get(1) << endl;
    cout << cache.get(3) << endl;
    cout << cache.get(4) << endl;

    return 0;
}
