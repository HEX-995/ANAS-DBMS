#include <bits/stdc++.h>
using namespace std;

void displayFrames(const vector<int>& frames) {
    for (int value : frames) cout << setw(3) << (value == -1 ? "-" : to_string(value));
}

bool isPageInFrames(const vector<int>& frames, int page) {
    return find(frames.begin(), frames.end(), page) != frames.end();
}

int findEmptyFrameIndex(const vector<int>& frames) {
    for (int i = 0; i < frames.size(); i++)
        if (frames[i] == -1) return i;
    return -1;
}

void printStep(int step, int page, const vector<int>& frames, bool hit) {
    cout << "Step " << setw(2) << (step + 1) << " | Ref: " << setw(3) << page << " | Frames: ";
    displayFrames(frames);
    cout << "   => " << (hit ? "HIT" : "FAULT") << "\n";
}

void printResults(int faults, int total) {
    cout << "\nResults:\n  Total Page Faults = " << faults 
         << "\n  Page Fault Rate = " << fixed << setprecision(2) 
         << (double)faults / total * 100.0 << "%\n";
}

void simulateFIFO(const vector<int>& pageReferences, int numberOfFrames) {
    cout << "\nFIFO (First In First Out)\n";
    vector<int> frames(numberOfFrames, -1);
    queue<int> pageInsertionOrder;
    int pageFaultCount = 0;

    for (int step = 0; step < pageReferences.size(); step++) {
        int currentPage = pageReferences[step];
        bool hit = isPageInFrames(frames, currentPage);

        if (!hit) {
            pageFaultCount++;
            int emptyIndex = findEmptyFrameIndex(frames);
            
            if (emptyIndex != -1) {
                frames[emptyIndex] = currentPage;
            } else {
                int oldestPage = pageInsertionOrder.front();
                pageInsertionOrder.pop();
                for (int i = 0; i < numberOfFrames; i++) {
                    if (frames[i] == oldestPage) {
                        frames[i] = currentPage;
                        break;
                    }
                }
            }
            pageInsertionOrder.push(currentPage);
        }
        printStep(step, currentPage, frames, hit);
    }
    printResults(pageFaultCount, pageReferences.size());
}

void simulateOptimal(const vector<int>& pageReferences, int numberOfFrames) {
    cout << "\nOptimal\n";
    vector<int> frames(numberOfFrames, -1);
    int pageFaultCount = 0;

    for (int step = 0; step < pageReferences.size(); step++) {
        int currentPage = pageReferences[step];
        bool hit = isPageInFrames(frames, currentPage);

        if (!hit) {
            pageFaultCount++;
            int emptyIndex = findEmptyFrameIndex(frames);
            
            if (emptyIndex != -1) {
                frames[emptyIndex] = currentPage;
            } else {
                int pageToReplaceIndex = 0, farthestFutureUse = -1;
                
                for (int i = 0; i < numberOfFrames; i++) {
                    int nextUsePosition = -1;
                    for (int j = step + 1; j < pageReferences.size(); j++) {
                        if (pageReferences[j] == frames[i]) {
                            nextUsePosition = j;
                            break;
                        }
                    }
                    if (nextUsePosition == -1) {
                        pageToReplaceIndex = i;
                        break;
                    }
                    if (nextUsePosition > farthestFutureUse) {
                        farthestFutureUse = nextUsePosition;
                        pageToReplaceIndex = i;
                    }
                }
                frames[pageToReplaceIndex] = currentPage;
            }
        }
        printStep(step, currentPage, frames, hit);
    }
    printResults(pageFaultCount, pageReferences.size());
}

void simulateLRU(const vector<int>& pageReferences, int numberOfFrames) {
    cout << "\nLRU (Least Recently Used)\n";
    vector<int> frames(numberOfFrames, -1);
    unordered_map<int, int> pageLastUsedTime;
    int pageFaultCount = 0;

    for (int step = 0; step < pageReferences.size(); step++) {
        int currentPage = pageReferences[step];
        bool hit = isPageInFrames(frames, currentPage);

        if (hit) {
            pageLastUsedTime[currentPage] = step;
        } else {
            pageFaultCount++;
            int emptyIndex = findEmptyFrameIndex(frames);
            
            if (emptyIndex != -1) {
                frames[emptyIndex] = currentPage;
            } else {
                int leastRecentlyUsedIndex = 0, oldestTime = INT_MAX;
                for (int i = 0; i < numberOfFrames; i++) {
                    if (pageLastUsedTime[frames[i]] < oldestTime) {
                        oldestTime = pageLastUsedTime[frames[i]];
                        leastRecentlyUsedIndex = i;
                    }
                }
                pageLastUsedTime.erase(frames[leastRecentlyUsedIndex]);
                frames[leastRecentlyUsedIndex] = currentPage;
            }
            pageLastUsedTime[currentPage] = step;
        }
        printStep(step, currentPage, frames, hit);
    }
    printResults(pageFaultCount, pageReferences.size());
}

int main() {
    int referenceStringLength;
    cout << "Enter length of reference string: ";
    while (!(cin >> referenceStringLength) || referenceStringLength <= 0) {
        cout << "Enter a positive integer: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    vector<int> pageReferences(referenceStringLength);
    cout << "Enter the reference string :";
    for (int i = 0; i < referenceStringLength; i++) cin >> pageReferences[i];

    int numberOfFrames;
    cout << "Enter number of frames available in memory: ";
    while (!(cin >> numberOfFrames) || numberOfFrames <= 0) {
        cout << "Enter a positive integer: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    simulateFIFO(pageReferences, numberOfFrames);
    simulateOptimal(pageReferences, numberOfFrames);
    simulateLRU(pageReferences, numberOfFrames);

    return 0;
}