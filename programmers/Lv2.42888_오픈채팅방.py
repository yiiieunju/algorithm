def solution(record):
    answer = []
    dict = {rec.split()[1]:rec.split()[2] for rec in record if rec.split()[0]!="Leave"}
    
    for rec in record:
        if rec.split()[0] =="Enter":
            answer.append(dict[rec.split()[1]]+"님이 들어왔습니다.")
        elif rec.split()[0] =="Leave":
            answer.append(dict[rec.split()[1]]+"님이 나갔습니다.")
    return answer

def main():
    reocord = ["Enter uid1234 Muzi", "Enter uid4567 Prodo","Leave uid1234","Enter uid1234 Prodo","Change uid4567 Ryan"]
    print(solution(reocord))

    
if __name__=="__main__":
    main()
    