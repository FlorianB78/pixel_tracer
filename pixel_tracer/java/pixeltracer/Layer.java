package pixeltracer;

import java.util.ArrayList;
import shape.*;

/**
 * Represents one drawing layer.
 * A layer groups shapes and can be visible or hidden.
 */
public class Layer {

    private int id;
    private boolean visible = true;
    private ArrayList<Shape> listShapes = new ArrayList<>();

    /**
     * Creates a layer with the given identifier.
     *
     * @param id layer id
     */
    public Layer(int id) {
        this.id = id;
    }

    /**
     * Sets layer id.
     *
     * @param id layer identifier
     */
    public void setId(int id) {
        this.id = id;
    }

    /**
     * Marks layer as visible.
     */
    public void setVisible() {
        this.visible = true;
    }

    /**
     * Marks layer as hidden.
     */
    public void setUnvisible() {
        this.visible = false;
    }

    /**
     * Replaces shapes list.
     *
     * @param listShapes new list of shapes
     */
    public void setListShapes(ArrayList<Shape> listShapes) {
        this.listShapes = listShapes;
    }

    /**
     * Gets layer id.
     *
     * @return layer id
     */
    public int getId() {
        return id;
    }

    /**
     * Gets visibility flag.
     *
     * @return true if visible
     */
    public boolean getVisible() {
        return visible;
    }

    /**
     * Gets list of shapes.
     *
     * @return shapes in this layer
     */
    public ArrayList<Shape> getListShapes() {
        return listShapes;
    }

    /**
     * Adds a shape to this layer.
     *
     * @param shape shape to append
     */
    public void addShapeToLayer(Shape shape) {
        listShapes.add(shape);
    }
}
