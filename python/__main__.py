"""Opening Docstring"""

def get_name(): 
    """Not sure what to do here."""
    # Request users name. 
    name = input("Please enter your name: ") 
    return name 


def print_name(name): 
    """Prints name."""
    # Print name 
    print("Hello, " + name + "!")


def main(): 
    name = get_name() 
    print_name(name) 


main() 
