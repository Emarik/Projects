/**
 * Created by Emarik on 2/10/2016.
 */
public class BoardTile {
    BoardTile()
    {

    }
    BoardTile(Place placer)
    {
        placement = placer;
    }
    Piece pieceOnTile = null;
    Place placement;
    public Piece checkPiece()
    {
        return pieceOnTile;
    }

    @Override
    public String toString() {
        if(pieceOnTile == null)
        {
            return "   ";
        }
        String ret = "";
        if(pieceOnTile.getClass() == King.class)
        {
            ret +="K";
        }
        else if(pieceOnTile.getClass() == Queen.class)
        {
            ret += "Q";
        }
        else if(pieceOnTile.getClass() == Rook.class)
        {
            ret += "R";
        }
        else if(pieceOnTile.getClass() == Knight.class)
        {
            ret += "N";
        }
        else if(pieceOnTile.getClass() == Bishop.class)
        {
            ret += "B";
        }
        else if(pieceOnTile.getClass() == Pawn.class)
        {
            ret += "P";
        }
        if(pieceOnTile.team == Side.DARK)
        {
            ret += "d ";
        }
        else if(pieceOnTile.team == Side.LIGHT)
        {
            ret += "l ";
        }
        return ret;
    }
}
