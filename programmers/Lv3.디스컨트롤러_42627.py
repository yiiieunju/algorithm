import heapq
def solution(jobs):
    answer, now, i = 0,0,0
    start = -1
    heap = []
    
    while i< len(jobs):
        for j in jobs:
            if start < j[0] <=now:
                heapq.heapqpush(heap, [j[1],j[0]])
            if len(heap) >0:
                current = heapq.heappop(heap)
                start = now
                now += current
                answer += (now - current[1])
                i+=1
            else:
                now+=1
    return int(answer/len(jobs))