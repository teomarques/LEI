import numpy as np
import scipy.io         # for saving / loading .mat files

# ----------------------------------------------------------------------------
# 1.1 -> define the matrix A
# ----------------------------------------------------------------------------
A = np.array([[1, 2, 3, 4],
              [5, 6, 7, 8],
              [9, 10, 11, 12]])
''' MATLAB
A = [1 2 3 4; 5 6 7 8; 9 10 11 12];
'''
# ----------------------------------------------------------------------------
# 1.2 -> define the matrix B with random integers 
# ----------------------------------------------------------------------------
B = np.random.randint(3, 11, size=A.shape)        # upper bound is exclusive, so use 11
print(A.shape)
''' MATLAB
B = randi([3, 10], size(A));
'''
# ----------------------------------------------------------------------------
# 1.3 -> save matrices to a .mat file (using script.io)
# ----------------------------------------------------------------------------
scipy.io.savemat('abfile.mat', {'A': A, 'B': B})
''' MATLAB
save('abfile.mat', 'A', 'B');
'''
# ----------------------------------------------------------------------------
# 1.4 -> clean workspace in MATLAB - only works in MATLAB 
# ----------------------------------------------------------------------------
''' MATLAB
clear;
------------
In PYTHON we can do:
del A, B
'''
# ----------------------------------------------------------------------------
# 1.5 -> load matrices from the .mat file (ideally only in MATLAB but I will use scipy.io)
# ----------------------------------------------------------------------------
mat_data = scipy.io.loadmat('abfile.mat')       # mat_data will be a list of the two matrices (lists of lists)
A = mat_data['A']
B = mat_data['B']
''' MATLAB
load('abfile.mat');
'''
# ----------------------------------------------------------------------------
# 1.6 -> eliminate second row of A and third row of B
# ----------------------------------------------------------------------------
A = np.delete(A, 1, axis=0)     # delete row at index 1 (second row) || axis=0 specifies ROW
B = np.delete(B, 2, axis=0)     # delete row at index 2 (third row) || axis=0 specifies ROW
''' MATLAB
A(2,:) = []
B(3,:) = []
'''
# ----------------------------------------------------------------------------
# 1.7 -> Concatene a matriz linha ��= [−3  −2  −1  0] no topo de A e a matriz coluna
#
#    [20
#     50]
#
# no final da matriz B.
# ----------------------------------------------------------------------------
row_vector = np.array([-3, -2, -1, 0])
A = np.vstack((row_vector, A))      # vstack() stacks rows vertically (rows)

col_vector = np.array([[20], [50]])   # column vector
B = np.vstack((B, col_vector.T))    # vstack and transpose (T) the column vector

# Display the results (optional)
print("Matrix A:\n", A)
print("Matrix B:\n", B)
print("Matrix Cp:\n", Cp)
print("E1 (C + D):\n", E1)
print("E2 (C - D):\n", E2)
print("E3 (C @ D.T):\n", E3)
print("E4 (C * D):\n", E4)
print("E5 (C / D):\n", E5)
print("E6 (C / D):\n", E6)
