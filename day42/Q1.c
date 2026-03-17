from collections import deque

# input
n = int(input())
queue = deque(map(int, input().split()))

stack = []

# Step 1: Queue -> Stack
while queue:
    stack.append(queue.popleft())

# Step 2: Stack -> Queue
while stack:
    queue.append(stack.pop())

# output
for i in queue:
    print(i, end=" ")
