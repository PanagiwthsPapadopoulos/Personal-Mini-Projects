import java.util.Scanner;

public class AwesomeJavaProgram{

    
    
    
    public static void main(String[] args){       
        boolean state = true;
        Scanner keyboard = new Scanner(System.in);
        System.out.println(state);
        //int num1;
        
        if(state){
            System.out.println("Enter the first number: ");           
            int num1 = keyboard.nextInt();
            System.out.println("Enter the second number: ");
            int num2 = keyboard.nextInt();

            System.out.println("Choices have been stored.");
            
            boolean state1 = false;
            while(!state1){
                System.out.println("Enter a number to select operation: ");

                System.out.println("1. Addition");
                System.out.println("2. Subtraction");
                System.out.println("3. Multiplication");
                System.out.println("4. Division");
                System.out.println("5. Exit");

                int choice = keyboard.nextInt();
            
                if(choice>5 || choice <1) {
                    System.out.println("Invalid Input. Try again.");
                }else {
                    state1 = true;
                }

                if(choice != 5){
                    switch(choice){
                        case 1: System.out.println(num1 + "+" + num2 + "=" + (num1+num2));
                        case 2: System.out.println(num1 + "-" + num2 + "=" + (num1-num2));
                        case 3: System.out.println(num1 + "*" + num2 + "=" + (num1*num2));
                        case 4: System.out.println(num1 + "/" + num2 + "=" + (num1/num2));
                    }
                }
                
            }

        }
    }
}


    
    