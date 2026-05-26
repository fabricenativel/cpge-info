def check_date(date):
    ldate = date.split("/") #date devient une liste
    if len(ldate)!=3: #qui doit avoir 3 éléments
        return False
    jour,mois, annee =  ldate #on décompacte
    if int(jour)<1 or int(jour)>31 or int(mois)<1 or int(mois)>12:
        return False
    return True