import re

class TextAnalyzer:
    def __init__(self, filename="input.txt"):
        self.inner_text = open(filename, mode='r', encoding="UTF-8").read()
        self.inner_text = re.sub(r"[\n\t\r\0\v]", " ", self.inner_text)
    
    def analyze(self):
        words = self.inner_text.split(" ")

        uni = set()
        unique_words = 0
        total_words = 0
        for w in words:
            # checking validity
            if w == '':
                continue

            # gather metrics
            total_words += 1

            if w not in uni:
                unique_words += 1
                uni.add(w)
        
        return total_words, unique_words
    

ta = TextAnalyzer('input.txt')
res = ta.analyze()
print(res[0], res[1])