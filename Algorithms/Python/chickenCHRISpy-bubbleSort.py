a = []
num = int(input("Please Enter the Total num of Elements : "))
for i in range(num):
    value = int(input("Please enter the %d Element of List1 : " %i))
    a.append(value)
#algo for bubble_sort()
for i in range(num -1):
    for j in range(num - i - 1):
        if(a[j] > a[j + 1]):
             temp = a[j]
             a[j] = a[j + 1]
             a[j + 1] = temp

print("The Sorted List in Ascending Order : ", a)
print("The Sorted List in Descending Order : ", a[::-1])
