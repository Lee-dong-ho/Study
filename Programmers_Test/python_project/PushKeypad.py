def solution(numbers, hand):
    answer = ''
    Lloc = (3, 0)
    Rloc = (3, 2)
    
    for num in numbers:
        if num == 0:
            nloc = (3, 1)
        else:
            nloc = ((num - 1) // 3, (num + 2) % 3)
        if num % 3 == 1:
            answer += "L"
            Lloc = nloc
        elif num % 3 == 2 or num == 0:
            if hand == "right":
                if abs(Lloc[0] - nloc[0]) + abs(Lloc[1] - nloc[1]) \
                    >= abs(Rloc[0] - nloc[0]) + abs(Rloc[1] - nloc[1]):
                    answer += "R"
                    Rloc = nloc
                else:
                    answer += "L"
                    Lloc = nloc
            else:
                if abs(Lloc[0] - nloc[0]) + abs(Lloc[1] - nloc[1]) \
                    <= abs(Rloc[0] - nloc[0]) + abs(Rloc[1] - nloc[1]):
                    answer += "L"
                    Lloc = nloc
                else:
                    answer += "R"
                    Rloc = nloc
        else:
            answer += "R"
            Rloc = nloc
    
    return answer
