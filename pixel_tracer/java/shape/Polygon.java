package shape;

import java.util.*;
import java.awt.Color;
import pixeltracer.*;
import pixel.*;


/**
 * Represents a polygon defined by ordered vertices.
 */
public class Polygon extends Shape {

  //
  // Fields
  //

  private ArrayList<Point> points;
  
  //
  // Constructors
  //
  /**
   * Creates a polygon from a list of points.
   *
   * @param id shape identifier
   * @param fill fill mode
   * @param thickness stroke thickness
   * @param rotation rotation value
   * @param color polygon color
   * @param points polygon vertices
   */
  public Polygon (int id, boolean fill, float thickness, double rotation, Color color, ArrayList<Point> points) {
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
    return "Polygone : number of points : " + points.size();
  }

  @Override
  public ArrayList<Pixel> draw(ArrayList<Pixel> lst) {
    for (int i = 1; i < points.size(); i++) {
        Point p1 = points.get(i - 1);
        Point p2 = points.get(i);
        int dx = p2.getPos_x() - p1.getPos_x();
        int dy = p2.getPos_y() - p1.getPos_y();
        drawSegment(p1.getPos_x(), p1.getPos_y(), dx, dy, lst);
    }
    return lst;
  }

}
