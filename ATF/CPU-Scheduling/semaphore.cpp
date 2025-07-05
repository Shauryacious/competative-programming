#include <iostream>
#include <thread>
#include <semaphore> // C++20

using namespace std;

binary_semaphore sem1(1); // Initially unlocked
binary_semaphore sem2(0); // Initially locked

void thread1() {
    for (int i = 0; i < 5; ++i) {
        sem1.acquire(); // Wait for signal
        cout << "Thread 1: Ping" << endl;
        sem2.release(); // Signal thread2
    }
}

void thread2() {
    for (int i = 0; i < 5; ++i) {
        sem2.acquire(); // Wait for signal
        cout << "Thread 2: Pong" << endl;
        sem1.release(); // Signal thread1
    }
}

int main() {
    thread t1(thread1);
    thread t2(thread2);

    t1.join();
    t2.join();

    return 0;
}
