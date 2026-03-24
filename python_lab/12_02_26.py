# # strings
# a='hello'
# print(a[1],a[-4])

# # slicing
# # s[start : end]
# message="welcome to python class"
# print(message[2:5])
# print(message[-10:-2])
# print(message[:5])
# print(message[2:])
# print(message)

# # slice with steps
# str='ABCDEFGHI'
# print(str[2:7:2])
# print(str[6:1:-2])

# #string operators
# # +,*,[],[:],in,not in

# hello='hello'
# world=' world'
# c=hello+world
# # check for l in hello
# if 'l' in hello:
#     print("yes,yes,ye.....s")

# # join method
# # string.join(iterable)
# list=['red','green','blue']
# print(','.join(list))

l=[1,2,3]
print(','.join(str(i) for i in l))
dict={'name':'bob','city':'delhi'}
print(','.join(dict))
print(','.join(dict.values()))