def solution(s):
    answer = len(s)
    # len(s)//2 까지는 len(s)==16일 때 n이 1~7(8-1)까지만 가능하다는 것
    # 길이가 16이므로 절반인 8개까지 가능해야하므로 1을 더해줌
    for n in range(1,len(s)//2+1):
        tmp = ""
        cnt=1
        pattern = s[:n]
        for i in range(n, len(s) , n):
            if pattern == s[i:i+n]:
                cnt+=1
            else:
                if cnt > 1:
                    tmp+=str(cnt)
                tmp +=pattern
                pattern = s[i:i+n]
                cnt=1
        if cnt > 1:
            tmp += str(cnt)
        tmp+=pattern
        print(n,tmp)
        answer = min(answer, len(tmp))
    return answer

def main():
    s1 = "aabbaccc"
    s2 = "ababcdcdababcdcd"
    s = "abcabcdede"
    s = "aabbabcabcabcabcdedededededeaccc"
    s = "xababcdcdababcdcd"
    print(solution(s2))

if __name__=="__main__":
    main()