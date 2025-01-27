# Example dialogue graphs represented as adjacency list to use as different test cases

# Valid Graph Example
OAK = {
    'A': ['B', 'C', 'E'],
    'B': ['C'],
    'C': ['D', 'F'],
    'D': [],
    'E': ['C'],
    'F': ['G'],
    'G': [] 
}

# Valid Graph Example 2
VALIDGRAPH2 = {
    'A': ['B', 'C', 'D'],
    'B': ['E'],
    'C': ['E'],
    'D': ['E'],
    'E': [],
}

# Valid Graph Example 3
VALIDGRAPH3 = {
    'A': ['B', 'C', 'E'],
    'B': ['D'],
    'C': ['E'],
    'D': [],
    'E': ['F'],
    'F': ['G'],
    'G': [] 
}

# Singleton Graph Example
SINGLETON = {
    'A': []
}

# Unreachable Node Example
NODENOTREACHED = {
    'A': ['C', 'E'],
    'B': ['C'],
    'C': ['D', 'F'],
    'D': [],
    'E': ['C'],
    'F': ['G'],
    'G': []  
}

# Unreachable Node Example 2
NODENOTREACHED2 = {
    'A': ['B', 'C'],
    'B': ['C'],
    'C': [],
    'D': ['C'],
}

# Infinite Loop with Two Nodes
INFINITELOOP = {
    'A': ['B'],
    'B': ['A']
}

# Infinite Loop in Larger Graph
INFINITELOOPLONG = {
    'A': ['B', 'C'], 
    'B': ['C'], 
    'C': ['A', 'D'], 
    'D': ['D']
}

# Multi-Node Circular Loop
INFINITECIRCLE = {
    'A': ['B'],
    'B': ['C'],
    'C': ['D'],
    'D': ['A']
}

# Multi-Node Circular Loop Example 2
INFINITECIRCLE2 = {
    'A': ['B'],
    'B': ['C'],
    'C': ['D'],
    'D': ['E'],
    'E': ['A']
}

# Self Loop in Graph
SELFLOOP = {
    'A': ['B', 'C', 'E'],
    'B': ['C'],
    'C': ['D', 'F'],
    'D': [],
    'E': ['C'],
    'F': ['G'],
    'G': ['G'] 
}

# Self Loop in Graph Example 2
SELFLOOP2 = {
    'A': ['B'],
    'B': ['B']
}
