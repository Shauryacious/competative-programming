#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

mutex rw_mutex;       // Mutex for writers
mutex console_mutex;  // Mutex for synchronizing console output
int reader_count = 0; // Number of active readers

void reader(int id) {
    for (int i = 0; i < 3; ++i) { // Each reader reads 3 times
        {
            lock_guard<mutex> lock(rw_mutex);
            reader_count++;
        }

        {
            lock_guard<mutex> lock(console_mutex);
            cout << "Reader " << id << " is reading." << endl;
        }
        this_thread::sleep_for(chrono::milliseconds(500)); // Simulate reading

        {
            lock_guard<mutex> lock(rw_mutex);
            reader_count--;
        }
    }
}

void writer(int id) {
    for (int i = 0; i < 2; ++i) { // Each writer writes 2 times
        lock_guard<mutex> lock(rw_mutex); // Exclusive access for writers
        {
            lock_guard<mutex> lock(console_mutex);
            cout << "Writer " << id << " is writing." << endl;
        }
        this_thread::sleep_for(chrono::milliseconds(700)); // Simulate writing
    }
}

int main() {
    thread readers[3], writers[2];

    for (int i = 0; i < 3; ++i) readers[i] = thread(reader, i + 1);
    for (int i = 0; i < 2; ++i) writers[i] = thread(writer, i + 1);

    for (int i = 0; i < 3; ++i) readers[i].join();
    for (int i = 0; i < 2; ++i) writers[i].join();

    return 0;
}
