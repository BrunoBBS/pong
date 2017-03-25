/**
 * Created by brunobbs on 3/23/17.
 */

import edu.princeton.cs.algs4.StdDraw;
import edu.princeton.cs.algs4.StdDraw.*;

import java.awt.event.KeyAdapter;
import java.awt.event.KeyEvent;
import java.security.Key;


public class Pong {
    private static final double XMIN = -100;
    private static final double XMAX = 100;
    private static final double YMIN = -100;
    private static final double YMAX = 100;
    private static final double MARGIN = 2;

    public static void main(String[] args) {
        StdDraw.setXscale(XMIN - MARGIN, XMAX + MARGIN);
        StdDraw.setYscale(YMIN - MARGIN, YMAX + MARGIN);
        Pallet p1 = new Pallet(0,1);
        Pallet p2 = new Pallet(0,0);
        StdDraw.enableDoubleBuffering();
        StdDraw.setPenColor(StdDraw.BLACK);
        while (true) {
        StdDraw.clear(StdDraw.WHITE);
            if (StdDraw.isKeyPressed(KeyEvent.VK_UP)) {
                p1.updatePos(1);

            }
        StdDraw.filledSquare(p1.xpos, p1.ypos, 5);
        //StdDraw.filledSquare(0, 0, 5);
        StdDraw.show();
        }
    }
}
