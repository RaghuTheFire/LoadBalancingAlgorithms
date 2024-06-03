
#include <iostream>
#include <unordered_map>
#include <vector>
#include <random>
#include <algorithm>

class LeastConnections 
{
  private:
      std::unordered_map<std::string, int> servers;
      std::random_device rd;
      std::mt19937 gen;
  
  public:
      LeastConnections(const std::vector<std::string>& serverList) : gen(rd()) 
      {
          for (const auto& server : serverList) 
          {
              servers[server] = 0;
          }
      }
  
      std::string getNextServer() 
      {
          // Find the minimum number of connections
          int minConnections = std::min_element(servers.begin(), servers.end(),
                                                [](const auto& p1, const auto& p2) {
                                                    return p1.second < p2.second;
                                                })->second;
  
          // Get all servers with the minimum number of connections
          std::vector<std::string> leastLoadedServers;
          for (const auto& [server, connections] : servers) 
          {
              if (connections == minConnections) 
              {
                  leastLoadedServers.push_back(server);
              }
          }
  
          // Select a random server from the least loaded servers
          std::uniform_int_distribution<> dis(0, leastLoadedServers.size() - 1);
          std::string selectedServer = leastLoadedServers[dis(gen)];
          servers[selectedServer]++;
          return selectedServer;
      }
  
      void releaseConnection(const std::string& server) 
      {
          if (servers[server] > 0) 
          {
              servers[server]--;
          }
      }
};

int main() 
{
    std::vector<std::string> servers = {"Server1", "Server2", "Server3"};
    LeastConnections loadBalancer(servers);

    for (int i = 0; i < 6; ++i) 
    {
        std::string server = loadBalancer.getNextServer();
        std::cout << "Request " << i + 1 << " -> " << server << std::endl;
        loadBalancer.releaseConnection(server);
    }

    return 0;
}
