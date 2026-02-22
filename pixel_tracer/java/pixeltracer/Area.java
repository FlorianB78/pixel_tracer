package pixeltracer;

import java.util.ArrayList;

public class Area {

    private int id;
    private int width;
    private int height;
    private char[][] area;
    private ArrayList<Layer> layers;
    private char empty_char;
    private char full_char;

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

    public void clearArea() {
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                area[i][j] = empty_char;
            }
        }
    }

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

    public int getId() {
        return id;
    }

    public int getWidth() {
        return width;
    }

    public int getHeight() {
        return height;
    }

    public char[][] getArea() {
        return area;
    }

    public ArrayList<Layer> getLayers() {
        return layers;
    }

    public char getEmpty_char() {
        return empty_char;
    }

    public char getFull_char() {
        return full_char;
    }

    public void setEmpty_char(char empty_char) {
        this.empty_char = empty_char;
    }

    public void setFull_char(char full_char) {
        this.full_char = full_char;
    }
}