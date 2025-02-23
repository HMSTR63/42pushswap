# Push Swap: An Efficient Positional Sorting Algorithm

## Overview

This project implements an efficient sorting algorithm for a random list of integers using a limited set of operations on two stacks (A and B). The goal is to sort the integers in ascending order within stack A using the fewest possible moves, adhering to the constraints of the Push_Swap project.

This implementation leverages an indexing and positional system to achieve high efficiency and a guaranteed 100% grade with correct implementation. This Readme provides a guide to the underlying concepts, the chosen approach, and tips for testing the code.

## Table of Contents

- [Push_Swap Rules](#push_swap-rules)
- [Possible Push_Swap Actions](#possible-push_swap-actions)
- [Grading System](#grading-system)
- [Methodology: Positional Sorting Algorithm](#methodology-positional-sorting-algorithm)
  - [Linked List Implementation](#linked-list-implementation)
  - [Assigning Indexes](#assigning-indexes)
  - [Choosing a Sorting Algorithm](#choosing-a-sorting-algorithm)
  - [Sorting Algorithm for 3 Numbers](#sorting-algorithm-for-3-numbers)
  - [Sorting Algorithm for Over 3 Numbers](#sorting-algorithm-for-over-3-numbers)
    - [Step 1: Send Everything to Stack B](#step-1-send-everything-to-stack-b)
    - [Step 2: Sort the 3 Numbers Left in Stack A](#step-2-sort-the-3-numbers-left-in-stack-a)
    - [Step 3: Calculating Positions](#step-3-calculating-positions)
    - [Step 4: Calculating the Cheapest Action Cost](#step-4-calculating-the-cheapest-action-cost)
    - [Step 5: Executing the Chosen Sequence of Actions](#step-5-executing-the-chosen-sequence-of-actions)
    - [Step 6: Rotate Stack A to the Right Position](#step-6-rotate-stack-a-to-the-right-position)

## Push_Swap Rules

The program must:

-   Receive a series of random positive and negative integers as arguments.
-   Print "error" if there are any duplicate numbers or if a number exceeds the integer limits.
-   Print a series of instructions, each on a new line, to sort the numbers in ascending order within stack A.

We are allowed to use two stacks:

-   **Stack A:** Initially filled with the numbers to be sorted (the first number is the top one).
-   **Stack B:** Starts off empty.

## Possible Push_Swap Actions

The following actions are available to manipulate the stacks:

**Push**

-   `pa` (push A): Take the first element at the top of stack B and put it at the top of stack A. Do nothing if B is empty.

    ```
    A : 1 3 4
    B : 5 9
    pa
    A : 5 1 3 4
    B : 9
    ```

-   `pb` (push B): Take the first element at the top of A and put it at the top of B. Do nothing if A is empty.

    ```
    A : 0 9 2
    B : 1 4
    pb
    A : 9 2
    B : 0 1 4
    ```

**Swap**

-   `sa` (swap A): Swap the first 2 elements at the top of stack A. Do nothing if there is only one or no elements.

    ```
    A : 8 3 9
    sa
    A : 3 8 9
    ```

-   `sb` (swap B): Swap the first 2 elements at the top of stack B. Do nothing if there is only one or no elements.

    ```
    B : 6 5 7
    sb
    B : 5 6 7
    ```

-   `ss`:  `sa` and `sb` at the same time.

    ```
    A : 2 1 3
    B : 5 0
    ss
    A : 1 2 3
    B : 0 5
    ```

**Rotate**

-   `ra` (rotate A): Shift all elements of stack A up by 1. The first element becomes the last one.

    ```
    A : 9 2 5 8
    ra
    A : 2 5 8 9
    ```

-   `rb` (rotate B): Shift all elements of stack B up by 1. The first element becomes the last one.

    ```
    B : 7 3 4 6
    rb
    B : 3 4 6 7
    ```

-   `rr`: `ra` and `rb` at the same time.

    ```
    A : 8 0 1 2 3
    B : 9 5 6
    rr
    A : 0 1 2 3 8
    B : 5 6 9
    ```

**Reverse Rotate**

-   `rra` (reverse rotate A): Shift all elements of stack A down by 1. The last element becomes the first one.

    ```
    A : 1 2 4 9 0
    rra
    A : 0 1 2 4 9
    ```

-   `rrb` (reverse rotate B): Shift all elements of stack B down by 1. The last element becomes the first one.

    ```
    B : 8 3 4 6 1
    rrb
    B : 1 8 3 4 6
    ```

-   `rrr`: `rra` and `rrb` at the same time.

    ```
    A : 7 6 4 9 2
    B : 8 5 3 1
    rrr
    A : 2 7 6 4 9
    B : 1 8 5 3
    ```

## Grading System

The grade depends on the efficiency of the actions generated to sort the numbers:

-   Sorting 3 values: no more than 3 actions.
-   Sorting 5 values: no more than 12 actions.
-   Sorting 100 values:
    -   5 points: less than 700 actions
    -   4 points: less than 900 actions
    -   3 points: less than 1,100 actions
    -   2 points: less than 1,300 actions
    -   1 point: less than 1,500 actions
-   Sorting 500 values:
    -   5 points: less than 5,500 actions
    -   4 points: less than 7,000 actions
    -   3 points: less than 8,500 actions
    -   2 points: less than 10,000 actions
    -   1 point: less than 11,500 actions

A grade of at least 80% is required to validate the project.

## Methodology: Positional Sorting Algorithm

This algorithm sorts by index and position, offering excellent performance and a guaranteed 100% grade if correctly implemented.

### Linked List Implementation

The algorithm uses linked lists.  Each element in the list contains the following variables:

typedef struct s_stack
{
	int value;
	int index;
	int pos;
	int target_pos;
	int cost_a;
	int cost_b;
	struct s_stack *next;
} 	t_stack;


Let's break down the purpose of each member within the `t_stack` structure:

-   `value`: The integer that needs to be sorted. This is the actual number that is being moved around in the stacks.

-   `index`:  A unique numerical identifier assigned to each integer.  The index represents the sorted order of the number within the entire list of numbers to be sorted. The smallest number has an index of 1, the next smallest has an index of 2, and so on. This is crucial for determining the correct sorted order.

-   `pos`: The current position of the number within its stack (either stack A or stack B). The position is an integer representing the element's location, starting from the top of the stack (position 0).  This is updated dynamically as elements are moved between stacks and rotated.

-   `target_pos`: This member is specifically used for elements residing in stack B. It indicates the desired position within stack A where the element should be placed to maintain the ascending sorted order. The algorithm aims to move the element from stack B to this `target_pos` in stack A.

-   `cost_a`:  An estimate of the number of operations (rotations or reverse rotations) needed to bring the element at `target_pos` to the top of stack A. This is used in conjunction with `cost_b` to determine the most efficient move.

-   `cost_b`: An estimate of the number of operations (rotations or reverse rotations) needed to bring the considered element to the top of stack B.  This is used in conjunction with `cost_a` to determine the most efficient move.

-   `next`: A pointer to the next element in the linked list, allowing us to traverse the stack.

The importance of all these variables will become clearer throughout the description of the algorithm.

### Assigning Indexes

Once we’ve filled our stack A with the values to sort, we need to assign each element an index, from smallest to biggest. For practical reasons, the index will start at 1 and end at the total number of values to sort. For example, let’s say we have a list of 10 numbers to sort, we will assign an index to each like this:

| Value        | Index |
| ------------ | ----- |
| 1900         | 9     |
| 42           | 8     |
| 18           | 7     |
| -146         | 2     |
| -30          | 3     |
| 2147483647   | 10    |
| 3            | 6     |
| 0            | 5     |
| -2147483648  | 1     |
| -2           | 4     |

Attributing indexes this way will make it much easier to know the order in which the random numbers should be.

### Choosing a Sorting Algorithm Depending on The Number of Values to Sort

Most other push_swap algorithms have distinct sorting methods for 5, 100 and 500 numbers. This isn’t the case here. What works for 500 numbers also works for 5. However, we still need a different algorithm for a 3 number sort.

But before we even choose between two sorting methods, it’s a good idea to check if stack A is already sorted, just in case. If it is, push_swap’s job ends right here.

However, if stack A is not sorted, we need to proceed differently depending on the number of values we need to sort:

-   2 values: all we need to do is `sa`.
-   3 values: jump to the 3 number algorithm
-   > 3 values: jump to the more-than-three numbers algorithm

### Sorting Algorithm For 3 Numbers

As per the grading scale, we should be able to sort 3 numbers with 3 or fewer actions. Here, we will never use more than two. For 3 values, there are six possible cases:

| Case    | Actions                      |
| ------- | ---------------------------- |
| 1 2 3   | => no action                 |
| 1 3 2   | -> rra -> 2 1 3 -> sa -> 1 2 3 => 2 actions |
| 2 1 3   | -> sa -> 1 2 3 => 1 action   |
| 2 3 1   | -> rra -> 1 2 3 => 1 action  |
| 3 1 2   | -> ra -> 1 2 3 => 1 action   |
| 3 2 1   | -> ra -> 2 1 3 -> sa -> 1 2 3 => 2 actions |

Our little 3 number sorting algorithm needs only pick one of three actions: `ra`, `rra` and `sa`, depending on the biggest number’s position. We can sum up the simple algorithm this way:

-   If the index of the first number is highest, do `ra`,
-   Otherwise, if the index of the second number is highest, do `rra`,
-   Then, if the index of the first number is bigger than the index of the second number, do `sa`.

We don’t use stack B at all here: a `pb` to push a number from stack A to stack B, followed by a `pa` to send it back to stack A would be a waste of actions!

### Sorting Algorithm for Over 3 Numbers

This algorithm consists of the following steps:

1.  **Send Everything to Stack B:** `pb` all elements from stack A to stack B, except for the smallest three. Prioritize pushing smaller values (index less than the median index) to stack B first, rotating A otherwise. After that, freely pb all the rest of the elements except for the last three that will remain in stack A.
2.  **Sort the 3 Numbers Left in Stack A:** Use the 3-number sorting algorithm to sort the remaining elements in stack A.
3.  **Iterate while stack B is not empty:**
    1.  **Calculate Positions:** Find the current position of every element in stacks A and B.
    2.  **Calculate Target Positions:** Calculate the target position in stack A for each element in stack B (where it should be inserted to maintain ascending order).
    3.  **Calculate Action Costs:** Determine the number of actions (cost) required to move each element from stack B to its target position in stack A. Choose the element with the lowest cost.
    4.  **Execute Actions:** Execute the sequence of actions to move the chosen element from stack B to stack A.
4.  **Final Rotation:** If stack A is not fully sorted, rotate it using `ra` or `rra` to achieve ascending order.

#### Step 1: Send Everything to Stack B

Push all elements from stack A to stack B, except for three. Elements are pushed in a semi-ordered way based on their index relative to the median index.

#### Step 2: Sort the 3 Numbers Left in Stack A

Sort the remaining three elements in stack A using the 3-number sorting algorithm.

#### Step 3: Calculating Positions

##### Finding the Position of Each Element

Scan the stack from top to bottom, assigning each element a position that increments with each iteration. Update these positions frequently to reflect stack changes.

##### Finding the Target Position of Each Element in Stack B

For each element in stack B, the target position is the location in stack A where the element should be inserted to maintain ascending order. This is found by identifying the element in stack A with the closest superior index. If an element in stack B has a superior index to all elements in stack A, the smallest index's position in stack A is used as the target position.

Here's an example of calculating target positions:

**Stack A:**

| Value | Index | Position |
| ----- | ----- | -------- |
| 8     | 6     | 0        |
| 0     | 1     | 1        |
| 1     | 2     | 2        |
| 3     | 4     | 3        |

**Stack B:**

| Value | Index | Position | Target Position |
| ----- | ----- | -------- | --------------- |
| 2     | 3     | 0        | 3               |
| 6     | 5     | 1        | 0               |
| 9     | 7     | 2        | 1               |

#### Step 4: Calculating the Cheapest Action Cost

After determining positions and target positions, compare the costs (number of actions) to move each element from stack B to its correct location in stack A. This calculation considers rotations in both stacks.

#### Step 5: Executing the Chosen Sequence of Actions

Execute the optimal sequence of `pa`, `pb`, `ra`, `rb`, `rra`, `rrb` (and potentially `sa`, `sb`, `ss`, `rr`, `rrr`) commands to bring the chosen element from the top of stack B to its target position in stack A.

#### Step 6: Rotate Stack A to the Right Position

After transferring all elements from stack B back to A, perform final rotations (`ra` or `rra`) on stack A to ensure it's completely sorted in ascending order, with the smallest element at the top.


There ! Stack A should now be correctly sorted in ascending order, and our push_swap program should have printed out the smallest number of instructions to make it so.