# match
# 1,2,3
# 10;3;2,8;2;0,2;5;4
# 8,4,9
# 1;4;10,5;1;2,0;2;8
# red
# match
# 2,1,8
# 5;2;4,8;4;4,4;4;3
# 13,22,10
# 4;4;10,5;1;4,2;2;3
# blue

# Dále načtěte soubor s názvy hráčů. Na každém řádku souboru bude dvojice oddělená čárkou. Prvním členem dvojice bude ID hráče a druhým členem jeho přezdívka.

# Ukázkový obsah souboru s názvy hráčů:

# 1,darksider
# 2,yasuo4life
# 4,heimerdanger
import random

char = "a"
print(chr(ord(char)+1))


def createUser():
    string = []
    for i in range(random.randint(6, 10)):
        string.append(chr(ord(char)+random.randint(0, 22)))

    res = "".join(string)
    return res


def createGame(array):
    pass


def toFile(fileName, array):

    file = open(fileName, 'w')
    for items in array:
        file.writelines(items+'\n')

    file.close()


def writeToFile(nameOfFile):
    pass


baseUserArray = []
baseGamesArray = []
for i in range(random.randint(9, 20)):
    baseUserArray.append((str(i))+","+createUser())
toFile("users.txt", baseUserArray)
for i in range(random.randint(80, 300)):
    baseGamesArray.append((i,))
# mobile = ['samsung', 'redmi', 'oneplus']

# file = open('f1.txt', 'w')
# for items in ar00ray:
#     file.writelines(items+'\n')

# file.close()
