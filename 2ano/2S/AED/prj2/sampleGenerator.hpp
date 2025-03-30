#ifndef SAMPLE_GENERATOR_HPP
#define SAMPLE_GENERATOR_HPP

// here there is a generic function that generates a sample of integers with repetition
// the specific ones only call this generic function with specific parameters for the program to work

#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <set>
#include <stdexcept>
#include <functional>

// Generic sample generation function that accepts a custom insertion function
// will be used by the wrapper functions below
std::vector<int> generate_sample_with_repetition
(
    // Parameters
    int range_start, 
    int range_end, 
    int sample_size, 
    std::function<void(int)> insert_func,   // function to insert values to respective tree
    bool ascending = true, 
    bool random_order = false, 
    double repeat_percentage = 0.5
) {
    // Check if we can generate enough unique values
    if (range_end - range_start + 1 < sample_size)
    {
        throw std::invalid_argument("Range too small to generate requested unique numbers");
    }

    // Random number generation setup
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(range_start, range_end);

    // Generate unique numbers
    std::set<int> unique_nums;
    while (unique_nums.size() < sample_size)
      unique_nums.insert(dist(gen));

    // Create result vector with unique numbers
    std::vector<int> result(unique_nums.begin(), unique_nums.end());

    // Add repeated values
    int repeat_count = sample_size * repeat_percentage;
    for (int i = 0; i < repeat_count; ++i)
    {
        std::uniform_int_distribution<int> repeat_dist(0, result.size() - 1);
        result.push_back(result[repeat_dist(gen)]);
    }

    // Sort or shuffle based on parameters
    if (ascending)  std::sort(result.begin(), result.end()); 
    
    if (random_order)   std::shuffle(result.begin(), result.end(), gen);

    // Insert values using the provided insertion function
    for (int val : result)  insert_func(val);

    return result;
}

// Wrapper functions with specific configurations for ascending sample
std::vector<int> ascending_sample_repetition
(
    // parameters
    int range_start, 
    int range_end, 
    int sample_size, 
    std::function<void(int)> insert_func    // function to insert values to respective tree
) {
    return generate_sample_with_repetition  // call generic function that generates sample
    (
        // paraneters of the generic function
        range_start, range_end, sample_size, insert_func, 
        true, false
    );
}

// Wrapper functions with specific configuration for descending sample
std::vector<int> descending_sample_repetition
(
    // parameters
    int range_start, 
    int range_end, 
    int sample_size, 
    std::function<void(int)> insert_func
) {
    auto result = generate_sample_with_repetition
    (
        range_start, range_end, sample_size, 
        insert_func, true, false
    );
    std::sort(result.begin(), result.end(), std::greater<int>());
    
    // Re-insert sorted values
    for (int val : result)  insert_func(val);
    
    return result;
}

// Wrapper functions with specific configuration for random sample
std::vector<int> random_sample_repetition
(
    // parameters
    int range_start, 
    int range_end, 
    int sample_size, 
    std::function<void(int)> insert_func
) {
    return generate_sample_with_repetition
    (
        range_start, range_end, sample_size, 
        insert_func, true, true
    );
}

// Wrapper functions with specific configuration for 90% random sample
std::vector<int> random_sample_90percent
(
    int range_start, 
    int range_end, 
    int sample_size, 
    std::function<void(int)> insert_func
) {
    return generate_sample_with_repetition
    (
        range_start, range_end, sample_size, 
        insert_func, true, true, 0.9
    );
}

#endif // SAMPLE_GENERATOR_HPP
