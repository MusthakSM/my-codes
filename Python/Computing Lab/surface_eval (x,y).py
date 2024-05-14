import math

# The surface of a 3D object is given by the equation (1),  z = sin(x)^2 × cos(y)

def surface_eval(x,y):
    z = (math.sin(x) ** 2) * math.cos(y)
    return z

f = open('C:\\Users\\MUSTHAK\\Desktop\\VSCode\\Computing Lab\\Dataset 1.txt','r')

ans_list = []
for line in f.readlines():
    [x , y] = line.split(',')

    z = surface_eval(float(x),float(y))
    ans_list.append(z)

    print("x: {a:.4f}  y: {b:.4f}  z:{c:.4f}".format(a = float(x), b= float(y), c = z))
f.close()

result_file = open('C:\\Users\\MUSTHAK\\Desktop\\VSCode\\Computing Lab\\ans.txt','a')
for result in ans_list:
    result_file.write(str(result)+"\n")


result_file.close()