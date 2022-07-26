
lines=[]

def init():  
    input_lines=["2016-09-15 00:00:00.000 3s"]
    
    global lines
    lines = list(input_lines)
    

def throughput(data, time):
    cnt = 0
    start = time
    end = time + 1000
    
    # 각 limit마다 진행중인 경우
    # =>시작시간이 end보다 작고, 끝나는 시간이 start보다 크다
    for d in data:
        if  d[0]<end and d[1]>=start:
            cnt+=1
    return cnt

def solution(lines):
    answer = 0
    data=[]
    
    #mec단위로 변환
    for line in lines:
        date, s, t = line.split() # 날짜, 완료시간, 처리시간
        s =  s.split(':')
        t = t.split('s')[0]
        
        #시작시간, 완료시간을 msec단위로 저장
        end_time = (int(s[0])*60*60+ int(s[1])*60 + float(s[2])) * 1000
        start_time = end_time - float(t)*1000 + 1
        
        data.append([start_time, end_time])
    # 모든 log데이터를 검사해서
    # 초마다 시작시간, 완료시간이 걸쳐져있는 지    
    for d in data:
        answer = max(answer, throughput(data, d[0]),throughput(data, d[1]))
          
    return answer    

if __name__=="__main__":
    init()
    ans = solution(lines)
    print(ans)
    
    '''
    이 때, 주의해야 할 점은 조건이 end_time[i] <= start_time[j] - 1000이 아닌,
    end_time[i] < start_time[j] - 1000라는 것이다.
    처리시간은 시작시간과 끝 시간을 모두 포함하기 때문에,
    끝시간에서 생각한다면 999 밀리초 이내에 같은 작업이 끝남과 동시에 시작된다면 초당 처리시간이 증가하게 되는것이다.
    따라서 start_time[j] - 1000이라면 end_time[i]보다 작아야 초당 처리시간이 증가하게 된다.
    '''