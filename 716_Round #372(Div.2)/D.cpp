package CodeForces;
import java.util.*;
public class CF372B {
	public static void main(String []args){
		Scanner sc=new Scanner(System.in);
		String s=sc.next();
		int n=s.length();
		int num1=0,num2=0,sta=0;
		int []h=new int[26];
		boolean judge=false;
		int []dp=new int[n];
		Arrays.fill(h, -1);
		for(int i=0;i<n;i++){
			if(num1+num2==26){
				for(int j=sta;j<i;j++){
					if(s.charAt(j)=='?'){
						for(int k=0;k<26;k++){
							if(h[k]==-1){
								h[k]=j;
								s=s.substring(0, j)+(char)(k+'A')+s.substring(j+1,n);
								break;
							}
						}
					}
				}
				judge=true;
			}
			if(judge)
				break;
			if(s.charAt(i)=='?')
				dp[i]=num2++;
			else if(h[s.charAt(i)-'A']==-1){
				h[s.charAt(i)-'A']=i;
				num1++;
				dp[i]=num2;
			}
			else if(h[s.charAt(i)-'A']!=-1){
				sta=h[s.charAt(i)-'A']+1;
				num2-=dp[h[s.charAt(i)-'A']];
				num1=i-h[s.charAt(i)-'A']-num2;
				h[s.charAt(i)-'A']=i;
			}
		}
		if(!judge&&num1+num2==26){
			for(int j=sta;j<s.length();j++){
				if(s.charAt(j)=='?'){
					for(int k=0;k<26;k++){
						if(h[k]==-1){
							h[k]=j;
							s=s.substring(0, j)+(char)(k+'A')+s.substring(j+1,n);
							break;
						}
					}
				}
			}
			judge=true;
		}
		if(judge==false)
			System.out.println(-1);
		else{
			for(int i=0;i<n;i++)
				if(s.charAt(i)=='?')
					s=s.substring(0, i)+'A'+s.substring(i+1,n);
			System.out.println(s);
		}
	}
}
