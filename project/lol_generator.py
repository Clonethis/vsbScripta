# match
# 1,2,3
# 10;3;2,8;2;0,2;5;4
# k,a,d for each player divided by column

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


def createGame(userArray):
    # game = "match"
    if len(userArray) >= 6:
        usedUser = len(userArray[-1])+3 
        print("used",usedUser)
        print(userArray)
        print("user arraylen ",len(userArray)-2 )
        for game in range(random.randint(100,200)):
            blu = []
            red = []
            statsRed = []
            statsBlu = []
            usedArray = []
            teams = ["red", "blu"]
            for i in range(len(userArray)):
                usedArray.append(i)
            for i in range(3):
                for x in range(3):
                    statsR = []
                    statsB = []
                    statsR.append(random.randint(0, 20))
                    statsB.append(random.randint(0, 20))
                statsBlu.append(statsB)
                statsRed.append(statsR)
                # blu.append(random.randint(0, len(userArray)-2))
                # usedArray[blu[-1]] = usedUser
                users = []
                for i in range(5):
                    user = random.randint(0, len(usedArray)-2)
                    users.append(user)
                    usedArray.pop(user)
                for i in range(len(users)):
                    blu.append(users[i])
                    i += 1
                    red.append(users[i])
                randomUser = random.randint(0, len(userArray)-2)

                # if(usedUsers[randomUser]==usedUser):
                # while usedArray[randomUser] == usedUser:
                randomUser = random.randint(0, len(userArray)-2)
                red.append(randomUser)

            whowon = random.choice(teams)
            file = open('game.txt', "w")
            file.writelines("match")
            file.writelines(str(red))
            # for y in statsRed:
                # print(y)
                # file.writelines(statsRed)
            # file.writelines(blu)
            # file.writelines(statsBlu)
            # file.writelines(whowon)
            file.close()
            # toFile("game.txt",red,',')

            # red.append(random.randint(0, len(userArray)))

        # if bluUsere in blu:


def toFile(fileName, array, separator):

    file = open(fileName, 'w')
    for items in array:
        file.writelines(items+separator)

    file.close()


def writeToFile(nameOfFile):
    pass


def createUserFile():
    baseUserArray = []
    for i in range(random.randint(9, 20)):
        baseUserArray.append((str(i))+","+createUser())
    toFile("users.txt", baseUserArray, '\n')
    return baseUserArray


#


baseUserArray = createUserFile()
createGame(baseUserArray)
# createGameFile(baseUserArray)
# file = open('f1.txt', 'w')
# for items in ar00ray:
#     file.writelines(items+'\n')

# file.close()
