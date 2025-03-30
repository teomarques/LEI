import time
import elem as arr  # Assuming elem is a module with an array

def verifica(arr):
    # Start timing
    start_time = time.time()
    
    # variables
    length = len(arr)
    minEl = min(arr)
    maxEl = max(arr)
    flag = False
    missing = -1

    # two fors iterate through the loop N² times
    for i in range(length-1):
        for j in range(length-1):
            if(arr[j] == arr[i]+1 and arr[i] < maxEl):
                flag = True
                break
            elif(arr[j] == maxEl and not flag):
                missing = arr[i]+1
    
    # End timing
    end_time = time.time()
    
    # Calculate execution time in seconds
    execution_time = end_time - start_time
    
    print(f"Missing element: {missing}")
    print(f"Execution time: {execution_time:.6f} seconds")
    
    return missing

# Example usage (since I don't have access to elem module)
if __name__ == "__main__":
    # Test with a sample array since elem isn't available
    test_arr = [1, 2, 4, 5, 6]  # Should find 3 as missing
    verifica(test_arr)
