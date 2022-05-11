from datetime import datetime, timedelta
def solution(lines):
    answer = 0
    start_time = []
    end_time = []
    
    for t in lines:
        list = t.split()
        sdt = list[0]+" "+list[1]
        idelta = float(list[2][:-1]) - 0.001
        date_time_obj = ToDatetime(sdt)
        start_time.append(date_time_obj-timedelta(seconds=idelta))
        end_time.append(date_time_obj)
    total_time = start_time + end_time
    for time in total_time:
        count = 0
        for s_time in start_time:
            if time + timedelta(seconds=0.999) >= s_time:
                count += 1
        for e_time in end_time:
            if time > e_time:
                count -= 1
        answer = max(answer,count)
        
    return answer

def ToDatetime(sdatetime):
    dt = sdatetime.split()
    if len(dt[1]) <= len(str("00:00:00")):
        strtime = dt[0] + " " + dt[1] + ".000"
    else:
        strtime = dt[0] + " " + dt[1]
    return datetime.strptime(strtime, '%Y-%m-%d %H:%M:%S.%f')
