x = input("Words: ").split(" ")

print(x)

dictionary = {
    
}

for i in x:
    dictionary[i] = 0
    
for i in x:
    if i in dictionary.keys():
        dictionary[i] += 1
       
print(dictionary)