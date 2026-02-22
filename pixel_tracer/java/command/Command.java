package command;

import java.util.ArrayList;
import java.util.Scanner;
import pixeltracer.PixelTracer;

public class Command {
    
    private String name;
    private ArrayList<Integer> intParams;
    private ArrayList<String> stringParams;
    private ArrayList<Float> floatParams;
    private static int error_num = 0;
    private static String[] error_messages = {
        "",
        "commande inconnue",
        "commande manquante",
        "erreur paramètres, consulter la commande help",
        "exit",
        "clear",
        "plot",
        "~~~ Help ~~~",
        "done",
        "id inconnu dans la list"
    };
    private int intSize;
    private int strSize;
    private int floatSize;

    public Command() {
        this.intParams = new ArrayList<>();
        this.stringParams = new ArrayList<>();
        this.floatParams = new ArrayList<>();
        this.intSize = 0;
        this.strSize = 0;
        this.floatSize = 0;
    }
    public void setName(String name) {
        this.name = name;
    }

    public void addInt(int var1) {
        this.intParams.add(var1);
        this.intSize++;
    }

    public void addString(String var1) {
        this.stringParams.add(var1);
        this.strSize++;
    }

    public void addFloat(Float var1) {
        this.floatParams.add(var1);
        this.floatSize++;
    }
//    public static boolean is_int(String str) { 
//        try {  
//          Integer.parseInt(str);  
//          return true;
//        } catch(NumberFormatException e){  
//          return false;  
//        }
//    }
//
    public static boolean is_word(String str) {
        try {  
            Integer.parseInt(str); 
            return false;
          } catch(NumberFormatException e){  
            if (str == str.toLowerCase())
                return true;
            else
                return false;
          }
    }

    public static boolean isInteger(String str) {
        return str.matches("\\d+");
    }

    public static boolean isFloat(String str) {
        return str.matches("\\d+\\.\\d+");
    }

    public static String cleanText(String str) {
        str = str.toLowerCase();

        int index = str.indexOf('#');
        if (index != -1) {
            str = str.substring(0, index);
        }

        return str.trim();
    }

    public static Command readFromStdin() {

        Scanner scanner = new Scanner(System.in);

        System.out.print("~> ");

        String line = scanner.nextLine();

        if (line == null || line.isBlank())
            return null;

        line = cleanText(line);

        String[] tokens = line.split("\\s+");

        Command cmd = new Command();

        for (int i = 0; i < tokens.length; i++) {

            String token = tokens[i];

            if (i == 0) {
                cmd.setName(token);
                cmd.addString(token);
                continue;
            }

            if (isInteger(token))
                cmd.addInt(Integer.parseInt(token));

            else if (isFloat(token))
                cmd.addFloat(Float.parseFloat(token));

            else
                cmd.addString(token);
        }

        return cmd;
    }

    public void execute(PixelTracer app) {

        switch (name) {

            /* ===== SYSTEM ===== */

            case "exit":

                System.out.println("exit");
                System.exit(0);
                break;


            case "help":

                printHelp();
                break;


            /* ===== DISPLAY ===== */

            case "clear":

                app.clear();
                System.out.println("clear");
                app.draw();
                break;


            case "plot":

                app.draw();
                System.out.println("plot");
                break;


            /* ===== SHAPES ===== */

            case "point":

                if (intParams.size() == 2) {

                    int x = intParams.get(0);
                    int y = intParams.get(1);

                    app.addPoint(x, y);

                    System.out.println("point ajouté");
                    app.draw();

                } else
                    error();

                break;


            case "line":

                if (intParams.size() == 4) {

                    app.addLine(
                            intParams.get(0),
                            intParams.get(1),
                            intParams.get(2),
                            intParams.get(3)
                    );

                    System.out.println("line ajoutée");
                    app.draw();

                } else
                    error();

                break;


            case "circle":

                if (intParams.size() == 3) {

                    app.addCircle(
                            intParams.get(0),
                            intParams.get(1),
                            intParams.get(2)
                    );

                    System.out.println("circle ajouté");
                    app.draw();

                } else
                    error();

                break;


            case "rectangle":

                if (intParams.size() == 4) {

                    app.addRectangle(
                            intParams.get(0),
                            intParams.get(1),
                            intParams.get(2),
                            intParams.get(3)
                    );

                    System.out.println("rectangle ajouté");
                    app.draw();

                } else
                    error();

                break;


            case "square":

                if (intParams.size() == 3) {

                    app.addSquare(
                            intParams.get(0),
                            intParams.get(1),
                            intParams.get(2)
                    );

                    System.out.println("square ajouté");
                    app.draw();

                } else
                    error();

                break;


            case "polygon":

                if (intParams.size() >= 6 && intParams.size() % 2 == 0) {

                    app.addPolygon(intParams);

                    System.out.println("polygon ajouté");
                    app.draw();

                } else
                    error();

                break;


            case "curve":

                if (intParams.size() >= 4) {

                    app.addCurve(intParams);

                    System.out.println("curve ajoutée");
                    app.draw();

                } else
                    error();

                break;


            /* ===== OBJECT MANAGEMENT ===== */

            case "list":

                if (strSize >= 2) {

                    switch (stringParams.get(1)) {

                        case "layers":
                            app.listLayers();
                            break;

                        case "areas":
                            app.listAreas();
                            break;

                        case "shapes":
                            app.listShapes();
                            break;

                        default:
                            error();
                    }
                }
                break;


            case "delete":

                if (strSize >= 2 && intSize == 1) {

                    switch (stringParams.get(1)) {

                        case "area":
                            app.deleteArea(intParams.get(0));
                            break;

                        case "layer":
                            app.deleteLayer(intParams.get(0));
                            break;

                        case "shape":
                            app.deleteShape(intParams.get(0));
                            break;
                    }

                    app.draw();
                }
                break;


            case "select":

                if (strSize >= 2 && intSize == 1) {

                    if (stringParams.get(1).equals("area")) {
                        app.selectArea(intParams.get(0));
                    }
                    else if (stringParams.get(1).equals("layer")) {
                        app.setLayer(intParams.get(0));
                    }
                }
                break;


            case "new":

                if (strSize >= 2) {

                    if (stringParams.get(1).equals("area")) {
                        app.newArea();
                    }
                    else if (stringParams.get(1).equals("layer")) {
                        app.newLayer();
                    }

                    app.draw();
                }
                break;

            case "char":

                if (intSize == 1) {

                    char c = (char) intParams.get(0).intValue();

                    if (stringParams.get(2).equals("border")) {
                        app.setBorderChar(c);
                    }
                    else if (stringParams.get(2).equals("background")) {
                        app.setBackgroundChar(c);
                    }

                    app.draw();
                }
                else {
                    error();
                }
                break;


            /* ===== SET ===== */

            case "set":

                executeSet(app);
                break;


            default:

                System.out.println("commande inconnue");
        }
    }

    private void executeSet(PixelTracer app) {

        if (stringParams.size() < 2) {
            error();
            return;
        }

        String param = stringParams.get(1);

        switch (param) {

            case "color":

                if (intParams.size() == 3) {

                    app.setColor(
                            intParams.get(0),
                            intParams.get(1),
                            intParams.get(2)
                    );

                    System.out.println("color changée");

                } else
                    error();

                break;


            case "layer":

                if (intSize == 1) {

                    int id = intParams.get(0);

                    if (stringParams.get(2).equals("visible")) {
                        app.setLayerVisible(id, true);
                    }
                    else if (stringParams.get(2).equals("unvisible")) {
                        app.setLayerVisible(id, false);
                    }

                    app.draw();
                }
                else {
                    error();
                }
                break;


            default:

                error();
        }
    }

    private void printHelp() {


        System.out.println("**************************************************");
        System.out.println("****         VECTOR TEXT-BASED EDITOR         ****");
        System.out.println("**************************************************");
        System.out.println("==== Control ====");
        System.out.println("plot : draw dcreen");
        System.out.println("clear : clear screen");
        System.out.println("exit : quitter le programme");
        System.out.println("        ==== Draw shapes ====");
        System.out.println("point px py : create point a position (px, px)");
        System.out.println("line x1 y1 x2 x2 : draw line from (x1, y1) to (x1, y1)");
        System.out.println("square x1 y1 l : draw square (x1, y1)  length");
        System.out.println("rectangle x1 y1 w h : draw square (x1, y1)  width height");
        System.out.println("circle x y r : center at (x, y) radus r");
        System.out.println("polygon x1 y1 x2 y2 ... : draw polygon");
        System.out.println("curve x1 y1 x2 y2 x3 y3 x4 y4 : draw Bezier curve");
        System.out.println("        ==== Draw manager ====");
        System.out.println("list {layers, arias, shapes}");
        System.out.println("select {aria, layer} {id}");
        System.out.println("delete {aria, layer, shape} {id}");
        System.out.println("new {aria, layer}");
        System.out.println("==== Set ====");
        System.out.println("set char {border, background} ascii_code");
        System.out.println("set layer {visible, unvisible} {id}");
        System.out.println("set color r g b (ne fait rien en ligne de texte)");
    }

    private void error() {
        System.out.println("erreur paramètres");
    }
}
