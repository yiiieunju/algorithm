def find_money(parents, money, i, answer):
    if parents[i] == i or money//10 == 0:
        answer[i]+=money
        return
    
    pay = money // 10
    mine = money - pay
    answer[i] +=mine
    find_money(parents, pay, parents[i], answer)
            
def solution(enroll, referral, seller, amount):
    n = len(enroll)
    answer = [0]*(n+1)
    dic = {enroll[i] : i+1 for i in range(n)} # 자신의 번호를 저장
    parents = [i for i in range(n+1)]   # 자신을 부모로 초기화 , 누가 자신의 부모인지 저장할 예정, 0번은 민호
    
    for i in range(n):
        if referral[i] ==  "-": # 부모가 민호
            parents[i+1] = 0
        else:
            parents[i+1] = dic[referral[i]] #refferral의 부모는 enroll에 들어있음
 

    #벌어온 돈 정산하기
    for i in range(len(seller)):
        find_money(parents, amount[i]*100, dic[seller[i]], answer)

    return answer[1:]


def main():
    
    enroll = ["john", "mary", "edward", "sam", "emily", "jaimie", "tod", "young"]
    referral = ["-", "-", "mary", "edward", "mary", "mary", "jaimie", "edward"]
    seller = ["young", "john", "tod", "emily", "mary"]
    amount = [12, 4, 2, 5, 10]
    
    ans = solution(enroll, referral, seller, amount)
    print(ans)
    
if __name__ =="__main__":
    main()