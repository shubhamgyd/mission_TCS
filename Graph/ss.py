def calculate_xor_sum(A):
    count = [0] * 3  # Initialize count array

    # Count the occurrences of each remainder
    for num in A:
        count[num % 3] += 1

    xor_sum = 0

    # Compute the sum of A[i] xor A[j] for all pairs satisfying A[i]%3 == A[j]%3
    for i in range(3):
        for j in range(i, 3):
            if (i + j) % 3 == 0:  # Pair with remainder 0
                xor_sum += count[i] * (count[j] - (i == j))

    return xor_sum


A = [1, 10, 13]
print(calculate_xor_sum(A))
