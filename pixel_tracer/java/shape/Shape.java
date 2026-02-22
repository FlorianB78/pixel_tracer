package shape;

import pixeltracer.*;
import java.util.*;
import java.awt.Color;
import pixel.*;

/**
 * Class Shape
 */
abstract public class Shape {

  //
  // Fields
  //

  protected int id;
  protected boolean fill;
  protected float thickness;
  protected double rotation;
  protected Color color;
  
  //
  // Constructors
  //
  public Shape (int id, boolean fill, float thickness, double rotation, Color color) {
    this.id = id;
    this.fill = fill;
    this.thickness = thickness;
    this.rotation = rotation;
    this.color = color;
  };
  
  //
  // Methods
  //


  //
  // Accessor methods
  //

  /**
   * Set the value of id
   * @param newVar the new value of id
   */
  public void setId (int newVar) {
    id = newVar;
  }

  /**
   * Get the value of id
   * @return the value of id
   */
  public int getId () {
    return id;
  }

  /**
   * Set the value of fill
   * @param newVar the new value of fill
   */
  public void setFill (boolean newVar) {
    fill = newVar;
  }

  /**
   * Get the value of fill
   * @return the value of fill
   */
  public boolean getFill () {
    return fill;
  }

  /**
   * Set the value of thickness
   * @param newVar the new value of thickness
   */
  public void setThickness (float newVar) {
    thickness = newVar;
  }

  /**
   * Get the value of thickness
   * @return the value of thickness
   */
  public float getThickness () {
    return thickness;
  }

  /**
   * Set the value of rotation
   * @param newVar the new value of rotation
   */
  public void setRotation (double newVar) {
    rotation = newVar;
  }

  /**
   * Get the value of rotation
   * @return the value of rotation
   */
  public double getRotation () {
    return rotation;
  }

  public void setColor (Color newVar) {
        color = newVar;
    }

    public Color getColor () {
        return color;
    }

  //
  // Other methods
  //

  /**
   * @return       String
   */
  public String toString()
  {
    String str = "Unknow shape";
    return str;
  }

  public ArrayList<Pixel> drawSegment(int x, int y, int dx, int dy, ArrayList<Pixel> lst){
    int i, cumul;
    int xinc, yinc;
    Pixel px;

    xinc = (dx > 0) ? 1 : -1;
    yinc = (dy > 0) ? 1 : -1;
    dx = Math.abs(dx);
    dy = Math.abs(dy);

    px = new Pixel(x, y, color);
    lst.add(px);

    if (dx > dy) {
        cumul = dx / 2;
        for (i = 1; i <= dx; i++) {
            x += xinc;
            cumul += dy;
            if (cumul >= dx) {
                cumul -= dx;
                y += yinc;
            }
            px = new Pixel(x, y, color);
            lst.add(px);
        }
    } else {
        cumul = dy / 2;
        for (i = 1; i <= dy; i++) {
            y += yinc;
            cumul += dx;
            if (cumul >= dy) {
                cumul -= dy;
                x += xinc;
            }
            px = new Pixel(x, y, color);
            lst.add(px);
        }
    }
    return lst;
  }

  public ArrayList<Pixel> draw(ArrayList<Pixel> lst) {
    return lst;
  }
}
