import os
from random import random, seed
from random import randint
import numpy as np
import math
import shutil
import random

def make_new_directory(directory):
    if not os.path.exists(directory):
        os.makedirs(directory)
subtask1 = ['1','2','3','4','5','6','7','8','9','10']
subtask2 = ['12','13','14','20','21','22', '28','29','32','43']
subtask3 = ['25', '30','31','34','35','38','40','41','46','51']
subtask4 = ['53','54','56','59', '61', '63','71','74','81', '73']
subtask = [subtask1, subtask2, subtask3, subtask4];

def copy_rename_testcase(path):
    des_path = path + "\\data\\"
    all_file = os.listdir(path)
    total, cur = 0, 0
    all_file.sort()
    make_new_directory(des_path+"input\\")
    make_new_directory(des_path+"output\\")
    all_file.sort()
    testcase = 0
    for file in all_file:
        cur_dir = path + "\\" + file
       
        name = file.split('.')[0]
        temp = name.replace('Test','')
        check = False

        for sub in subtask: 
            if temp in sub: check = True
        if check == False: continue
        print(name)
        print(check)
        check = file.split('.')
        try:
            if check[1] == 'in': des_dir = des_path + "\\input\\input" + str(total) + ".txt"
            else: des_dir = des_path + "\\output\\output" + str(total) + ".txt"
        except: print('err' ,check)
        testcase += 1
        shutil.copy(cur_dir,des_dir)
        cur+=1
        if cur == 2: 
            total += 1
            cur = 0
    print(testcase)
    return

if __name__ == "__main__": 
    # seed(1)
    # path = "D:\\Competitive_Programming\\cvip\\create_Test\\data\\"
    # for i in range(50):
    #     fileName = path + "input\\input" + str(i) + ".txt"
    #     print(fileName)      
    #     createTest(i, fileName)
    # copy_rename_testcase()
        
    path = 'E:\\Competitive_Programming\\cvip\\create_Test\\[1] Martian DNA'
    # print(os.listdir(path))
    copy_rename_testcase(path=path)
        