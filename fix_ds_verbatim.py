with open("docs/mp2i/Evaluations/DS/DS1/DS1.tex", "r") as f:
    content = f.read()

content = content.replace("\\tcor{\n\\begin{langageC}", "\\ifcorrige\n\\begin{langageC}")
content = content.replace("\\end{langageC}\n\t}", "\\end{langageC}\n\\fi")

with open("docs/mp2i/Evaluations/DS/DS1/DS1.tex", "w") as f:
    f.write(content)
