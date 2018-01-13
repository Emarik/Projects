import java.util.ArrayList;
import java.util.Map.Entry;
import java.util.Scanner;
/**
 * Created by Emarik on 2/22/2016.
 */
public class TurnTaker {
    Board b;
    FileLoader f;
    TurnTaker(Board board, FileLoader file)
    {
        b = board;
        f = file;
    }
    public void turns()
    {
    	while(true)
    	{
    		ArrayList<Place> pieces = new ArrayList<Place>();
    		/*for(char I = 'a';I<'i';I++)
    		{
    			for(int i=1;i<9;i++)
    			{
    				Piece p = Board.board.get(new Place(I,i)).pieceOnTile;
    				if(p!=null)
    				if(p.team == b.turn)
    				{
    					pieces.add(new Place(I,i));
    				}
    			}
    		}*/

    		for(Entry<Place,BoardTile > entry : Board.board.entrySet()) {
    		    Place key = entry.getKey();
    		    BoardTile value = entry.getValue();
    		    Place test = new Place('a',1);
    		    if(value.pieceOnTile!=null)
    		    if(value.pieceOnTile.team==b.turn)
    		    {
    		    	pieces.add(key);
    		    }

    		}
    		System.out.println("Option 0: Exit Game");
    		for(int I = 1;I<pieces.size()+1;I++)
			{
    			System.out.println("Option "+ I + ": " +pieces.get(I-1));
    		}
    		Scanner in = new Scanner(System.in);
    		int response = in.nextInt();
    		while(response > pieces.size()+1 || response < 0)
    		{
    			System.out.println("Incorrect response, number input not valid, please try again");
    			response = in.nextInt();
    		}
    		if(response == 0)
    		{
    			break;
    		}
    		else
    		{
    			Place p = pieces.get(response-1);
    			ArrayList<Place> moves = new ArrayList<Place>();
    			moves = Board.board.get(p).pieceOnTile.moveables(p);
        		System.out.println("Option 0: Exit Move");
    			for(int I = 1; I<moves.size()+1;I++)
    			{
    				System.out.println("Option " + I +": "+ moves.get(I-1));
    			}
    			Scanner inMoves = new Scanner(System.in);
        		int responseMoves = in.nextInt();
    			while(responseMoves > moves.size()+1 || responseMoves < 0)
        		{
        			System.out.println("Incorrect response, number input not valid, please try again");
        			responseMoves = in.nextInt();
        		}
    			if(responseMoves == 0)
    			{
    				break;
    			}
    			else
    			{
    				System.out.println(response);
    				System.out.println(responseMoves);
    				System.out.println(pieces.get(response-1));
    				System.out.println(moves.get(responseMoves-1));
    				b.movePiece(pieces.get(response-1), moves.get(responseMoves-1));
    				if(b.turn == Side.LIGHT)
    					b.turn = Side.DARK;
    				else
    					b.turn = Side.LIGHT;
    			}
    		}
    	}
    }
    
    
}
