array = [0,0,2,4]

def dup (array):
    for i in array:
        if array.count(i) > 1:
            return True
        else:
            return False

print(dup(array))