def solution(n, t, m, timetable):
    answer = ''
    
    timetable = [int(time.split(":")[0])*60+int(time.split(":")[1]) for time in timetable]
    timetable = sorted(timetable)
    
    bustime = [9*60+ t * i for i in range(n)]
    
    i=0
    for time in bustime:
        passenger = 0
        while passenger < m and i < len(timetable) and timetable[i]<=time:
            passenger +=1
            i+=1
    if passenger < m:
        answer = time
    else:
        answer = timetable[i-1]-1
            
    return str(answer//60).zfill(2) +":"+ str(answer%60).zfill(2)

def main():
    n = 1
    t = 1
    m = 5
    timetable  = ["08:00", "08:01", "08:02", "08:03"]
    
    n = 2
    t = 10
    m = 2
    timetable  = ["09:10", "09:09", "08:00"]
    
    n = 1
    t = 1
    m = 5
    timetable  = ["00:01", "00:01", "00:01","00:01", "00:01", "00:02", "00:03", "00:04"]
    
    
    # n = 2
    # t = 1
    # m = 2
    # timetable  = ["09:00", "09:00", "09:00", "09:00"]
    
    # n = 1
    # t = 1
    # m = 5
    # timetable  = 	["00:01", "00:01", "00:01", "00:01", "00:01"]
    
    # n = 1
    # t = 1
    # m = 1
    # timetable  = ["23:59"]
    
    # n = 10
    # t = 	60
    # m = 45
    # timetable  = ["23:59","23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59"]
    
    print(solution(n, t, m, timetable))

    

if __name__=="__main__":
    main()