#1단계 new_id의 모든 대문자를 대응되는 소문자로 치환합니다.
#2단계 new_id에서 알파벳 소문자, 숫자, 빼기(-), 밑줄(_), 마침표(.)를 제외한 모든 문자를 제거합니다.
#3단계 new_id에서 마침표(.)가 2번 이상 연속된 부분을 하나의 마침표(.)로 치환합니다.
#4단계 new_id에서 마침표(.)가 처음이나 끝에 위치한다면 제거합니다.
#5단계 new_id가 빈 문자열이라면, new_id에 "a"를 대입합니다.
#6단계 new_id의 길이가 16자 이상이면, new_id의 첫 15개의 문자를 제외한 나머지 문자들을 모두 제거합니다.
#     만약 제거 후 마침표(.)가 new_id의 끝에 위치한다면 끝에 위치한 마침표(.) 문자를 제거합니다.
#7단계 new_id의 길이가 2자 이하라면, new_id의 마지막 문자를 new_id의 길이가 3이 될 때까지 반복해서 끝에 붙입니다.
def solution(new_id):
    answer = ''
    possible_word = ['-','_','.']
    new_id = new_id.lower()
    print("1단계 : ", new_id) # 1단계
    for c in new_id:
        if  c.isalnum(): continue
        if  c in possible_word: continue
        new_id = new_id.replace(c,"")
    print("2단계 : ", new_id) # 2단계
    while ".." in new_id: new_id = new_id.replace("..", ".")
    print("3단계 : ", new_id) # 3단계
    new_id = new_id.strip(".")
    print("4단계 : ", new_id) # 4단계
    if not new_id: new_id = "a"
    print("5단계 : ", new_id) # 5단계
    if len(new_id) > 15:
        new_id = new_id[:15]
        new_id = new_id.rstrip(".")
    print("6단계 : ", new_id) # 6단계
    while len(new_id) < 3: new_id += new_id[-1]
    print("7단계 : ", new_id) # 7단계
    return answer

import re
def solution2(new_id):
    st = new_id
    st = st.lower()
    st = re.sub('[^a-z0-9\-_.]', '', st)
    st = re.sub('\.+', '.', st)
    st = re.sub('^[.]|[.]$', '', st)
    st = 'a' if len(st) == 0 else st[:15]
    st = re.sub('^[.]|[.]$', '', st)
    st = st if len(st) > 2 else st + "".join([st[-1] for i in range(3-len(st))])
    return st

new_id = "...!@BaT#*..y.abcdefghijklm"
new_id2 = ""
print(solution(new_id))