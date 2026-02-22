package pixeltracer;

import java.util.ArrayList;
import shape.*;

public class Layer {

    private int id;
    private boolean visible = true;
    private ArrayList<Shape> listShapes = new ArrayList<>();

    public Layer(int id) {
        this.id = id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public void setVisible() {
        this.visible = true;
    }

    public void setUnvisible() {
        this.visible = false;
    }

    public void setListShapes(ArrayList<Shape> listShapes) {
        this.listShapes = listShapes;
    }

    public int getId() {
        return id;
    }

    public boolean getVisible() {
        return visible;
    }

    public ArrayList<Shape> getListShapes() {
        return listShapes;
    }

    public void addShapeToLayer(Shape shape) {
        listShapes.add(shape);
    }
}
