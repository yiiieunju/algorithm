def find_unique_products(N):
    unique_products = []
    for num in range(2, N + 1):
        found = False
        for i in range(2, int(num**0.5) + 1):
            if num % i == 0:    
                factor1 = i
                factor2 = num // i
                if factor1 != factor2:
                    unique_products.append(num)
                    found = True
                    break
        if not found:
            unique_products.append(num)
    return unique_products


arr = find_unique_products(100)
print(arr)
print(len(arr))