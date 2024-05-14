
public class TestTime {
    public static void main(String... args)
    {
        // case 1: valid input
        //int hour = 23, minute = 58, second = 58;
        // case 2: invalid input
        int hour = 24, minute = 58, second = 58;
        Time t12;
        
        //t12 = new Time(second, minute, hour);
        // without try-catch, the program will terminate abruptly if exception thrown

        try{
            t12 = new Time(second, minute, hour);
            // if input is invalid, throw exception. Skip the rest, goto "catch".
            // Else complete "try", skip "catch"

            System.out.println("Valid input");

        } catch(IllegalArgumentException ex){
            // You have the opportunity to do something to recover from the error.
            ex.printStackTrace();        // print error messages
            System.out.println("Error in input. Set to default value.");
            // You should ask the user to provide the valid input instead!
            t12 = new Time();
        }   

        System.out.println("Time is "+ t12);
        System.out.println("Life goes on...");

        // case 1 output
        // valid input
        // Time is 23:58:58
        // Life goes on..

        // case 2 output
        // java.land.IllegalArgumentException: invalid hour
        // Error in input. set to default value
        // Time is 00:00:00
        // Life goes on...
    }
}
