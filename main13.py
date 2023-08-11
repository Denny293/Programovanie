
def change(u_list, i_list):
    for key, value in u_list.items():
        i_list[value] = key

u_list = {
    "Tom": 1,
    1: "Tom",
    "+383826583": "Token"
}

i_list = {
    
}

change(u_list, i_list)

print(u_list)
print(i_list)

