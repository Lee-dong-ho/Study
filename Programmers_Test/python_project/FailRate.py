def solution(N, stages):
    d = {x+1: 0 for x in range(N)}
    totalnum = [0, len(stages)]
    for s in stages:
        if s == N+1: continue
        d[s] += 1
    for i in range(1, N+1):
        if totalnum[i] > 0:
            totalnum.append(totalnum[i] - d[i])
            d[i] = d[i] / totalnum[i]            
        else:
            totalnum.append(totalnum[i])
            d[i] = 0
    return sorted(d, key = lambda x: d[x], reverse=True)

def solution2(N, stages):
    d = {x+1: 0 for x in range(N)}
    totalnum = len(stages)
    for i in range(1, N+1):
        if totalnum != 0:
            count = stages.count(i)
            d[i] = count / totalnum
            totalnum -= count
        else: d[i] = 0
    return sorted(d, key = lambda x: d[x], reverse=True)

stages = [2, 1, 2, 6, 2, 4, 3, 3] # 3 4 2 1 5
stages1 = [4, 4, 4, 4, 4] # 4,1,2,3
print(solution(5,stages))
print(solution(4,stages1))