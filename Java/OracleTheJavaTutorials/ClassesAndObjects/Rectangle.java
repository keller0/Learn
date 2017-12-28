public class Rectangle {
    public int width = 0;
    public int height = 0;
    public Point origin;
 
    // four constructors
    public Rectangle() {
        origin = new Point(0, 0);
    }
    public Rectangle(Point p) {
        origin = p;
    }
    public Rectangle(int w, int h) {
        origin = new Point(0, 0);
        width = w;
        height = h;
    }
    public Rectangle(Point p, int w, int h) {
        origin = p;
        width = w;
        height = h;
    }
    // use this
    // public Rectangle() {
    //     this(0, 0, 1, 1);
    // }
    // public Rectangle(int width, int height) {
    //     this(0, 0, width, height);
    // }
    // public Rectangle(int x, int y, int width, int height) {
    //     this.x = x;
    //     this.y = y;
    //     this.width = width;
    //     this.height = height;
    // }
 
    // a method for moving the rectangle
    public void move(int x, int y) {
        origin.x = x;
        origin.y = y;
    }
 
    // a method for computing the area of the rectangle
    public int getArea() {
        return width * height;
    }
}