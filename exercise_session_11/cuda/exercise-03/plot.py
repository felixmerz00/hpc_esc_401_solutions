import numpy as np
import matplotlib.pyplot as plt

# Read data from the file
data = np.genfromtxt("/Users/felixmerz/Documents/Git_Repositories/hpc_esc_401_solutions/exercise_session_11/cuda/exercise-03/runtimes.txt", delimiter=',', skip_header=1)

# Extract NUM_BLOCK, NUM_THREAD, and runtime columns
num_blocks = data[:, 0]
num_threads = data[:, 1]
runtime = data[:, 2]

# Reshape runtime to a 2D array
runtime_matrix = runtime.reshape((len(np.unique(num_blocks)), len(np.unique(num_threads))))

# Create the colormesh plot
plt.pcolormesh(np.unique(num_threads), np.unique(num_blocks), runtime_matrix, cmap='viridis', shading='auto')

# Add colorbar
plt.colorbar(label='Runtime (seconds)')

# Set labels and title
plt.xlabel('Number of Threads')
plt.ylabel('Number of Blocks')
plt.title('2D Colormesh Plot of Runtimes')

# Show the plot
plt.savefig("/Users/felixmerz/Documents/Git_Repositories/hpc_esc_401_solutions/exercise_session_11/cuda/exercise-03/out-fig.png", format="png")
plt.show()
