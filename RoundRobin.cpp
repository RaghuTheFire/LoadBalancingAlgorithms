#include <iostream>
#include <vector>
#include <string>

class RoundRobin 
{
private:
    std::vector<std::string> servers;
    int currentIndex;

public:
    RoundRobin(const std::vector<std::string>& servers) : servers(servers), currentIndex(-1) {}

    std::string getNextServer() 
    {
        currentIndex = (currentIndex + 1) % servers.size();
        return servers[currentIndex];
    }
};

int main() 
{
    std::vector<std::string> servers = {"Server1", "Server2", "Server3"};
    RoundRobin loadBalancer(servers);

    for (int i = 0; i < 6; ++i) 
    {
        std::string server = loadBalancer.getNextServer();
        std::cout << "Request " << i + 1 << " -> " << server << std::endl;
    }

    return 0;
}
