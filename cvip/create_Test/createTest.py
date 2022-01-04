import os
from random import random, seed
from random import randint
import numpy as np
import math
import shutil
import random
import numpy as np
def make_new_directory(directory):
    if not os.path.exists(directory):
        os.makedirs(directory)

def copy_rename_testcase(path):
    
    return

def subtask1(filename, n):
    f = open(filename, 'w')
    step = randint(0, 100)
    step = 13
    m = length = int(random.uniform(0.01, 0.3) * n)
    f.write(str(n) + ' ' + str(m) + '\n')
    cur_num = 12
    for i in range(n):
        f.write(str(cur_num) + ' ')
        if i %2 == 0: cur_num += step
        else: cur_num += step
        # if i % 100001 == 0: cur_num = 507
    f.write("\n")
    cur_num = 123456
    for i in range(m):
        f.write(str(cur_num) + ' ')
        if i %2 == 0: cur_num += step
        else: cur_num += step

def init_arr(length: int):
    arr = []
    for i in range(length):
        arr.append(randint(0, 100))
    return arr
def random_arr(length: int):
    arr = []
    for i in range(length):
        arr.append(randint(10, 1e8))
    return arr

def subtask2(filename, n):
    f = open(filename, 'w')
    step = randint(0, 100)
    length = int(random.uniform(0.01, 0.05) * n)
    res = []
    i, length_random = 0, 10
    isRandom = False
    init = init_arr(length)
    total_res = 0
    while i < n:
        total_res += 1
        init_val = randint(1, 1e6)
        for val in init:
            res.append(val+init_val)
            i+=1
            if (i  == n): break
        random_length = min(length, n - i)
        res.extend(random_arr(random_length))
        i += random_length
    f.write(str(n) + ' ' + str(length) + '\n')
    for i in res:
        f.write(str(i) + ' ')
    f.write('\n')
    res.clear
    init_val = randint(1, 100000)
    for i in init:
        f.write(str(i+init_val) + ' ')  
    print(total_res)
def createTest(filename, x):
    f = open(filename, 'w')
    
    n = x
    arr = np.random.permutation(n)
    # print(arr)
    f.write(str(n) + "\n")
    for i in arr:
        f.write(str(i + 1) + ' ')
    return

if __name__ == "__main__":
    # seed(1)
    path = "E:\\Competitive_Programming\\cvip\\create_Test\\"
    for i in range(8,100):
        fileName = path + "input\\input" + str(i) + ".txt"
        createTest(fileName, 10000)
    # i = 2
    # fileName = path + "input\\input" + str(i) + ".txt"
    # # createTest(fileName)
    # subtask1(fileName, 5000)
    # copy_rename_testcase()
        
    # path = 'E:\\Competitive_Programming\\cvip\\create_Test\\[1] Martian DNA'
    # print(os.listdir(path))
    # copy_rename_testcase(path=path)
        