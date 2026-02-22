package main;

import command.Command;
import pixeltracer.PixelTracer;

public class Main {

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
