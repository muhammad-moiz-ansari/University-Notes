import tensorflow as tf  # Importing TensorFlow Library for Automatic Differentiation

print("Welcome To The FMCG Company!")
print("M. Abdullah Siddiqui  23I-0617")
print("Moiz Ansari           23I-0523")
print("Faizan Ur Rehman      23I-0321")
input("Press Any Key To Continue.....")  # Generate response according to user Input

def Derivative(P_BnB, P_A, P_B):  # User Defined Function For Calculating Derivative
    with tf.GradientTape() as tape:  # Used for Automatic Differentiation Based on inputs
        tape.watch(P_BnB)  # Track operations involving P_BnB
        Function = 10000 - 2.5 * tf.pow(P_BnB, 2) + 3 * P_A + 1.5 * P_B   # Making Function
    
    Change = tape.gradient(Function, P_BnB)  # Used for Automatic Differentiation Based on inputs

    return Change  # Returning The result of the defined function to the Called Place

def main():
    while True:
        # Assumed Values For Task 2
        P_A = 10.0         # Same Price Of A & B Products
        P_B = 10.0
        P_BnB = float(input("Enter the price of BnB: "))  # Take input for Pbnb from the user

        # Calculating The Effect
        Effect = Derivative(tf.constant(P_BnB, dtype=tf.float32), tf.constant(P_A, dtype=tf.float32), tf.constant(P_B, dtype=tf.float32)) # Calling The Defined Function

        print("Due to increase in Price of BnB, Demand of BnB is Affected by : ", Effect.numpy())  # Printing The Results

        user_input = input("Do you want to run another query? (y/n): ").lower()
        if user_input == "n":
            print("Terminating the program...")
            break

if __name__ == "__main__":
    main()
