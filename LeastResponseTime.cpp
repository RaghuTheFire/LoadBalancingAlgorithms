#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <unistd.h>

class LeastResponseTime 
{
  private:
      std::vector<std::string> servers;
      std::vector<double> response_times;
  
  public:
      LeastResponseTime(const std::vector<std::string>& servers) : servers(servers), response_times(servers.size(), 0.0) {}
  
      std::string get_next_server() 
      {
          auto min_response_time = *std::min_element(response_times.begin(), response_times.end());
          auto min_index = std::distance(response_times.begin(), std::find(response_times.begin(), response_times.end(), min_response_time));
          return servers[min_index];
      }
  
      void update_response_time(const std::string& server, double response_time) 
      {
          auto index = std::distance(servers.begin(), std::find(servers.begin(), servers.end(), server));
          response_times[index] = response_time;
      }
};

// Simulated server response time function
double simulate_response_time() 
{
    // Simulating response time with random delay
    double delay = (static_cast<double>(rand()) / RAND_MAX) * 0.9 + 0.1; // Random delay between 0.1 and 1.0 seconds
    usleep(delay * 1000000); // Sleep for the simulated delay
    return delay;
}

int main() 
{
    std::srand(std::time(nullptr)); // Seed the random number generator

    std::vector<std::string> servers = {"Server1", "Server2", "Server3"};
    LeastResponseTime load_balancer(servers);

    for (int i = 0; i < 6; ++i) 
    {
        std::string server = load_balancer.get_next_server();
        std::cout << "Request " << i + 1 << " -> " << server << std::endl;
        double response_time = simulate_response_time();
        load_balancer.update_response_time(server, response_time);
        std::cout << "Response Time: " << response_time << "s" << std::endl;
    }

    return 0;
}





