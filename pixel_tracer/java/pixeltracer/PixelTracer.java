package pixeltracer;

import shape.*;
import java.util.ArrayList;
import java.awt.Color;

/**
 * Core drawing engine of the application.
 * Manages areas, layers, shapes, and ASCII rendering to stdout.
 */
public class PixelTracer {

    private Color color;

    private ArrayList<Area> areas = new ArrayList<>();

    private int currentArea = 0;
    private int currentLayer = 0;

    private char borderChar = '@';
    private char backgroundChar = '.';


    /**
     * Creates an engine with one default area of size 40x20.
     */
    public PixelTracer() {
        areas.add(new Area(0, 40, 20));
    }

    /**
     * Adds a point to the current layer.
     *
     * @param x x coordinate
     * @param y y coordinate
     */
    public void addPoint(int x, int y) {

        Point p = new Point(
                areas.get(currentArea)
                        .getLayers()
                        .get(currentLayer)
                        .getListShapes().size(),
                false,
                1.0f,
                0.0,
                color,
                x,
                y
        );

        areas.get(currentArea)
                .getLayers()
                .get(currentLayer)
                .addShapeToLayer(p);
    }

    /**
     * Adds a line to the current layer.
     *
     * @param x1 start x
     * @param y1 start y
     * @param x2 end x
     * @param y2 end y
     */
    public void addLine(int x1, int y1, int x2, int y2) {

        ArrayList<Point> pts = new ArrayList<>();

        pts.add(new Point(0, false, 1.0f, 0.0, color, x1, y1));
        pts.add(new Point(0, false, 1.0f, 0.0, color, x2, y2));

        Line l = new Line(
                areas.get(currentArea)
                        .getLayers()
                        .get(currentLayer)
                        .getListShapes().size(),
                false,
                1.0f,
                0.0,
                color,
                pts
        );

        areas.get(currentArea)
                .getLayers()
                .get(currentLayer)
                .addShapeToLayer(l);
    }

    /**
     * Adds a circle to the current layer.
     *
     * @param x center x
     * @param y center y
     * @param radius circle radius
     */
    public void addCircle(int x, int y, int radius) {

        Point center = new Point(
                0,
                false,
                1.0f,
                0.0,
                color,
                x,
                y
        );

        Circle c = new Circle(
                areas.get(currentArea)
                        .getLayers()
                        .get(currentLayer)
                        .getListShapes().size(),
                false,
                1.0f,
                0.0,
                color,
                radius,
                center
        );

        areas.get(currentArea)
                .getLayers()
                .get(currentLayer)
                .addShapeToLayer(c);
    }

    /**
     * Adds a rectangle to the current layer.
     *
     * @param x origin x
     * @param y origin y
     * @param length rectangle length
     * @param width rectangle width
     */
    public void addRectangle(int x, int y, int length, int width) {

        Point origin = new Point(
                0,
                false,
                1.0f,
                0.0,
                color,
                x,
                y
        );

        Rectangle rect = new Rectangle(
                areas.get(currentArea)
                        .getLayers()
                        .get(currentLayer)
                        .getListShapes().size(),
                false,
                1.0f,
                0.0,
                color,
                length,
                width,
                origin
        );

        areas.get(currentArea)
                .getLayers()
                .get(currentLayer)
                .addShapeToLayer(rect);
    }

    /**
     * Adds a square to the current layer.
     *
     * @param x origin x
     * @param y origin y
     * @param length side length
     */
    public void addSquare(int x, int y, int length) {

        Point origin = new Point(
                0,
                false,
                1.0f,
                0.0,
                color,
                x,
                y
        );

        Square s = new Square(
                areas.get(currentArea)
                        .getLayers()
                        .get(currentLayer)
                        .getListShapes().size(),
                false,
                1.0f,
                0.0,
                color,
                length,
                origin
        );

        areas.get(currentArea)
                .getLayers()
                .get(currentLayer)
                .addShapeToLayer(s);
    }

    /**
     * Adds a polygon from pairs of integer coordinates.
     *
     * @param intParams list [x1, y1, x2, y2, ...]
     */
    public void addPolygon(ArrayList<Integer> intParams) {

        ArrayList<Point> pts = new ArrayList<>();

        for (int i = 0; i < intParams.size(); i += 2) {
            pts.add(new Point(
                    0,
                    false,
                    1.0f,
                    0.0,
                    color,
                    intParams.get(i),
                    intParams.get(i + 1)
            ));
        }

        Polygon poly = new Polygon(
                areas.get(currentArea)
                        .getLayers()
                        .get(currentLayer)
                        .getListShapes().size(),
                false,
                1.0f,
                0.0,
                color,
                pts
        );

        areas.get(currentArea)
                .getLayers()
                .get(currentLayer)
                .addShapeToLayer(poly);
    }

    /**
     * Adds a Bezier curve from control points encoded as integer pairs.
     *
     * @param intParams list [x1, y1, x2, y2, ...]
     */
    public void addCurve(ArrayList<Integer> intParams) {

        ArrayList<Point> pts = new ArrayList<>();

        for (int i = 0; i < intParams.size(); i += 2) {
            pts.add(new Point(
                    0,
                    false,
                    1.0f,
                    0.0,
                    color,
                    intParams.get(i),
                    intParams.get(i + 1)
            ));
        }

        Curve curve = new Curve(
                areas.get(currentArea)
                        .getLayers()
                        .get(currentLayer)
                        .getListShapes().size(),
                false,
                1.0f,
                0.0,
                color,
                pts
        );

        areas.get(currentArea)
                .getLayers()
                .get(currentLayer)
                .addShapeToLayer(curve);
    }

    private void setupShape(Shape s) {
        s.setColor(color);
    }

   // public void listShapes() {
   //     shapes.print();
   // }

    /**
     * Deletes a shape by index in the current layer.
     *
     * @param id shape index
     */
    public void deleteShape(int id) {

        Layer layer =
                areas.get(currentArea)
                        .getLayers()
                        .get(currentLayer);

        if (id >= 0 && id < layer.getListShapes().size()) {
            layer.getListShapes().remove(id);
        }

        draw();
    }

    /**
     * Sets current drawing color.
     *
     * @param color color to use for newly created shapes
     */
    public void setColor(Color color) {
        this.color = color;
    }

    /**
     * Removes all shapes from the current layer.
     */
    public void clear() {
        areas.get(currentArea)
                .getLayers()
                .get(currentLayer)
                .getListShapes().clear();
    }

    /**
     * Renders visible layers of the current area into the ASCII grid and prints it.
     */
    public void draw() {

        if (areas.isEmpty()) {
            System.out.println("No area available.");
            return;
        }

        Area area = areas.get(currentArea);

        // 1️⃣ Nettoyer le plateau
        area.clearArea();

        char[][] grid = area.getArea();

        // 2️⃣ Parcourir les layers
        for (Layer layer : area.getLayers()) {

            if (!layer.getVisible())
                continue;

            // 3️⃣ Parcourir les shapes
            for (Shape s : layer.getListShapes()) {

                // ===== POINT =====
                if (s instanceof Point) {

                    Point p = (Point) s;

                    int x = p.getPos_x();
                    int y = p.getPos_y();

                    if (x >= 0 && x < area.getWidth()
                            && y >= 0 && y < area.getHeight()) {

                        grid[y][x] = area.getFull_char();
                    }
                }

                // ===== LINE =====
                else if (s instanceof Line) {

                    Line line = (Line) s;

                    ArrayList<Point> pts = line.getPoints();

                    for (Point p : pts) {

                        int x = p.getPos_x();
                        int y = p.getPos_y();

                        if (x >= 0 && x < area.getWidth()
                                && y >= 0 && y < area.getHeight()) {

                            grid[y][x] = area.getFull_char();
                        }
                    }
                }

                // ===== CURVE =====
                else if (s instanceof Curve) {

                    Curve curve = (Curve) s;

                    for (Point p : curve.getPoints()) {

                        int x = p.getPos_x();
                        int y = p.getPos_y();

                        if (x >= 0 && x < area.getWidth()
                                && y >= 0 && y < area.getHeight()) {

                            grid[y][x] = area.getFull_char();
                        }
                    }
                }

                // ===== POLYGON =====
                else if (s instanceof Polygon) {

                    Polygon poly = (Polygon) s;

                    for (Point p : poly.getPoints()) {

                        int x = p.getPos_x();
                        int y = p.getPos_y();

                        if (x >= 0 && x < area.getWidth()
                                && y >= 0 && y < area.getHeight()) {

                            grid[y][x] = area.getFull_char();
                        }
                    }
                }

                // ===== RECTANGLE =====
                else if (s instanceof Rectangle) {

                    Rectangle rect = (Rectangle) s;

                    Point origin = rect.getPoints();

                    int startX = origin.getPos_x();
                    int startY = origin.getPos_y();

                    for (int i = 0; i < rect.getLength(); i++) {
                        for (int j = 0; j < rect.getWidth(); j++) {

                            int x = startX + i;
                            int y = startY + j;

                            if (x >= 0 && x < area.getWidth()
                                    && y >= 0 && y < area.getHeight()) {

                                grid[y][x] = area.getFull_char();
                            }
                        }
                    }
                }

                // ===== SQUARE =====
                else if (s instanceof Square) {

                    Square sq = (Square) s;

                    Point origin = sq.getPoints();

                    int startX = origin.getPos_x();
                    int startY = origin.getPos_y();

                    for (int i = 0; i < sq.getLength(); i++) {
                        for (int j = 0; j < sq.getLength(); j++) {

                            int x = startX + i;
                            int y = startY + j;

                            if (x >= 0 && x < area.getWidth()
                                    && y >= 0 && y < area.getHeight()) {

                                grid[y][x] = area.getFull_char();
                            }
                        }
                    }
                }

                // ===== CIRCLE =====
                else if (s instanceof Circle) {

                    Circle circle = (Circle) s;

                    Point center = circle.getCenter();
                    int radius = circle.getRadius();

                    int cx = center.getPos_x();
                    int cy = center.getPos_y();

                    for (int y = 0; y < area.getHeight(); y++) {
                        for (int x = 0; x < area.getWidth(); x++) {

                            int dx = x - cx;
                            int dy = y - cy;

                            if (dx * dx + dy * dy <= radius * radius) {
                                grid[y][x] = area.getFull_char();
                            }
                        }
                    }
                }
            }
        }

        // 4️⃣ Affichage final
        area.printArea();
    }

    private void plot(char[][] board, int x, int y) {
        if (y >= 0 && y < board.length && x >= 0 && x < board[0].length) {
            board[y][x] = borderChar;
        }
    }

    private void drawLine(char[][] board, Point p1, Point p2) {
        drawLine(board, p1.getPos_x(), p1.getPos_y(), p2.getPos_x(), p2.getPos_y());
    }

    private void drawLine(char[][] board, int x1, int y1, int x2, int y2) {

        int dx = Math.abs(x2 - x1);
        int dy = Math.abs(y2 - y1);
        int sx = x1 < x2 ? 1 : -1;
        int sy = y1 < y2 ? 1 : -1;
        int err = dx - dy;

        while (true) {
            plot(board, x1, y1);
            if (x1 == x2 && y1 == y2) break;

            int e2 = 2 * err;

            if (e2 > -dy) {
                err -= dy;
                x1 += sx;
            }
            if (e2 < dx) {
                err += dx;
                y1 += sy;
            }
        }
    }

    /**
     * Prints shapes of the current layer.
     */
    public void listShapes() {

        Layer layer =
                areas.get(currentArea)
                        .getLayers()
                        .get(currentLayer);

        for (int i = 0; i < layer.getListShapes().size(); i++) {
            System.out.println(
                    i + " : " + layer.getListShapes().get(i)
            );
        }
    }

    /**
     * Sets current drawing color from RGB values.
     *
     * @param r red channel in [0, 255]
     * @param g green channel in [0, 255]
     * @param b blue channel in [0, 255]
     */
    public void setColor(int r, int g, int b) {

        if (r < 0 || r > 255 ||
                g < 0 || g > 255 ||
                b < 0 || b > 255) {

            System.out.println("RGB values must be between 0 and 255.");
            return;
        }

        this.color = new Color(r, g, b);
    }

    /**
     * Selects current layer by id in the current area.
     *
     * @param id layer id
     */
    public void setLayer(int id) {
        if (id >= 0 && id < areas.get(currentArea).getLayers().size()) {
            currentLayer = id;
        }
    }

    /**
     * Deletes a layer by id, except layer 0.
     *
     * @param id layer id
     */
    public void deleteLayer(int id) {

        if (id > 0 && id < areas.get(currentArea).getLayers().size()) { // on protège layer 0
            areas.get(currentArea).getLayers().remove(id);
        }
    }

    /**
     * Creates and selects a new layer in the current area.
     */
    public void newLayer() {
        areas.get(currentArea).getLayers().add(new Layer(areas.get(currentArea).getLayers().size()));
    }

    /**
     * Toggles visibility of a layer.
     *
     * @param id layer id
     * @param visible true to show, false to hide
     */
    public void setLayerVisible(int id, boolean visible) {

        if (id >= 0 && id < areas.get(currentArea).getLayers().size()) {

            if (visible)
                areas.get(currentArea).getLayers().get(id).setVisible();
            else
                areas.get(currentArea).getLayers().get(id).setUnvisible();
        }
    }

    /**
     * Sets border character used by low-level plotting helpers.
     *
     * @param c border character
     */
    public void setBorderChar(char c) {
        borderChar = c;
    }

    /**
     * Sets background character used by low-level plotting helpers.
     *
     * @param c background character
     */
    public void setBackgroundChar(char c) {
        backgroundChar = c;
    }

    /**
     * Prints layers of the current area.
     */
    public void listLayers() {

        Area area = areas.get(currentArea);

        System.out.println("Area " + area.getId());

        for (Layer layer : area.getLayers()) {

            System.out.println(
                    "  Layer " + layer.getId() +
                            " | visible=" + layer.getVisible() +
                            " | shapes=" + layer.getListShapes().size()
            );
        }
    }

    /**
     * Prints all areas with their layer count.
     */
    public void listAreas() {

        for (Area area : areas) {

            System.out.println(
                    "Area " + area.getId() +
                            " | layers=" + area.getLayers().size()
            );
        }
    }

    /**
     * Creates a new default area of size 40x20.
     */
    public void newArea() {
        areas.add(new Area(areas.size(), 40, 20));
    }

    /**
     * Selects current area and resets current layer to 0.
     *
     * @param id area id
     */
    public void selectArea(int id) {
        if (id >= 0 && id < areas.size()) {
            currentArea = id;
            currentLayer = 0; // reset layer
        }
    }

    /**
     * Deletes an area by id, except area 0.
     *
     * @param id area id
     */
    public void deleteArea(int id) {
        if (id > 0 && id < areas.size()) {
            areas.remove(id);
        }
    }
}
