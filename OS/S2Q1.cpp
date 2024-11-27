//Question - 1

/*Implement a program to simulate memory allocation strategies (First Fit, Best Fit, Worst Fit). 
Allow the user to input memory block sizes and process sizes. Compare and display the memory allocation results for each strategy.
*/

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Function to perform First Fit allocation
void firstFit(vector<int> blocks, vector<int> processes) {
    vector<int> allocation(processes.size(), -1);

    for (int i = 0; i < processes.size(); i++) {
        for (int j = 0; j < blocks.size(); j++) {
            if (blocks[j] >= processes[i]) {
                allocation[i] = j;
                blocks[j] -= processes[i];
                break;
            }
        }
    }

    cout << "First Fit Allocation:\n";
    for (int i = 0; i < processes.size(); i++) {
        if (allocation[i] != -1)
            cout << "Process " << i + 1 << " allocated to block " << allocation[i] + 1 << "\n";
        else
            cout << "Process " << i + 1 << " not allocated\n";
    }
}

// Function to perform Best Fit allocation
void bestFit(vector<int> blocks, vector<int> processes) {
    vector<int> allocation(processes.size(), -1);

    for (int i = 0; i < processes.size(); i++) {
        int bestIdx = -1;
        for (int j = 0; j < blocks.size(); j++) {
            if (blocks[j] >= processes[i]) {
                if (bestIdx == -1 || blocks[j] < blocks[bestIdx]) {
                    bestIdx = j;
                }
            }
        }

        if (bestIdx != -1) {
            allocation[i] = bestIdx;
            blocks[bestIdx] -= processes[i];
        }
    }

    cout << "Best Fit Allocation:\n";
    for (int i = 0; i < processes.size(); i++) {
        if (allocation[i] != -1)
            cout << "Process " << i + 1 << " allocated to block " << allocation[i] + 1 << "\n";
        else
            cout << "Process " << i + 1 << " not allocated\n";
    }
}

// Function to perform Worst Fit allocation
void worstFit(vector<int> blocks, vector<int> processes) {
    vector<int> allocation(processes.size(), -1);

    for (int i = 0; i < processes.size(); i++) {
        int worstIdx = -1;
        for (int j = 0; j < blocks.size(); j++) {
            if (blocks[j] >= processes[i]) {
                if (worstIdx == -1 || blocks[j] > blocks[worstIdx]) {
                    worstIdx = j;
                }
            }
        }

        if (worstIdx != -1) {
            allocation[i] = worstIdx;
            blocks[worstIdx] -= processes[i];
        }
    }

    cout << "Worst Fit Allocation:\n";
    for (int i = 0; i < processes.size(); i++) {
        if (allocation[i] != -1)
            cout << "Process " << i + 1 << " allocated to block " << allocation[i] + 1 << "\n";
        else
            cout << "Process " << i + 1 << " not allocated\n";
    }
}

int main() {
    int numBlocks, numProcesses;

    // Input memory block sizes
    cout << "Enter the number of memory blocks: ";
    cin >> numBlocks;
    vector<int> blocks(numBlocks);
    cout << "Enter the sizes of the memory blocks:\n";
    for (int i = 0; i < numBlocks; i++) {
        cin >> blocks[i];
    }

    // Input process sizes
    cout << "Enter the number of processes: ";
    cin >> numProcesses;
    vector<int> processes(numProcesses);
    cout << "Enter the sizes of the processes:\n";
    for (int i = 0; i < numProcesses; i++) {
        cin >> processes[i];
    }

    // Perform allocations
    firstFit(blocks, processes);
    
    // Reset memory block sizes for next strategy
    cout << endl;
    
   bestFit(blocks,processes);
}
