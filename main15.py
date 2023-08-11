dict1 = {
    "d":1,
    "f":2 
}
dict2 = {
    "f":5,
    "a":4 
}
dict01 = {
    
}
dicts = [dict1, dict2]

def combine(dicts, dict01):
    for i in dicts:
        for key, value in i.items():
            dict01[key] = value
        
combine(dicts, dict01)

print(dict01)
    
