// import java.util.Scanner;

// public class MultiThreadingCounter {
//     /**
//      given class counter
//      */
//     static class Counter {
//         int count;
//         void inc() {
//             // Increment counter
//             count = count+1;
//         }
//         int getCount() {
//             return count;
//         }
//     }

//     // It will be incremented
//     static Counter counter;
//     // it will incremented each thread
//     static int numberOfIncrements;   
//      // Utility class that increments counter numberOfIncrements times
//     static class ThreadIncrement extends Thread {
//         public void run() {
//             for (int i = 0; i < numberOfIncrements; i++) {
//                 counter.inc();
//             }
//         }
//     }
    
//     public static void main(String[] args) {

//         Scanner in = new Scanner(System.in);
        
//         // Until user want
//         while (true) {
//             System.out.print("Enter Number of Threads (Enter 0 to end): ");
//             int numberOfThreads = in.nextInt();
//             // int numberOfIncrements;
//             if (numberOfThreads <= 0) 
//                 break;
//             do {
//                 // System.out.println();
//                 System.out.println("Number of times that each thread will increment the counter: ");
//                 numberOfIncrements = in.nextInt();
//                 if (numberOfIncrements < 1) {
//                     System.out.println("Number of increments must be positive.");
//                     numberOfIncrements = 1;
//                 }
//             } while (numberOfIncrements <= 0);
            
//             System.out.println();
//             // Print the basic data
//             System.out.println("Using " + numberOfThreads + " threads.");
//             System.out.println("Each thread increments the counter " 
//                                              + numberOfIncrements + " times.");
            
//             // Creation of threads and starting it
//             System.out.println();
//             System.out.println("Working...");
//             System.out.println();
//             // generation of thread
//             ThreadIncrement[] trackers = new ThreadIncrement[numberOfThreads];
//             counter = new Counter();
            
//             // Creating new Thread
//             for (int i = 0; i < numberOfThreads; i++)
//             {
//                 trackers[i] = new ThreadIncrement();
//             }
//             // Starting each Thread
//             for (int i = 0; i < numberOfThreads; i++)
//             {
//                 trackers[i].start();
//             }
           
//            // Terminating Thread 
//             for (int i = 0; i < numberOfThreads; i++) {
//                 try 
//                 {
//                     trackers[i].join();
//                 }
//                 catch (InterruptedException e) {
//                 }
//             }
//             // Print result
//             System.out.println("The final value of the counter should be "
//                                                      + (numberOfIncrements*numberOfThreads));
//             System.out.println("Actual final value of counter is: " + counter.getCount());
//             System.out.println();
//             System.out.println();
//         } 
//     }
// } 