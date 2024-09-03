import csv

HEADER = "num;enonce;reponseA;reponseB;reponseC;reponseD;bonne_reponse;chapitre;image\n"

with open("qcm.csv","r",encoding="utf-8") as f:
        questions = list(csv.DictReader(f,delimiter=";"))



for q in questions:  
    print(q['enonce'])
    nc = int(input("Numéro de chapitre ?"))
    q['chapitre']=nc
    
with open("qcm2.csv", 'w',encoding='utf-8') as fic_qcm:
    fic_qcm.write(HEADER)
    writer = csv.writer(fic_qcm,delimiter=";",quotechar='"')
    for q in questions:
        fields=[q[t] for t in q]
        writer.writerow(fields)
# with open("qcm2.csv","w",encoding="utf-8") as f:
#     f.write(HEADER)
#     for q in questions:
#         tow = ";".join([str(q[k]) for k in q])
#         f.write(tow+"\n")
