#include <iostream>
#include <vector>

using namespace std;

struct Process {
  int pid;
  int burstTime;
  int arrivalTime;
};

void findTurnAroundTime(Process proc[], int n, int wt[], int tat[]) {
  for (int i = 0; i < n; i++) {
    tat[i] = proc[i].burstTime + wt[i];
  }
}

void findWaitingTime(Process proc[], int n, int wt[]) {
  wt[0] = 0;
  for (int i = 1; i < n; i++) {
    wt[i] = proc[i - 1].burstTime + wt[i - 1];
  }
}

int findShortestJob(Process proc[], int n, int arrivalTime[], int burstTime[]) {
  int minIndex = 0;
  for (int i = 1; i < n; i++) {
    if (proc[i].arrivalTime < proc[minIndex].arrivalTime) {
      minIndex = i;
    }
  }
  return minIndex;
}

void sortProcesses(Process proc[], int n) {
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - i - 1; j++) {
      if (proc[j].burstTime > proc[j + 1].burstTime) {
        swap(proc[j], proc[j + 1]);
      }
    }
  }
}

int main() {
  int n;
  cout << "Enter the number of processes: ";
  cin >> n;

  Process proc[n];
  for (int i = 0; i < n; i++) {
    cout << "Enter the process ID " << i + 1 << ": ";
    cin >> proc[i].pid;
    cout << "Enter the arrival time for process " << i + 1 << ": ";
    cin >> proc[i].arrivalTime;
    cout << "Enter the burst time for process " << i + 1 << ": ";
    cin >> proc[i].burstTime;
  }

  sortProcesses(proc, n);

  int wt[n], tat[n];
  findWaitingTime(proc, n, wt);
  findTurnAroundTime(proc, n, wt, tat);

  cout << "\nProcess\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time" << endl;
  for (int i = 0; i < n; i++) {
    cout << proc[i].pid << "\t\t" << proc[i].arrivalTime << "\t\t" << proc[i].burstTime << "\t\t"
         << wt[i] << "\t\t" << tat[i] << endl;
  }

  return 0;
}
