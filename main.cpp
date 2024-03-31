#include <iostream>
#include <chrono>
#include <vector> 
#include <fstream>

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

    // Write benchmark
    for (long long i = 0; i < arraySize; ++i) {
        array[i] = 1;
}

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    return duration.count() / 1000.0; // Convert to seconds
}


double hardDriveBenchmark1() {
    const long long fileSize = 1000000000; // 1 billion bytes
    const int bufferSize = 100;
    char buffer[bufferSize] = {0}; // Buffer for read/write operations
    
    auto start = high_resolution_clock::now();
    // Placeholder for write and read operations
    // Write 1GB data to file, 100 bytes at a time
    
    std::ofstream outFile("benchmark_file1.bin", ios::binary);
    for(long long i = 0; i < fileSize; i += bufferSize) {
        outFile.write(buffer, bufferSize);
    }
    outFile.close();

    // Read the file back, 100 bytes at a time
    std::ifstream inFile("benchmark_file1.bin", ios::binary);
    while(inFile.read(buffer, bufferSize)) {}
    inFile.close();

    

    
}



int main() {
    double intOpTime = intOperationBenchmark();
    cout << "32-bit Integer operation benchmark time: " << intOpTime << " seconds" << endl;

    double floatOpTime = floatOperationBenchmark();
    cout << "64-bit Floating point operation benchmark time: " << floatOpTime << " seconds" << endl;

    double memoryTime = memoryBenchmark();
    cout << "Memory benchmark time: " << memoryTime << " seconds" << endl;


    return 0;
}


