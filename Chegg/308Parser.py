def main(player1, player2):
    play1 = input("Enter player 1's hand shape ('r', 'p', or 's'):")
    play2 = input("Enter player 2's hand shape ('r', 'p', or 's'):")

    if determine_winner(play1, play2) == "Tie":
        print("Tie!")
    elif determine_winner(play1, play2):
        print(player1+"Wins!")
    else:
        print(player2+"Wins!")


def parse_args(args_list):
    parder = argparse.ArguementParser(args_list)
