from PIL import Image



def pixellise(img, n):
    nbcol = img.width
    nblig = img.height
    for col in range(0,nbcol-n,n):
        for lig in range(0,nblig-n,n):
            r,v,b = 0,0,0
            for dl in range(n):
                for dc in range(n):
                    dr, dv, db = img.getpixel((col+dl,lig+dl))
                    r += dr
                    v += dv
                    b += db
            r = r//(n*n)
            v = v//(n*n)
            b = b//(n*n)
            for dl in range(n):
                for dc in range(n):
                    img.putpixel((col+dc,lig+dl),(r,v,b))
    img.save("pixellise.jpg")
    img.show()

animal = Image.open("Mont_Fuji.jpg")
n = 4
pixellise(animal, n)    