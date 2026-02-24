package shape;

import java.util.*;
import java.awt.Color;
import pixeltracer.*;
import pixel.*;

/**
 * Represents an axis-aligned rectangle.
 */
public class Rectangle extends Shape {

  //
  // Fields
  //

  private int length;
  private int width;
  private Point points;
  
  //
  // Constructors
  //
  /**
   * Creates a rectangle from origin point, length, and width.
   *
   * @param id shape identifier
   * @param fill fill mode
   * @param thickness stroke thickness
   * @param rotation rotation value
   * @param color rectangle color
   * @param length rectangle length
   * @param width rectangle width
   * @param points origin point
   */
  public Rectangle (int id, boolean fill, float thickness, double rotation, Color color, int length, int width, Point points) {
    super(id, fill, thickness, rotation, color);
    this.length = length;
    this.width = width;
    this.points = points;
  };
  
  //
  // Methods
  //


  //
  // Accessor methods
  //

  /**
   * Set the value of length
   * @param newVar the new value of length
   */
  public void setLength (int newVar) {
    length = newVar;
  }

  /**
   * Get the value of length
   * @return the value of length
   */
  public int getLength () {
    return length;
  }

  /**
   * Set the value of width
   * @param newVar the new value of width
   */
  public void setWidth (int newVar) {
    width = newVar;
  }

  /**
   * Get the value of width
   * @return the value of width
   */
  public int getWidth () {
    return width;
  }

  /**
   * Set the value of points
   * @param newVar the new value of points
   */
  public void setPoints (shape.Point newVar) {
    points = newVar;
  }

  /**
   * Get the value of points
   * @return the value of points
   */
  public shape.Point getPoints () {
    return points;
  }

  //
  // Other methods
  //

  /**
   * @return       String
   */
  public String toString()
  {
    return "Rectangle : width : " + width + ", length : " + length;
  }

  @Override
  public ArrayList<Pixel> draw(ArrayList<Pixel> lst){
    lst = super.drawSegment(points.getPos_x(), points.getPos_y(), 0, width - 1, lst);
    lst = super.drawSegment(points.getPos_x(), points.getPos_y(), length - 1, 0, lst);
    lst = super.drawSegment(points.getPos_x(), points.getPos_y() + width - 1, length - 1, 0, lst);
    lst = super.drawSegment(points.getPos_x() + length - 1, points.getPos_y(), 0, width - 1, lst);
    return lst;
  }
}
