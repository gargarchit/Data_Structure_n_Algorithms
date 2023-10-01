# To remove the Duplicates
#Previous version was useful for the duplicates which are in consecutive order 
#only not for the elements in random order for example :2 1 3 1 3 2

#Input the size of array
print("Enter the size of array")
n=int(input())
#input the array of elements
print("Enter the elements of array")
l=list(map(int,input().split()))
p=[i for i in set(l)]
#After removing the duplicates
print(p)
