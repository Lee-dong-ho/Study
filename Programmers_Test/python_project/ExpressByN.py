def solution(N, number):
    dp = []
    
    for i in range(1,9):
        opset = set()
        opset.add(int(str(N)*i))
        for j in range(1,i):
            for op1 in dp[j-1]:
                for op2 in dp[i-j-1]:
                    opset.add(op1 + op2)
                    opset.add(op1 - op2)
                    opset.add(op1 * op2)
                    if op2 != 0:
                        opset.add(op1 / op2)
        dp.append(opset)
        if number in dp[i-1]:
            return i
    return -1
