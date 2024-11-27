#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

mutex forks[5]; // Mutexes representing forks

void philosopher(int id) {
    int leftFork = id;
    int rightFork = (id + 1) % 5;

    for (int i = 0; i < 3; ++i) { // Each philosopher eats 3 times
        cout << "Philosopher " << id << " is thinking..." << endl;
        this_thread::sleep_for(chrono::milliseconds(500));

        // Odd philosophers pick left fork first, even philosophers pick right fork first
        if (id % 2 == 0) {
            lock_guard<mutex> rightLock(forks[rightFork]);
            lock_guard<mutex> leftLock(forks[leftFork]);
            cout << "Philosopher " << id << " is eating..." << endl;
        } else {
            lock_guard<mutex> leftLock(forks[leftFork]);
            lock_guard<mutex> rightLock(forks[rightFork]);
            cout << "Philosopher " << id << " is eating..." << endl;
        }

        this_thread::sleep_for(chrono::milliseconds(500)); // Eating
    }
}



int main() {
    thread philosophers[5];

    for (int i = 0; i < 5; ++i) {
        philosophers[i] = thread(philosopher, i);
    }

    for (int i = 0; i < 5; ++i) {
        philosophers[i].join();
    }

    return 0;
}
