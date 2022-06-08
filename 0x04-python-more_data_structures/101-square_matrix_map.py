#!/usr/bin/python3
def square_matrix_map(matrix=[]):
    return list(map(lambda m: [(m[0])**2, (m[1])**2, (m[2])**2], matrix))
