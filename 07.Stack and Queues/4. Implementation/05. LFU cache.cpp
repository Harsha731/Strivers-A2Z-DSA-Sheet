/*
1. Cache Initialization
When the cache is created, it initializes:
    capacity: The maximum number of key-value pairs it can hold.
    minFreq: Tracks the minimum frequency in the cache.
    Supporting data structures:
        keyVal: Maps keys to {value, frequency}.
        freqList: Maps frequencies to lists of keys.
        pos: Maps keys to their position (iterator) in freqList.

2. get(key)
If Key Exists:
    Retrieve the key's value.
    Increase the key's frequency in keyVal.
    Remove the key from its current frequency list (freqList).
    Add the key to the list of the new, incremented frequency.
    Update the pos map with the key's new position.
    If the list for minFreq is empty, increment minFreq.
If Key Doesn't Exist:  Return -1.

3. put(key, value)
If Capacity is 0:
    Do nothing.

If Key Already Exists:
    Update the key's value in keyVal.
    Follow the same steps as get(key) to update the frequency.

If Key is New:
    Cache is Full:
    Remove the least frequently used key (freqList[minFreq].front()).
    Delete this key from keyVal, freqList, and pos.
    Add the new key with frequency 1.
    Reset minFreq to 1.

4. Eviction (When Cache is Full)
    Least Frequently Used (LFU):
        Use minFreq to find the list of keys with the minimum frequency.
    Least Recently Used (LRU) Within LFU:
        Use pop_front() to remove the oldest (least recently used) key in the minFreq list.

5. Edge Cases
Cache Capacity = 0:
No operations can be performed.

All Keys Have Same Frequency:
The LRU key among these is evicted when capacity is full.  using pop_front()

Multiple Frequency Levels:
The key with the lowest frequency (minFreq) is evicted, even if other keys are recently used.
*/
__________________________________

class LFUCache {
    int capacity; // Maximum capacity of the cache
    int minFreq; // Current minimum frequency
    unordered_map<int, pair<int, int>> keyVal; // Stores key and its {value, frequency}
    unordered_map<int, list<int>> freqList; // Maps frequency to a list of keys
    unordered_map<int, list<int>::iterator> pos; // Maps key to its position in the list, the value is a iterator of list and not list

public:
    LFUCache(int capacity) {
        this->capacity = capacity;
        minFreq = 0;
    }

    // Get the value of the key if it exists in the cache
    int get(int key) {
        if (keyVal.find(key) == keyVal.end()) // Key not found
            return -1;

        // Update the frequency list
        freqList[keyVal[key].second].erase(pos[key]);
        keyVal[key].second++; // Increment the frequency
        freqList[keyVal[key].second].push_back(key); // Add to new frequency list
        pos[key] = --freqList[keyVal[key].second].end(); // Update position       
        // Important step  -  pos is updated to the end of the list having keyVal[key].second frequency

        // Update minimum frequency if the old list is empty
        if (freqList[minFreq].empty())
            minFreq++;

        return keyVal[key].first; // Return the value
    }

    // Add or update the value of a key in the cache
    void put(int key, int value) {
        if (!capacity) // If capacity is 0, do nothing
            return;

        if (keyVal.find(key) != keyVal.end()) {
            // Key already exists, update its value and frequency
            keyVal[key].first = value;

            // These 6 lines are same as put() fucntion
            freqList[keyVal[key].second].erase(pos[key]);
            keyVal[key].second++;
            freqList[keyVal[key].second].push_back(key);
            pos[key] = --freqList[keyVal[key].second].end();    
            if (freqList[minFreq].empty())
                minFreq++;                                      // The above 6 lines are same as in get() fucntion

            return;
        }

        // If the cache is full, remove the least frequently used key
        if (keyVal.size() == capacity) {
            int delKey = freqList[minFreq].front(); // Get the least frequently used key
            keyVal.erase(delKey); // Remove it from key-value map
            pos.erase(delKey); // Remove its position
            freqList[minFreq].pop_front(); // Remove it from frequency list     // why pop_front() ?
        }

        // Add the new key with frequency 1
        keyVal[key] = {value, 1};
        freqList[1].push_back(key);
        pos[key] = --freqList[1].end();
        minFreq = 1; // Reset minimum frequency to 1
    }
};
