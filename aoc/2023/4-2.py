from collections import defaultdict

def read_file(file_path):
    with open(file_path, 'r') as file:
        return file.read()

def return_one():
    return 1

def point_for_cards(card_string):
    cards = card_string.split('\n')
    total = defaultdict(return_one)
    total_cards = len(cards)

    for i, card in enumerate(cards):
        total[i] = total[i]
        both = card.split('|')
        winning_nums = both[0].split(':')[1]
        winning_nums = set([int(x) for x in filter(None, winning_nums.strip().split(' '))])

        your_nums = both[1].strip()
        your_nums = [int(x) for x in  filter(None, your_nums.split(' '))]

        num_in = 0
        for num in your_nums:
            if (num in winning_nums):
                num_in += 1

        if num_in > 0:
            for j in range(i+1, min(total_cards, i+1+num_in)):
                total[j] += total[i]

    total_return_cards = 0
    for _, card_count in total.items():
        total_return_cards += card_count
    return total_return_cards

file_path = 'input-4.txt'

card_string = read_file(file_path)

total_cards = point_for_cards(card_string)

print('Total cards: ', total_cards)

        