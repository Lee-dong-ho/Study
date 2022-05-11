import re
def solution(s):
    d = {"0": "zero", "1": "one", "2": "two", "3": "three", "4": "four", 
         "5": "five", "6": "six", "7": "seven", "8": "eight", "9": "nine"}
    for k,v in d.items():
        s = re.sub(v, k, s)

    return int(s)

s = "one4seveneight"
print(solution(s))