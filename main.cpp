#include <iostream>
#include <fstream>
#include <chrono>
#include <vector>

using namespace std;
using namespace chrono;

double intOperationBenchmark() {
    auto start = high_resolution_clock::now();
    
    for (int i = 0; i < 1010; ++i) {
        int result = 100 + 200; // Integer addition
    }

    for (long long i = 0; i < 5000000000; ++i) {
        int result = 100 * 200; // Integer multiplication
    }

    for (long long i = 0; i < 2000000000; ++i) {
        int result = 100 / 2; // Integer division
    }

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    return duration.count() / 1000.0; // Convert to seconds
}

double floatOperationBenchmark() {
    auto start = high_resolution_clock::now();
    
    for (int i = 0; i < 1010; ++i) {
        double result = 100.0 + 200.0; // Floating point addition
    }

    for (long long i = 0; i < 5000000000; ++i) {
        double result = 100.0 * 200.0; // Floating point multiplication
    }

    for (long long i = 0; i < 2000000000; ++i) {
        double result = 100.0 / 2.0; // Floating point division
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
        int value = array[i];
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
    ofstream outFile("benchmark_file1.bin", ios::binary);
    outFile.seekp(1000000000 - 1);
    outFile.write("", 1);
    outFile.close();

    auto start = high_resolution_clock::now();

    ifstream inFile("benchmark_file1.bin", ios::binary);
    char buffer[100];
    while (inFile.read(buffer, 100)) {}

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    return duration.count() / 1000.0; // Convert to seconds
}

double hardDriveBenchmark2() {
    ofstream outFile("benchmark_file2.bin", ios::binary);
    outFile.seekp(1000000000 - 1);
    outFile.write("", 1);
    outFile.close();

    auto start = high_resolution_clock::now();

    ifstream inFile("benchmark_file2.bin", ios::binary);
    char buffer[10000];
    while (inFile.read(buffer, 10000)) {}

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    return duration.count() / 1000.0; // Convert to seconds
}

int main() {
    double intOpTime = intOperationBenchmark();
    double floatOpTime = floatOperationBenchmark();
    double memoryTime = memoryBenchmark();
    double hdBenchmark1Time = hardDriveBenchmark1();
    double hdBenchmark2Time = hardDriveBenchmark2();

    cout << "32-bit Integer operation benchmark time: " << intOpTime << " seconds" << endl;
    cout << "64-bit Floating point operation benchmark time: " << floatOpTime << " seconds" << endl;
    cout << "Memory benchmark time: " << memoryTime << " seconds" << endl;
    cout << "Hard drive benchmark 1 time: " << hdBenchmark1Time << " seconds" << endl;
    cout << "Hard drive benchmark 2 time: " << hdBenchmark2Time << " seconds" << endl;

    return 0;
}
