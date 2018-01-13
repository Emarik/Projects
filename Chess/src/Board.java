import java.util.HashMap;

/**
 * Created by Emarik on 2/10/2016.
 */
public class Board {
    Side turn = Side.LIGHT;
    static HashMap<Place,BoardTile> board = new HashMap<>(8*8);
    Board()
    {
        for(int I = 1; I<9;I++)
        {
            for(char i = 'a'; i < 'i';i++)
            {
                board.put(new Place(i,I),new BoardTile(new Place(i,I)));
            }
        }
        showBoard();
    }

    /**
     *
     * @param type The piece that is being placed
     * @param side The team that the piece is on
     * @param placement The place that the piece is being put on
     */
    public void setPiece(Piece type,Side side, Place placement )
    {
        BoardTile changingTile = board.get(placement);
        changingTile.pieceOnTile = type;
        changingTile.pieceOnTile.team = side;
        board.put(placement,changingTile);
        //System.out.println("Setting piece: " + type + " on team: " + side + " at place "+ placement.characterside+placement.numberside);
        showBoard();
    }

    /**
     *
     * @param from Place that piece is being moved from
     * @param to Place that piece is being moved to
     */
    public void movePiece(Place from, Place to)
    {
        BoardTile changingTileFrom = board.get(from);
        BoardTile changingTileTo = board.get(to);
        //if(changingTileFrom.pieceOnTile.team == turn)
        //{
            if (changingTileFrom.pieceOnTile.checkMove(from, to))
            {
                changingTileTo.pieceOnTile = changingTileFrom.pieceOnTile;
                changingTileFrom.pieceOnTile = null;
                board.put(from, changingTileFrom);
                board.put(to, changingTileTo);
                /*if(turn == Side.LIGHT)
                {
                    turn = Side.DARK;
                }
                else
                {
                    turn = Side.LIGHT;
                }*/
            }
            //System.out.println("Moving piece from " + from.characterside + from.numberside + " to place " + to.characterside + to.numberside);
        /*}
        else
        {
            System.out.println(changingTileFrom.pieceOnTile.team);
            System.out.println(turn);
            System.out.println("Wrong team taking the turn, canceling action");
        }*/
        showBoard();

    }
    /**
     *
     * @param from Place that piece is being moved from
     * @param to Place that piece is being moved to
     */
    public void capturePiece(Place from, Place to)
    {
        BoardTile changingTileFrom = board.get(from);
        BoardTile changingTileTo = board.get(to);
        //if(changingTileFrom.pieceOnTile.team == turn)
        //s{
            if (changingTileFrom.pieceOnTile.checkMove(from, to))
            {
                changingTileTo.pieceOnTile = changingTileFrom.pieceOnTile;
                changingTileFrom.pieceOnTile = null;
                board.put(from, changingTileFrom);
                board.put(to, changingTileTo);
                /*if(turn == Side.LIGHT)
                {
                    turn = Side.DARK;
                }
                else
                {
                    turn = Side.LIGHT;
                }*/
            }
            //System.out.println("Capturing piece from " + from.characterside + from.numberside + " at place " +to.characterside + to.numberside);
        /*}
        else
        {
            System.out.println(changingTileFrom.pieceOnTile.team);
            System.out.println(turn);
            System.out.println("Wrong team taking the turn, canceling action");
        }*/
        showBoard();
    }

    /**
     *
     * @param from1 Place that piece one is moving from(King)
     * @param to1 Place that piece one is moving to(King)
     * @param from2 Place that piece two is moving from(Rook)
     * @param to2 Place that piece two is moving to(Rook)
     */
    public void castlePiece(Place from1, Place to1, Place from2, Place to2)
    {
        BoardTile changingTileFrom1 = board.get(from1);
        BoardTile changingTileTo1 = board.get(to1);
        //if(changingTileFrom1.pieceOnTile.team == turn) {
            changingTileTo1.pieceOnTile = changingTileFrom1.pieceOnTile;
            changingTileFrom1.pieceOnTile = null;
            board.put(from1, changingTileFrom1);
            board.put(to1, changingTileTo1);
            BoardTile changingTileFrom2 = board.get(from2);
            BoardTile changingTileTo2 = board.get(to2);
            changingTileTo2.pieceOnTile = changingTileFrom2.pieceOnTile;
            changingTileFrom2.pieceOnTile = null;
            board.put(from2, changingTileFrom2);
            board.put(to2, changingTileTo2);
            /*if (turn == Side.LIGHT) {
                turn = Side.DARK;
            } else {
                turn = Side.LIGHT;
            }*/
        /*}
        else
        {
            System.out.println("Wrong team taking the turn, canceling action");
        }*/
        showBoard();
    }

    /**
     * Prints the board to console
     */
    public void showBoard()
    {
    	System.out.println(Board.board.get(new Place('a',2)).pieceOnTile);
        System.out.println("---------------------------");
        System.out.println("   a  b  c  d  e  f  g  h  ");
        for(int I = 1; I<9;I++)
        {
            System.out.print(I+"  ");
            for(char i = 'a'; i < 'i';i++)
            {
                System.out.print(board.get(new Place(i,I)));
            }
            System.out.println();
        }
            System.out.println("---------------------------");
    }
}
