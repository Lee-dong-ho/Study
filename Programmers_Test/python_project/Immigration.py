def solution(n, times):
    answer = 0
    left = 1
    right = max(times)*n
    while left <= right:
        p = 0
        mid = (left + right) // 2
        for t in times:
            p += mid // t
            if p >= n:
                break
        if p >= n:
            answer = mid
            right = mid -1
        else:
            left = mid + 1
    return answer
