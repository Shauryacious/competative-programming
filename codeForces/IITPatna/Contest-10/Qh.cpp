#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct Process{
    int pId;           
    int arrivalTime;    
    int burstTime;      
    int completionTime; 
    int turnAroundTime; 
    int waitingTime;    
};



void calculateCompletionTime(vector<Process>& processes){
    int n = processes.size();
    processes[0].completionTime = processes[0].arrivalTime + processes[0].burstTime;
    for(int i = 1; i < n; i++){
        processes[i].completionTime = processes[i-1].completionTime + processes[i].burstTime;
    }
}

void calculateTurnAroundTime(vector<Process>& processes){
    for(auto& process : processes){
        process.turnAroundTime = process.completionTime - process.arrivalTime;
    }
}

void calculateWaitingTime(vector<Process>& processes){
    for(auto& process : processes){
        process.waitingTime = process.turnAroundTime - process.burstTime;
        if(process.waitingTime < 0){
            process.waitingTime = 0;
        }
    }
}

void calculateAverageTimes(vector<Process>& processes){
    int n = processes.size();
    calculateCompletionTime(processes);
    calculateTurnAroundTime(processes);
    calculateWaitingTime(processes);

    int totalWaitingTime = 0;
    int totalTurnAroundTime = 0;

    for(auto& process : processes){
        totalWaitingTime += process.waitingTime;
        totalTurnAroundTime += process.turnAroundTime;
    }

    float averageWaitingTime = (float)totalWaitingTime / n;
    float averageTurnAroundTime = (float)totalTurnAroundTime / n;

    cout << "Average Waiting Time = " << averageWaitingTime << endl;
    cout << "Average Turn Around Time = " << averageTurnAroundTime << endl;
}

int main(){
    int n;
    cin >> n;

    vector<Process> processes(n);

    for(int i = 0; i < n; i++){
        processes[i].pId = i + 1;
        cin >> processes[i].arrivalTime >> processes[i].burstTime;
    }

    sort(processes.begin(), processes.end(), [](const Process& p1, const Process& p2) {
        return p1.arrivalTime < p2.arrivalTime;
    });

    calculateAverageTimes(processes);

    cout << endl << "Process details:" << endl;
    cout << "PID\tAT\tBT\tCT\tTAT\tWT\n";
    for(const auto& process : processes){
        cout << process.pId << "\t" << process.arrivalTime << "\t" 
             << process.burstTime << "\t" << process.completionTime << "\t" 
             << process.turnAroundTime << "\t" << process.waitingTime << endl;
    }

    return 0;
}
