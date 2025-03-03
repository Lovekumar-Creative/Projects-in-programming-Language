/*
Scenario:
An e-commerce platform processes thousands of customer orders daily. 
Each order has a priority (e.g., high, medium, low), and the system must always process high-priority orders first. Orders also have timestamps, and if two orders have the same priority, the older order should be processed first.

Task:
Design a system to efficiently process incoming orders using C++ and STL. 
The system should support the following operations:
Adding a new order (order_id, priority, timestamp).
Retrieving and processing the highest-priority order.
Removing processed orders.

Hint:
Use a priority queue (std::priority_queue) with a custom comparator to maintain order priority while ensuring that orders with the same priority are processed based on timestamps.
*/

#include<iostream>
#include<queue>
using namespace std;
struct Order{
    int order_id;
    int priority;
    int timestamp;
    Order(int o, int p, int t) : order_id(o), priority(p), timestamp(t){}
};
struct Comparator{
    bool operator()(const Order& a, const Order& b){
        if(a.priority != b.priority){
            return a.priority<b.priority;
        }
        return a.timestamp > b.timestamp;
    }
};
int main(){
    priority_queue<Order, vector<Order>, Comparator> pq;
    pq.push(Order(1, 2, 1001));  
    pq.push(Order(2, 3, 1002));
    pq.push(Order(3, 3, 1000));
    pq.push(Order(4, 1, 1003));

    while (!pq.empty()) {
        Order topOrder = pq.top();
        std::cout << "Processing Order ID: " << topOrder.order_id << ", Priority: " << topOrder.priority << ", Timestamp: " << topOrder.timestamp << std::endl;
        pq.pop();
    }

    return 0;
}