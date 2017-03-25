/**
 * Created by brunobbs on 3/23/17.
 */

public class Pallet {
    public int ypos, xpos;
    private int vel = 5;

    public Pallet() {
    }
    
    public Pallet(int pos, int side) {
        ypos = pos;
        xpos = (side==1)?70:-70;
    }
    public void updatePos(int dir) {
        ypos += vel * dir;
    }

}
