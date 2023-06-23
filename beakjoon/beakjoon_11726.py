import sys
input = int(sys.stdin.readline())

answer = [1,2]
if(input<=2):
    print(answer[input-1])
else:
    for i in range(input-2):
        last_num = answer[len(answer)-1]+ answer[len(answer)-2]
        answer.append(last_num)
    print(answer[len(answer)-1])