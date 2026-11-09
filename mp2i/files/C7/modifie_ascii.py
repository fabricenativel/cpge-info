with open("ex_ascii.txt") as f:
    contenu = f.read()

new = ""
for c in contenu:
    if c=='\t':
        new+='    '
    else:
        new+=c

w = open("new_ascii.txt","w")
w.write(new)
w.close()
