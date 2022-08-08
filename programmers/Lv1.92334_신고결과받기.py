def solution(id_list, report, k):
    answer = [0]*len(id_list)
    dic = {x:0 for x in id_list}
    
    for re in set(report):
        dic[re[1]] +=1
    
    for re in set(report):
        if dic[re] >= k:
            answer[id_list.index]+=1
    
    return answer


if __name__ == "__main__":
    id_list = ["muzi", "frodo", "apeach", "neo"]
    report = ["muzi frodo","apeach frodo","frodo neo","muzi neo","apeach muzi"]
    k = 2
    print (solution(id_list, report, k))
