#include <iostream>
#include <vector>
#include <algorithm>

class WeightedRoundRobin 
{
private:
    std::vector<std::string> servers;
    std::vector<int> weights;
    int current_index;
    int current_weight;

public:
    WeightedRoundRobin(const std::vector<std::string>& servers, const std::vector<int>& weights)
        : servers(servers), weights(weights), current_index(-1), current_weight(0) {}

    std::string get_next_server() 
    {
        while (true) 
        {
            current_index = (current_index + 1) % servers.size();
            if (current_index == 0) 
            {
                current_weight--;
                if (current_weight <= 0) 
                {
                    current_weight = *std::max_element(weights.begin(), weights.end());
                }
            }
            if (weights[current_index] >= current_weight) 
            {
                return servers[current_index];
            }
        }
    }
};

int main() 
{
    std::vector<std::string> servers = {"Server1", "Server2", "Server3"};
    std::vector<int> weights = {5, 1, 1};
    WeightedRoundRobin load_balancer(servers, weights);

    for (int i = 0; i < 7; ++i) 
    {
        std::string server = load_balancer.get_next_server();
        std::cout << "Request " << i + 1 << " -> " << server << std::endl;
    }

    return 0;
}
