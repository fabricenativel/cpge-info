from math import pi, cos, sin

# --8<-- [start:Q3]
def binarisation(imgG:array, seuil:int) -> array:
    n0, n1, _ = dimension(img)
    img_nb = initialise(n0, n1, 0)
    for i in range(n0):
        for j in range(n1):
            if imgG[i][j]>seuil:
                img_nb[i][j] = 255
    return img_nb
# --8<-- [end:Q3]

# --8<-- [start:Q4]
def bilineaire(im : array, x:float, y: float) -> int :
    x0 = int(x)
    x1 = xo + 1
    y0 = int(y)
    y1 = y0 + 1
    a = lineaire(y, y0, y1, im[x0][y0], im[x0][y1])
    b = lineaire(y, y0, y1, im[x1][y0], im[x1][y1])
    c = lineaire(x, x0, x1, a, b)
    return int(c)
# --8<-- [end:Q4]

# --8<-- [start:Q4]
def rotation(im:array, angle:float) -> array :
    p, q, _ = dimension(im)
    angr = -ang *pi / 180
    matR = [[cos(angr), -sin()]]