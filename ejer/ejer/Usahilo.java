package ejer;
public class Usahilo {
    public static void main(String[] args) {
    
        Hilo h1 = new Hilo(1);
        Hilo h2 = new Hilo(2);
    
        Thread t = new Thread(h1);
        Thread p = new Thread(h2);
    
        t.run();
        p.run();
    }
}
