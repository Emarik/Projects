import java.util.ArrayList;

/**
 * Created by Emarik on 2/10/2016.
 */
public abstract class Piece {
    Side team = null;
    boolean moved = false;
    public boolean checkMove(Place currentPlace, Place checkingPlace)
    {
        boolean ret = true;

        // boolean ret = false;

         ArrayList<Place> moves = moveables(currentPlace);

         for(int I = 0; I<moves.size();I++)

         {

            Place checking = moves.get(I);

            if(checkingPlace.equals(checking))

            {

            	if(Board.board.get(checking).pieceOnTile!=null)
                if(team == Board.board.get(checking).pieceOnTile.team)

                {

                    System.out.println("Attempting to capture own teams piece");

                    ret = false;

                }

                /*else if(Board.board.get(checking).pieceOnTile.team == null && capturing)

                {

                    System.out.println("Move said that it was capturing piece, but no piece is there");

                    ret = false;

                }

                else if(Board.board.get(checking).pieceOnTile.team != null && !capturing)

                {

                    System.out.println("Move did not state that there was a capture, but there is enemy piece there");

                    ret = false;

                }*/

                else

                {

                    ret = true;

                }

            }
        }
        return ret;
    }
    public abstract ArrayList<Place> moveables(Place currentPlace);
    @Override
    public String toString() {
    return "" + team;

    }
}
