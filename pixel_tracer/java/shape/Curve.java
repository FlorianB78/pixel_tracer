package shape;

import java.util.ArrayList;
import java.awt.Color;
import pixeltracer.*;
import pixel.*;

/**
 * Represents a Bezier curve defined by control points.
 */
public class Curve extends Shape {

  //
  // Fields
  //

  private ArrayList<Point> points;
  
  //
  // Constructors
  //
  /**
   * Creates a curve from control points.
   *
   * @param id shape identifier
   * @param fill fill mode
   * @param thickness stroke thickness
   * @param rotation rotation value
   * @param color curve color
   * @param points control points
   */
  public Curve (int id, boolean fill, float thickness, double rotation, Color color, ArrayList<Point> points) {
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
    return "Curve : number of points : " + points.size();
  }

  /**
   * Calcule le point intermédiaire entre deux points
   *
   * @param p1 Premier point
   * @param p2 Deuxième point
   * @param t Paramètre entre 0 et 1
   * @return Point Point interpolé
   */
  public Point calc_point_median(Point p1, Point p2, double t) {
    double x = p1.getPos_x() * (1 - t) + p2.getPos_x() * t;
    double y = p1.getPos_y() * (1 - t) + p2.getPos_y() * t;
    Point result = new Point(id, fill, thickness, rotation, color, x, y);
    return result;
  }

  /**
  * Calcule un point sur la courbe de Bezier via Casteljau
  *
  * @param points Tableau de points de contrôle
  * @param num_pt Nombre de points
  * @param t Paramètre entre 0 et 1
  * @return Point Calculé sur la courbe
  */
  public Point cj_calc(ArrayList<Point> points, int num_pt, double t) {
    ArrayList<Point> tmp_pt = new ArrayList<>();
    for (int i = 0; i < num_pt; ++i) {
        tmp_pt.add(points.get(i));
    }
    for (int i = num_pt - 1; i > 0; --i) {
        for (int j = 0; j < i; ++j) {
            tmp_pt.set(j, calc_point_median(tmp_pt.get(j), tmp_pt.get(j + 1), t));
        }
    }
    return tmp_pt.get(0);
  }

  @Override
  public ArrayList<Pixel> draw(ArrayList<Pixel> lst){
    for (double t = 0; t < 1.0; t += 0.0001) {
      Point cjp1 = cj_calc(points, points.size(), t);
      Pixel px = new Pixel(cjp1.getPos_x(), cjp1.getPos_y(), color);
      lst.add(px);
  }
    return lst;
  }
}
