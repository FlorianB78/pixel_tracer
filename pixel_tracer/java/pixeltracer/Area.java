package pixeltracer;

import java.util.ArrayList;

/**
 * Represents a drawable text area.
 * Stores the character grid and its associated drawing layers.
 */
public class Area {

    private int id;
    private int width;
    private int height;
    private char[][] area;
    private ArrayList<Layer> layers;
    private char empty_char;
    private char full_char;

    /**
     * Creates a new area and initializes one default layer.
     *
     * @param id area identifier
     * @param width grid width
     * @param height grid height
     */
    public Area(int id, int width, int height) {

        this.id = id;
        this.width = width;
        this.height = height;

        this.empty_char = '.';
        this.full_char = '@';

        // INITIALISATION DU TABLEAU
        this.area = new char[height][width];

        // Remplir avec le caractère vide
        clearArea();

        // Initialisation des layers
        this.layers = new ArrayList<>();
        this.layers.add(new Layer(0)); // layer par défaut
    }

    // =========================
    // MÉTHODES UTILES
    // =========================

    /**
     * Fills the grid with the empty character.
     */
    public void clearArea() {
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                area[i][j] = empty_char;
            }
        }
    }

    /**
     * Prints the grid to standard output.
     */
    public void printArea() {
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                System.out.print(area[i][j]);
            }
            System.out.println();
        }
    }

    // =========================
    // GETTERS / SETTERS
    // =========================

    /**
     * Gets area identifier.
     *
     * @return area id
     */
    public int getId() {
        return id;
    }

    /**
     * Gets grid width.
     *
     * @return width in characters
     */
    public int getWidth() {
        return width;
    }

    /**
     * Gets grid height.
     *
     * @return height in characters
     */
    public int getHeight() {
        return height;
    }

    /**
     * Gets underlying character matrix.
     *
     * @return grid matrix
     */
    public char[][] getArea() {
        return area;
    }

    /**
     * Gets layers in this area.
     *
     * @return layer list
     */
    public ArrayList<Layer> getLayers() {
        return layers;
    }

    /**
     * Gets empty/background character.
     *
     * @return empty character
     */
    public char getEmpty_char() {
        return empty_char;
    }

    /**
     * Gets full/foreground character.
     *
     * @return full character
     */
    public char getFull_char() {
        return full_char;
    }

    /**
     * Sets empty/background character.
     *
     * @param empty_char background character
     */
    public void setEmpty_char(char empty_char) {
        this.empty_char = empty_char;
    }

    /**
     * Sets full/foreground character.
     *
     * @param full_char foreground character
     */
    public void setFull_char(char full_char) {
        this.full_char = full_char;
    }
}
