import random

def generate_array():
    # random.sample guarantees uniqueness of the elements and the selection is random. returns array of unique elements
    array = random.sample(range(1000), 999)
    return array

# Generate the array
array = generate_array()

# Writing the array to a file for the cpp program to read back
with open('array.txt', 'w') as f:
    for item in array:
        f.write(f"{item}\n")

# Printing all elements without iterating through the whole array:
# Using string join for efficiency
print(", ".join(map(str, array)))
