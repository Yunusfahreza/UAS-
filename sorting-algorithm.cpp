#include <iostream>
#include <vector>
#include <algorithm> // Untuk std::sort
#include <chrono>    // Untuk menghitung waktu eksekusi
using namespace std;
using namespace chrono;

// Fungsi Binary Search
int binarySearch(const vector<int>& arr, int target) {
    int low = 0, high = arr.size() - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1; // Tidak ditemukan
}

// Fungsi Linear Search
int linearSearch(const vector<int>& arr, int target) {
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == target)
            return i;
    }
    return -1; // Tidak ditemukan
}

int main() {
    // Membuat data besar (1 juta elemen terurut)
    vector<int> data(1000000);
    for (int i = 0; i < data.size(); i++) {
        data[i] = i + 1; // Data terurut dari 1 hingga 1 juta
    }

    // Target untuk dicari
    int target = 987654;

    // Binary Search
    auto startBinary = high_resolution_clock::now();
    int binaryResult = binarySearch(data, target);
    auto endBinary = high_resolution_clock::now();

    // Linear Search
    auto startLinear = high_resolution_clock::now();
    int linearResult = linearSearch(data, target);
    auto endLinear = high_resolution_clock::now();

    // Output hasil pencarian
    cout << "=== Binary Search ===" << endl;
    if (binaryResult != -1)
        cout << "Elemen ditemukan pada indeks " << binaryResult << endl;
    else
        cout << "Elemen tidak ditemukan." << endl;
    cout << "Waktu eksekusi: " 
         << duration_cast<microseconds>(endBinary - startBinary).count() 
         << " mikrodetik" << endl;

    cout << "\n=== Linear Search ===" << endl;
    if (linearResult != -1)
        cout << "Elemen ditemukan pada indeks " << linearResult << endl;
    else
        cout << "Elemen tidak ditemukan." << endl;
    cout << "Waktu eksekusi: " 
         << duration_cast<microseconds>(endLinear - startLinear).count() 
         << " mikrodetik" << endl;

    return 0;
}
