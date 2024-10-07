fruits=['apple','orange','pear','grape']
counts=[10,3,4,5]
for f,c in zip(fruits,counts):
    match f,c:
        case 'apple',10:
            print(f,c)
        case 'orange',3:
            print(f,c)
        case 'pear',4:
            print(f,c)
        case 'grape',5:
            print(f,c)