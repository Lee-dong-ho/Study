def solution(id_list, report, k):
    answer = []
    al = []
    d = dict()
    b = dict()
    for il in id_list:
        d[il] = ""
        b[il] = 0
    for r in report:
        rl = r.split()
        tl = []
        if not "" in d[rl[0]]:
            if rl[1] in d[rl[0]]: continue
            tl = d[rl[0]]
        tl.append(rl[1])
        d[rl[0]] = tl
        b[rl[1]] += 1
    for key,v in b.items():
        if v >= k: al.append(key)
    for key,v in d.items():
        num = 0
        for rep in al:
            if rep in v: num += 1
        answer.append(num)
    
    return answer

def solution2(id_list, report, k):
    answer = [0] * len(id_list)
    reports = {x : 0 for x in id_list}
    for r in set(report):
        reports[r.split()[1]] += 1
    for r in set(report):
        if reports[r.split()[1]] >= k:
            answer[id_list.index(r.split()[0])] += 1    
    return answer

idl = ["muzi", "frodo", "apeach", "neo"]
reportl = ["muzi frodo","apeach frodo","frodo neo","muzi neo","apeach muzi"]
idl2 = ["con", "lion"]
reportl2 = ["lion con", "lion con", "lion con", "lion con"]
print(solution(idl, reportl, 2))
#print(solution(idl2, reportl2, 3))
print(solution2(idl, reportl, 2))