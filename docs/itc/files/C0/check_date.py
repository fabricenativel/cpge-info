def check_date(date):
    ldate = date.split("/")
    if len(ldate)!=3: 
        return False
    jour,mois =  int(ldate[0]),int(ldate[1])
    if jour<1 or jour>31 or mois<1 or mois>12:
        return False
    return True