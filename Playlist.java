import java.util.Scanner;

class Node {
    String song;
    Node lptr;
    Node rptr;

    Node(String song) {
        this.song = song;
        this.lptr = null;
        this.rptr = null;
    }
}

public class Playlist {
    static Node first = null;

    public static Node insertEnd(Node first) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter Song: ");
        String s = sc.nextLine();

        Node newNode = new Node(s);

        if (first == null) {
            first = newNode;
            return first;
        }

        Node temp = first;
        while (temp.rptr != null) {
            temp = temp.rptr;
        }

        temp.rptr = newNode;
        newNode.lptr = temp;

        return first;
    }

    public static void display(Node first) {
        Node temp = first;
        System.out.println("Playlist:");
        while (temp != null) {
            System.out.println("• " + temp.song);
            temp = temp.rptr;
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        char choice;

        do {
            first = insertEnd(first);
            System.out.print("Add another song? (y/n): ");
            choice = sc.next().charAt(0);
            sc.nextLine(); // consume newline
        } while (choice == 'y' || choice == 'Y');

        display(first);
        sc.close();
    }
}