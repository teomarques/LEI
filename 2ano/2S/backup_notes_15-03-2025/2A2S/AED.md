#### Avaliação

	PRJ1 ->   2 + 20 + 15 pts
	PRj2 ->   60 pts
	PRJ3 ->   10 pts

# TP-1

###### **Big-O Notation**

- **Complexity of an algorithm**

	##### **O(n)**

- Take the function that relates the input with the time
	- If the relation in time complexity is **linear**, then the **complexity** is **O(n)**
	- If the time increases (e.g.) quadradically according to the input, then the **complexity** is **O(n²)**
	- Logarithmic time complexity (e.g.) -> **O(log n)**
- To decide the worst algorithm, order by complexity and 
- *The time of execution is not a good measure for a good algorithm* 
	- *time or programming language used can be misleading to analyze the complexity of the algorithm* (e.g. a program executed in python will be slower than in C)

	PS: Not always the program of complexity *O(n)* is more efficient than the *O(n²)*. Sometimes if *n* is sufficiently big, *n²* can be more efficient than n, if the linear regression of n in time is steep enough

---

# T 4

==Binary Trees==

-  Specifies how a given sequence of bits must be interpreted
- Determines the space (in memory) that must be reserved to gather the declared object(s)

![[Pasted image 20250224170853.png]]

==Binary Search Trees (BST)==

> On the other hand, the BSTs need the left nodes (and subtrees) to have the lower value nodes (until a leaf) than the right side ones.

%faltam coisas%

==Tree re-balancing==

==AVL Trees==

![[Pasted image 20250224163312.png]]

- this means that an AVL tree can only have a Balance Factor (FE) with the values -1, 0 or 1
- *always* go from the bottom UP, in the sub-tree that has the greatest height, and then perform the rotations