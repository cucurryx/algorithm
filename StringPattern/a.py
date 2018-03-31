import random

with open('txt', 'wt') as fw:
    for i in range(10000000):
        fw.write(chr(random.randint(65, 91)))