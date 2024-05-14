public class Teacher extends Person {
    private int numCourses;
    private String[] courses;
    private static final int MAX_COURSES = 5;

    public Teacher(String name, String address)
    {
        super(name, address);
        numCourses = 0;
        courses = new String[MAX_COURSES];
    }

    @Override
    public String toString()
    {
        return "Teacher: "+super.toString();
    }

    public boolean addCourse(String course)
    {
        // check whether the course ia already there or not...
        for(int i=0; i<numCourses; i++)
        {
            if (courses[i].equals(course))
                return false;
        }

        courses[numCourses] = course;
        numCourses++;
        return true;
    }

    public boolean removeCourse(String course)
    {
        boolean found = false;
        int position = -1;          // index of the course in the courses array..

        for (int i=0; i<numCourses; i++)
        {
            if (courses[i].equals(course))
            {
                found = true;
                position = i;
                break;
            }
        }

        if (found == true)
        {
            // remove the particular course and adjust the array accordingly..
            for (int i=position; i<numCourses-1; i++)
            {
                courses[i] = courses[i+1];
            }
            --numCourses;
            return true;
        }else{
            return  false;
        }
    }
}

