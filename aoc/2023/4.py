def read_file(file_path):
    with open(file_path, 'r') as file:
        return file.read()

def point_for_cards(card_string):
    cards = card_string.split('\n')
    total = 0
    for card in cards:
        if not card.strip():
            continue
        both = card.split('|')
        winning_nums = both[0].split(':')[1]
        winning_nums = set([int(x) for x in filter(None, winning_nums.strip().split(' '))])

        your_nums = both[1].strip()
        your_nums = [int(x) for x in  filter(None, your_nums.split(' '))]

        num_in = 0
        for num in your_nums:
            if (num in winning_nums):
                num_in += 1
        
        if (num_in > 0):
            total += pow(2, num_in-1)
    
    return total

file_path = 'input-4.txt'

card_string = read_file(file_path)

total_points = point_for_cards(card_string)

print('Total card points: ', total_points)

        