def solution(clothes):
    answer = 1
    dict = {}

    for item, category in clothes:
        if category in dict:
            dict[category].append(item)
        else:
            dict[category] = [item]

    for data in dict.values():
        answer *= (len(data) + 1)

    return answer - 1
