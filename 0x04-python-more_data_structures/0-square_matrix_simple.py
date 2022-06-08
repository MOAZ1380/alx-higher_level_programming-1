#!/usr/bin/python3

"""
    /** square_matrix_simple - computes the square value of integers in matrix
      * @matrix: 2 dimensional matrix
      *
      * Return: matrix
      */
"""


def square_matrix_simple(matrix=[]):
    return list(map(lambda m: [(m[0])**2, (m[1])**2, (m[2])**2], matrix))
