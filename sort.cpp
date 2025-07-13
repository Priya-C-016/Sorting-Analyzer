#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <chrono>
#include <algorithm>
// #include "sort.h";
using namespace std;
using namespace chrono;
using std::chrono::nanoseconds;

struct Result
{
    string name;
    double time_ms;
    int comparisons;
    int swaps;
    string space, complexity;
    vector<int> sorted;
};

vector<int> parseArray(const string &input)
{
    vector<int> arr;
    stringstream ss(input);
    string num;
    while (getline(ss, num, ','))
    {
        arr.push_back(stoi(num));
    }
    return arr;
}

void selectionSort(vector<int> &arr, Result &res)
{
    auto start = high_resolution_clock::now();
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i)
    {
        int minIdx = i;
        for (int j = i + 1; j < n; ++j)
        {
            res.comparisons++;
            if (arr[j] < arr[minIdx])
                minIdx = j;
        }
        if (minIdx != i)
        {
            swap(arr[i], arr[minIdx]);
            res.swaps++;
        }
    }
    auto end = high_resolution_clock::now();
res.time_ms = duration<double, std::milli>(end - start).count();
    res.sorted = arr;
    res.name = "Selection Sort";
    res.complexity = "Best/Worst: O(n^2)";
    res.space = "O(1)";
}

void insertionSort(vector<int> &arr, Result &res)
{
    auto start = high_resolution_clock::now();
    int n = arr.size();
    for (int i = 1; i < n; ++i)
    {
        int key = arr[i], j = i - 1;
        res.comparisons++;
        while (j >= 0 && arr[j] > key)
        {
            res.comparisons++;
            arr[j + 1] = arr[j];
            j--;
            res.swaps++;
        }
        arr[j + 1] = key;
    }
    auto end = high_resolution_clock::now();
res.time_ms = duration<double, std::milli>(end - start).count();
    res.sorted = arr;
    res.name = "Insertion Sort";
    res.complexity = "Best: O(n), Worst: O(n^2)";
    res.space = "O(1)";
}

void bubbleSort(vector<int> &arr, Result &res)
{
    auto start = high_resolution_clock::now();
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i)
        for (int j = 0; j < n - i - 1; ++j)
        {
            res.comparisons++;
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                res.swaps++;
            }
        }
    auto end = high_resolution_clock::now();
res.time_ms = duration<double, std::milli>(end - start).count();
    res.sorted = arr;
    res.name = "Bubble Sort";
    res.complexity = "Best: O(n), Worst: O(n^2)";
    res.space = "O(1)";
}

void merge(vector<int> &arr, int l, int m, int r, Result &res)
{
    int n1 = m - l + 1, n2 = r - m;
    vector<int> L(n1), R(n2);
    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2)
    {
        res.comparisons++;
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }
    while (i < n1)
        arr[k++] = L[i++];
    while (j < n2)
        arr[k++] = R[j++];
}

void mergeSortUtil(vector<int> &arr, int l, int r, Result &res)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;
        mergeSortUtil(arr, l, m, res);
        mergeSortUtil(arr, m + 1, r, res);
        merge(arr, l, m, r, res);
    }
}

void mergeSort(vector<int> &arr, Result &res)
{
    auto start = high_resolution_clock::now();
    mergeSortUtil(arr, 0, arr.size() - 1, res);
    auto end = high_resolution_clock::now();
res.time_ms = duration<double, std::milli>(end - start).count();
    res.sorted = arr;
    res.name = "Merge Sort";
    res.complexity = "Best/Worst: O(n log n)";
    res.space = "O(n)";
}

int partition(vector<int> &arr, int low, int high, Result &res)
{
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; ++j)
    {
        res.comparisons++;
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
            res.swaps++;
        }
    }
    swap(arr[i + 1], arr[high]);
    res.swaps++;
    return i + 1;
}

void quickSortUtil(vector<int> &arr, int low, int high, Result &res)
{
    if (low < high)
    {
        int pi = partition(arr, low, high, res);
        quickSortUtil(arr, low, pi - 1, res);
        quickSortUtil(arr, pi + 1, high, res);
    }
}

void quickSort(vector<int> &arr, Result &res)
{
    auto start = high_resolution_clock::now();
    quickSortUtil(arr, 0, arr.size() - 1, res);
    auto end = high_resolution_clock::now();
res.time_ms = duration<double, std::milli>(end - start).count();
    res.sorted = arr;
    res.name = "Quick Sort";
    res.complexity = "Best: O(n log n), Worst: O(n^2)";
    res.space = "O(log n)";
}

void heapify(vector<int> &arr, int n, int i, Result &res)
{
    int largest = i, l = 2 * i + 1, r = 2 * i + 2;
    if (l < n && arr[l] > arr[largest])
        largest = l;
    if (r < n && arr[r] > arr[largest])
        largest = r;
    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        res.swaps++;
        heapify(arr, n, largest, res);
    }
}

void heapSort(vector<int> &arr, Result &res)
{
    auto start = high_resolution_clock::now();
    int n = arr.size();
    for (int i = n / 2 - 1; i >= 0; --i)
        heapify(arr, n, i, res);
    for (int i = n - 1; i > 0; --i)
    {
        swap(arr[0], arr[i]);
        res.swaps++;
        heapify(arr, i, 0, res);
    }
    auto end = high_resolution_clock::now();
res.time_ms = duration<double, std::milli>(end - start).count();
    res.sorted = arr;
    res.name = "Heap Sort";
    res.complexity = "O(n log n)";
    res.space = "O(1)";
}
void shellSort(vector<int> &arr, Result& res) {
    auto start = high_resolution_clock::now();
    int n = arr.size();

    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; ++i) {
            int temp = arr[i];
            int j = i;

            res.comparisons++;
            while (j >= gap && arr[j - gap] > temp) {
                res.comparisons++;
                arr[j] = arr[j - gap];
                j -= gap;
                res.swaps++;
            }
            arr[j] = temp;
        }
    }

    auto end = high_resolution_clock::now();
res.time_ms = duration<double, std::milli>(end - start).count();
    res.sorted = arr;
    res.name = "Shell Sort";
    res.complexity = "Best: O(n log n), Worst: O(n^2)";
    res.space = "O(1)";
}
void countingSort(vector<int> &arr, Result& res) {
    auto start = high_resolution_clock::now();
    int max_val = *max_element(arr.begin(), arr.end());
    int min_val = *min_element(arr.begin(), arr.end());
    int range = max_val - min_val + 1;

    vector<int> count(range, 0);
    vector<int> output(arr.size());

    for (int i = 0; i < arr.size(); i++) {
        count[arr[i] - min_val]++;
        res.comparisons++; // Count frequency as comparisons
    }

    for (int i = 1; i < range; i++) {
        count[i] += count[i - 1];
    }

    for (int i = arr.size() - 1; i >= 0; i--) {
        output[count[arr[i] - min_val] - 1] = arr[i];
        count[arr[i] - min_val]--;
        res.swaps++;
    }

    auto end = high_resolution_clock::now();
res.time_ms = duration<double, std::milli>(end - start).count();
    res.sorted = output;
    res.name = "Counting Sort";
    res.complexity = "Best/Worst: O(n + k)";
    res.space = "O(k)";
}
int getMax(vector<int>& arr) {
    return *max_element(arr.begin(), arr.end());
}

void countingSortForRadix(vector<int>& arr, int exp, Result& res) {
    int n = arr.size();
    vector<int> output(n);
    int count[10] = {0};

    for (int i = 0; i < n; i++) {
        count[(arr[i] / exp) % 10]++;
        res.comparisons++;
    }

    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
        res.swaps++;
    }

    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

void radixSort(vector<int>&arr, Result& res) {
    auto start = high_resolution_clock::now();
    int max_num = getMax(arr);

    for (int exp = 1; max_num / exp > 0; exp *= 10)
        countingSortForRadix(arr, exp, res);

    auto end = high_resolution_clock::now();
res.time_ms = duration<double, std::milli>(end - start).count();
    res.sorted = arr;
    res.name = "Radix Sort";
    res.complexity = "Best/Worst: O(nk)";
    res.space = "O(n + k)";
}

void writeToJSON(const vector<Result> &results)
{
    ofstream out("result.json");
    out << "{\n";
    for (size_t i = 0; i < results.size(); ++i)
    {
        const auto &r = results[i];
        out << "  \"" << r.name << "\": {\n";
        out << "    \"name\": \"" << r.name << "\",\n";
        out << "    \"time_ms\": " << r.time_ms << ",\n";
        out << "    \"comparisons\": " << r.comparisons << ",\n";
        out << "    \"swaps\": " << r.swaps << ",\n";
        out << "    \"complexity\": \"" << r.complexity << "\",\n";
        out << "    \"space\": \"" << r.space << "\",\n";
        out << "    \"sorted\": [" << flush;
        for (int j = 0; j < r.sorted.size(); ++j)
            out << r.sorted[j] << (j + 1 == r.sorted.size() ? "" : ", ");
        out << "]\n  }" << (i + 1 < results.size() ? ",\n" : "\n");
    }
    out << "}\n";
}

int main()
{
    ifstream fin("input.txt");
    string line;
    getline(fin, line);
    vector<int> input = parseArray(line);

    vector<Result> results(9);
    for (int i = 0; i < 9; ++i) {
    vector<int> arr = input;
    switch(i) {
        case 0: selectionSort(arr, results[i]); break;
        case 1: insertionSort(arr, results[i]); break;
        case 2: bubbleSort(arr, results[i]); break;
        case 3: mergeSort(arr, results[i]); break;
        case 4: quickSort(arr, results[i]); break;
        case 5: heapSort(arr, results[i]); break;
        case 6: shellSort(arr, results[i]); break;
        case 7: countingSort(arr, results[i]); break;
        case 8: radixSort(arr, results[i]); break;
    }
}
    // selectionSort(input, results[0]);
    // insertionSort(input, results[1]);
    // bubbleSort(input, results[2]);
    // mergeSort(input, results[3]);
    // quickSort(input, results[4]);
    // heapSort(input, results[5]);
    // shellSort(input, results[6]);    // if implemented
    // countingSort(input, results[7]); // if applicable
    // radixSort(input, results[8]);
    writeToJSON(results);
    return 0;
}
