def solution(dartResult):
    answer = 0
    
    stack = []
    bonus = {'S':1, 'D':2, 'T':3}
    option = {'*':2, '#':-1}
    
    dartResult=dartResult.replace('10','A')
    for da in dartResult:
        if da.isnumeric() or da=='A':
            stack.append(10 if da=='A' else int(da))
        elif da in 'SDT':
            stack.append(pow(int(stack.pop()),bonus[da]))
        elif da =='*':
            #stack을 다 pop시켜서 *option[da]
            tmp=stack.pop()
            if len(stack)>0:
                stack.append(stack.pop()*option[da])
            stack.append(tmp*option[da])
        elif da == '#':
            stack.append(stack.pop()*option[da])

    while len(stack)!=0:
        answer += stack.pop()
        
    return answer 