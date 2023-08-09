test =int(input("Number: "))
a = 0
for i in range(1,test):
    i = int(i)
    if i != test and i != 1:
        if test % i == 0:
            a = 1
            break

            
            
if a == 1:
    print("nope")
else:
    print("yup")
        
