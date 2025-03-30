def compare(a, b):
    return a - b

# Complexity O(n log n)
if __name__ == "__main__":
    import sys

    # Get data from file
    with open('array.txt', 'r') as file:
        sequence = [int(line.strip()) for line in file if line.strip()]

    # Get parameter from argv (though not used in this context)
    if len(sys.argv) > 1:
        size = int(sys.argv[1])
    else:
        size = len(sequence)

    # Sorting
    sequence.sort(key=int)

    # Find the gap
    for i in range(len(sequence) - 1):
        if sequence[i + 1] - sequence[i] > 1:
            print(sequence[i] + 1)
