array = [0,2,0,4,0,3,4,5,0]

def nu (array):
    for i in range(array.count(0)):
        a = array.index(0)
        print(a)
        array.pop(a)
        array.append(0)  
    print(array)

nu(array)
