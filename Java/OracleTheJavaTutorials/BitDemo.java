/*
    The unary bitwise complement operator "~" inverts a bit pattern
    signed left shift operator     "<<"
    signed right shift operator    ">>" 
    unsigned right shift operator  ">>>" 
    The bitwise & operator performs a bitwise AND operation.
    The bitwise ^ operator performs a bitwise exclusive OR operation.
    The bitwise | operator performs a bitwise inclusive OR operation.
*/

class BitDemo {
    public static void main(String[] args) {
        int bitmask = 0x000F;
        int val = 0x2222;
        // prints "2"
        System.out.println(val & bitmask);
        int i = -1;
        System.out.printf("Max int %l", i>>>1);

    }
}