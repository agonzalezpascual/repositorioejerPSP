package ejer;
public class Hilo implements Runnable{

    private int clase;

    public Hilo(int i) {
        this.clase=i;
    }
    public void run() {
        if(clase ==1){
            for(int i=0; i<=30;i++){
                System.out.println(i+"");
            }
        }else{
            for(int i=97; i<=122;i++){
                System.out.println((char)i);
            }
        }
    }
}


