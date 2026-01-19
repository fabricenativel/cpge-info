DEAD = '.'
ALIVE = '#'

def evolution(config):
    n = len(config)
    nconfig = config[0]
    for i in range(1,n-1):
        if (config[i+1]==config[i-1]):
            nconfig += DEAD
        else:
            nconfig += ALIVE
    nconfig += config[-1]
    return nconfig

n = 30
c = "."*(n//2)+"#"+"."*(n//2-1)
s = 0
seen = set()
seen.add(c)
step = 0
end = False
while (not end):
    step += 1
    c = evolution(c)
    if c not in seen:
        seen.add(c)
    else:
        end = True
print(c)
print(step)