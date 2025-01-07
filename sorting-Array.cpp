#include <iostream>
#include <vector>
using namespace std;

vector<int> mergeArrays(const vector<int>& arr1, const vector<int>& arr2) {
    vector<int> merged;
    int i = 0, j = 0;

    while (i < arr1.size() && j < arr2.size()) {
        if (arr1[i] <= arr2[j]) {
            merged.push_back(arr1[i]);
            i++;
        } else {
            merged.push_back(arr2[j]);
            j++;
        }
    }

    while (i < arr1.size()) {
        merged.push_back(arr1[i]);
        i++;
    }

    while (j < arr2.size()) {
        merged.push_back(arr2[j]);
        j++;
    }

    return merged;
}

int main() {
    vector<int> array1 = {1, 3, 5, 7, 9};
    vector<int> array2 = {2, 4, 6, 8, 10};

    vector<int> result = mergeArrays(array1, array2);

    cout << "Array hasil penggabungan yang terurut: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
