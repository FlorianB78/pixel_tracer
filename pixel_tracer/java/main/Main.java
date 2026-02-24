package main;

import command.Command;
import pixeltracer.PixelTracer;

/**
 * Entry point of the PixelTracer CLI application.
 * Initializes the drawing engine and executes commands in an infinite loop.
 */
public class Main {

    /**
     * Utility class constructor.
     */
    public Main() {
    }

    /**
     * Starts the application.
     *
     * @param args command line arguments (unused)
     */
    public static void main(String[] args) {

        PixelTracer app = new PixelTracer();
        app.draw();

        System.out.println("PixelTracer Java");

        while (true) {

            Command cmd = Command.readFromStdin();

            if (cmd != null)
                cmd.execute(app);
        }
    }
}
