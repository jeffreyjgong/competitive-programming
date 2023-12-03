def read_file_to_2d_array(file_path):
    array_2d = []
    with open(file_path, 'r') as file:
        for line in file:
            array_2d.append(list(line.strip()))
    
    return array_2d

def check_around_number(grid, row, cols, width, height, gear_map):
    # check left number
    coords_to_check = []
    coords_to_check.append((row-1, cols[0]-1))
    coords_to_check.append((row, cols[0]-1))
    coords_to_check.append((row+1, cols[0]-1))

    # check middle
    for col in cols:
        coords_to_check.append((row-1, col))
        coords_to_check.append((row+1, col))

    # check right number
    coords_to_check.append((row-1, cols[len(cols)-1]+1))
    coords_to_check.append((row, cols[len(cols)-1]+1))
    coords_to_check.append((row+1, cols[len(cols)-1]+1))

    for coord in coords_to_check:
        compute_gear(grid, coord[0], coord[1], width, height, gear_map, row, cols)
    

def compute_gear(grid, r, c, width, height, gear_map, orig_row, cols):
    if (r < 0 or r >= height or c < 0 or c >= width):
        return

    if (grid[r][c] == '*'):
        if ((r,c) in gear_map):
            cur_count, cur_prod = gear_map[(r,c)]
            gear_map[(r,c)] = (cur_count+1, cur_prod * cols_to_num(grid, orig_row, cols))
        else:
            gear_map[(r,c)] = (1, cols_to_num(grid, orig_row, cols))

def cols_to_num(grid, r, cols):
    num = ""
    for col in cols:
        num += grid[r][col]
    
    return int(num)

def traverse_grid(grid):
    width = len(grid[0])
    height = len(grid)

    all_gear_ratios = 0

    cur_cols = []

    gear_map = {}

    for r in range(0, height):
        for c in range(0, width):
            if (not grid[r][c].isdigit()):
                if (len(cur_cols) > 0):
                    check_around_number(grid, r, cur_cols, width, height, gear_map)
                    cur_cols.clear()
            else:
                # is digit
                cur_cols.append(c)
                if (c == width-1):
                    check_around_number(grid, r, cur_cols, width, height, gear_map)
                    cur_cols.clear()
    
    print(len(gear_map))

    for gear_loc in gear_map:
        gear_count, gear_prod = gear_map[gear_loc]
        if (gear_count == 2):
            all_gear_ratios += gear_prod

    return all_gear_ratios 

file_path = 'input-3.txt'
grid = read_file_to_2d_array(file_path)

all_gear_ratios = traverse_grid(grid)

print("Sum of gear ratios: ", all_gear_ratios)