package shape;

import java.util.*;
import java.awt.Color;
import pixeltracer.*;
import pixel.*;


/**
 * Class Line
 */
public class Line extends Shape {

  //
  // Fields
  //

  private ArrayList<Point> points;
  
  //
  // Constructors
  //
  public Line (int id, boolean fill, float thickness, double rotation, Color color, ArrayList<Point> points) {
    super(id, fill, thickness, rotation, color);
    this.points = points;
  };
  
  //
  // Methods
  //


  //
  // Accessor methods
  //

  /**
   * Set the value of points
   * @param newVar the new value of points
   */
  public void setPoints (ArrayList<Point> newVar) {
    points = newVar;
  }

  /**
   * Get the value of points
   * @return the value of points
   */
  public ArrayList<Point> getPoints () {
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
    int dx, dy, x, y;
    
    x = points.get(0).getPos_x();
    y = points.get(0).getPos_y();
    dx = points.get(1).getPos_x();
    dy = points.get(1).getPos_y();
    return "Line from {" + x + ", " + y + "} to {" + dx + ", " + dy + "}";  
  }

  @Override
  public ArrayList<Pixel> draw(ArrayList<Pixel> lst) {
    int dx, dy, x, y;

    x = points.get(0).getPos_x();
    y = points.get(0).getPos_y();
    dx = points.get(1).getPos_x() - points.get(0).getPos_x();
    dy = points.get(1).getPos_y() - points.get(0).getPos_y();
    drawSegment(x, y, dx, dy, lst);
    return lst;
  }


}
