# LoadBalancingAlgorithms
Load balancing is the process of distributing incoming network traffic across multiple servers to ensure that no single server is overwhelmed.

![Untitled](https://github.com/raghunihal/LoadBalancingAlgorithms/assets/67452178/945a5c05-ac05-40b2-a66e-4cd4faa9e4c2)

By evenly spreading the workload, load balancing aims to prevent overload on a single server, enhance performance by reducing response times and improve availability by rerouting traffic in case of server failures. There are several algorithms to achieve load balancing, each with its pros and cons.In this we will dive into the most commonly used load balancing algorithms, how they work, when to use them, their benefits/drawbacks and how to implement them in code.

## Algorithm 1: Round Robin

![Untitled](https://github.com/raghunihal/LoadBalancingAlgorithms/assets/67452178/a81fc158-b82f-4b54-a3eb-aebdf2673ab5)

When to Use:
- When all servers have similar processing capabilities and are equally capable of handling requests.
- When simplicity and even distribution of load is more critical.

Benefits:
- Simple to implement and understand.
- Ensures even distribution of traffic.

Drawbacks:
- Does not consider server load or response time.
- Can lead to inefficiencies if servers have different processing capabilities.

## Implementation:
# RoundRobin.cpp
This C++ program demonstrates the implementation of the Round Robin load balancing algorithm. Here's a breakdown of the code: 
1. The `RoundRobin` class is defined with a private member `servers` (a vector of strings) to store the server names, and a private member `currentIndex` (an integer) to keep track of the current server index.
2. The constructor `RoundRobin(const std::vector<std::string>& servers)` initializes the `servers` vector with the provided server names and sets `currentIndex` to -1.
3. The `getNextServer()` method increments `currentIndex` by 1, wrapping around to 0 if it exceeds the size of the `servers` vector, and returns the server name at the new `currentIndex`.
4. In the `main()` function, a vector of server names is created, and a `RoundRobin` object `loadBalancer` is instantiated with this vector.
5. A loop iterates 6 times, calling `loadBalancer.getNextServer()` on each iteration and printing the request number and the returned server name.

# Algorithm 2: Weighted Round Robin

![Untitled](https://github.com/raghunihal/LoadBalancingAlgorithms/assets/67452178/c778f84c-4bc0-4aac-a636-a7a87ca4d914)

# How it Works:
- Each server is assigned a weight based on their processing power or available resources.
- Servers with higher weights receive a proportionally larger share of incoming requests.

# When to use:
- When servers have different processing capabilities or available resources.
- When you want to distribute the load based on the capacity of each server.

# Benefits:
- Balances load according to server capacity.
- More efficient use of server resources.

# Drawbacks:
- Slightly more complex to implement than simple Round Robin.
- Does not consider current server load or response time.

## Implementation:
# WeightedRoundRobin.cpp
This C++ program demonstrates the implementation of the Weighted Round Robin load balancing algorithm. Here's a breakdown of the code: 
1. The `WeightedRoundRobin` class is implemented as a C++ class with private member variables `servers` (a vector of strings), `weights` (a vector of integers), `currentIndex` (an integer), and `currentWeight` (an integer).
2. The constructor takes two vectors, `servers` and `weights`, and initializes the member variables accordingly.
3. The `getNextServer` function is the main logic of the class. It uses a loop to iterate through the servers based on their weights.
4. Inside the loop, the `currentIndex` is incremented and wrapped around if it reaches the end of the `servers` vector.
5. If the `currentIndex` is 0, it means a new round of server selection has started. In this case, the `currentWeight` is decremented, and if it becomes 0 or negative, it is reset to the maximum weight among all servers.
6. If the weight of the current server is greater than or equal to the `currentWeight`, that server is returned.
7. In the `main` function, an example usage is provided. A vector of server names and a vector of weights are created.
8. An instance of the `WeightedRoundRobin` class is created with the server names and weights.
9. A loop iterates 7 times, calling the `getNextServer` function and printing the selected server for each request.

# Algorithm 3: Least Connections

![Untitled](https://github.com/raghunihal/LoadBalancingAlgorithms/assets/67452178/f75dde16-4267-47ec-a64d-d243ae2ab71a)

# How it Works:
- Monitor the number of active connections on each server.
- Assigns incoming requests to the server with the least number of active connections.

# When to use:
- When you want to distribute the load based on the current number of active connections.
- When servers have similar processing capabilities but may have different levels of concurrent connections.

# Benefits:
- Balances load more dynamically based on current server load.
- Helps prevent any server from becoming overloaded with a high number of active connections.

# Drawbacks:
- May not be optimal if servers have different processing capabilities.
- Requires tracking active connections for each server.

## Implementation:
# LeastConnections.cpp
This C++ program demonstrates the implementation of the LeastConnections load balancing algorithm. Here's a breakdown of the code: 
The `LeastConnections` class has the following methods:
- `LeastConnections(const std::vector<std::string>& serverList)`: Constructor that initializes the `servers` map with the given server names and sets their connection counts to 0.
- `getNextServer()`: Finds the servers with the minimum number of connections, selects a random server from them, increments its connection count, and returns the server name.
- `releaseConnection(const std::string& server)`: Decrements the connection count of the given server if it has at least one connection.

In the `main` function, I have created a vector of server names, instantiated the `LeastConnections` object, and demonstrated its usage by getting the next server and releasing the connection for 6 requests.


# Algorithm 4: Least Response Time

![Untitled](https://github.com/raghunihal/LoadBalancingAlgorithms/assets/67452178/7d424764-e612-4de8-bc86-ac53eeaf45d2)

How It Works:
- Monitors the response time of each server.
- Assigns incoming requests to the server with the fastest response time.

When to Use:
- When you have servers with varying response times and want to route requests to the fastest server.

Benefits:
- Minimizes overall latency by selecting the server with the fastest response time.
- Can adapt dynamically to changes in server response times.
- Helps improve the user experience by providing quick responses.

Drawbacks:
- Requires accurate measurement of server response times, which can be challenging in distributed systems.
- May not consider other factors such as server load or connection count.

## Implementation:
# LeastResponseTime.cpp

This C++ code implements a simple load balancer that distributes requests to servers based on their response times. The load balancer selects the server with the least response time for each incoming request. Here's a breakdown of the code: 
1. The `LeastResponseTime` class is defined, which has two private member variables: `servers` (a vector of server names) and `response_times` (a vector of corresponding response times).
2. The constructor of `LeastResponseTime` takes a vector of server names and initializes the `response_times` vector with zeros.
3. The `get_next_server()` function finds the server with the minimum response time and returns its name.
4. The `update_response_time()` function updates the response time for a given server.
5. The `simulate_response_time()` function simulates a server's response time by introducing a random delay between 0.1 and 1.0 seconds.
6. In the `main()` function:
- The random number generator is seeded with the current time
- A vector of server names is created: `{"Server1", "Server2", "Server3"}`.
- An instance of `LeastResponseTime` is created with the server names.
- A loop runs for 6 iterations:
- The `get_next_server()` function is called to get the server with the least response time.
- The server name is printed. - The `simulate_response_time()` function is called to simulate the response time.
- The simulated response time is printed. - The `update_response_time()` function is called to update the response time for the selected server. The program simulates a load balancer that distributes requests to servers based on their response times. It selects the server with the least response time for each request and updates the response time for that server after simulating the response time.
