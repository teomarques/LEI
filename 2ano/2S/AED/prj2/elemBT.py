import random

def create_test_files():
    """
    Creates 5 text files containing distinct random integers.
    Each file has a different size: 10K, 20K, 30K, 40K, and 50K elements.
    Each integer is written on a separate line.
    """
    # Define the file sizes we want to create (in thousands)
    file_sizes = [10, 20, 30, 40, 50]
    
    # Create a large pool of random numbers to ensure we have enough distinct values
    # Using a range much larger than our needs to minimize chance of collisions
    max_range = 10000000  # 10 million possible values
    
    for size in file_sizes:
        # Calculate actual number of elements needed
        num_elements = size * 1000
        
        # Generate unique random integers
        # random.sample ensures no duplicates
        random_numbers = random.sample(range(max_range), num_elements)
        
        # Create filename based on the number of elements
        filename = f"{size}Karray.txt"
        
        # Write numbers to file, one per line
        with open(filename, 'w') as file:
            for number in random_numbers:
                file.write(f"{number}\n")
        
        print(f"Created {filename} with {num_elements} distinct random integers.")

# Run the function when the script is executed
if __name__ == "__main__":
    create_test_files()
    print("All test files generated successfully!")
