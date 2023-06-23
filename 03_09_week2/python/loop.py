for i in range(1, 101):
    if i%20 == 0 or i%30 == 0:
        print(i,end=" ")

print()
count = 1
while(count <= 100):
    if(count % 20 == 0 or count % 30 == 0):
        print(count,end=" ")
    count += 1