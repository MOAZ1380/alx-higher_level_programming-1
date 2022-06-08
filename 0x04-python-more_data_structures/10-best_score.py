#!/usr/bin/python3

def best_score(a_dictionary):
    key = None
    if a_dictionary:
        for idx, item in a_dictionary.items():
            if item > a_dictionary.get(key, 0):
                key = idx
    return (key)
