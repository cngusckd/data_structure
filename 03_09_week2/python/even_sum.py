def even_sum(start, end):
    sum = 0
    for i in range(start,end+1):
        if(i%2 == 0):
            sum += i
    return sum

start = 0
end = 10
sum = even_sum(start,end)
print(f"{start}와 {end} 사이의 짝수의 합 : {sum}")
print("%d와 %d 사이의 짝수의 합 = %d" %(start, end, even_sum(start,end)))