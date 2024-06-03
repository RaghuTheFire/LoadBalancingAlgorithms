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

# Implementation:
