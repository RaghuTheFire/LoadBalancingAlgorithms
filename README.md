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
1. The program includes the necessary header files: `iostream` for input/output operations, `vector` for using dynamic arrays, and `algorithm` for various algorithms.
2. The `using namespace std;` line allows the program to use the standard namespace without explicitly prefixing it.
3. The `roundRobin` function takes two vectors as input: `servers` (a vector of server IDs) and `requests` (a vector of request IDs).
4. Inside the `roundRobin` function, the number of servers (`n`) and the number of requests (`m`) are calculated from the sizes of the respective vectors.
5. The `currentServer` variable is initialized to 0, representing the index of the current server to handle the next request.
6. A loop iterates over each request (`i` from 0 to `m-1`).
7. Inside the loop, the program prints a message indicating which request is assigned to which server. For example, "Request 10 assigned to Server 1".
8. After assigning the request, the `currentServer` variable is updated to move to the next server in a circular fashion. This is done by incrementing `currentServer` by 1 and taking the modulus with `n` (the number of servers). This ensures that the server index wraps around to 0 when it reaches the end of the server list.
9. In the `main` function, two vectors are initialized: `servers` with server IDs (1, 2, 3, 4) and `requests` with request IDs (10, 20, 30, 40, 50).
10. The `roundRobin` function is called, passing the `servers` and `requests` vectors as arguments.
11. The program exits with a return code of 0. When the program is executed, it will output the assignment of requests to servers in a round-robin fashion. For example: ``` Request 10 assigned to Server 1 Request 20 assigned to Server 2 Request 30 assigned to Server 3 Request 40 assigned to Server 4 Request 50 assigned to Server 1 ``` This demonstrates how the Round Robin algorithm distributes requests evenly across multiple servers in a circular order, ensuring that no server is overloaded or underutilized.

Algorithm 2: Weighted Round Robin

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
