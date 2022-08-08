def solution1(arr):
    answer = [arr[0]]
    
    same = False
    prev = arr[0]
    for index, value in enumerate(arr):
        if index==0:
            continue
        if prev!=value:
            answer.append(value)
        prev = value
    
    return answer

def solution2(arr):
    
    stack = []
    
    for ar in arr:
        if len(stack) ==0:
            stack.append(ar)
        if stack[-1] != ar:
            stack.append(ar)

    return stack

def solution3(arr):
    
    stack = [arr[0]]
    
    for ar in arr:
        if stack[-1] != ar:
            stack.append(ar)
            
    return stack