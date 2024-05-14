public class TestPerson {
    public static void main(String... args)
    {
        Student s1 = new Student("Musthak", "Oddamavadi");
        s1.addCourseGrade("CO222", 90);
        s1.addCourseGrade("CO223", 70);

        s1.printGrades();
        System.out.println("Average is " + s1.getAverageGrade());

        Teacher t1 = new Teacher("Azhar", "Kala weva");
        System.out.println(t1);

        String[] courses = {"EM285", "EE201", "CE224"};

        for (String course: courses)
        {
            if (t1.addCourse(course))
            {
                System.out.println(course + " added");
            }else{
                System.out.println(course+" can not be added");
            }
        }

        for (String course: courses)
        {
            if (t1.removeCourse(course))
            {
                System.out.println(course + " removed");
            }else{
                System.out.println(course + " can not be removed");
            }
        }
    }
}
