package shape;

import java.util.*;
import java.awt.Color;
import pixeltracer.*;
import pixel.*;


/**
 * Represents a circle defined by center and radius.
 */
public class Circle extends Shape {

  //
  // Fields
  //

  private int radius;
  private Point center;
  
  //
  // Constructors
  //
  /**
   * Creates a circle.
   *
   * @param id shape identifier
   * @param fill fill mode
   * @param thickness stroke thickness
   * @param rotation rotation value
   * @param color circle color
   * @param radius circle radius
   * @param point circle center
   */
  public Circle (int id, boolean fill, float thickness, double rotation, Color color, int radius, Point point) {
    super(id, fill, thickness, rotation, color);
    this.radius = radius;
    this.center = point;
  };
  
  //
  // Methods
  //


  //
  // Accessor methods
  //

  /**
   * Set the value of radius
   * @param newVar the new value of radius
   */
  public void setRadius (int newVar) {
    radius = newVar;
  }

  /**
   * Get the value of radius
   * @return the value of radius
   */
  public int getRadius () {
    return radius;
  }

  /**
   * Set the value of points
   * @param newVar the new value of points
   */
  public void setPoints (shape.Point newVar) {
    center = newVar;
  }

  /**
   * Get the value of points
   * @return the value of points
   */
  public Point getCenter () {
    return center;
  }

  //
  // Other methods
  //

 /**
   * @return       String
   */
  public String toString()
  {
    return "Circle : center : " + center;
  }


  @Override
  public ArrayList<Pixel> draw(ArrayList<Pixel> lst){
    int x = 0;
    int y = radius;
    int d = radius - 1;
    Pixel px;

    while (y >= x) {
        /* Insère tous les octants du cercle */
        px = new Pixel(center.getPos_x() + x, center.getPos_y() + y, color);
        lst.add(px);
        
        px = new Pixel(center.getPos_x() + y, center.getPos_y() + x, color);
        lst.add(px);

        px = new Pixel(center.getPos_x() - x, center.getPos_y() + y, color);
        lst.add(px);

        px = new Pixel(center.getPos_x() -y, center.getPos_y() + x, color);
        lst.add(px);

        px = new Pixel(center.getPos_x() + x, center.getPos_y() - y, color);
        lst.add(px);

        px = new Pixel(center.getPos_x() + y, center.getPos_y() - x, color);
        lst.add(px);

        px = new Pixel(center.getPos_x() - x, center.getPos_y() - y, color);
        lst.add(px);

        px = new Pixel(center.getPos_x() - y, center.getPos_y() - x, color);
        lst.add(px);

        if (d >= 2 * x) {
            d -= 2 * x + 1;
            x++;
        } else if (d < 2 * (radius - y)) {
            d += 2 * y - 1;
            y--;
        } else {
            d += 2 * (y - x - 1);
            y--;
            x++;
        }
    }
    return lst;
  }


}
