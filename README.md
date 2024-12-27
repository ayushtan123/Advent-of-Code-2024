# Advent of Code 2024
This repository contains my solutions for **Advent of Code 2024**.  

Update: completed till day 9. Dec is vacation time 🙃

Author : **Ayush Tandon**  

Start Date  : **06-12-2024**  

## Day 1  

### Part 1:  
- Use two priority queues.  
- Find the absolute difference:
  
  ```cpp
    abs(A.top() - B.top())

### Part 2:
- Implement a solution using two maps in C++.
- Traverse through column 1 (it is iterator over column 1):

  ```cpp
    ans += freq of it.first in column 2 * freq of it.first in column 1 * it.first

Where it.first refers to the value.
