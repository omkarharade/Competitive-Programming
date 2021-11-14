def divide_integers():
    while True:
        try:
            a = int(input("Please enter the numerator: "))
            b = int(input("Please enter the denominator: "))
            print(a / b)
        except ZeroDivisionError:
            print("Please enter a valid denominator.")
        except ValueError:
            print("Both values have to be integers.")
        finally:
            print("Code ends using finally")

divide_integers() 