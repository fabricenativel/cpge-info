def maximum(entiers):
    max = entiers[0]
    for i in range(len(entiers)):
        if entiers[i]>max:
            max = entiers[i]
    return entiers


def maximum_recursif(entiers):
    if len(entiers)==1:
        return entiers[0]
    maxi_reste = maximum_recursif(entiers[1:])
    if entiers[0]>maxi_reste:
        return entiers[0]
    else:
        return maxi_reste