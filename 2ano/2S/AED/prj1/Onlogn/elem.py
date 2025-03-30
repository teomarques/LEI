import random

def generate_array():
    # random.sample guarantees uniqueness of the elements and the selection is random. returns array of unique elements
    array = random.sample(range(999999), 999998) 
    return array

# writing the array in a file for the cpp program to get back
with open('array.txt', 'w') as f:
    for item in generate_array():
        f.write(f"{item}\n")

