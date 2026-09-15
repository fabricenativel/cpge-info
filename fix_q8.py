with open("docs/annales/CCMP2025/CCMP2025.py", "r") as f:
    content = f.read()

q8_code = """# --8<-- [start:Q8]
def construitLi(obj):
    Lqi = []
    Li = []
    for i in range(len(obj)):
        Lqi.append(.........)
        Li.append(i)
    for i in range(1, len(Lqi)):
        x = Lqi[i]
        # In order to sync Li with Lqi, we must swap the same indices in Li
        y = Li[i]
        j = i
        while j > 0 and Lqi[j-1] < x:
            Lqi[j] = Lqi[j-1]
            Li[j] = Li[j-1]
            j = j - 1
        Lqi[j] = x
        Li[j] = y
    return Li
# --8<-- [end:Q8]"""

# I am replacing the empty Q8 block in CCMP2025.py
import re
new_content = re.sub(r'# --8<-- \[start:Q8\]\n\n# --8<-- \[end:Q8\]', q8_code, content)

with open("docs/annales/CCMP2025/CCMP2025.py", "w") as f:
    f.write(new_content)
