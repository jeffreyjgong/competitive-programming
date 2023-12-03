def read_file(file_path):
    with open(file_path, 'r') as file:
        return file.read()

def parse_game_data(game_data):
    games = {}
    for line in game_data.split('\n'):
        if not line.strip():
            continue
        game_id, csets = line.split(': ')
        game_id = int(game_id.split(' ')[1])
        cube_sets = [cset.strip().split(', ') for cset in csets.split('; ')]
        games[game_id] = cube_sets
    return games

def is_game_possible(cube_sets, red_limit, green_limit, blue_limit):
    for cset in cube_sets:
        red, green, blue = 0, 0, 0
        for cube in cset:
            count, color = cube.split(' ')
            count = int(count)

            if color == 'red':
                red += count 
            elif color == 'green':
                green += count
            elif color == 'blue':
                blue += count
        if red > red_limit or green > green_limit or blue > blue_limit:
            return False
    return True

def calculate_possible_games_sum(game_data):
    games = parse_game_data(game_data)
    possible_games_sum = 0
    for game_id, cube_sets in games.items():
        if is_game_possible(cube_sets, 12, 13, 14):
            possible_games_sum += game_id
    return possible_games_sum

file_path = 'input-2.txt'

game_data = read_file(file_path)

sum_of_possible_games = calculate_possible_games_sum(game_data)
print("Sum of IDS: ", sum_of_possible_games)