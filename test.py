# models = """TinyCLIP-RN19M
# TinyCLIP-RN30M
# TinyCLIP-40M/32
# MobileCLIP-SO
# ACED-F0
# MobileCLIP2-S0
# OpenAI-RN50
# TinyCLIP-61M/32
# TinyCLIP-63M/32
# MobileCLIP-S1
# OpenAI-RN101
# OpenAI-B/32
# LAION-B/32
# DataComp-B/32
# DataComp-B/32-256
# SigLIP2-B/32
# MobileCLIP-S2
# ACED-F1
# ACED-F2
# MobileCLIP2-S2
# VeCLIP-B/16
# OpenAI-B/16
# LAION-B/16
# EVA02-B/16
# DFN-B/16
# DataComp-B/16
# MobileCLIP-B
# MobileCLIP-B(LT)
# MobileCLIP2-B
# SigLIP-B/16
# SigLIP-B/16-256
# SigLIP2-B/16
# SigLIP2-B/16-256
# MobileCLIP-S3
# MobileCLIP2-S3
# SigLIP-L/16
# DFN-L/14-quickgelu
# MobileCLIP-L/14
# MobileCLIP2-S4
# MobileCLIP2-L/14
# MobileCLIP-S4
# SigLIP-SO400M/14
# SigLIP2-L/16
# SigLIP2-SO400M/14""".split("\n")

# latencies = """1.9 + 1.9 
# 2.6 + 2.6 
# 3.0 + 1.9 
# 1.5 + 1.6 
# 2.1 + 1.8 
# 1.5 + 3.3
# 3.3 + 3.3 
# 4.3 + 2.6
# (-)
# 2.5 + 3.3
# 4.3 + 3.3 
# 4.3 + 3.3 
# 5.9 + 3.3
# 5.9 + 3.3
# 6.2 + 3.3 
# 6.3 + 6.3 
# 3.6 + 3.3 
# 6.2 + 1.8
# 6.5 + 1.8 
# 3.6 + 3.3
# 11.5 + 3.3 
# 11.5 + 3.3 
# 11.5 + 3.3 
# (-)
# 11.5 + 3.3 
# 11.5 + 3.3 
# 10.4 + 3.3 
# 10.4 + 3.3 
# 10.4 + 3.3
# 9.9 + 5.8 
# 11.4 + 5.8 
# 9.9 + 6.3 
# 11.4 + 6.3 
# 8.0 + 6.6 
# 8.0 + 6.6
# 38.2 + 19.1 
# 57.9 + 6.6 
# 57.9 + 6.6 
# 19.6 + 6.6 
# 57.9 + 6.6 
# 19.6 + 6.6 
# (-)
# 38.2 + 19.8 
# (-)""".split("\n")

# coco_perfs = """30.9
# 33.8
# 33.5
# 40.4
# 41.2
# 43.7
# 28.5
# 36.5
# 38.5
# 44.0
# 30.7
# 30.4
# 39.1
# 37.1
# 39.9
# 47.9
# 45.4
# 47.3
# 49.7
# 48.8
# 48.4
# 40.4
# 42.3
# 42.2
# 43.4
# 42.3
# 50.6
# 50.0
# 49.9
# 47.8
# 48.4
# 53.2
# 54.1
# 51.3
# 50.9
# 52.3
# 53.7
# 47.6
# 51.5
# 51.6
# 52.1
# 51.8
# 54.7
# 55.5""".split("\n")

# table = {}
# for i in range(len(models)):
#     if latencies[i] == "(-)":
#         continue

#     table[models[i]] = (eval(latencies[i]), float(coco_perfs[i]))

# # print(table)
# import matplotlib.pyplot as plt
# import numpy as np

# fig, ax = plt.subplots(figsize=(10, 7))
# # ax.grid(True)
# # ax.set_yticks(np.arange(0, 100, 1))
# ax.set_xlabel("latency")
# ax.set_ylabel("coco_t2i_r@1")
# # ax.set_xscale("log")
# # ax.set_ylim(10, 80)

# for i, k in enumerate(table):
#     ax.scatter(table[k][0], table[k][1], linewidths=10)
#     # ax.scatter(i, table[k][1])
#     ax.annotate(k, table[k], size=10, textcoords="offset pixels", xytext=(10, 0))

# ax.hlines(63, 0, 50, 'red')
# ax.annotate("BLIP", (25, 63))
# plt.show()

with open("test.txt", "r") as f:
    data = [int(s) for s in f.readline().split(" ")]
    print(data[0] + data[1])
    # print(data)
    f.write()