import huffman
import collections


with open("notredame_ascii.txt") as reader:
    content = reader.read()

res = huffman.codebook(collections.Counter(content).items())
for c in range(0,128) :
    if chr(c) in res: print(f"{c}->{chr(c)} : {res[chr(c)]}")
tc = sum([len(res[c]) for c in content])
print(f"Taux de compression = {tc/(len(content)*8)}")
