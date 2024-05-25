#include<bits/stdc++.h>
using namespace std;

void firstFit(vector<int>& blockSize, int m, vector<int>& processSize, int n)
{
    vector<int> allocation(n, -1);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (blockSize[j] >= processSize[i])
            {
                allocation[i] = j;
                blockSize[j] -= processSize[i];
                break;
            }
        }
    }
    cout << "\nProcess No.\tProcess Size\tBlock no.\n";
    for (int i = 0; i < n; i++)
    {
        cout << " " << i + 1 << "\t\t" << processSize[i] << "\t\t";
        if (allocation[i] != -1)
        {
            cout << allocation[i] + 1;
        }
        else
        {
            cout << "Not Allocated";
        }
        cout << "\n";
    }
}

int main()
{
    int m, n;
    vector<int> blockSize, processSize;
    cout << "Enter blocksize: ";
    cin >> m;
    cout << "Enter Blocks: ";
    for (int i = 0; i < m; i++)
    {
        int block;
        cin >> block;
        blockSize.push_back(block);
    }
    cout << "Enter processsize: ";
    cin >> n;
    cout << "Enter Processes: ";
    for (int i = 0; i < n; i++)
    {
        int process;
        cin >> process;
        processSize.push_back(process);
    }
    firstFit(blockSize, m, processSize, n);
    return 0;
}