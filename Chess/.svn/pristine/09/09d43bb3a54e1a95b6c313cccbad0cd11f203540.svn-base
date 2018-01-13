/**
 * Created by Emarik on 2/12/2016.
 */
public class Place {
    @Override
	public String toString() {
		return ""+characterside + numberside;
	}
    public Place(Place p)
    {
    	characterside = p.characterside;
    	numberside = p.numberside;
    }

	Place(char character,int number)
    {
        this.numberside = number;
        this.characterside = character;
    }
    int numberside;
    char characterside;

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;

        Place place = (Place) o;

        if (numberside != place.numberside) return false;
        return characterside == place.characterside;

    }

    @Override
    public int hashCode() {
        int result = numberside;
        result = 31 * result + (int) characterside;
        return result;
    }


}
