package pixel;

import java.awt.Color;

/**
 * Represents one colored pixel coordinate.
 */
public class Pixel {

    int px;     
    int py;     
    Color color;

    /**
     * Creates a pixel.
     *
     * @param px x coordinate
     * @param py y coordinate
     * @param color pixel color
     */
    public Pixel(int px, int py, Color color) {
        this.px = px;
        this.py = py;
        this.color = color;
    }

    public int getPx() {
        return px;
    }

    public int getPy() {
        return py;
    }

    public Color getColor() {
        return color;
    }

}
