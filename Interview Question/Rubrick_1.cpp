#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

vector<tuple<int, int>> cache;

void read(int offset, int length) {
    cache.push_back(make_tuple(offset, offset + length - 1));
}

void printCache() {
    vector<tuple<int, int>> mergedCache;

    sort(cache.begin(), cache.end());

    for (auto tup : cache) {
        int offset = get<0>(tup);
        int end = get<1>(tup);

        if (mergedCache.empty()) {
            mergedCache.push_back(make_tuple(offset, end));
        } else {
            tuple<int, int>& lastTup = mergedCache.back();
            int lastOffset = get<0>(lastTup);
            int lastEnd = get<1>(lastTup);

            if (lastEnd >= offset) {
                get<1>(lastTup) = max(lastEnd, end);
            } else {
                mergedCache.push_back(make_tuple(offset, end));
            }
        }
    }

    for (auto tup : mergedCache) {
        int offset = get<0>(tup);
        int end = get<1>(tup);
        int length = end - offset + 1;
        cout << "(" << offset << "," << length << ")" << endl;
    }
}

int main() {
    read(50, 2);
    printCache();
    cout << endl;
    read(60, 3);
    printCache();
    cout << endl;
    read(51, 4);

    printCache();

    return 0;
}


/Output/
(50,2)

(50,2)
(60,3)

(50,5)
(60,3)
