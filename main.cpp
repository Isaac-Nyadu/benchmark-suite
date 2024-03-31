#include <iostream>
#include <fstream>
#include <chrono>
#include <vector>

using namespace std;
using namespace chrono;

double intOperationBenchmark() {
    auto start = high_resolution_clock::now();
    
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
    constexpr long long arraySize = 5000000000;
    vector<int> array(arraySize);
    
    auto start = high_resolution_clock::now();

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
    const string filename = "benchmark_file1.bin";
    ofstream outFile(filename, ios::binary);
    const char data[100] = {};
    const long long fileSize = 1000000000; // 1 billion bytes

    outFile.seekp(fileSize - 1);
    outFile.write("", 1); // Create a file of approximately 1GB
    outFile.close();

    auto start = high_resolution_clock::now();

    // Write to the file
    outFile.open(filename, ios::binary);
    for (long long i = 0; i < fileSize; i += 100) {
        outFile.write(data, sizeof(data));
    }
    outFile.close();

    // Read the file
    ifstream inFile(filename, ios::binary);
    char buffer[100];
    while (inFile.read(buffer, sizeof(buffer))) {}
    inFile.close();

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    return duration.count() / 1000.0; // Convert to seconds
}

double hardDriveBenchmark2() {
    const string filename = "benchmark_file2.bin";
    ofstream outFile(filename, ios::binary);
    const char data[10000] = {};
    const long long fileSize = 1000000000; // 1 billion bytes

    outFile.seekp(fileSize - 1);
    outFile.write("", 1); // Create a file of approximately 1GB
    outFile.close();

    auto start = high_resolution_clock::now();

    // Write to the file
    outFile.open(filename, ios::binary);
    for (long long i = 0; i < fileSize; i += 10000) {
        outFile.write(data, sizeof(data));
    }
    outFile.close();

    // Read the file
    ifstream inFile(filename, ios::binary);
    char buffer[10000];
    while (inFile.read(buffer, sizeof(buffer))) {}
    inFile.close();

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    return duration.count() / 1000.0; // Convert to seconds
}

int main() {
    double intOpTime = intOperationBenchmark();
    cout << "32-bit Integer operation benchmark time: " << intOpTime << " seconds" << endl;

    double floatOpTime = floatOperationBenchmark();
    cout << "64-bit Floating point operation benchmark time: " << floatOpTime << " seconds" << endl;

    double memoryTime = memoryBenchmark();
    cout << "Memory benchmark time: " << memoryTime << " seconds" << endl;

    double hdBenchmark1Time = hardDriveBenchmark1();
    cout << "Hard drive benchmark 1 time: " << hdBenchmark1Time << " seconds" << endl;

    double hdBenchmark2Time = hardDriveBenchmark2();
    cout << "Hard drive benchmark 2 time: " << hdBenchmark2Time << " seconds" << endl;

    return 0;
}
