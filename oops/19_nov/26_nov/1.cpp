//create a program in cpp that simulate an event scheduler with custom Epoch
#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
using namespace std;
struct Event {
    string name;
    time_t epochTime; // Custom Epoch time

    Event(string n, time_t e) : name(n), epochTime(e) {}
};
void displayEvents(const vector<Event>& events) {
    cout << "\nScheduled Events:\n";
    for (const auto& event : events) {
        cout << "Event: " << event.name << ", Epoch Time: " << event.epochTime << "\n";
    }
}
int main() {
    vector<Event> events;
    int n;
    cout << "Enter number of events to schedule: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        string eventName;
        time_t eventEpoch;
        cout << "Enter name of event " << (i + 1) << ": ";
        cin >> eventName;
        cout << "Enter epoch time for event " << (i + 1) << ": ";
        cin >> eventEpoch;
        events.emplace_back(eventName, eventEpoch);
    }
    displayEvents(events);
    // Sort events based on epoch time
    sort(events.begin(), events.end(), [](const Event& a, const Event& b) {
        return a.epochTime < b.epochTime;
    });
    cout << "\nEvents sorted by Epoch Time:\n";
    displayEvents(events);
    return 0;
}