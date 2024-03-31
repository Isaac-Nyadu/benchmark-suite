#include <iostream>
#include <chrono>
#include <vector> 

using namespace std;
using namespace chrono;

double intOperationBenchmark() {
    auto start = high_resolution_clock::now();
    // Placeholder for operations
    for (int i = 0; i < 1010; ++i) {
        int result = 100 + 200;  // Integer addition
}

for (long long i = 0; i < 5000000000; ++i) {
    int result = 100 * 200;  // Integer multiplication
}

for (long long i = 0; i < 2000000000; ++i) {
    int result = 100 / 2;    // Integer division
}

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    return duration.count() / 1000.0; // Convert to seconds
}

double floatOperationBenchmark() {
    auto start = high_resolution_clock::now();
    // Placeholder for operations
    for (int i = 0; i < 1010; ++i) {
    double result = 100.0 + 200.0;  // Floating point addition
}

    for (long long i = 0; i < 5000000000; ++i) {
    double result = 100.0 * 200.0;  // Floating point multiplication
}

    for (long long i = 0; i < 2000000000; ++i) {
    double result = 100.0 / 2.0;    // Floating point division
}

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    return duration.count() / 1000.0; // Convert to seconds
}
  

double memoryBenchmark() {
    auto start = high_resolution_clock::now();
    constexpr long long arraySize = 5000000000;
    vector<int> array(arraySize);
    // Placeholder for read and write operations

    // Read benchmark
    for (long long i = 0; i < arraySize; ++i) {
        volatile int value = array[i];
}

    
}


int main() {
    double intOpTime = intOperationBenchmark();
    cout << "32-bit Integer operation benchmark time: " << intOpTime << " seconds" << endl;

    double floatOpTime = floatOperationBenchmark();
    cout << "64-bit Floating point operation benchmark time: " << floatOpTime << " seconds" << endl;

    return 0;
}


