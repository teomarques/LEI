import sys
import re
import matplotlib.pyplot as plt

def parse_input():
    # Dictionary to store results for each method
    results = {}
    current_method = None

    for line in sys.stdin:
        line = line.strip()
        
        # Detect which method is being used
        menu_match = re.match(r'Enter choice: (\d+)', line)
        if menu_match:
            current_method = int(menu_match.group(1))
            results[current_method] = {'sample_sizes': [], 'times': []}
        
        # Parse sample size and time data
        csv_match = re.match(r'(\d+),(\d+)', line)
        if csv_match and current_method:
            sample_size = int(csv_match.group(1))
            time_ms = int(csv_match.group(2))
            results[current_method]['sample_sizes'].append(sample_size)
            results[current_method]['times'].append(time_ms)

    return results

def plot_graphs(results):
    # Method names corresponding to menu choices
    method_names = {
        1: 'Random Sample (Few Repeated)',
        2: 'Ascending Sample',
        3: 'Descending Sample', 
        4: 'Random Sample (90% Repeated)'
    }

    # Create a figure with subplots
    fig, ax = plt.subplots(figsize=(12, 6))

    # Plot each method
    for method, data in results.items():
        if method in method_names:
            ax.plot(data['sample_sizes'], data['times'], 
                    marker='o', label=method_names[method])

    ax.set_xlabel('Sample Size')
    ax.set_ylabel('Time (ms)')
    ax.set_title('Binary Tree Construction Time by Sample Type')
    ax.legend()
    ax.grid(True)

    # Use logarithmic scale if the times vary widely
    ax.set_xscale('log')
    ax.set_yscale('log')

    plt.tight_layout()
    plt.show()

def main():
    try:
        # Parse input from stdin
        results = parse_input()
        
        # Plot graphs
        plot_graphs(results)
    
    except Exception as e:
        print(f"Error processing input: {e}", file=sys.stderr)

if __name__ == '__main__':
    main()
