package shape;

import java.util.*;
import pixeltracer.*;
import java.awt.Color;
import pixel.*;


/**
 * Represents a 2D point shape.
 */
public class Point extends Shape {

  //
  // Fields
  //

  private int pos_x;
  private int pos_y;
  private double double_pos_x;
  private double double_pos_y;
  
  //
  // Constructors
  //
  /**
   * Creates a point from integer coordinates.
   *
   * @param id shape identifier
   * @param fill fill mode
   * @param thickness stroke thickness
   * @param rotation rotation value
   * @param color point color
   * @param x x coordinate
   * @param y y coordinate
   */
  public Point (int id, boolean fill, float thickness, double rotation, Color color, int x, int y) {
    super(id, fill, thickness, rotation, color);
    pos_x = x;
    pos_y = y;
  };
  
  /**
   * Creates a point from floating point coordinates.
   *
   * @param id shape identifier
   * @param fill fill mode
   * @param thickness stroke thickness
   * @param rotation rotation value
   * @param color point color
   * @param x x coordinate
   * @param y y coordinate
   */
  public Point (int id, boolean fill, float thickness, double rotation, Color color, double x, double y) {
    super(id, fill, thickness, rotation, color);
    double_pos_x = x;
    double_pos_y = y;
    pos_x = (int) Math.round(x);
    pos_y = (int) Math.round(y);
  };

  //
  // Methods
  //


  //
  // Accessor methods
  //

  /**
   * Set the value of pos_x
   * @param newVar the new value of pos_x
   */
  public void setPos_x (int newVar) {
    pos_x = newVar;
  }

  /**
   * Get the value of pos_x
   * @return the value of pos_x
   */
  public int getPos_x () {
    return pos_x;
  }

  /**
   * Set the value of pos_y
   * @param newVar the new value of pos_y
   */
  public void setPos_y (int newVar) {
    pos_y = newVar;
  }

  /**
   * Get the value of pos_y
   * @return the value of pos_y
   */
  public int getPos_y () {
    return pos_y;
  }

  /**
   * Set the value of double_pos_x
   * @param newVar the new value of pos_x
   */
  public void setDoublePos_x (double newVar) {
    double_pos_x = newVar;
  }

  /**
   * Get the value of double_pos_x
   * @return the value of pos_x
   */
  public double getDoublePos_x () {
    return double_pos_x;
  }

  /**
   * Set the value of double_pos_y
   * @param newVar the new value of pos_y
   */
  public void setDoublePos_y (double newVar) {
    double_pos_y = newVar;
  }

  /**
   * Get the value of double_pos_y
   * @return the value of pos_y
   */
  public double getDoublePos_y () {
    return double_pos_y;
  }
  //
  // Other methods
  //

  /**
   * @return       String
   */
  public String toString()
  {
    return "Point : {" + pos_x + ", " + pos_y + "}";
  }

  @Override
  public ArrayList<Pixel> draw(ArrayList<Pixel> lst) {
    Pixel px = new Pixel(pos_x, pos_y, super.color);
    lst.add(px);
    return lst;
  }
}
