array = []
for i in range(10):
    array.append(i+1)
print("List : ",array)

for i in array:
    if i%2 == 0:
        array.remove(i)
print("짝수 값을 뺀 List : ",array)

for i in range(len(array)):
    array[i] = array[i] * 10
print("10을 곱한 List : ",array)
