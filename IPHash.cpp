#include <iostream>
#include <vector>
#include <string>
#include <openssl/md5.h>

std::string md5(const std::string& input) 
{
    unsigned char digest[MD5_DIGEST_LENGTH];
    MD5((unsigned char*)input.c_str(), input.length(), digest);

    char hex[33];
    for (int i = 0; i < MD5_DIGEST_LENGTH; i++) 
    {
        sprintf(hex + i * 2, "%02x", digest[i]);
    }
    hex[32] = 0;

    return std::string(hex);
}

class IPHash 
{
private:
    std::vector<std::string> servers;

public:
    IPHash(const std::vector<std::string>& servers) : servers(servers) {}

    std::string get_next_server(const std::string& client_ip) 
    {
        std::string hash_value = md5(client_ip);
        size_t index = std::stoull(hash_value, nullptr, 16) % servers.size();
        return servers[index];
    }
};

int main() 
{
    std::vector<std::string> servers = {"Server1", "Server2", "Server3"};
    IPHash load_balancer(servers);

    std::vector<std::string> client_ips = {"192.168.0.1", "192.168.0.2", "192.168.0.3", "192.168.0.4"};
    for (const auto& ip : client_ips) 
    {
        std::string server = load_balancer.get_next_server(ip);
        std::cout << "Client " << ip << " -> " << server << std::endl;
    }

    return 0;
}
