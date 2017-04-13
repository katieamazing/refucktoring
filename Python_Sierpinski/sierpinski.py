## source: https://rosettacode.org/wiki/Sierpinski_triangle#Python

def sierpinski(n):
    d = ["*"]
    for i in range(n):
        sp = " " * (2 ** i)
        d = [sp+x+sp for x in d] + [x+" "+x for x in d]
    return d
