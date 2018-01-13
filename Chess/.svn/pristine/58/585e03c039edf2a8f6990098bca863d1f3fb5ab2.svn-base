import java.io.*;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

/**
 * Created by Emarik on 2/10/2016.
 */
public class FileLoader {
    Board b;
    FileLoader(Board b){this.b = b;}
    public void ReadFile(String filename)
    {
        try(InputStream in = new FileInputStream(filename))
        {
            BufferedReader buffer = new BufferedReader(new InputStreamReader(in));
            String line = null;
            while((line = buffer.readLine()) != null)
            {
                parseLine(line);
            }
        }
        catch(IOException e)
        {
            System.out.println("File not loaded correctly");
        }
    }
    public void parseLine(String line)
    {
        Pattern setPattern =     Pattern.compile( "([kqrpbn])([ld])([abcdefgh])([12345678])");
        Pattern movePattern =    Pattern.compile( "([abcdefgh])([12345678])\\s([abcdefgh])([12345678])");
        Pattern catpurePattern = Pattern.compile( "([abcdefgh])([12345678])\\s([abcdefgh])([12345678])[*]");
        Pattern castlePattern =  Pattern.compile( "([abcdefgh])([12345678])\\s([abcdefgh])([12345678])\\s([abcdefgh])([12345678])\\s([abcdefgh])([12345678])");
        Matcher setMatcher = setPattern.matcher(line);
        Matcher captureMatcher = catpurePattern.matcher(line);
        Matcher castleMatcher = castlePattern.matcher(line);
        Matcher moveMatcher = movePattern.matcher(line);
        if(setMatcher.find())
        {
            //System.out.println("Found value: " + setMatcher.group(1) );
            //System.out.println("Found value: " + setMatcher.group(2) );
            //System.out.println("Found value: " + setMatcher.group(3) );
            //System.out.println("Found value: " + setMatcher.group(4) );
            Place placement = new Place(setMatcher.group(3).charAt(0),Integer.parseInt(setMatcher.group(4)));
            Side side;
            switch( setMatcher.group(2))
            {
                case "l":
                    side = Side.LIGHT;
                    break;
                case "d":
                    side = Side.DARK;
                    break;
                default:
                    System.out.println("ERROR: the side selected is not one of the options of the board");
                    side = Side.LIGHT;
            }
            Piece pieceCreated;
            switch ( setMatcher.group(1))
            {
                case "k":
                    pieceCreated = new King();
                    break;
                case "q":
                    pieceCreated = new Queen();
                    break;
                case "r":
                    pieceCreated = new Rook();
                    break;
                case "n":
                    pieceCreated = new Knight();
                    break;
                case "b":
                    pieceCreated = new Bishop();
                    break;
                case "p":
                    pieceCreated = new Pawn();
                    break;
                default:
                    System.out.println("ERROR: piece is not one of the options");
                    pieceCreated = null;
            }
            b.setPiece(pieceCreated,side,placement);

        }
        else if(captureMatcher.find())
        {
            //System.out.println("Found value: " + captureMatcher.group(1) );
            //System.out.println("Found value: " + captureMatcher.group(2) );
            //System.out.println("Found value: " + captureMatcher.group(3) );
            //System.out.println("Found value: " + captureMatcher.group(4) );
            Place placeFrom = new Place(captureMatcher.group(1).charAt(0),Integer.parseInt(captureMatcher.group(2)));
            Place placeTo =   new Place(captureMatcher.group(3).charAt(0),Integer.parseInt(captureMatcher.group(4)));
            b.capturePiece(placeFrom,placeTo);
        }
        else if(castleMatcher.find())
        {
            //System.out.println("Found value: " + castleMatcher.group(1) );
            //System.out.println("Found value: " + castleMatcher.group(2) );
            //System.out.println("Found value: " + castleMatcher.group(3) );
            //System.out.println("Found value: " + castleMatcher.group(4) );
            //System.out.println("Found value: " + castleMatcher.group(5) );
            //System.out.println("Found value: " + castleMatcher.group(6) );
            //System.out.println("Found value: " + castleMatcher.group(7) );
            //System.out.println("Found value: " + castleMatcher.group(8) );
            Place from1 = new Place(castleMatcher.group(1).charAt(0),Integer.parseInt(castleMatcher.group(2)));
            Place to1 = new Place(castleMatcher.group(3).charAt(0),Integer.parseInt(castleMatcher.group(4)));
            Place from2 = new Place(castleMatcher.group(5).charAt(0),Integer.parseInt(castleMatcher.group(6)));
            Place to2 = new Place(castleMatcher.group(7).charAt(0),Integer.parseInt(castleMatcher.group(8)));
            b.castlePiece(from1,to1,from2,to2);
        }
        else if(moveMatcher.find())
        {
            //System.out.println("Found value: " + moveMatcher.group(1) );
            //System.out.println("Found value: " + moveMatcher.group(2) );
            //System.out.println("Found value: " + moveMatcher.group(3) );
            //System.out.println("Found value: " + moveMatcher.group(4) );
            Place from = new Place(moveMatcher.group(1).charAt(0),Integer.parseInt(moveMatcher.group(2)));
            Place to = new Place(moveMatcher.group(3).charAt(0),Integer.parseInt(moveMatcher.group(4)));
            b.movePiece(from,to);
        }
        else
        {
            System.out.println("No match was found for " + line);
        }
        //String setPattern = "[kqrpbn][ld][abcdefgh][12345678]";
        //String movePattern = "[abcdefgh][12345678]\\s[abcdefgh][12345678]";
        //String catpurePattern = "[abcdefgh][12345678]\\s[abcdefgh][12345678][*]";
        //String castlePattern = "[abcdefgh][12345678]\\s[abcdefgh][12345678]\\s[abcdefgh][12345678]\\s[abcdefgh][12345678]";
    }
}
