
connection_type = input("How resistors are connected? if parallel Type p or if series TYPE s:")
type = connection_type

if type == "P" or type == "p" or type == "S" or type == "s" :

    no_of_resistors = int(input("No of resistors connected in the circuit:"))
    n = no_of_resistors

    i = 1
    R = 0       # Equivalent resistance
    r = 0       # r = 1/R  
    while i<=n :
        resistor_value = float(input("value of the resistor:"))

        if type == "S" or type == "s" :
            Connection = "Series"
            R += resistor_value

        elif type == "P" or type == "p" :
            Connection = "Parallel"
            r += 1/resistor_value
            R = 1/r

        i += 1

    print("Equivalent resistance of this",Connection,"connection =", R)

else:
    print("Connection is not recognized...")

        

