def add(a,b):
    return a+b
def subtract(a,b):
    return a-b
def multiply(a,b):
    return a*b
def divide(a,b):
    if(B != 0):
        return a/b
    else:
        print("0으로 수를 나눌 수 없습니다.")
        return None

while(True):
    print("1.add    2.subtract  3.multiply  4.divide ( exit : -1 ) : ",end=" ")
    user_order = int(input())
    if(user_order == -1):break
    print("두 수를 입력해주세요", end=" ")
    A, B = input().split()
    A, B = int(A), int(B)
    if(user_order == 1):print(add(A,B))
    elif(user_order == 2):print(subtract(A,B))
    elif(user_order == 3):print(multiply(A,B))
    elif(user_order == 4):print(divide(A,B))
    else:continue

print("파이썬 / 201812671 / 추현창")