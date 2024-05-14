
/*
 * The time class models a time instance with second, minute and hour.
 * This class performs input validations using exception handling.
 */

public class Time{
    // The private instance variables - with input validations.
    private int second;     // valid range is [0, 59]
    private int minute;     // valid range is [0, 59]
    private int hour;       // valid range is [0, 23]

    // Input validations are done in the setters
    // All the other methods (such as constructors and setTime()) invoke
    // ..these setters to perform input validations to avoid code duplication.
    /* Sets the second to the given value with input validations */

    public void setSecond(int second)
    {
        if (second >= 0 && second <= 59)
        {
            this.second = second;
        }else{
            throw new IllegalArgumentException("Invalid second");
        }
    }

    public void setMinute(int minute)
    {
        if (minute >= 0 && minute <= 59)
        {
            this.minute = minute;
        }else{
            throw new IllegalArgumentException("Invalid minute");
        }
    }

    public void setHour(int hour)
    {
        if (hour >= 0 && hour <= 23)
        {
            this.hour = hour;
        }else{
            throw new IllegalArgumentException("Invalid hour");
        }
    }

    /* sets second, minute and hour to the given values with input validation */
    public void setTime(int second, int minute, int hour)
    {
        // invoke setters to do input validations
        this.setSecond(second);
        this.setMinute(minute);
        this.setHour(hour);
    }

    /* construct a Time instance with the given values with input validations */
    public Time(int second, int minute, int hour)
    {
        // invoke setters to do input validations
        this.setSecond(second);
        this.setMinute(minute);
        this.setHour(hour);
    }

    /* construct a Time instance with default values */
    public Time()
    {
        this.second = 0;
        this.minute = 0;
        this.hour = 0;
    }

    // The public getters
    
    public int getSecond()
    {
        return this.second;
    }

    public int getMinute()
    {
        return this.minute;
    }

    public int getHour()
    {
        return this.hour;
    }

    /* Returns a self-descriptive string in the form of "hh:mm:ss" with leading zeroes */
    public String toString()
    {
        return String.format("%02d:%02d:%02d", this.hour, this.minute, this.second);
    }

    /* Advances this Time instance by one second and returns this instance to support chaining */
    public Time nextSecond()
    {
        ++second;
        if (second == 60)   // we are sure that second <= 60 here because of the input validation
        {
            second = 0;
            ++minute;
            if (minute == 60)
            {
                minute = 0;
                ++hour;
                if (hour == 24)
                {
                    hour =0;
                }
            }
        }

        return this;        // Returns this instance, to support chaining
    }
}