import os
import numpy as np

# input_file = open("D:\Competitive_Programming\cvip\create_Test\data\themes.txt", "r")
f = open("D:\\Competitive_Programming\\cvip\\create_Test\\data\\themes.txt", "r")

# print(f.read())
arr = f.read().split('\n')
arr.sort()
word_list = []
# arr = arr.lower()
for word in arr:
    word = str(word)
    word = word.lower()
    
    try:
        word[0] = word[0].upper()
        if (word[0] != '#'): word_list.append(word)
    except: pass

write_file = open("cvip\\create_Test\\name.txt", "a")
write_file.write(str(word_list))