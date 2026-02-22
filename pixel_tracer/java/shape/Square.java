package shape;

import java.util.*;
import java.awt.Color;
import pixeltracer.*;
import pixel.*;

/**
 * Class Square
 */
public class Square extends Shape {

  //
  // Fields
  //

  private int length;
  private Point points;
  
  //
  // Constructors
  //
  public Square (int id, boolean fill, float thickness, double rotation, Color color, int length, shape.Point points) {
    super(id, fill, thickness, rotation, color);
    this.length = length;
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
    return "Square : length : " + length;
  }

  @Override
  public ArrayList<Pixel> draw(ArrayList<Pixel> lst) {
    drawSegment(points.getPos_x(), points.getPos_y(), length - 1, 0, lst);
    drawSegment(points.getPos_x(), points.getPos_y(), 0, length - 1, lst);
    drawSegment(points.getPos_x(), points.getPos_y() + length - 1, length - 1, 0, lst);
    drawSegment(points.getPos_x() + length - 1, points.getPos_y(), 0, length - 1, lst);
    return lst;
  }

}
