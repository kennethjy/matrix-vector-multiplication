import numpy
c_output = []
count = 0
while True:
    line = input()
    c_output.append(line)
    if line[-1] == ']':
        count += 1
        if count == 3:
            break


matrix_and_vectors = []
temp_list = []
for i in c_output:
    if i == '[':
        matrix_and_vectors.append(temp_list)
        temp_list = []
    else:
        to_append = i.split(',')
        for j in range(len(to_append) - 1):
            to_append[j] = int(to_append[j].strip('] '))
        to_append.pop()
        temp_list.append(to_append)
matrix_and_vectors.append(temp_list)
del matrix_and_vectors[0]
matrix = numpy.matrix(matrix_and_vectors[0])
vector = numpy.matrix(matrix_and_vectors[1])
product = numpy.matrix(matrix_and_vectors[2])
print("Product from numpy: ")
print(matrix * vector)
print("\nProduct from C code:")
print(product)
if product.all() == (matrix * vector).all():
    print("\nC code works")
else:
    print("\n C code outputs incorrect value(s)")



