# 1. Считывание данных (улучшено)
data = []
for line in input():
    try:
        parts = line.strip().split()
        if not parts:
            continue
        num, den = map(int, parts)
    except ValueError:
        continue # Пропускаем некорректные строки

    if num == 0 and den == 0:
        break
    if den == 0:
        continue # Пропускаем, если знаменатель равен 0
    data.append((num, den))

if not data:
    print(0)
    # exit(0)

def gcd(a, b):
    """НОД по алгоритму Евклида."""
    # Обрабатываем отрицательные числа, хотя по условию числитель и знаменатель целые
    a, b = abs(a), abs(b)
    while b:
        a, b = b, a % b
    return a

# 2. Суммирование дробей (упрощено и унифицировано)
cur_num = 0
cur_den = 1

for num, den in data:
    # A/B + C/D = (A*D + C*B) / (B*D)
    new_num = cur_num * den + num * cur_den
    new_den = cur_den * den
    
    # Сокращение
    div = gcd(new_num, new_den)
    cur_num = new_num // div
    cur_den = new_den // div

# Проверка, если сумма равна 0
if cur_num == 0:
    print(0)
    # exit(0)

# 3. Обработка целого числа
if cur_num % cur_den == 0:
    print(cur_num // cur_den)
    # exit(0)
    
# 4. Преобразование в десятичную дробь с отслеживанием остатков (самый надежный способ)

integer_part = cur_num // cur_den
remainder = cur_num % cur_den
denominator = cur_den

result = str(integer_part) + "."
decimal_digits = []

# Словарь для отслеживания остатков: остаток -> позиция в десятичной части
remainders_map = {} 
position = 0

current_remainder = remainder

while current_remainder != 0:
    # Если остаток уже встречался, найден период
    if current_remainder in remainders_map:
        start_period_index = remainders_map[current_remainder]
        
        # Разделение на непериодическую и периодическую части
        non_repeat = "".join(decimal_digits[:start_period_index])
        repeat = "".join(decimal_digits[start_period_index:])
        
        print(result + non_repeat + f"({repeat})")
        # exit(0)

    # Запоминаем текущий остаток и его позицию
    remainders_map[current_remainder] = position
    
    # Шаг деления:
    current_remainder *= 10
    digit = current_remainder // denominator
    current_remainder %= denominator
    
    decimal_digits.append(str(digit))
    position += 1

# Если цикл завершился (current_remainder == 0), дробь конечна
print(result + "".join(decimal_digits))