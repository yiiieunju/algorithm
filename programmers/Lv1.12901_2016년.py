def solution(a, b):
    answer = ''
    
    days = ['THU','FRI','SAT','SUN','MON','TUE','WED']
    mon = [31,29,31,30,31,30,31,31,30,31,30,31]
    
    day = 0
    # 5월 12일은 4월까지 더하고 12일을 더해야한다.
    for i in range(0,a-1):
        day+=mon[i]
    day += b
    
    answer = days[day%7]
    return answer