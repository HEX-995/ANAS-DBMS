d={"b":3,"a":1,"c":2}
print(dict(sorted(d.items())))
print(dict(sorted(d.items(),key=lambda x:x[1])))