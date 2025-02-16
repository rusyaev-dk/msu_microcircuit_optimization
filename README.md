# Microcircuit Optimization

## 📌 Project Description
This project focuses on optimizing computations in a stack-based microcircuit, which performs multiplication, exponentiation, and value storage operations. The main goal is to minimize the number of clock cycles required to compute the power function x^n.

## 🔧 Core Microcircuit Operations
Operation	Description	Execution Time (Cycles)
- WRITE X:	Pushes the number X onto the stack	1 cycle
- MUL:	Multiplies the top two numbers on the stack and replaces them with the result	1 cycle
- POW N:	Raises the top value on the stack to the power of N and replaces it	N - 1 cycles

## 🚀 Optimization Approach

### 1️⃣ Efficient Exponentiation Using Binary Exponentiation
- Instead of naïve exponentiation (O(n) complexity), the microcircuit uses binary exponentiation (O(log n)), reducing execution cycles significantly.
- Converts n into binary form.
- Uses squaring and selective multiplication to minimize operations.
### 2️⃣ Optimized Stack Management
- Avoids unnecessary operations and stack manipulations.
- Reduces memory footprint by efficiently handling intermediate values.

Results:

![1](/screenshots/1.png "1")
![2](/screenshots/2.png "2")


## 📊 Performance Metrics Tracking
To measure and compare different optimization approaches, the following metrics are tracked:

- Cycles	The total number of execution cycles
- Elementary Operations	Number of multiplications, additions, etc.
- Execution Time (ms)	The actual runtime of the computation
- These metrics help in evaluating Brute Force vs. Binary Exponentiation approaches.

## Performance Comparison
| Test Case | BF (Cycles) | BE (Cycles) | BF (Ops) | BE (Ops) | BF (ms) | BE (ms) |
|-----------|------------|------------|------------|------------|------------|------------|
| 1         | 10         | 4          | 9          | 3          | 15.432     | 7.120      |
| 2         | 20         | 5          | 18         | 4          | 32.845     | 9.302      |

Results clearly show that Binary Exponentiation (BE) is significantly more efficient than Brute Force (BF) in terms of cycles and execution time.
