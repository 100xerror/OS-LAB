//Question - 1

/*Implement a program to simulate memory allocation strategies (First Fit, Best Fit, Worst Fit). 
Allow the user to input memory block sizes and process sizes. Compare and display the memory allocation results for each strategy.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class MemoryAllocator {
private:
    vector<int> memoryChunks;
    vector<int> originalChunks;

public:
    MemoryAllocator(vector<int> chunks) : memoryChunks(chunks), originalChunks(chunks) {}

    void resetMemory() {
        memoryChunks = originalChunks;
    }

    void firstFit(const vector<int>& requests) {
        vector<int> allocation(requests.size(), -1);

        for (size_t i = 0; i < requests.size(); i++) {
            for (size_t j = 0; j < memoryChunks.size(); j++) {
                if (memoryChunks[j] >= requests[i]) {
                    allocation[i] = j;
                    memoryChunks[j] -= requests[i];
                    break;
                }
            }
        }

        cout << "First Fit Allocation:\n";
        displayResults(requests, allocation);
    }

    void bestFit(const vector<int>& requests) {
        vector<int> allocation(requests.size(), -1);

        for (size_t i = 0; i < requests.size(); i++) {
            int bestIdx = -1;
            for (size_t j = 0; j < memoryChunks.size(); j++) {
                if (memoryChunks[j] >= requests[i]) {
                    if (bestIdx == -1 || memoryChunks[j] < memoryChunks[bestIdx]) {
                        bestIdx = j;
                    }
                }
            }
            if (bestIdx != -1) {
                allocation[i] = bestIdx;
                memoryChunks[bestIdx] -= requests[i];
            }
        }

        cout << "Best Fit Allocation:\n";
        displayResults(requests, allocation);
    }

    void worstFit(const vector<int>& requests) {
        vector<int> allocation(requests.size(), -1);

        for (size_t i = 0; i < requests.size(); i++) {
            int worstIdx = -1;
            for (size_t j = 0; j < memoryChunks.size(); j++) {
                if (memoryChunks[j] >= requests[i]) {
                    if (worstIdx == -1 || memoryChunks[j] > memoryChunks[worstIdx]) {
                        worstIdx = j;
                    }
                }
            }
            if (worstIdx != -1) {
                allocation[i] = worstIdx;
                memoryChunks[worstIdx] -= requests[i];
            }
        }

        cout << "Worst Fit Allocation:\n";
        displayResults(requests, allocation);
    }

    void displayResults(const vector<int>& requests, const vector<int>& allocation) {
        cout << "Process No.\tProcess Size\tBlock No.\n";
        for (size_t i = 0; i < requests.size(); i++) {
            cout << i + 1 << "\t\t" << requests[i] << "\t\t";
            if (allocation[i] != -1) {
                cout << allocation[i] + 1 << endl;
            } else {
                cout << "Not Allocated\n";
            }
        }
        cout << endl;
    }
};

int main() {
    vector<int> memoryChunks = {100, 500, 200, 300, 600};
    vector<int> processSizes = {212, 417, 112, 426};

    MemoryAllocator allocator(memoryChunks);

    cout << "Memory Allocation Simulation:\n\n";

    allocator.firstFit(processSizes);
    allocator.resetMemory();

    allocator.bestFit(processSizes);
    allocator.resetMemory();

    allocator.worstFit(processSizes);

    return 0;
}

