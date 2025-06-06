#!/bin/python3
import pikepdf
from colorama import Fore
import getpass
import os

PATH = "/home/fenarius/Travail/Cours/cpge-info/docs/mp2i/Cours/"
START = 10
END = 20


print(Fore.YELLOW+f"Protection des fichiers de cours MP2I de C{START} à C{END}")
password = getpass.getpass("Entrer le mot de passe : ")

for i in range(START, END+1):
    pdfname = f"{PATH}C{i}/C{i}-cours.pdf"
    if (os.path.isfile(pdfname)):
        try:
            pdf = pikepdf.Pdf.open(pdfname,allow_overwriting_input=True)    
            pdf.save(pdfname, encryption=pikepdf.Encryption(owner=password, user=password, R=6)) 
            pdf.close()
            print(Fore.RED+f"Protection ok sur C{i}")
        except:
            print(Fore.GREEN+f"Protection déjà active sur C{i}")
    else:
        print(Fore.WHITE+f"Le fichier C{i} n'existe pas !")
    


