with open("dates.txt") as reader:
    datestrings = reader.read().strip().split('\n')


nb_jours = {1: 31, 2: 28, 3: 31, 4: 30, 5: 31, 6: 30,
            7: 31, 8: 31, 9: 30, 10: 31, 11: 30, 12: 31}


def is_bissextile(a):
    return (a % 4 == 0 and a % 100 != 0) or a % 1000 == 0


def make_date(dstring):
    j, m, a = tuple(map(int, dstring.split('/')))
    return j, m, a


def is_valid(j, m, a):
    if m > 12:
        return False
    if is_bissextile(a) and m == 2:
        return j <= 29
    else:
        return j <= nb_jours[m]


bad = 0
for d in datestrings:
    if not is_valid(*make_date(d)):
        bad = bad + 1

print(f"il y a {bad} dates non valides")
