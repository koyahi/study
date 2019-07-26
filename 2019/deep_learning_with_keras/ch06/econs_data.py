# -*- coding: utf-8 -*-
import numpy as np
import matplotlib.pyplot as plt
import os
import re

DATA_DIR = "./data"

with open(os.path.join(DATA_DIR, "LD2011_2014.txt"), "r") as fld:
    data = []
    cid = 250
    for line_num, line in enumerate(fld):
        # 指定した文字列で始まるか
        if line.startswith("\"\";"):
            continue
        if line_num % 100 == 0:
            print("{:d} lines read".format(line_num))
        # re.subの第一引数は正規表現パターン, 第二引数に置換先文字列, 第三引数に処理対象の文字列
        cols = [float(re.sub(",", ".", x)) for x in line.strip().split(";")[1:]]
        data.append(cols[cid])

NUM_ENTRIES = 1000
plt.plot(range(NUM_ENTRIES), data[0:NUM_ENTRIES])
plt.ylabel("electricity consumption")
plt.xlabel("time (1pt = 15 mins)")
plt.show()

np.save(os.path.join(DATA_DIR, "LD_250.npy"), np.array(data))
