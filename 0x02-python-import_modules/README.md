# Python - import & modules
- The objects of this projects are:
- Why Python programming is awesome
- How to import functions from another file
- How to use imported functions
- How to create a module
- How to use the built-in function `dir()`
- How to prevent code in your script from being executed when imported
- How to use command line arguments with your Python programs

> **0. Import a simple function from a simple file**
[0-add.py](./0-add.py) a program that imports the function `def add(a, b)`

> **1. My first toolbox!**
[1-calculation.py](./1-calculation.py) a program that imports functions from the file [calculator_1.py](./calculator_1.py), does some Maths, and prints the result

> **2. How to make a script dynamic!**
[2-args.py](./2-args.py)a program that prints the number of and the list of its arguments

> **3. Infinite addition**
[3-infinite_add.py](3-infinite_add.py) a program that prints the result of the addition of all arguments

> **4. Who are you?**
a program that prints all the names defined by the compiled module [hidden_4.pyc](./https://github.com/holbertonschool/0x03.py/blob/master/12-switch_py).

> **5. Everything can be imported**
[5-variable_load.py](./5-variable_load.py) a program that imports the variable a from the file `variable_load_5.py` and prints its value.

> **6. Build my own calculator!**
[100-my_calculator.py](./100-my_calculator.py) a program that imports all functions from the file [calculator_1.py](./calculator_1.py) and handles basic operations

> **7. Easy print**
[101-easy_print.py](./101-easy_print.py) a program that prints #pythoniscool, followed by a new line, in the standard output.

> **8. ByteCode -> Python #3**
[102-magic_calculation.py](./102-magic_calculation.py) the Python function def magic_calculation(a, b) that does exactly the same as the following Python bytecode
```
3           0 LOAD_CONST               1 (0)
              3 LOAD_CONST               2 (('add', 'sub'))
              6 IMPORT_NAME              0 (magic_calculation_102)
              9 IMPORT_FROM              1 (add)
             12 STORE_FAST               2 (add)
             15 IMPORT_FROM              2 (sub)
             18 STORE_FAST               3 (sub)
             21 POP_TOP

  4          22 LOAD_FAST                0 (a)
             25 LOAD_FAST                1 (b)
             28 COMPARE_OP               0 (<)
             31 POP_JUMP_IF_FALSE       94

  5          34 LOAD_FAST                2 (add)
             37 LOAD_FAST                0 (a)
             40 LOAD_FAST                1 (b)
             43 CALL_FUNCTION            2 (2 positional, 0 keyword pair)
             46 STORE_FAST               4 (c)

  6          49 SETUP_LOOP              38 (to 90)
             52 LOAD_GLOBAL              3 (range)
             55 LOAD_CONST               3 (4)
             58 LOAD_CONST               4 (6)
             61 CALL_FUNCTION            2 (2 positional, 0 keyword pair)
             64 GET_ITER
        >>   65 FOR_ITER                21 (to 89)
             68 STORE_FAST               5 (i)

  7          71 LOAD_FAST                2 (add)
             74 LOAD_FAST                4 (c)
             77 LOAD_FAST                5 (i)
             80 CALL_FUNCTION            2 (2 positional, 0 keyword pair)
             83 STORE_FAST               4 (c)
             86 JUMP_ABSOLUTE           65
        >>   89 POP_BLOCK

  8     >>   90 LOAD_FAST                4 (c)
             93 RETURN_VALUE

 10     >>   94 LOAD_FAST                3 (sub)
             97 LOAD_FAST                0 (a)
            100 LOAD_FAST                1 (b)
            103 CALL_FUNCTION            2 (2 positional, 0 keyword pair)
            106 RETURN_VALUE
            107 LOAD_CONST               0 (None)
            110 RETURN_VALUE
```

> **9. Fast alphabet**
[103-fast_alphabet.py](./103-fast_alphabet.py)a program that prints the alphabet in uppercase, followed by a new line

