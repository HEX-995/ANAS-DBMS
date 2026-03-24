#include <bits/stdc++.h>

using namespace std;

const int BUFFER_SIZE = 5;
const int NUM_PRODUCERS = 2;
const int NUM_CONSUMERS = 2;
const int TOTAL_ITEMS = 10;

class Semaphore {
private:
    int count;
    mutex mtx;
    condition_variable cv;

public:
    Semaphore(int initial_count) : count(initial_count) {}

    void wait() {
        unique_lock<mutex> lock(mtx);
        cv.wait(lock, [this] { return count > 0; });
        count--;
    }

    void signal() {
        unique_lock<mutex> lock(mtx);
        count++;
        cv.notify_one();
    }
};

vector<int> buffer;
Semaphore empty_slots(BUFFER_SIZE);
Semaphore full_slots(0);
Semaphore mutex_sem(1);

atomic<int> item_no(0);
atomic<int> items_produced(0);
atomic<bool> production_done(false);

void producer(int producer_id) {
    while (true) {
        mutex_sem.wait();
        if (items_produced >= TOTAL_ITEMS) {
            mutex_sem.signal();
            break;
        }
        items_produced++;
        int item = ++item_no;
        mutex_sem.signal();

        this_thread::sleep_for(chrono::milliseconds(100));

        empty_slots.wait();
        
        mutex_sem.wait();
        buffer.push_back(item);
        cout << "Producer " << producer_id << " produced item " << item
             << " | Buffer size: " << buffer.size() << endl;
        mutex_sem.signal();
        
        full_slots.signal();
    }

    mutex_sem.wait();
    if (items_produced >= TOTAL_ITEMS && !production_done) {
        production_done = true;
        for (int i = 0; i < NUM_CONSUMERS; ++i) {
            full_slots.signal();
        }
    }
    mutex_sem.signal();
}

void consumer(int consumer_id) {
    int consumed_count = 0;
    
    while (true) {
        full_slots.wait();
        
        mutex_sem.wait();
        
        if (production_done && buffer.empty()) {
            mutex_sem.signal();
            break;
        }

        if (buffer.empty()) {
            mutex_sem.signal();
            continue;
        }

        int item = buffer.back();
        buffer.pop_back();
        consumed_count++;
        cout << "Consumer " << consumer_id << " consumed item " << item
             << " | Buffer size: " << buffer.size() << endl;
        
        mutex_sem.signal();
        
        empty_slots.signal();

        this_thread::sleep_for(chrono::milliseconds(150));
    }
    
    cout << "Consumer " << consumer_id  <<" exiting"<<"("<< consumed_count << " items consumed)." << endl;
}

int main() {
    cout << "\n=== PRODUCER-CONSUMER PROBLEM USING SEMAPHORES ===\n" << endl;
    cout << "Configuration:" << endl;
    cout << "  Buffer Size: " << BUFFER_SIZE << endl;
    cout << "  Number of Producers: " << NUM_PRODUCERS << endl;
    cout << "  Number of Consumers: " << NUM_CONSUMERS << endl;
    cout << "  Total Items to Produce: " << TOTAL_ITEMS << "\n" << endl;

    vector<thread> producers, consumers;

    for (int i = 1; i <= NUM_PRODUCERS; ++i)
        producers.emplace_back(producer, i);

    for (int i = 1; i <= NUM_CONSUMERS; ++i)
        consumers.emplace_back(consumer, i);

    for (auto &p : producers) p.join();

    for (auto &c : consumers) c.join();

    cout << "\nAll " << TOTAL_ITEMS << " items produced and consumed successfully." << endl;
    cout << "Final buffer size: " << buffer.size() << "\n" << endl;

    return 0;
}