def solution(record):
    answer = []
    d = dict()
    for str in record:
        _list = str.split()
        if _list[0] == 'Enter':
            d.update({_list[1] : _list[2]})
            answer.append(_list[1]+'님이 들어왔습니다.')
        elif _list[0] == 'Leave':
            answer.append(_list[1]+'님이 나갔습니다.')
        elif _list[0] == 'Change':
            d.update({_list[1] : _list[2]})
    for i in range(len(answer)):
        answer[i] = d[answer[i][:answer[i].find('님이')]] + answer[i][answer[i].find('님이'):]
    return answer
