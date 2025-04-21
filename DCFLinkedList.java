import java.util.LinkedList;
import java.util.Scanner;
public class DCFLinkedList {
    public static void main(String args[]){
        LinkedList<String> list = new LinkedList<>();
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the value in the Linked list or Press \"EXIT\"  : ");
        while(true){
            String data = sc.nextLine();
            if(data.equalsIgnoreCase("EXIT")){
                break;
            }
            list.add(data);
        }

        for(String Str : list){
            System.out.print(Str+" ");
        }
        System.out.println();
        System.out.println("Enter the element want to remove: ");
        String value = sc.nextLine();
        list.remove(value);
        System.out.print("After removing element: ");
        for(String Str : list){
            System.out.print(Str+" ");
        }
    }
}
