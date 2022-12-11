# Global list
building_list = [
    ['--', '--', 'R3'],
    ['--', 'S2', 'W2'],
    ['R4', 'S4', 'G4']]

# Function which return the int value based on type of item


def building(type):
    # If type is recycled return 5
    if type == "recycled":
        for recycled in building_list:
            if "R3" in recycled or "R4" in recycled:
                return (5)

    # if type is stone return 3
    if type == "stone":
        for stone in building_list:
            if "S2" in stone or "S4" in stone:
                return (3)

    # if type is wood return 6
    if type == "wood":
        for wood in building_list:
            if "W2" in wood:
                return (6)
    # if type is glass return 4
    if type == "glass":
        for glass in building_list:
            if "G4" in glass:
                return (4)
    # in default cases return 0
    return 0


def main():
    result = open('scoring-result.txt', 'w')
    result.write(' +------------+----+\n')

    # material: recycled, score: 5
    score = building("recycled")
    result.write(' | {} | {} |\n'.format("recycled", building("recycled")))

    # material: stone, score: 3
    score = score+building("stone")
    result.write(' | {} | {} |\n'.format("stone", building("stone")))

    # material: wood, score: 6
    score = score+building("wood")
    result.write(' | {} | {} |\n'.format("wood", building("wood")))

    # material: glass, score: 4
    score = score+building("glass")
    result.write(' | {} | {} |\n'.format("glass", building("glass")))
    result.write('+============+====+\n')
    result.write(' | total: | {} |\n'.format(score))  # total score sum
    result.write('+------------+----+\n')
    result.close()


main()
