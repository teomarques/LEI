import numpy as np

a = np.zeros(3)               # is an array of floats
type(a)                      # array
type(a[0])                    # float
print(a)

z = np.shape        
z.shape = (10, 1)            # creates an array of shape 10 by 1
print(z)

z = np.ones(10)              # creates an array of floats
type(z[0])                   # float
print(z)

z = np.empty(3)             # creates an empty array (array of zeros)
print(z)

z = np.linspace(2, 10, 5)   # from 2 to 10, with 5 elements
print(z)

z = np.array([10, 20])      # ndarray from python list
print(z)

a_list = [1, 2, 3, 4, 5, 6, 7]
z = np.array([a_list])
print(z)

np.random.seed(0)
z1 = np.random.randint(10, size=6)  # array of 6 random numbers from 0 to 9
print(z1)