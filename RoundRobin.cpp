
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to implement Round Robin load balancing algorithm
void roundRobin(vector<int>& servers, vector<int>& requests) 
{
    int n = servers.size(); // Number of servers
    int m = requests.size(); // Number of requests
    int currentServer = 0; // Index of the current server

    for (int i = 0; i < m; i++) 
    {
        cout << "Request " << requests[i] << " assigned to Server " << servers[currentServer] << endl;
        currentServer = (currentServer + 1) % n; // Move to the next server in a circular fashion
    }
}

int main() 
{
    vector<int> servers = {1, 2, 3, 4}; // Server IDs
    vector<int> requests = {10, 20, 30, 40, 50}; // Request IDs
    roundRobin(servers, requests);
    return 0;
}
