#include <bits/stdc++.h>

using namespace std;

class DiskScheduler {
private:
    vector<int> requests;
    int initialHead;
    int diskSize;

    void printSequence(const string& algorithm, const vector<int>& sequence, int totalMovement) {
        cout << "\n" << algorithm << " Algorithm:" << endl;
        cout << string(50, '-') << endl;
        cout << "Seek Sequence: ";
        for (size_t i = 0; i < sequence.size(); i++) {
            cout << sequence[i];
            if (i < sequence.size() - 1) cout << " -> ";
        }
        cout << "\nTotal Head Movement: " << totalMovement << " cylinders" << endl;
        cout << "Average Seek Length: " << fixed << setprecision(2) 
             << (double)totalMovement / requests.size() << " cylinders" << endl;
    }

    int calculateMovement(const vector<int>& sequence) {
        int movement = 0;
        for (size_t i = 1; i < sequence.size(); i++) {
            movement += abs(sequence[i] - sequence[i-1]);
        }
        return movement;
    }

public:
    DiskScheduler(vector<int> req, int head, int size = 200) 
        : requests(req), initialHead(head), diskSize(size) {}

    // FCFS - First Come First Serve
    void FCFS() {
        vector<int> sequence;
        sequence.push_back(initialHead);
        
        for (int req : requests) {
            sequence.push_back(req);
        }
        
        int totalMovement = calculateMovement(sequence);
        printSequence("FCFS", sequence, totalMovement);
    }

    // SSTF - Shortest Seek Time First
    void SSTF() {
        vector<int> sequence;
        vector<int> remainingRequests = requests;
        int currentHead = initialHead;
        
        sequence.push_back(currentHead);
        
        while (!remainingRequests.empty()) {
            int minDistance = INT_MAX;
            int closestIndex = 0;
            
            // Find closest request
            for (size_t i = 0; i < remainingRequests.size(); i++) {
                int distance = abs(remainingRequests[i] - currentHead);
                if (distance < minDistance) {
                    minDistance = distance;
                    closestIndex = i;
                }
            }
            
            currentHead = remainingRequests[closestIndex];
            sequence.push_back(currentHead);
            remainingRequests.erase(remainingRequests.begin() + closestIndex);
        }
        
        int totalMovement = calculateMovement(sequence);
        printSequence("SSTF", sequence, totalMovement);
    }

    // SCAN - Elevator Algorithm
    void SCAN(string direction = "right") {
        vector<int> sequence;
        vector<int> left, right;
        
        // Separate requests based on initial head position
        for (int req : requests) {
            if (req < initialHead)
                left.push_back(req);
            else
                right.push_back(req);
        }
        
        sort(left.begin(), left.end());
        sort(right.begin(), right.end());
        
        sequence.push_back(initialHead);
        
        if (direction == "right") {
            // Service right side first
            for (int req : right) {
                sequence.push_back(req);
            }
            if (!right.empty() && right.back() != diskSize - 1) {
                sequence.push_back(diskSize - 1); // Go to end
            }
            // Then service left side in reverse
            reverse(left.begin(), left.end());
            for (int req : left) {
                sequence.push_back(req);
            }
        } else {
            // Service left side first
            reverse(left.begin(), left.end());
            for (int req : left) {
                sequence.push_back(req);
            }
            if (!left.empty() && left.front() != 0) {
                sequence.push_back(0); // Go to start
            }
            // Then service right side
            for (int req : right) {
                sequence.push_back(req);
            }
        }
        
        int totalMovement = calculateMovement(sequence);
        printSequence("SCAN", sequence, totalMovement);
    }

    // C-SCAN - Circular SCAN
    void CSCAN(string direction = "right") {
        vector<int> sequence;
        vector<int> left, right;
        
        for (int req : requests) {
            if (req < initialHead)
                left.push_back(req);
            else
                right.push_back(req);
        }
        
        sort(left.begin(), left.end());
        sort(right.begin(), right.end());
        
        sequence.push_back(initialHead);
        
        if (direction == "right") {
            // Service right side
            for (int req : right) {
                sequence.push_back(req);
            }
            if (!right.empty() && right.back() != diskSize - 1) {
                sequence.push_back(diskSize - 1); // Go to end
            }
            // Jump to start
            if (!left.empty()) {
                sequence.push_back(0);
                // Service left side from start
                for (int req : left) {
                    sequence.push_back(req);
                }
            }
        } else {
            // Service left side
            reverse(left.begin(), left.end());
            for (int req : left) {
                sequence.push_back(req);
            }
            if (!left.empty() && left.front() != 0) {
                sequence.push_back(0); // Go to start
            }
            // Jump to end
            if (!right.empty()) {
                sequence.push_back(diskSize - 1);
                // Service right side from end
                reverse(right.begin(), right.end());
                for (int req : right) {
                    sequence.push_back(req);
                }
            }
        }
        
        int totalMovement = calculateMovement(sequence);
        printSequence("C-SCAN", sequence, totalMovement);
    }

    // LOOK
    void LOOK(string direction = "right") {
        vector<int> sequence;
        vector<int> left, right;
        
        for (int req : requests) {
            if (req < initialHead)
                left.push_back(req);
            else
                right.push_back(req);
        }
        
        sort(left.begin(), left.end());
        sort(right.begin(), right.end());
        
        sequence.push_back(initialHead);
        
        if (direction == "right") {
            // Service right side
            for (int req : right) {
                sequence.push_back(req);
            }
            // Service left side in reverse (no going to end)
            reverse(left.begin(), left.end());
            for (int req : left) {
                sequence.push_back(req);
            }
        } else {
            // Service left side
            reverse(left.begin(), left.end());
            for (int req : left) {
                sequence.push_back(req);
            }
            // Service right side (no going to start)
            for (int req : right) {
                sequence.push_back(req);
            }
        }
        
        int totalMovement = calculateMovement(sequence);
        printSequence("LOOK", sequence, totalMovement);
    }

    // C-LOOK
    void CLOOK(string direction = "right") {
        vector<int> sequence;
        vector<int> left, right;
        
        for (int req : requests) {
            if (req < initialHead)
                left.push_back(req);
            else
                right.push_back(req);
        }
        
        sort(left.begin(), left.end());
        sort(right.begin(), right.end());
        
        sequence.push_back(initialHead);
        
        if (direction == "right") {
            // Service right side
            for (int req : right) {
                sequence.push_back(req);
            }
            // Jump to leftmost and service left side
            if (!left.empty()) {
                for (int req : left) {
                    sequence.push_back(req);
                }
            }
        } else {
            // Service left side
            reverse(left.begin(), left.end());
            for (int req : left) {
                sequence.push_back(req);
            }
            // Jump to rightmost and service right side
            if (!right.empty()) {
                reverse(right.begin(), right.end());
                for (int req : right) {
                    sequence.push_back(req);
                }
            }
        }
        
        int totalMovement = calculateMovement(sequence);
        printSequence("C-LOOK", sequence, totalMovement);
    }

    void runAll(string direction = "right") {
        cout << "\n" << string(70, '=') << endl;
        cout << "DISK SCHEDULING ALGORITHM COMPARISON" << endl;
        cout << string(70, '=') << endl;
        cout << "Initial Head Position: " << initialHead << endl;
        cout << "Disk Size: " << diskSize << " cylinders" << endl;
        cout << "Request Queue: ";
        for (size_t i = 0; i < requests.size(); i++) {
            cout << requests[i];
            if (i < requests.size() - 1) cout << ", ";
        }
        cout << endl;
        cout << "Direction: " << direction << endl;
        
        FCFS();
        SSTF();
        SCAN(direction);
        CSCAN(direction);
        LOOK(direction);
        CLOOK(direction);
        
        cout << "\n" << string(70, '=') << endl;
    }
};

int main() {
    // Example 1
    vector<int> requests1 = {98, 183, 37, 122, 14, 124, 65, 67};
    int initialHead1 = 53;
    
    DiskScheduler scheduler1(requests1, initialHead1, 200);
    scheduler1.runAll("right");
    
    // Example 2
    cout << "\n\n" << string(70, '#') << endl;
    cout << "ANOTHER EXAMPLE" << endl;
    cout << string(70, '#') << endl;
    
    vector<int> requests2 = {176, 79, 34, 60, 92, 11, 41, 114};
    int initialHead2 = 50;
    
    DiskScheduler scheduler2(requests2, initialHead2, 200);
    scheduler2.runAll("right");
    
    return 0;
}