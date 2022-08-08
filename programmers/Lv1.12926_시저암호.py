def solution(s, n):
    answer =''
    for singl in s:
        asci = 0
        if singl ==" ":
            answer+=" "
            continue
        elif singl.islower():
            asci=ord('a') + (ord(singl)+n - ord('a'))%26 
        elif singl.isupper():
            asci= ord('A') + (ord(singl)+n - ord('A'))%26 
        answer+=chr(asci)
    return answer


def solution(s, n):
    answer =''
    s = list(s)
    for i in range(0,len(s)):
        if s[i].islower():
            s[i] = chr(ord('a') + (ord(s[i])-ord('a')+n)%26)
        if s[i].isupper():
            s[i] = chr(ord('A') + (ord(s[i])-ord('A')+n)%26)
    answer = "".join(s)
    return answer