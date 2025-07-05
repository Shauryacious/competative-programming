#include <iostream>
#include <thread>
#include <semaphore> // C++20
#include <queue>

using namespace std;

binary_semaphore emptySlots(1); // Semaphore to control empty slots
binary_semaphore fullSlots(0); // Semaphore to control full slots

queue<int> buffer; // Shared buffer

void producer() {
    for (int i = 1; i <= 5; ++i) {
        emptySlots.acquire(); // Wait for an empty slot
        buffer.push(i); // Produce an item
        cout << "Produced: " << i << endl;
        fullSlots.release(); // Signal a full slot
        this_thread::sleep_for(chrono::milliseconds(500));
    }
}

void consumer() {
    for (int i = 1; i <= 5; ++i) {
        fullSlots.acquire(); // Wait for a full slot
        int item = buffer.front(); // Consume an item
        buffer.pop();
        cout << "Consumed: " << item << endl;
        emptySlots.release(); // Signal an empty slot
        this_thread::sleep_for(chrono::milliseconds(800));
    }
}

int main() {
    thread prod(producer);
    thread cons(consumer);

    prod.join();
    cons.join();

    return 0;
}
