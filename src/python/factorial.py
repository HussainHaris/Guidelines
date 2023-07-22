import time

def factorial(n):
    factorial = 1
    for i in range(1, n+1):
        factorial *= i
    return factorial

if __name__ == "__main__":
    print(factorial(5))
