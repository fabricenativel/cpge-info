from random import sample

files = {"EN":"phrase_olivertwist.txt","FR":"phrase_miserables_raw.txt","DE":"phrase_faust_raw.txt"}

nb = 1100
for l in files:
    with open(files[l]) as reader:
        sentences = reader.read().lower().split('\n')
        sentences = sample(sentences, nb)
    with open(f"phrases_{l}.txt","w") as writer:
        writer.write('\n'.join(sentences))
    
