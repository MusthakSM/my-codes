
public class TestAuthor{

    public static void main(String... args)
    {
        Author MQ = new Author("Musthak", "musthakahamed741300@gmail.com", 'm');
        System.out.println(MQ);

        MQ.setEmail("musthak741300@gmail.com");
        System.out.println(MQ);

        System.out.println("Name is: "+ MQ.getName());
        System.out.println("Email is: "+ MQ.getEmail());
        System.out.println("Gender is: "+ MQ.getGender());

    }
}