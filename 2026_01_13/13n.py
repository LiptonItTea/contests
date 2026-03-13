import sys

def solve():
    """
    Основная функция для чтения входных данных и обработки строк.
    """
    try:
        first_line = sys.stdin.readline()
        if not first_line:
            return
        
        N, L = map(int, first_line.split())
    except EOFError:
        return
    except Exception:
        # Если ввод некорректный или отсутствует
        return

    OPEN_BRACKETS = {'(': ')', '[': ']'}
    CLOSE_BRACKETS = {')', ']'}

    for _ in range(N):
        s = sys.stdin.readline().strip('\n')

        if not s:
            print("()")
            continue

        current_level = 0
        output = ""
        i = 0
        
        while i < len(s):
            char = s[i]

            if char in OPEN_BRACKETS:
                if current_level == L and L > 0:                    
                    balance = 1
                    j = i + 1
                    
                    # Ищем закрывающую скобку, игнорируя содержимое
                    while j < len(s) and balance != 0:
                        next_char = s[j]
                        if next_char in OPEN_BRACKETS:
                            balance += 1
                        elif next_char in CLOSE_BRACKETS:
                            balance -= 1
                        j += 1
                    
                    # Устанавливаем индекс i на индекс закрывающей скобки (j-1), 
                    # чтобы следующая итерация (i += 1) началась после нее.
                    i = j - 1
                    # current_level не меняется, так как мы пропустили содержимое.
                
                # Если это не случай пропуска (например, L=0, или current_level < L),
                # то просто увеличиваем уровень.
                else:
                    current_level += 1
                    
            elif char in CLOSE_BRACKETS:
                # Нормальный выход из скобок
                current_level -= 1
                
            else:
                # Символ, который не является скобкой
                if current_level == L:
                    output += char

            # Переходим к следующему символу (включая пропуск, если он был)
            i += 1
        
        # Финализация вывода для строки
        if not output:
            print("()")
        else:
            print(output)

if __name__ == "__main__":
    solve()