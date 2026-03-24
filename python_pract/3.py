tup=(1,2,2,3,3)
new_tup=()
for a in tup:
    if a not in new_tup:
        new_tup=new_tup+(a,)
print(new_tup)
