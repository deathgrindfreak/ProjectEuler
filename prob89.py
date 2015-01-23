# Project Euler Problem: 89
# Goal: Write the list of roman numerals in the best way possible and find the number of
# characters saved in doing so
# Author: Cooper Bell


def rom_reduce(rom):
    if ('DCCCC' in rom):
        rom = rom.replace('DCCCC', 'CM')
    if ('CCCC' in rom):
        rom = rom.replace('CCCC', 'CD')
    if ('LXXXX' in rom):
        rom = rom.replace('LXXXX', 'XC')
    if ('XXXX' in rom):
        rom = rom.replace('XXXX', 'XL')
    if ('VIIII' in rom):
        rom = rom.replace('VIIII', 'IX')
    if ('IIII' in rom):
        rom = rom.replace('IIII', 'IV')

    return rom


# main
def main():
    numerals = open("roman.txt")

    nums = []
    for line in numerals:
        line = line.strip()
        num = rom_reduce(line)
        nums.append(num)

    rom_red = open("roman_reduced.txt", 'rw+')
    rom_red.truncate()
    reds = []

    for n in nums:
        reds.append(n)
        rom_red.write(n+'\n')

    numerals.close()
    rom_red.close()

if __name__ == '__main__':
    main()
