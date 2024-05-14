public class Account {

    private int number;
    private double balance = 0.0;

    public Account(int number)
    {
        this.number = number;
    }

    public Account(int number, double balance)
    {
        this.number = number;
        this.balance = balance;
    }

    public int getNumber()
    {
        return this.number;
    }

    public double getBalance()
    {
        return this.balance;
    }

    public String toString()
    {
        return String.format("Account[number = %d, balance = $%.2f]", this.number, this.balance);
    }

    public Account credit(double amount)
    {
        balance += amount;
        return this;
    }

    public Account debit(double amount)
    {
        if (balance >= amount)
        {
            balance -= amount;
            return  this;
        }else{
            throw new IllegalArgumentException("Insufficient balance");
        }
    }

    public Account transferTo(double amount, Account another)
    {
        if (balance >= amount)
        {
            balance -= amount;
            another.balance += amount;
            return this;
        }else{
            throw new IllegalArgumentException("Insufficient balance");

        }
    }
    
}
