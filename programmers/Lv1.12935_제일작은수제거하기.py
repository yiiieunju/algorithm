def solution(arr):
    answer = []
    min_index = arr.index(min(arr))
    
    if len(arr)>1:
        del arr[min_index]
        answer = arr
    else:
        answer.append(-1)
    return answer