from mistralai import Mistral
import json

with open('./2025_07_20URFU_QUAL/test-nolabels.json', "r") as f:
    d = json.load(f)
    result = dict()
    i = 0
    for k in d:
        result[k] = i % 2
        i += 1

with open("result_sussybaka.json", "w") as f:
    f.write(json.dumps(result, indent=4))