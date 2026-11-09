from PIL import Image

animal = Image.open("img.jpg")
print(f"{animal.width}x{animal.height}")
l = animal.width
h = animal.height
print(f"Dernier pixel : {animal.getpixel((l-1,h-1))}")
for i in range(0,3):
    for j in range(l-1):
        animal.putpixel((i,j),(127,127,127))
for i in range(h-3,h):
    for j in range(l):
        animal.putpixel((i,j),(127,127,127))

animal.show()
