#include <iostream>
#include <cstdlib>
#include <chrono>
#include <future>
#include <string>
#include <thread>
#include <unistd.h>
using namespace std;

void ThreadChecking() {
    auto future = async(launch::async, [] {
        for (int i=0; i<5; i++)
            cout << "threading" << endl;
        this_thread::sleep_for(1s);
        return 8;
    });

    auto status = future.wait_for(0ms);

    // Print status.
    if (status == future_status::ready) {
        cout << "Thread finished" << endl;
    } else {
        cout << "Thread still running" << endl;
    }

    auto result = future.get(); // Get result.
}

void foo(string param){
    for (int i=0; i<10; i++){
        this_thread::sleep_for(chrono::milliseconds(1000));
        cout << param << endl;
    }
    return;
}

int main () {
    //g++ test.cpp -o test.exe -lpthread
    thread thread_1(foo, "thread 1");
    thread thread_2(foo, "thread 2");
    thread_1.join();
    thread_2.join();
    return 0;
}