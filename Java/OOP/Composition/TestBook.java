public class TestBook {
    public static void main(String... args)
    {
        Author MQ = new Author("Musthak", "musthak741300@gmail.com",'m');

        System.out.println(MQ);

        Book dummyBook = new Book("Java for aliens", MQ, 9.99, 100);
        System.out.println(dummyBook);


        dummyBook.setPrice(8.88);
        dummyBook.setQty(88);

        System.out.println("name is: " + dummyBook.getName());
        System.out.println("price is: " + dummyBook.getPrice());
        System.out.println("qty is: " + dummyBook.getQty());

        System.out.println("Author is: " + dummyBook.getAuthor());
        System.out.println("Author's name is: " + dummyBook.getAuthor().getName());

        System.out.println("Author's email is: " + dummyBook.getAuthor().getEmail());

        System.out.println("Author's gender is: " + dummyBook.getAuthor().getGender());

        Book moreDummyBook = new Book("Java for more dummies", new Author("Peter", "Peter@nowhere.com", 'm'), 19.99, 8);

        System.out.println(moreDummyBook);


    }
}
