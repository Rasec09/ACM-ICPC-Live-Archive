import java.util.*;

public class Main {
	
	public static void main(String args[]){
		
		Scanner in = new Scanner(System.in);
		int T, N;
		int cubeta[] = new int[10];
		String aux;

		T = in.nextInt();
		while(T-- > 0)
		{
			N = in.nextInt();
			for(int i = 1; i <= N; i++){
				aux = String.valueOf(i);
				for(int j = 0; j < aux.length(); j++){
					switch(aux.charAt(j))
					{
						case '0':
							cubeta[0] += 1;
							break;
						case '1':
							cubeta[1] += 1;
							break;
						case '2':
							cubeta[2] += 1;
							break;
						case '3':
							cubeta[3] += 1;
							break;
						case '4':
							cubeta[4] += 1;
							break;
						case '5':
							cubeta[5] += 1;
							break;
						case '6':
							cubeta[6] += 1;
							break;
						case '7':
							cubeta[7] += 1;
							break;
						case '8':
							cubeta[8] += 1;
							break;
						case '9':
							cubeta[9] += 1;
							break;
					}
				}
			}
			
			System.out.print(cubeta[0]);
			cubeta[0] = 0;
			for(int i = 1; i < 10; i++){
				System.out.print(" "+cubeta[i]);
				cubeta[i] = 0;
			}
			System.out.println();							
		}		
	}
}
