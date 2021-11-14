def print_three_items(data):

    if len(data) == 0:
        raise ValueError("The argument must have non-zero elements")
    
    if  len(data) != 3:
        raise ValueError("The argument must have three elements")
    
        
    for item in data:
        print(item)

print_three_items([])