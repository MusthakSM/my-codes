
def capitalizer(Name):
    new_name = Name.title()
    return new_name

print ( capitalizer (" kasun dissanayake ") )
print ( capitalizer (" thilini madhushani Rathnayake ") )

n = 0
while True:
    action = input("Enter a name (E) or Terminate the code (T) :")

    if action == "E":
        name = input("Please enter the full name:")

        if len(name.split(" ")) == 1 :
            print(" ERROR - Please enter a full name < given names , family name >")
            continue
        
        changed_name = capitalizer(name)
        n+=1

        name_file = open('C:\\Users\\MUSTHAK\\Desktop\\VSCode\\Computing Lab\\names.txt','a')

        name_file.write(str(n)+" "+","+" "+changed_name+"\n")


    elif action == "T": 
        print("END.")
        break      
    
    else:
        print("Unvalid action")
        continue
