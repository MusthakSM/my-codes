class account:
    balance = 1000
    def __init__(self, name):
        self.name = name
        self.identity_number = id

    def account_balance(self):
        print(self.name, "your account balance is = ", self.balance)
    
    def deposite(self, amount):
        self.balance += amount

    def withdrawal(self, amount):
        if (self.balance > 500 and amount<self.balance):
            self.balance -= amount
        else:
            print("your balance is not enough")

    def money_transfer(self, amount, target_account_name):
        if(self.balance > 500 and amount<self.balance):
            self.balance -= amount
            global target_account_object
            target_account_object = account(target_account_name)
            target_account_object.deposite(amount)
        
        else:
            print("your balance is not enough")

        

account1 = account("Musthak")


account1.deposite(9000)
account1.withdrawal(2000)
account1.account_balance() 
account1.money_transfer(1000, "Yassith")
account1.account_balance()
target_account_object.account_balance()