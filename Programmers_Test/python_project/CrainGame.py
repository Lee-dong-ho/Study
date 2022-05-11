def solution(board, moves):
    answer = 0
    box = [0]
    for m in moves:
        for i in range(len(board)):
            if board[i][m-1] != 0:
                if box[-1] == board[i][m-1]: 
                    del box[-1]
                    answer += 2
                else: box.append(board[i][m-1])
                board[i][m-1] = 0
                print(box)
                break
    return answer

def solution2(board, moves):
    cols = list(map(lambda x: list(filter(lambda y: y > 0, x)), zip(*board)))
    a, s = 0, [0]
    for m in moves:
        if len(cols[m - 1]) > 0:
            if (d := cols[m - 1].pop(0)) == (l := s.pop()):
                a += 2
            else:
                s.extend([l, d])

    return a

board = [[0,0,0,0,0],[0,0,1,0,3],[0,2,5,0,1],[4,2,4,4,2],[3,5,1,3,1]]
moves = [1,5,3,5,1,2,1,4]
print(solution2(board, moves)) # 4 3 1 1 3 2 4