
''' Numerical python'''

# Row vector
import numpy as np

r_vector = np.array([1,3,4,5,6,7,9])

print(r_vector)
print(type(r_vector))
print(r_vector.shape) # Number of dimensions or Length of the vector or number of columns
print(r_vector.size)    # Number of elements inside the array.

print(r_vector[3])      # accessing the 4th element of the vector.

# Column vector

c_v = np.array([[1],[2],[11],[23],[12]])
print(c_v)
print(type(c_v))
print(c_v.shape)
print(c_v.size)

print(c_v[3])

# arange function can be used to create vector by specifying start , end and then step.
One2tenVector =  np.arange(1,11)
print(One2tenVector)

oddVector = np.arange(1,11,2)
print(oddVector)

# linspace funtions is used to generate linearly spaced vectors in a given range
x = np.linspace(1,100,100)
print(x)
print(x.shape)
print(x.size)

# Matrices ( 2d arrays)
N = np.array([[1,2,3],[4,5,6],[7,8,9,]])
print(N)
print(type(N))
print(N.shape)
print(N.size)
print(N[1][1])

# Generating matrices ( np.ones(), np.zeroes(), np.eye(), np.random.rand(), np.random.randint() )

print(np.ones(5,dtype=int))

print(np.ones((3,3)))

print(np.zeros(5))

print(np.zeros((5,5),dtype=int))

print(np.eye(3,dtype=int))

print(np.eye((5),dtype=int))

print(np.random.rand(3))  # Random numbers from uniform distribution over [0,1]

print(np.random.rand(3,2))

print(np.random.randn(3))  # Random numbers from a standard normal distribution
print(np.random.randn(3,2))

print(np.random.randint(1,100))
print(np.random.randint(1,100,10))

# Reviving elements from matrices

P = np.array([[1,2,3,4],[5,6,7,8],[9,10,11,12],[13,14,15,16]])

print(P)
print(P.shape)

print(P[2][3])  # This same action can be done with P[2,3]

print(P[2,:])
print(P[:,3])

