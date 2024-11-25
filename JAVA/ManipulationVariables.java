public class ManipulationVariables
{
	public static void main(String[] args)
	{
		int	epargne = 500;
		int	revenus = 2000;
		// Ajoutez 100 à votrev épargne
		epargne = epargne + 100;
		//epargne += 100;

		//enlevez 50 à votre indemnité
		revenus = revenus - 50;
		//faites une mise à jour sur votre délai d'épargne
		int	nombreDeJoursEpargne = (5000 - revenus) / 500;
	
		//Mettez à jour à nouveau votre indemnité
		revenus = revenus + (30 - 10) * 7;
	}
}

//une string s'ecrit :
//String text = "toto";

//les constantes s'écrivent en majuscules et le type est précédé de final
//final int	NUMBEROFDAYINAWEEEK = 7;
//final	String MYFAVOURITEFOOD = "Icecream";
//int	numberOfPets = 1;
//String	currentSeason = "Winter";