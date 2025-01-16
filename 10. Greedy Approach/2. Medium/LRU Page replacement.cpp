void LRUPageReplacement(int pages[], int n, int capacity) {
    list<int> cache; // Doubly linked list to represent cache
    unordered_map<int, list<int>::iterator> pageMap; // Maps page to its position in cache
    int pageFaults = 0;

    for (int i = 0; i < n; i++) {
        int page = pages[i];

        // If the page is not in the cache
        if (pageMap.find(page) == pageMap.end()) {
            // If the cache is full, remove the least recently used page
            if (cache.size() == capacity) {
                int lru = cache.back(); // Least recently used page is at the back
                cache.pop_back(); // Remove it from the cache
                pageMap.erase(lru); // Remove its entry from the map
            }

            // Add the current page to the cache (front)
            cache.push_front(page);
            pageMap[page] = cache.begin();
            pageFaults++; // Increment page fault count
        } else {
            // If the page is already in the cache, move it to the front
            cache.erase(pageMap[page]);
            cache.push_front(page);
            pageMap[page] = cache.begin();
        }

        // Print current cache state
        cout << "Cache state after accessing page " << page << ": ";
        for (auto it : cache) {
            cout << it << " ";
        }
        cout << endl;
    }

    cout << "\nTotal Page Faults: " << pageFaults << endl;
}
