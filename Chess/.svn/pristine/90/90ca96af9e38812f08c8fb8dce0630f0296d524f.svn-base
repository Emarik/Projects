/**
 * Created by Emarik on 2/10/2016.
 */
public class Game {
    public static void main(String[] args)
    {
        Board b = new Board();
        FileLoader load = new FileLoader(b);
        load.ReadFile(args[0]);
        TurnTaker userInput = new TurnTaker(b,load);
        userInput.turns();
        //load.parseLine("d8 h4");
    }	
}
