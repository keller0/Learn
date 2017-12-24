class ConcatDemo {
    public static void main(String[] args){
        String firstString = "This is";
        String secondString = " a concatenated string ";
        String thirdString = firstString+secondString;
        String lastString = thirdString+"and another string";
        System.out.println(lastString);
    }
}