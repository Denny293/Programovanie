array = [1,2,5,34,6]

def mult (array):
    j = array[0]
    k = array[0]
    for i in array:
        if i > j:
            j = i
            
    h = array.index(j)
    array[h] = 0
    
    for i in array:
        if i > k:
            k = i
            
    array[h] = j
   
    return j * k
    
print(mult(array))  