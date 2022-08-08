
#if를 여러줄 쓰면 바로 걸려서 return 돼버린다.
#if의 모든 조건을 만족하는지 확인하려면 flag를 써야한다.
def solution(s):
    answer = False
    if (len(s)==4 or len(s)==6) and s.isdigit() == True:
        return True
    return answer