# 🏗️ Push_Swap Project

## 🚀 Overview

The **Push_Swap** project is a sorting algorithm challenge where integers must be organized in ascending order using two stacks (`a` and `b`) and a minimal set of operations. This project emphasizes algorithmic efficiency, modularity, and memory-safe programming, providing an excellent exercise in optimization and data structure management. 

## 🧩 Algorithm: Segmented Recursive Strategy

The Push_Swap project's core sorting mechanism is a segmented recursive strategy inspired by merge-sort principles but uniquely adapted to the constraints of dual-stack operations. The algorithm ensures efficiency, modularity, and compliance with the minimal operation requirements of the project.

### Overview

The algorithm operates in two main phases:

-> **Segmentation**✂️: Splitting the stack into smaller, manageable parts using dynamic pivot selection.

-> **Recursive Sorting** 🔄: Sorting and reintegrating the segments back into the main stack in sorted order.
By dynamically dividing and conquering the problem, the algorithm achieves near-optimal efficiency while maintaining the constraints of the Push_Swap instruction set.

By dynamically dividing and conquering the problem, the algorithm achieves near-optimal efficiency while maintaining the constraints of the Push_Swap instruction set.

### Step-by-Step Breakdown

1. **Input Handling**
The program initializes stack a with the given integers, ensuring all constraints (e.g., no duplicates, valid input) are met.
Stack b is initially empty and used as auxiliary storage during sorting.

2. **Base Cases**
Small Inputs (≤ 3 Elements):
For inputs with 1 to 3 elements, specific functions are used to sort directly with minimal operations.

3. **Segmentation**
For larger inputs, the stack is segmented using two pivots:
Pivot 1: Divides the stack into a lower third.
Pivot 2: Separates the middle third.
The segments are categorized into:
Max: Largest elements.
Mid: Middle-range elements.
Min: Smallest elements.

5. **Recursive Sorting**
Each segment (Max, Mid, Min) is recursively sorted:
Base Case: When segment size ≤ 3, it is handled with direct sorting functions.
Recursive Case: Segments are further divided and sorted until base cases are reached.

7. **Reintegration**
Segments are reintegrated into stack a in sorted order, maintaining the ascending sequence.

### Key Functions and Their Roles

- Segmentation (`divide.c`):

  - Dynamically calculates pivots based on the segment size.
  - Categorizes elements into Max, Mid, and Min segments.

- Recursive Sorting (`segmented_sort.c`):

  - Recursively processes each segment, using smaller cases for segments with fewer elements.

- Operations Abstraction (`move.c`):

  - Encapsulates stack manipulation operations (`op_pb`, `op_sa`, etc.) into reusable movement functions.

- Utilities (`segment_utils.c`):

  - Helper functions like segment_rank, segment_max_rank ensure efficient segmentation and ranking within stacks.
- Circular Indexing:
  - The stack supports circular indexing to ensure seamless rotation, avoiding out-of-bounds errors.
  
### Algorithm Complexity
* **Time Complexity**: Approximately O(n log n), due to recursive segmentation and linear processing of each segment.
* **Space Complexity**: Efficiently uses stack space and temporary variables for pivots and segment tracking.

### ASCII Representation of the Process:
```shell
                🚦 Start
                  |
                  v
      +--------------------+
      |   Initial Stack A  |
      +--------------------+
                  |
                  v
      +-------------------------------+
      |   Segmentation (Using Pivots) |
      +-------------------------------+
                  |
                  v
    +-----------------------------------+
    |     Divide into Three Segments:   |
    |                                   |
    |     +---------+    +---------+    |
    |     |   Max   |    |   Mid   |    |
    |     +---------+    +---------+    |
    |                                   |
    |     +---------+                   |
    |     |   Min   |                   |
    |     +---------+                   |
    +-----------------------------------+
                  |
                  v
     +----------------------------------+
     | Recursive Sorting of Each Segment|
     +----------------------------------+
                  |
                  v
     +-----------------------------------+
     |   Reintegration into Stack A in   |
     |         Sorted Order              |
     +-----------------------------------+
                  |
                  v
              🎉 Sorted!
```

## 🧰 Data Structures and Memory Management

## Core Data Types

* t_stack
Represents one stack (`a` or `b`) with circular indexing for seamless rotation.
```shell
+---------------------+
|      t_stack        |
+--------------------------------+
| stack   -> (array of integers) |
| top     -> (index of top)      |
| bottom  -> (index of bottom)   |
| size    -> (capacity)          |
+--------------------------------+
```
* t_data
Global structure managing both stacks and the operation list.
```shell
+--------------------------------+
|            t_data              |
+--------------------------------+
| a       -> t_stack (Stack A)   |
| b       -> t_stack (Stack B)   |
| op_list -> operations list     |
+--------------------------------+
```
## Memory Safety

- Avoidance of Overflows:
  - Inputs are validated to fit within `INT_MIN` and `INT_MAX` ranges.
- Circular Indexing:
  - Functions like `next_index` and `prev_index` ensure safe access across the circular stack.

## ⚙️ Allowed Operations
The algorithm uses these operations to manipulate stacks efficiently:

### 🔄 Swap  Operations(`swap.c`): 
- sa: Swap the first two elements of stack a.
- sb: Swap the first two elements of stack b.
- ss: Perform sa and sb simultaneously.

### 📤 Push  Operations(`push.c`):
- pa: Push the top element of stack b onto stack a.
- pb: Push the top element of stack a onto stack b..

### 🔃 Rotate Operations(`rotate.c`):
- ra: Shift all elements of stack a upwards, with the first element becoming the last.
- rb: Shift all elements of stack b upwards.
- rr: Perform ra and rb simultaneously.

### ↩️Reverse Rotate Operations(`rrotate.c`):
- rra: Shift all elements of stack a downwards, with the last element becoming the first.
- rrb: Shift all elements of stack b downwards.
- rrr: Perform rra and rrb simultaneously.

Each operation is implemented in a modular manner, logged in `op_list`, and printed as the output.

## 🌟 Strengths of the Project
### ⚡ Optimized Performance:
  - Handles both small and large inputs efficiently.
### 🛡️ Robust Memory Management:
  - Prevents leaks and handles invalid inputs gracefully.
### 🛠️ Modular Design:
  - Each operation and sorting step is encapsulated in reusable functions.
### 📈 Scalable:
  - Adapts seamlessly to different input sizes.

## Conclusion
The Push_Swap project exemplifies the application of algorithmic strategies to achieve efficient sorting with minimal operations. By combining different sorting techniques based on input size and focusing on optimization, it offers a comprehensive exploration of algorithm design and performance tuning.
