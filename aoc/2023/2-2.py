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

def max_of_each(cube_sets):
    max_red, max_green, max_blue = 0,0,0
    for cset in cube_sets:
        for cube in cset:
            count, color = cube.split(' ')
            count = int(count)

            if color == 'red':
                max_red = max(max_red, count) 
            elif color == 'green':
                max_green = max(max_green, count)
            elif color == 'blue':
                max_blue = max(max_blue, count)
    return max_red*max_blue*max_green

def calculate_possible_games_sum(game_data):
    games = parse_game_data(game_data)
    game_power = 0
    for game_id, cube_sets in games.items():
        game_power += max_of_each(cube_sets)
    return game_power

file_path = 'input-2.txt'

game_data = read_file(file_path)

sum_of_possible_games = calculate_possible_games_sum(game_data)
print("Sum of game power: ", sum_of_possible_games)