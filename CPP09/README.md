# CPP Module 09 - STL Container Usage and Algorithms

This module focuses on using STL containers and implementing various algorithms in C++. Each exercise demonstrates different aspects of container usage, parsing, and algorithm implementation.

## Table of Contents
- [Exercise 00: Bitcoin Exchange](#exercise-00-bitcoin-exchange)
- [Exercise 01: Reverse Polish Notation](#exercise-01-reverse-polish-notation)
- [Exercise 02: PmergeMe - Ford-Johnson Algorithm](#exercise-02-pmergeme---ford-johnson-algorithm)
- [System Functions Used](#system-functions-used)

---

## Exercise 00: Bitcoin Exchange

### Overview
A program that calculates the value of bitcoins based on a database of exchange rates using the `std::map` container.

### Algorithm Description
The program uses a **binary search tree** (implemented via `std::map`) to store exchange rates and efficiently find the appropriate rate for a given date.

#### Key Algorithm Components:
1. **Data Storage**: Uses `std::map<std::string, double>` where keys are dates and values are exchange rates
2. **Date Lookup**: Implements `lower_bound()` to find the closest available date
3. **Date Validation**: Custom date validation algorithm that checks:
   - Syntax validation (YYYY-MM-DD format)
   - Leap year calculation
   - Month-specific day validation

### System Functions Used
- `std::ifstream::open()` - File opening operations
- `std::getline()` - Line-by-line file reading
- `std::strtod()` - String to double conversion
- `std::strtof()` - String to float conversion
- `std::atoi()` - String to integer conversion
- `std::map::insert()` - Container insertion
- `std::map::lower_bound()` - Binary search tree traversal
- `std::map::find()` - Element lookup

### Data Structures
- **Primary Container**: `std::map<std::string, double>` for O(log n) lookups
- **File Stream**: `std::ifstream` for file I/O operations

### Time Complexity
- **Insertion**: O(log n) per element
- **Lookup**: O(log n) per query
- **Overall**: O(n log n) for database creation, O(m log n) for m queries

### Usage
```bash
make -C ex00
./ex00/btc input.txt
```

### Input Format
```
date | value
2011-01-03 | 3
2011-01-03 | 2
2011-01-09 | 1
```

---

## Exercise 01: Reverse Polish Notation

### Overview
A calculator that evaluates mathematical expressions written in Reverse Polish Notation (RPN) using a `std::stack`.

### Algorithm Description
The program implements a **stack-based evaluation algorithm** for RPN expressions.

#### Algorithm Steps:
1. **Token Parsing**: Split input into tokens (numbers and operators)
2. **Stack Operations**:
   - If token is a number: push onto stack
   - If token is an operator: pop two operands, apply operation, push result
3. **Final Result**: Single value remaining on stack

#### Core Algorithm Implementation:
```cpp
void RPN::doRPN(std::stringstream &iss)
{
    std::string token;
    
    while (iss >> token)
    {
        if (isNumber(token))
        {
            long value = std::strtol(token.c_str(), NULL, 10);
            expressions.push(static_cast<int>(value));
        }
        else if (isOperator(token))
        {
            // Example: Addition operation
            if (expressions.size() < 2)
                throw std::invalid_argument("Not enough operands");
            
            int a = expressions.top(); expressions.pop();
            int b = expressions.top(); expressions.pop();
            
            expressions.push(b + a);  // Note: order matters for - and /
        }
    }
    
    if (expressions.size() != 1)
        throw std::invalid_argument("Invalid expression");
    
    std::cout << expressions.top() << std::endl;
}
```

#### Program Flow:
1. **Input Validation**: Checks if all tokens are valid numbers or operators
2. **Expression Evaluation**: Processes tokens left to right using stack operations
3. **Result Output**: Displays the final calculated value

#### Supported Operations:
- Addition (`+`)
- Subtraction (`-`)
- Multiplication (`*`)
- Division (`/`)

### System Functions Used
- `std::stack::push()` - Add element to stack
- `std::stack::pop()` - Remove top element
- `std::stack::top()` - Access top element
- `std::stack::size()` - Get stack size
- `std::strtol()` - String to long conversion
- `std::stringstream` - String tokenization

### Data Structures
- **Primary Container**: `std::stack<int>` for operand storage
- **Input Processing**: `std::stringstream` for tokenization

### Time Complexity
- **Per Operation**: O(1) for stack operations
- **Overall**: O(n) where n is the number of tokens

### Usage
```bash
make -C ex01
./ex01/RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"
```

### Example
```
Input: "3 4 + 2 *"
Stack Operations:
1. Push 3: [3]
2. Push 4: [3, 4]
3. '+': Pop 4,3 → Calculate 3+4 → Push 7: [7]
4. Push 2: [7, 2]
5. '*': Pop 2,7 → Calculate 7*2 → Push 14: [14]
Result: 14
```

**Why RPN is efficient:**
- No need for parentheses or operator precedence rules
- Linear time evaluation O(n)
- Natural stack-based processing

---

## Exercise 02: PmergeMe - Ford-Johnson Algorithm

### Overview
Implementation of the Ford-Johnson merge-insertion sort algorithm, comparing performance between `std::vector` and `std::deque` containers.

### Algorithm Description
The **Ford-Johnson algorithm** is a sorting algorithm that minimizes the number of comparisons by using a specific insertion order based on Jacobsthal numbers.

#### Algorithm Steps:
1. **Pairing Phase**: Group elements into pairs and sort each pair
2. **Recursive Sorting**: Recursively sort the larger elements of each pair
3. **Jacobsthal Sequence**: Generate optimal insertion order using Jacobsthal numbers
4. **Binary Insertion**: Insert smaller elements using binary search

#### Core Algorithm Implementation:
```cpp
std::vector<int> PmergeMe::_mergeInsertion(std::vector<int> &container)
{
    if (container.size() <= 1)
        return container;
    
    std::vector<int> smaller, larger;
    
    // Step 1: Pair and sort
    for (std::size_t i = 0; i+1 < container.size(); i += 2)
    {
        if (container[i] < container[i+1])
        {
            smaller.push_back(container[i]);
            larger.push_back(container[i+1]);
        }
        else
        {
            smaller.push_back(container[i+1]);
            larger.push_back(container[i]);
        }
    }
    
    // Step 2: Recursively sort larger elements
    std::vector<int> sortedLarger = _mergeInsertion(larger);
    
    // Step 3: Insert smaller elements using Jacobsthal order
    for (std::size_t i = 0; i < insertionOrder.size(); ++i)
    {
        if (insertionOrder[i] - 1 >= smaller.size())
            continue;
        
        int value = smaller[insertionOrder[i] - 1];
        std::size_t pos = _binarySearch(sortedLarger, value);
        sortedLarger.insert(sortedLarger.begin() + pos, value);
    }
    
    return sortedLarger;
}

// Binary search for insertion position
std::size_t PmergeMe::_binarySearch(const std::vector<int> &container, int value)
{
    std::size_t left = 0, right = container.size();
    
    while (left < right)
    {
        std::size_t mid = left + (right - left) / 2;
        if (container[mid] < value)
            left = mid + 1;
        else
            right = mid;
    }
    return left;
}
```

#### Program Flow:
1. **Input Parsing**: Converts command line arguments to integers
2. **Jacobsthal Generation**: Creates optimal insertion order sequence
3. **Dual Container Sort**: Sorts using both vector and deque containers
4. **Performance Comparison**: Measures and displays execution time for both containers

#### Jacobsthal Numbers:
The sequence follows: J(n) = (2^n - (-1)^n) / 3
- J(0) = 0, J(1) = 1, J(2) = 1, J(3) = 3, J(4) = 5, J(5) = 11, ...

```cpp
void PmergeMe::jacobsthalNumbers(std::size_t size)
{
    std::size_t prevJacob = 1;
    
    for (std::size_t n = 2; prevJacob < size; ++n)
    {
        std::size_t currentJacob = (std::pow(2, n) - (std::pow(-1, n))) / 3;
        insertionOrder.push_back(currentJacob);
        
        // Add intermediate values in reverse order
        for (std::size_t i = currentJacob - 1; i > prevJacob; --i)
            insertionOrder.push_back(i);
        
        prevJacob = currentJacob;
    }
}
```

### System Functions Used
- `std::vector::insert()` - Element insertion
- `std::deque::insert()` - Element insertion
- `std::vector::push_back()` - Element addition
- `std::deque::push_back()` - Element addition
- `clock()` - Performance timing
- `std::pow()` - Mathematical power calculation
- `std::setprecision()` - Output formatting

### Data Structures
- **Primary Containers**: `std::vector<int>` and `std::deque<int>`
- **Auxiliary**: `std::vector<std::size_t>` for insertion order sequence

### Time Complexity
- **Comparisons**: Approximately n * log(n) - optimal for comparison-based sorting
- **Insertions**: O(n²) in worst case due to element shifting
- **Overall**: O(n * log(n)) comparisons, O(n²) movements

### Space Complexity
- **Auxiliary Space**: O(n) for temporary containers during recursion

### Performance Comparison
The program measures and compares:
- **Vector**: Better cache locality, but expensive insertions
- **Deque**: Cheaper insertions, but slightly worse cache performance

### Usage
```bash
make -C ex02
./ex02/PmergeMe 3 5 9 7 4
```

### Example Output
```
Insertion order: 1 3 2 5 4 11 10 9 8 7 6 
Before: 3 5 9 7 4 
After(deque): 3 4 5 7 9 
Ford-Johnson algorithm executed: 0.000021s
After(vector): 3 4 5 7 9 
Ford-Johnson algorithm executed: 0.000018s
```

**Algorithm Visualization for [3, 5, 9, 7, 4]:**
```
Step 1 - Pairing: [(3,5), (9,7), 4]
Step 2 - Sort pairs: [(3,5), (7,9), 4]
Step 3 - Larger elements: [5, 9] → sorted: [5, 9]
Step 4 - Insert using Jacobsthal order:
  - Insert 3 into [5, 9] → [3, 5, 9]
  - Insert 7 into [3, 5, 9] → [3, 5, 7, 9]
  - Insert 4 into [3, 5, 7, 9] → [3, 4, 5, 7, 9]
```

## System Functions Used

### File I/O Operations
- `std::ifstream::open()` - Open files for reading
- `std::getline()` - Read lines from files
- `std::ifstream::close()` - Close file streams

### String Processing
- `std::strtod()` - Convert string to double
- `std::strtof()` - Convert string to float
- `std::strtol()` - Convert string to long
- `std::atoi()` - Convert string to integer
- `std::stringstream` - String tokenization and parsing

### Container Operations
- `std::map::insert()` - Insert key-value pairs
- `std::map::lower_bound()` - Find iterator to first element not less than key
- `std::map::find()` - Find element by key
- `std::stack::push()` - Add element to stack top
- `std::stack::pop()` - Remove top element
- `std::stack::top()` - Access top element
- `std::vector::insert()` - Insert elements at position
- `std::deque::insert()` - Insert elements at position

### Time Measurement
- `clock()` - Get processor time
- `CLOCKS_PER_SEC` - Clock ticks per second constant

### Mathematical Operations
- `std::pow()` - Calculate power
- `std::isdigit()` - Check if character is digit
- `std::isspace()` - Check if character is whitespace

### Memory and Error Handling
- `errno` - Global error variable
- `ERANGE` - Range error constant
- Exception handling with `try-catch` blocks

---

## Key Learning Points

1. **Container Selection**: Understanding when to use `std::map`, `std::stack`, `std::vector`, and `std::deque`
2. **Algorithm Implementation**: Practical implementation of sorting and evaluation algorithms
3. **Performance Analysis**: Comparing container performance characteristics
4. **Error Handling**: Robust input validation and exception handling
5. **File Processing**: Efficient file I/O operations
6. **Time Complexity**: Understanding algorithmic complexity in practice

This module demonstrates advanced C++ programming concepts including STL container usage, algorithm implementation, and performance optimization techniques.
