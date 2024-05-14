
class Account:
    '''Bank account of a customer. '''
    def __init__(self,nameOftheclient, currentbalance):
        self.name = nameOftheclient
        self.balance = currentbalance

    def get_info(self):             # print the information . Account holder:<> balance:<>
        print("Account holder:", self.name, "Balance: %.2f"%self.balance)


    def deposit(self,amount):      # deposit money to account
        self.balance = self.balance + amount

    def withdraw(self,amount):      # withdraw money from the account
        if amount <= self.balance:
            self.balance = self.balance - amount
        else:
            print("ERROR: Insufficient credit in the account.")

#02.
def transfer(ac1,ac2,amount):
    if ac1.balance >= amount:
        ac1.balance = ac1.balance - amount
        ac2.balance = ac2.balance + amount

    elif ac1.balance == 0 :
        print("Account is empty, can not transfer")
    else:
        print("Can not trasfer money, insufficient balance in the account.")

acc1 = Account("Chathura Gamage", 40000.00)
acc2 = Account("Rajithe Ramanayake", 50000.00)

transfer(acc1,acc2,1000)

acc1.get_info()
acc2.get_info()






