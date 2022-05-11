import heapq
def solution(jobs):
    answer, now, i, start = 0,0,0,-1
    heap = []
    num = len(jobs)
    while i < num:
        for j in jobs:
            if start < j[0] <= now:
                heapq.heappush(heap, [j[1], j[0]])
        if heap:
            cur = heapq.heappop(heap)
            start = now
            now += cur[0]
            answer += now - cur[1]
            i += 1
        else:
            now += 1
    return answer // num

jobs = [[0, 3], [2, 6], [1, 9]] #9
print(solution(jobs))