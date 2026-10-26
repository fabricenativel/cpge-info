with open("mot_cache.txt") as reader:
    data = reader.read().strip()

freq = {}
for d in data:
    if d in freq:
        freq[d] += 1
    else:
        freq[d] = 1

rares = [c for c in freq if freq[c]<10]

print(rares)
