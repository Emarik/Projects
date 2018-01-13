import java.util.ArrayList;

/**
 * Created by Emarik on 2/12/2016.
 */
public class King extends Piece {
    @Override
    public String toString()
    {
        return "King";
    }
    //public boolean checkMove(Place currentPlace, Place checkingPlace, boolean capturing)
    //{
    //    if(checkingPlace.characterside>'h' ||checkingPlace.characterside<'a'|| checkingPlace.numberside>8||checkingPlace.numberside<1)
    //    {
    //        System.out.println("The move is trying to move to a placement that is off of the board, canceling move");
    //        return false;
    //    }
    //    if(checkingPlace.characterside <= currentPlace.characterside+1&&checkingPlace.characterside >= currentPlace.characterside-1&&
    //       checkingPlace.numberside <= currentPlace.numberside+1&&checkingPlace.numberside >= currentPlace.numberside-1)
    //    {
    //        if(Board.board.get(checkingPlace).pieceOnTile.team == Board.board.get(currentPlace).pieceOnTile.team)
    //        {
    //            System.out.println("Attempting to capture own teams piece");
    //            return false;
    //        }
    //        else if(Board.board.get(checkingPlace).pieceOnTile.team == null && capturing)
    //        {
    //            System.out.println("Move said that it was capturing piece, but no piece is there");
    //            return false;
    //        }
    //        else if(Board.board.get(checkingPlace).pieceOnTile.team != null && !capturing)
    //        {
    //            System.out.println("Move did not state that there was a capture, but there is enemy piece there");
    //            return false;
    //        }
    //        else
    //        {
    //            return true;
    //        }
    //    }
    //    return false;
    //}
    public ArrayList<Place> moveables(Place currentPlace)
    {
        ArrayList ret = new ArrayList<Place>();
        Place checking = currentPlace;
        if(currentPlace.numberside+1<=8)
        {
            checking.numberside+=1;
            if(Board.board.get(checking).pieceOnTile == null)
            {
            	Place p = new Place(checking);ret.add(p);
            }
            else if(Board.board.get(checking).pieceOnTile.team != team)
            {
                Place p = new Place(checking);ret.add(p);
            }
            if(currentPlace.characterside+1 <='h')
            {
                checking.characterside+=1;
                if(Board.board.get(checking).pieceOnTile == null)
                {
                	Place p = new Place(checking);ret.add(p);
                }
                else if(Board.board.get(checking).pieceOnTile.team != team)
                {
                    Place p = new Place(checking);ret.add(p);
                }
                checking.characterside-=1;
            }
            if(currentPlace.characterside-1 >='a')
            {
                checking.characterside-=1;
                if(Board.board.get(checking).pieceOnTile == null)
                {
                	Place p = new Place(checking);ret.add(p);
                }
                else if(Board.board.get(checking).pieceOnTile.team != team)
                {
                    Place p = new Place(checking);ret.add(p);
                }
                checking.characterside+=1;
            }
            checking.numberside-=1;
        }
        if(currentPlace.numberside-1>=1)
        {
            checking.numberside-=1;
            if(Board.board.get(checking).pieceOnTile == null)
            {
            	Place p = new Place(checking);ret.add(p);
            }
            else if(Board.board.get(checking).pieceOnTile.team != team)
            {
                Place p = new Place(checking);ret.add(p);
            }
            if(currentPlace.characterside+1 <='h')
            {
                checking.characterside+=1;
                if(Board.board.get(checking).pieceOnTile == null)
                {
                	Place p = new Place(checking);ret.add(p);
                }
                else if(Board.board.get(checking).pieceOnTile.team != team)
                {
                    Place p = new Place(checking);ret.add(p);
                }
                checking.characterside-=1;
            }
            if(currentPlace.characterside-1 >='a')
            {
                checking.characterside-=1;
                if(Board.board.get(checking).pieceOnTile == null)
                {
                	Place p = new Place(checking);ret.add(p);
                }
                else if(Board.board.get(checking).pieceOnTile.team != team)
                {
                    Place p = new Place(checking);ret.add(p);
                }
                checking.characterside+=1;
            }
            checking.numberside+=1;
        }
        if(currentPlace.characterside+1<='h')
        {
            checking.characterside+=1;
            if(Board.board.get(checking).pieceOnTile == null)
            {
            	Place p = new Place(checking);ret.add(p);
            }
            else if(Board.board.get(checking).pieceOnTile.team != team)
            {
                Place p = new Place(checking);ret.add(p);
            }
            checking.characterside-=1;
        }
        if(currentPlace.characterside-1>='a')
        {
            checking.characterside-=1;
            if(Board.board.get(checking).pieceOnTile == null)
            {
            	Place p = new Place(checking);ret.add(p);
            }
            else if(Board.board.get(checking).pieceOnTile.team != team)
            {
                Place p = new Place(checking);ret.add(p);
            }
            checking.characterside+=1;
        }
        /*if(!moved)
        {
            checking.characterside+=1;
            if(Board.board.get(checking).pieceOnTile == null)
            {
                checking.characterside+=1;
                if(Board.board.get(checking).pieceOnTile == null)
                {
                    checking.characterside+=1;
                    Piece rooks = Board.board.get(checking).pieceOnTile;
                    if(rooks.getClass() == Rook.class && !rooks.moved)
                    {
                        
                    }
                }
            }
        }*/

        return ret;
    }
}
