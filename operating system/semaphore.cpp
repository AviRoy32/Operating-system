#include <iostream>
#include <semaphore>
#include <thread>
#include <chrono>
using namespace std;

// Initialize semaphore with a count of 3
counting_semaphore<10> semaphore(3);

void worker(int id)
{
    // Acquiring
    semaphore.acquire();

    // Simulate doing some work
    cout << "Thread " << id << " acquired the semaphore." << endl;
    this_thread::sleep_for(chrono::seconds(1));

    // Releasing
    cout << "Thread " << id << " released the semaphore." << endl;
    semaphore.release();
}

int main()
{
    thread t1(worker, 1);
    thread t2(worker, 2);
    thread t3(worker, 3);
    thread t4(worker, 4);
    thread t5(worker, 5);

    t1.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();

    return 0;
}
//