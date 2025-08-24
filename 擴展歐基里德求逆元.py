def main(): #引用
    from sys import stdin,stdout
    read=stdin.readline
    write=stdout.write

    x,y,d=0,0,0
    def exgcd(a, b):
        nonlocal x,y,d
        if b == 0:
            d = a
            x = 1
            y = 0
            return a
        d = exgcd(b, a % b)
        x, y = y, x - (a//b) * y 
        return d

    def inv(a,P):
        nonlocal x,y,d
        d,x,y=exgcd(a,P)
        return x%P if d==1 else -1

    n,P=map(int,read().split())
    write(' '.join(map(str,map(lambda x: inv(x,P),map(int, read().split())))))
main()

"""
#傳參
def main():
    from sys import stdin,stdout
    read=stdin.readline
    write=stdout.write
    
    def exgcd(a, b):
        if b == 0:
            return a, 1, 0
        d, x1, y1 = exgcd(b, a % b)
        x = y1
        y = x1 - (a // b) * y1
        return d, x, y

    def inv(a):
        d,x,y=exgcd(a,P)
        return x%P if d==1 else -1

    n,P=map(int,read().split())
    write(' '.join(map(str,map(inv,map(int, read().split())))))
main()

"""
