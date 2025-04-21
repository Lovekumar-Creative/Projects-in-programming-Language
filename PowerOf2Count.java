import java.util.*;
public class PowerOf2Count {
    public static int Count2Power(int n){
        int value = 1;
        int power = 0;
        while(value < n){
            value *= 2;
            power++;
        }
        if(value == n){
            return power;
        }else{
            return -1;
        }
    }
    public static void main(String args[]){
        System.out.print("Enter the number: ");
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();;
        int result = Count2Power(n);
        System.out.println("Hence the power of 2 of given number is : " + result);
    }
}
