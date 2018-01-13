import java.util.ArrayList;

/**
 * Created by Emarik on 2/12/2016.
 */
public class Pawn extends Piece {
    @Override
    public String toString()
    {
        return "Pawn";
    }
    public boolean checkMove(Place currentPlace, Place checkingPlace, boolean capturing)
    {
        if(checkingPlace.characterside>'h' ||checkingPlace.characterside<'a'|| checkingPlace.numberside>8||checkingPlace.numberside<1)
        {
            System.out.println("The move is trying to move to a placement that is off of the board, canceling move,pawn");
            return false;
        }
        int movement;
        if(Board.board.get(currentPlace).pieceOnTile.team == Side.DARK)
            movement = -1;
        else
            movement = 1;
        if(capturing)
        {
            if(checkingPlace.numberside == currentPlace.numberside+movement)
            {
                if (checkingPlace.characterside == currentPlace.characterside + 1 || checkingPlace.characterside == currentPlace.characterside - 1)
                {
                    if(Board.board.get(checkingPlace).pieceOnTile.team == null)
                    {
                        System.out.println("Attempting to take a piece when there is nothing there");
                        return false;
                    }
                    else if(Board.board.get(checkingPlace).pieceOnTile.team != Board.board.get(currentPlace).pieceOnTile.team)
                    {
                        return true;
                    }
                    else
                    {
                        System.out.println("Attempting to take a piece of your own team, denied");
                        return false;
                    }
                }
            }
            return false;
        }
        else {
            if(checkingPlace.characterside == currentPlace.characterside)
            {
                if (checkingPlace.numberside == currentPlace.numberside + movement)
                {
                    if (Board.board.get(checkingPlace).pieceOnTile == null)
                    {
                        return true;
                    }
                    else
                    {
                        System.out.println("Trying to move onto another piece as pawn without capturing");
                        return false;
                    }
                } else if (!moved) {
                    if (checkingPlace.numberside == currentPlace.numberside + movement * 2) {
                        Place oneMoveChecking = checkingPlace;
                        oneMoveChecking.numberside+=movement;
                        if(Board.board.get(oneMoveChecking).pieceOnTile!=null)
                        {
                            System.out.println("Attempting to move over a piece");
                            return false;
                        }
                        return true;
                    }
                }
            }
        }
        return false;
    }
    public ArrayList<Place> moveables(Place currentPlaces)
    {
    	Place currentPlace = new Place(currentPlaces);
        ArrayList ret = new ArrayList<Place>();
        int movement;
        if(Board.board.get(currentPlace).pieceOnTile.team == Side.DARK)
            movement = -1;
        else
            movement = 1;
        Place temp = currentPlace;
        temp.numberside+= movement;
        if(temp.numberside+movement >0 && temp.numberside+movement <9)
        {
            if (Board.board.get(temp).pieceOnTile == null)
            {
                Place p = new Place(temp);ret.add(p);
                if (!moved)
                {
                    temp.numberside += movement;
                    if (Board.board.get(temp).pieceOnTile == null)
                    {
                        Place pe = new Place(temp);ret.add(pe);
                    }
                }
            }
        }
        temp = currentPlace;
        if(temp.numberside+movement >=1 && temp.numberside+movement <=8)
        {
            temp.numberside += movement;
            if (temp.characterside + 1 <= 'h')
            {
                temp.characterside += 1;
                if (Board.board.get(temp).pieceOnTile != null && Board.board.get(temp).pieceOnTile.team != team)
                {
                    Place p = new Place(temp);ret.add(p);
                }
            }
            temp.characterside = currentPlace.characterside;
            if(temp.characterside - 1 >= 'a')
            {
                temp.characterside -=1;
                if (Board.board.get(temp).pieceOnTile != null && Board.board.get(temp).pieceOnTile.team != team)
                {
                    Place p = new Place(temp);ret.add(p);
                }
            }
        }



        return ret;
    }
}
