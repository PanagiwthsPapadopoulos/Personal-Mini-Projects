import random
import time

answ = 'y'

while answ == 'y' or answ == 'Y':


    num = random.randint(1,6)
    print("\n\nThe number "+str(num)+" was chosen.\n")

    time.sleep(2)
    print("Rolling die...")
    time.sleep(1)
    die = random.randint(1,6)
    time.sleep(1)
    
    if die == 1:
        print("-----")
        print("|   |")
        print("| 0 |")
        print("|   |")
        print("-----\n")

    elif die == 2:
        print("-----")
        print("|0  |")
        print("|   |")
        print("|  0|")
        print("-----\n")

    elif die == 3:
        print("-----")
        print("|0  |")
        print("| 0 |")
        print("|  0|")
        print("-----\n")

    elif die == 4:
        print("-----")
        print("|0 0|")
        print("|   |")
        print("|0 0|")
        print("-----\n")

    elif die == 5:
        print("-----")
        print("|0 0|")
        print("| 0 |")
        print("|0 0|")
        print("-----\n")

    elif die == 6:
        print("-----")
        print("|0 0|")
        print("|0 0|")
        print("|0 0|")
        print("-----\n")
  

    if die == num:
        answ = input( "Congratulations! You win.\nWould you like to play again? y/n\n") 
    else: answ = input( "You lose.\nWould you like to play again? y/n\n" )

