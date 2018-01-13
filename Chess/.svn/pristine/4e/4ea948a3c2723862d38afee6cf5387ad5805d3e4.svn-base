import java.util.ArrayList;

/**
 * Created by Emarik on 2/12/2016.
 */
public class Rook extends Piece {
    @Override
    public String toString()
    {
        return "Rook";
    }
    //public boolean checkMove(Place currentPlace, Place checkingPlace, boolean capturing)
    //{
    //    if(checkingPlace.characterside>'h' ||checkingPlace.characterside<'a'|| checkingPlace.numberside>8||checkingPlace.numberside<1)
    //    {
    //    System.out.println("The move is trying to move to a placement that is off of the board, canceling move, rook");
    //    return false;
    //    }
    //    Place temporaryCheckingPlace = currentPlace;
    //    int right;
    //    int up;
    //    if(checkingPlace.characterside > currentPlace.characterside)
    //        right = 1;
    //    else if(checkingPlace.characterside < currentPlace.characterside)
    //        right=-1;
    //    else
    //        right = 0;
    //    if(checkingPlace.numberside > currentPlace.numberside)
    //        up = 1;
    //    else if (checkingPlace.numberside < currentPlace.numberside)
    //        up = -1;
    //    else
    //        up = 0;
    //    while(temporaryCheckingPlace.characterside<='h' && temporaryCheckingPlace.numberside<=8 && temporaryCheckingPlace.numberside >= 1 && temporaryCheckingPlace.characterside >='a')
    //    {
    //        temporaryCheckingPlace.characterside+=right;
    //        temporaryCheckingPlace.numberside+=up;
    //        if(temporaryCheckingPlace.numberside == checkingPlace.numberside && temporaryCheckingPlace.characterside == checkingPlace.characterside)
    //        {
    //            if(Board.board.get(checkingPlace).pieceOnTile.team == Board.board.get(currentPlace).pieceOnTile.team)
    //            {
    //                System.out.println("Attempting to capture own teams piece");
    //                return false;
    //            }
    //            else if(Board.board.get(checkingPlace).pieceOnTile.team == null && capturing)
    //            {
    //                System.out.println("Move said that it was capturing piece, but no piece is there");
    //                return false;
    //            }
    //            else if(Board.board.get(checkingPlace).pieceOnTile.team != null && !capturing)
    //            {
    //                System.out.println("Move did not state that there was a capture, but there is enemy piece there");
    //                return false;
    //            }
    //            else
    //            {
    //                return true;
    //            }
    //        }
    //        else if(Board.board.get(temporaryCheckingPlace).pieceOnTile !=null)
    //        {
    //            return false;
    //        }
    //    }
    //    return false;
    //}
    public ArrayList<Place> moveables(Place currentPlace)
    {
        ArrayList<Place> ret = new ArrayList<Place>();
        Place checking = currentPlace;
        //Checking up
        while(checking.numberside>1)
        {
            checking.numberside-=1;
            if(Board.board.get(checking).pieceOnTile == null)
            {
            	Place p = new Place(checking);
                ret.add(p);
            }
            else if(Board.board.get(checking).pieceOnTile.team != team)
            {
            	Place p = new Place(checking);
                ret.add(p);
                break;
            }
            else
            {
                break;
            }
        }
        checking = currentPlace;
        //Checking down
        while(checking.numberside<8)
        {
            checking.numberside+=1;
            if(Board.board.get(checking).pieceOnTile == null)
            {
            	Place p = new Place(checking);
            	ret.add(p);
            }
            else if(Board.board.get(checking).pieceOnTile.team != team)
            {
            	Place p = new Place(checking);
                ret.add(p);
                break;
            }
            else
            {
                break;
            }
        }
        checking = currentPlace;
        //Checking left
        while(checking.characterside>'a')
        {
            checking.characterside-=1;
            if(Board.board.get(checking).pieceOnTile == null)
            {
                Place p = new Place(checking);ret.add(p);
            }
            else if(Board.board.get(checking).pieceOnTile.team != team)
            {
                Place p = new Place(checking);ret.add(p);
                break;
            }
            else
            {
                break;
            }
        }
        checking = currentPlace;
        //Checking right
        while(checking.characterside<'h')
        {
            checking.characterside+=1;

            if(Board.board.get(checking).pieceOnTile == null)
            {
                Place p = new Place(checking);ret.add(p);
            }
            else if(Board.board.get(checking).pieceOnTile.team != team)
            {
                Place p = new Place(checking);ret.add(p);
                break;
            }
            else
            {
                break;
            }
        }
        return ret;
    }
}
