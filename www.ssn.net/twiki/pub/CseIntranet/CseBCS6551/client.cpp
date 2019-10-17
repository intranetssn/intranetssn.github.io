//11

import java.util.Scanner;

public class Ceasar{
	
	public static String encrypt(String plainText,int shift){
		if(shift>26){
			shift = shift%26;
		}
		else if(shift<0){
			shift = (shift%26)+26;
		}
		String cipherText = "";
		int length = plainText.length();
		for(int i=0;i<length;i++){
			char ch = plainText.charAt(i);
			if(Character.isLetter(ch)){
				if(Character.isLowerCase(ch)){
					char c = (char)(ch+shift);
					if(c>'z'){
						cipherText += (char)(ch - (26-shift));
					}
					else{
						cipherText += c;
					}
				}
				else if(Character.isUpperCase(ch)){
					char c = (char)(ch+shift);
					if(c>'Z'){
						cipherText += (char)(ch - (26-shift));
					}
					else{
						cipherText += c;
					}
					
				}
			}
			else {
				cipherText += ch;	
			}
			
		}
		return cipherText;
		
	}
	public static String decrypt(String cipherText,int shift){
		if(shift>26){
			shift = shift%26;
		}
		else if(shift<0){
			shift = (shift%26)+26;
		}
		String plainText = "";
		int length = cipherText.length();
		for(int i=0;i<length;i++){
			char ch = cipherText.charAt(i);
			if(Character.isLetter(ch)){
				if(Character.isLowerCase(ch)){
					char c = (char)(ch-shift);
					if(c<'a'){
						plainText += (char)(ch + (26-shift));
					}
					else{
						plainText += c;
					}
				}
				else if(Character.isUpperCase(ch)){
					char c = (char)(ch-shift);
					if(c<'A'){
						plainText += (char)(ch + (26-shift));
					}
					else{
						plainText += c;
					}
					
				}
			}
			else {
				plainText += ch;	
			}
		}
		return plainText;
		
	}
        public static void cryptAnalysis(String cipherText){
            for(int shift = 1;shift < 26;shift++){
            System.out.println("shift:" + shift + "==" + decrypt(cipherText,shift) );
            }
        
        
        }
	
	public static void main(String[] args){
		
		Scanner in  = new Scanner(System.in);
		System.out.println("Enter the Plaintext:");
		String text = in.nextLine();
		System.out.println("Enter the shiftKey");
		int shiftnum = in.nextInt();
		String cipher = encrypt(text,shiftnum);
		System.out.println(cipher);
		System.out.println("Do You want to decrypt(press d) for cryptanalysis(press c)");
		char choice = in.next().charAt(0);
                switch(choice){
                    case 'd': String plainText = decrypt(cipher,shiftnum);
                            System.out.println(plainText);
                            break;
                        
                    case 'c':cryptAnalysis(cipher);
                            break;
                    default:System.out.println("WRONG CHOICE");
                            break;
                }
                
                
  
	}
	
	
}




//22 ********************************************************



import java.awt.Point;
import java.util.Scanner;

public class PlayFairCipher{
  
    
    
  private int length = 0;
  private String [][] table;
  
  
  public static void main(String[] args){
    PlayFairCipher pf = new PlayFairCipher();
  }
  
  
  private PlayFairCipher(){
  
    
    System.out.println("Enter the keyword");
    Scanner sc = new Scanner(System.in);
    String keyword = parseString(sc);
    while(keyword.equals(""))
      keyword = parseString(sc);
    System.out.println();
    table = this.cipherTable(keyword);
     
       
    System.out.println("Enter the message to encrypt");
    String input = parseString(sc);
    while(input.equals(""))
      input = parseString(sc);
    System.out.println();
    
        
    this.printTable(table);
    String output = encrypt(input);
    this.printResultsEncoded(output);
    System.out.println("Do u want to Decrypt y==yes||n=no");
    char choice = sc.next().charAt(0);
    if(choice=='y'||choice=='Y'){
    String decryptedOutput = decrypt(output);
    this.printResultsDecoded(decryptedOutput);
    }
    else if(choice=='n'||choice=='N'){
    System.exit(0);
    }
  }
  

  private String parseString(Scanner s){
    String parse = s.nextLine();
    parse = parse.toUpperCase();
    parse = parse.replaceAll("[^A-Z]", "");
    parse = parse.replace("I", "J");
    return parse;
  }
  
  
  private String[][] cipherTable(String key){
    String[][] playfairTable = new String[5][5];
    String keyString = key + "ABCDEFGHIKLMNOPQRSTUVWXYZ";
    

    for(int i = 0; i < 5; i++)
      for(int j = 0; j < 5; j++)
        playfairTable[i][j] = "";
    
    for(int k = 0; k < keyString.length(); k++){
      boolean repeat = false;
      boolean used = false;
      for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
          if(playfairTable[i][j].equals("" + keyString.charAt(k))){
            repeat = true;
          }else if(playfairTable[i][j].equals("") && !repeat && !used){
            playfairTable[i][j] = "" + keyString.charAt(k);
            used = true;
          }
        }
      }
    }
    return playfairTable;
  }
  

  private String encrypt(String in){
    length = (int) in.length() / 2 + in.length() % 2;       /*count length*/
    
 
    for(int i = 0; i < (length - 1); i++){
      if(in.charAt(2 * i) == in.charAt(2 * i + 1)){         /*Checking next char is repeated one or not?*/
        in = new StringBuffer(in).insert(2 * i + 1, 'X').toString();    /*if then insert X to that position*/
        length = (int) in.length() / 2 + in.length() % 2;       /*recount length()*/
      }
    }
    
 
    String[] digraph = new String[length];
    for(int j = 0; j < length ; j++){
      if(j == (length - 1) && in.length() / 2 == (length - 1))
        in = in + "X";
      digraph[j] = in.charAt(2 * j) +""+ in.charAt(2 * j + 1);
    }
    
    
    String out = "";
    String[] encDigraphs = new String[length];
    encDigraphs = encodeDigraph(digraph);
    for(int k = 0; k < length; k++)
      out = out + encDigraphs[k];
    return out;
  }
  

  private String[] encodeDigraph(String di[]){
    String[] enc = new String[length];
    for(int i = 0; i < length; i++){
      char a = di[i].charAt(0);
      char b = di[i].charAt(1);
      int r1 = (int) getPoint(a).getX();
      int r2 = (int) getPoint(b).getX();
      int c1 = (int) getPoint(a).getY();
      int c2 = (int) getPoint(b).getY();
      
      
      if(r1 == r2){
        c1 = (c1 + 1) % 5;
        c2 = (c2 + 1) % 5;
        
      
      }else if(c1 == c2){
        r1 = (r1 + 1) % 5;
        r2 = (r2 + 1) % 5;
      
      
      }else{
        int temp = c1;
        c1 = c2;
        c2 = temp;
      }
      
      
      enc[i] = table[r1][c1] + "" + table[r2][c2];
    }
    return enc;
  }
  
  
  private String decrypt(String out){
    String decoded = "";
    for(int i = 0; i < out.length() / 2; i++){
      char a = out.charAt(2*i);
      char b = out.charAt(2*i+1);
      int r1 = (int) getPoint(a).getX();
      int r2 = (int) getPoint(b).getX();
      int c1 = (int) getPoint(a).getY();
      int c2 = (int) getPoint(b).getY();
      if(r1 == r2){
        c1 = (c1 + 4) % 5;
        c2 = (c2 + 4) % 5;
      }else if(c1 == c2){
        r1 = (r1 + 4) % 5;
        r2 = (r2 + 4) % 5;
      }else{
        int temp = c1;
        c1 = c2;
        c2 = temp;
      }
      decoded = decoded + table[r1][c1] + table[r2][c2];
    }
    return decoded;
  }
  
  
  private Point getPoint(char c){
    Point pt = new Point(0,0);
    for(int i = 0; i < 5; i++)
      for(int j = 0; j < 5; j++)
        if(c == table[i][j].charAt(0))
          pt = new Point(i,j);
    return pt;
  }
  
  
  private void printTable(String[][] printedTable){
    System.out.println("This is the cipher table from the given keyword.");
    System.out.println();
    
    for(int i = 0; i < 5; i++){
      for(int j = 0; j < 5; j++){
        System.out.print(printedTable[i][j]+" ");
      }
      System.out.println();
    }
    System.out.println();
  }
  
  
  private void printResultsEncoded(String enc){
    System.out.println("This is the encoded message:");
    System.out.println(enc);
    System.out.println();
  }
  
  private void printResultsDecoded(String dec){
      System.out.println("This is the decoded mesage");
      System.out.println(dec);
  }
  
}



	
//33 *************************************************************

import java.util.*;
import java.lang.*;

class Hill{
static Scanner scanner;
static char[] plainText;
static char[] cipherText;
static char[] key;
static int temp;
static String ch;
static int opt,i,j,k,l,n,m,q;
static char[][] matrix;
static char[][] matrixInverse;
static char[][] plainTextMatrix;
static char[][] cipherTextMatrix;
static List<Character> alphabetsList;
static List<Character> keyList;
static List<Character> differenceList;
static List<Character> plainTextList;
static List<Character> cipherTextList;

public static void main(String[] args){
scanner = new Scanner(System.in);

do{
matrix = new char[5][5];
System.out.println("Enter key: ");
key = scanner.nextLine().replace(" ","").toCharArray();

n = (int)Math.sqrt(key.length);
matrix = findMatrix(key);

//Debug
for(i=0;i<n;i++)
{
for(j=0;j<n;j++)
{
System.out.print(matrix[i][j] + " ");
}
System.out.println(" ");
}

System.out.println("1.Encode\n2.Decode\nEnter option: ");
opt = Integer.parseInt(scanner.nextLine());

if(opt == 1)
{
System.out.println("Enter plain text: ");
plainText = scanner.nextLine().replace(" ","").toCharArray();
encode();
}
else
{
System.out.println("Enter cipher text: ");
cipherText = scanner.nextLine().replace(" ","").toCharArray();
decode();
}

System.out.println("Do you want to continue(y/n): ");
ch = scanner.nextLine();

}while(!ch.equals("n"));
}

public static char[][] findMatrix(char[] charArray){
char[][] tempMatrix = new char[n][n];
l = 0;

for(i=0;i<n;i++)
{
for(j=0;j<n;j++)
{
tempMatrix[i][j] = charArray[l];
l++;
}
}

return tempMatrix;
}

public static char[][] findMatrix1(char[] charArray){
q = charArray.length;
m = (int)Math.ceil(((double)(q)/n));
System.out.println(m);
char[][] tempMatrix = new char[n][m];
l = 0;

for(i=0;i<m;i++)
{
for(j=0;j<n;j++)
{
if(l<q)
{
tempMatrix[j][i] = charArray[l];
l++;
}
else
{
tempMatrix[j][i] = 'x';
}
}
}

return tempMatrix;
}

public static void encode(){
plainTextMatrix = findMatrix1(plainText);
cipherTextMatrix = new char[n][m];

//Debug
for(i=0;i<n;i++)
{
for(j=0;j<m;j++)
{
System.out.print(plainTextMatrix[i][j] + " ");
}
System.out.println(" ");
}

int sum = 0;

for(i=0;i<n;i++)
{
for(j=0;j<m;j++)
{
for(k=0;k<n;k++)
{
sum = sum + toASCII(matrix[i][k])*toASCII(plainTextMatrix[k][j]);
}
//System.out.println(sum);
cipherTextMatrix[i][j] = toChar(sum);
          sum = 0;
}
}

//Debug
System.out.println(" ");
for(i=0;i<n;i++)
{
for(j=0;j<m;j++)
{
System.out.print(cipherTextMatrix[i][j] + " ");
}
System.out.println(" ");
}

for(i=0;i<m;i++)
{
for(j=0;j<n;j++)
{
System.out.print(cipherTextMatrix[j][i]);
}
}
}

public static int toASCII(char ch){
int a = 0;
a = (int)(ch)-97;
//System.out.println(a);
return a;
}

public static char toChar(int ascii){
char ch;
ch = (char)((ascii%26)+97);
return ch;
}

public static void decode(){
matrixInverse = findInverse(matrix);


cipherTextMatrix = findMatrix1(cipherText);
plainTextMatrix = new char[n][m];

//Debug
for(i=0;i<n;i++)
{
for(j=0;j<m;j++)
{
System.out.print(cipherTextMatrix[i][j] + " ");
}
System.out.println(" ");
}

int sum = 0;

for(i=0;i<n;i++)
{
for(j=0;j<m;j++)
{
for(k=0;k<n;k++)
{
sum = sum + toASCII(matrixInverse[i][k])*toASCII(cipherTextMatrix[k][j]);
}
//System.out.println(sum);
plainTextMatrix[i][j] = toChar(sum);
          sum = 0;
}
}

//Debug
System.out.println(" ");
for(i=0;i<n;i++)
{
for(j=0;j<m;j++)
{
System.out.print(plainTextMatrix[i][j] + " ");
}
System.out.println(" ");
}

for(i=0;i<m;i++)
{
for(j=0;j<n;j++)
{
System.out.print(plainTextMatrix[j][i]);
}
}

}

public static char[][] findInverse(char[][] mat){
char[][] tempMatrix = new char[n][n];
float det = 0;
int detInverse = 0;
for(i = 0; i < 3; i++)
       det = det + (toASCII(mat[0][i])) * (toASCII(mat[1][(i+1)%3]) * toASCII(mat[2][(i+2)%3]) - toASCII(mat[1][(i+2)%3]) * toASCII(mat[2][(i+1)%3]));

det = det%26;
                if(det < 0)
                    det += 26;
detInverse = findDetInverse(det);

System.out.println("\ndeterminant = " + det);
System.out.println("\ndeterminant inverse = " + detInverse);

//System.out.println("\nInverse of matrix is:");
for(i = 0; i < 3; ++i)
{
for(j = 0; j < 3; ++j)
{
tempMatrix[i][j] = formatASCII((toASCII(mat[(j+1)%3][(i+1)%3]) * toASCII(mat[(j+2)%3][(i+2)%3])) - (toASCII(mat[(j+1)%3][(i+2)%3]) * toASCII(mat[(j+2)%3][(i+1)%3])));
tempMatrix[i][j] = toChar(toASCII(tempMatrix[i][j]) * detInverse);
}

}

return tempMatrix;
}

public static char formatASCII(float ascii){
char ch;
System.out.print(ascii + " ");
if(ascii < 0)
ascii = (ascii%26) + 26;
ch = (char)((ascii%26)+97);
System.out.print(ascii + " " + ch);
System.out.println("");
return ch;
}

static int findDetInverse(float a)
    {
        a = a % 26;
        for (int x = 1; x < 26; x++)
           if ((a * x) % 26 == 1)
              return x;
        return 1;
    }
}



//44 *******************************************************

package vigenere;


import java.util.*;
public class Vigenere {

   
    public static void main(String[] args) {
        // TODO code application logic here
        char mat[][]=new char[26][26];
        String text,key=null;
        char key1[]=new char[100];
        
        int choice,n1=0,n2=0;
        Scanner myscanner=new Scanner(System.in);
        while(true)
        {
        System.out.println("1.Encrypt\n2.Decrypt\nEnter your choice : ");
        choice=myscanner.nextInt();
        myscanner.nextLine();
        if(choice==1)
        {
        System.out.println("Enter the plain text message : ");
        text=myscanner.nextLine();
        System.out.println("Enter the key : ");
        key=myscanner.nextLine();
        char alpha;
        n1=text.length();n2=key.length();
        if(n2<n1)
        {
            for(int i=0;i<n2;i++)
                key1[i]=key.charAt(i);
            int p=0;
            for(int i=n2;i<=n1;i++)
            {
                key1[i]=key.charAt(p++);
                if(p>=n2)
                    p=0;
            }
        }
        key1[n1]='\0';
        for(int i=0;i<=n1;i++)
            {
            System.out.println(key1[i]);
            }
        for(int i=0;i<26;i++)
        {
            alpha='A';
            for(int j=0,k=i;j<26;j++,k++)
            {
                if(k+65<=90)
                mat[i][j]=(char)(k+65);
                else
                mat[i][j]=alpha++;
            }
        }
        
       for(int i=0;i<26;i++)
        {
            for(int j=0;j<26;j++)
            {
              System.out.print(mat[i][j]+" ");
          
            }System.out.print("\n");
        }
       
       int row=0,col=0;
       for(int c=0;c<n1;c++)
       {
        for(int i=0;i<26;i++)
        {
                if(text.charAt(c)==i+65)
                {row=i;break;}
        }   
        
        for(int i=0;i<26;i++)
        {
                if(key1[c]==i+65)
                {col=i;break;}
        }
        System.out.print(mat[row][col]);
    
       }System.out.print("\n");
    
       
    }else if(choice==2)
    {
        System.out.print("Enter the cipher text to decrypt : ");
        String str=myscanner.nextLine();
        for(int c=0;c<str.length();c++)
        {
        for(int i=0;i<26;i++)
        {
            if(key1[c]==i+65)
            {
                for(int j=0;j<26;j++)
                {
                    if(str.charAt(c)==mat[i][j])
                    {System.out.print((char)(j+65));break;}  
                }break;
            }
        }
        
        
    }
        System.out.print("\n");
        
        }else break;
    }
    
}
}



//55 ********************************************************

import java.util.*;
public class RailFence {

     public static void main(String[] args) {
        // TODO code application logic here
        String text;
        String decrypt; 
        int count=0,temp=0,ct=0;
        
        int key=0,choice;
        char str[]=new char[100];int c=0;
        
        Scanner myscanner=new Scanner(System.in);
        while(true)
        {
        System.out.println("1.Encrypt\n2.Decrypt\nEnter your choice");
        choice=myscanner.nextInt();
        if(choice==1)
        {
        myscanner.nextLine();
        System.out.println("Enter the plain text : ");
        text=myscanner.nextLine();
        System.out.println("Enter the depth : ");
        key=myscanner.nextInt();
        char mat[][]=new char[key][text.length()];
        while(ct<text.length())
        {
            if(count<key)
            {
                mat[count][ct]=text.charAt(temp++);
                count++;ct++;
            }
            else {
            count=0;
            }
          }
        
        for(int i=0;i<key;i++)
        {
            for(int j=0;j<text.length();j++)
                System.out.print(mat[i][j]+" ");
            System.out.print("\n");
            
        }
         for(int i=0;i<key;i++)
        {
            for(int j=0;j<text.length();j++)
            {
                if(mat[i][j]!='\0')
                {
                   str[c++]=mat[i][j]; 
                }
            }
        }
         str[c]='\0';
         
         System.out.println("Cipher text:");
         for(int i=0;i<str.length;i++)
        {
            System.out.print(str[i]);
        }
         System.out.print("\n");
        }
        
         //DECRYPT
        else if(choice==2)
        {
        myscanner.nextLine();
        System.out.println("Enter the cipher text:");
         
        decrypt=myscanner.nextLine();
        char matrix[][]=new char[key][decrypt.length()];
         ct=0;count=0;
         while(ct<decrypt.length())
        {
            if(count<key)
            {
                matrix[count][ct]='*';
                count++;ct++;
            }
            else {
            count=0;
            }
        }
        
        
        int counter=0;
        for(int i=0;i<key;i++)
        {
            for(int j=0;j<decrypt.length();j++)
            {
                if(matrix[i][j]=='*')
                {
                    matrix[i][j]=decrypt.charAt(counter++);
                }
            }
        }
        
        ct=0;count=0;
        System.out.println("Plain text:");
        while(ct<decrypt.length())
        {
            if(count<key)
            {
                System.out.print(matrix[count][ct]);
                count++;ct++;
            }
            else {
            count=0;
            }
        }
        System.out.print("\n");
            
        
        }
        else break;
         
        } 
      }
   }
   
 

 
 //66 ********************************************************
import java.util.*;
public class RowColCipher {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        //TODO code application logic here
        String key=null,text;
        Scanner myscanner=new Scanner(System.in);
        int count=0;
        int p=0,c=0;
        int counter=0,choice;
        
        
        while(true)
        {
        
        System.out.println("1.Encrypt\n2.Decrypt\nEnter your choice : ");
        choice=myscanner.nextInt();
        
        if(choice==1)
        {
        char mat[][]=new char[100][100];
        char tempstr[]=new char[100];
        
        myscanner.nextLine();
        System.out.println("Enter the plain text :");
        text=myscanner.nextLine();
        System.out.println("Enter the key :");
        key=myscanner.nextLine();
        char encrypt[]=new char[text.length()];        
        
        count=0;
        counter=0;
        p=0;
        c=0;
        
        while(count<text.length())
        {
            for(int j=0;j<key.length();j++)
            { 
                if(count<text.length())
                mat[c][j]=text.charAt(count++);
            }c++;
        }
        c--;
        
        while(p<=c)
        {
            for(int j=0;j<key.length();j++)
            {
               System.out.print(mat[p][j]+" ");
            }
            p++;
            System.out.print("\n");
        }
        
        
        
        for(int i=0;i<key.length();i++)
        tempstr[i]=key.charAt(i);
        
        Arrays.sort(tempstr);
        counter=0;
        
        for(int i=0;i<tempstr.length;i++)
        {
            for(int j=0;j<key.length();j++)
            {
            if(tempstr[i]==key.charAt(j))
            {
                p=0;
                while(p<=c && counter<text.length())
                {
                    encrypt[counter++]=mat[p][j];
                    p++;
                }
             break;
            }
            }
        }

        for(int i=0;i<encrypt.length;i++)
        System.out.print(encrypt[i]);
        
        System.out.print("\n\n");
        }
        else if(choice==2)
        {
        char tempstr[]=new char[100];
        
        for(int i=0;i<key.length();i++)
        tempstr[i]=key.charAt(i);
        
        Arrays.sort(tempstr);
        
        //decrypt*******************************************************
        counter=0;
        char encrypt[]=new char[100];
        char mat1[][]=new char[100][100];
        
        myscanner.nextLine();
        System.out.println("Enter the cipher text :");
        text=myscanner.nextLine();
        
        for(int i=0;i<text.length();i++)
            encrypt[i]=text.charAt(i);
        
       
        for(int i=0;i<tempstr.length;i++)
        {
            for(int j=0;j<key.length();j++)
            {
            if(tempstr[i]==key.charAt(j))
            {
                p=0;
                while(p<=c && counter<encrypt.length-1)
                {
                    mat1[p][j]=encrypt[counter++];
                    p++;
                }
             break;
            }
            }
        }
        p=0;
        while(p<=c)
        {
            for(int j=0;j<key.length();j++)
            {
               System.out.print(mat1[p][j]);
            }
            p++;
        }
        System.out.print("\n");
        
        
        }
        else break;
        }
          
    }
    
}



\\77 *****************************************************

mport java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Scanner;


public class DES {
            static Scanner scanner;

    public static String hex2bin(String s){
        // hexadecimal to binary conversion
    Map<Character,String> mp=new HashMap<Character,String>();
    mp.put('0',"0000");
    mp.put('1',"0001");
    mp.put('2',"0010");
    mp.put('3',"0011");
    mp.put('4',"0100");
    mp.put('5',"0101");
    mp.put('6',"0110");
    mp.put('7',"0111");
    mp.put('8',"1000");
    mp.put('9',"1001");
    mp.put('A',"1010");
    mp.put('B',"1011");
    mp.put('C',"1100");
    mp.put('D',"1101");
    mp.put('E',"1110");
    mp.put('F',"1111");
   
    String bin="";
    for(int i=0; i<s.length(); i++){
        bin+= mp.get(s.charAt(i));
    }
    return bin;
}
public static String bin2hex(String s){
        // binary to hexadecimal conversion
    Map<String,String> mp=new HashMap<String,String>();
    mp.put("0000","0");
    mp.put("0001","1");
    mp.put("0010","2");
    mp.put("0011","3");
    mp.put("0100","4");
    mp.put("0101","5");
    mp.put("0110","6");
    mp.put("0111","7");
    mp.put("1000","8");
    mp.put("1001","9");
    mp.put("1010","A");
    mp.put("1011","B");
    mp.put("1100","C");
    mp.put("1101","D");
    mp.put("1110","E");
    mp.put("1111","F");
    String hex="";
    for(int i=0; i<s.length(); i+=4){
        String ch="";
        ch+= s.charAt(i);
        ch+= s.charAt(i+1);
        ch+= s.charAt(i+2);
        ch+= s.charAt(i+3);  
        hex+= mp.get(ch);
    }
    return hex;
}

    public static String permute(String k, int[] arr, int n){
    String per="";
    for(int i=0; i<n ; i++){
        per+= k.charAt(arr[i]-1);
    }
    return per;
}
    public static String shift_left(String k, int shifts){
    String s="";
    for(int i=0; i<shifts; i++){
        for(int j=1; j<28; j++){
            s+= k.charAt(j);
        }
        s+= k.charAt(0);
        k=s;
        s="";
    }
    return k;
}
   
    public static String xor_(String a, String b){
    String ans= "";
    for(int i=0; i<a.length(); i++){
        if(a.charAt(i)==b.charAt(i)){
            ans+= "0";
        }else{
            ans+= "1";
        }
    }
    return ans;
}
    public static String encrypt(String pt, List<String> rkb, List<String> rk)
    {
        pt= hex2bin(pt);
        int initial_perm[]=  
    {   58,50,42,34,26,18,10,2,
        60,52,44,36,28,20,12,4,
        62,54,46,38,30,22,14,6,
        64,56,48,40,32,24,16,8,
        57,49,41,33,25,17,9,1,
        59,51,43,35,27,19,11,3,
        61,53,45,37,29,21,13,5,
        63,55,47,39,31,23,15,7
    };
    //Initial Permutation
    pt= permute(pt, initial_perm, 64);
        System.out.println("after IP: "+bin2hex(pt));
    String left= pt.substring(0, 32);
    String right= pt.substring(32, 64);
        System.out.println("left:"+bin2hex(left)+" right:"+bin2hex(right));
    int exp_d[]=  
    {   32,1,2,3,4,5,4,5,
        6,7,8,9,8,9,10,11,
        12,13,12,13,14,15,16,17,
        16,17,18,19,20,21,20,21,
        22,23,24,25,24,25,26,27,
        28,29,28,29,30,31,32,1
    };
     
    //S-box Table
    int s[][][]=
    {{
        {14,4,13,1,2,15,11,8,3,10,6,12,5,9,0,7},
        {0,15,7,4,14,2,13,1,10,6,12,11,9,5,3,8} ,
        {4,1,14,8,13,6,2,11,15,12,9,7,3,10,5,0} ,
        {15,12,8,2,4,9,1,7,5,11,3,14,10,0,6,13}
    },
    {
        {15,1,8,14,6,11,3,4,9,7,2,13,12,0,5,10} ,
        {3,13,4,7,15,2,8,14,12,0,1,10,6,9,11,5} ,
        {0,14,7,11,10,4,13,1,5,8,12,6,9,3,2,15} ,
        {13,8,10,1,3,15,4,2,11,6,7,12,0,5,14,9}
    },
 
    {
        {10,0,9,14,6,3,15,5,1,13,12,7,11,4,2,8},
        {13,7,0,9,3,4,6,10,2,8,5,14,12,11,15,1},
        {13,6,4,9,8,15,3,0,11,1,2,12,5,10,14,7},
        {1,10,13,0,6,9,8,7,4,15,14,3,11,5,2,12}
    },
    {
        {7,13,14,3,0,6,9,10,1,2,8,5,11,12,4,15},
        {13,8,11,5,6,15,0,3,4,7,2,12,1,10,14,9},
        {10,6,9,0,12,11,7,13,15,1,3,14,5,2,8,4},
        {3,15,0,6,10,1,13,8,9,4,5,11,12,7,2,14}
    },
    {
        {2,12,4,1,7,10,11,6,8,5,3,15,13,0,14,9},
        {14,11,2,12,4,7,13,1,5,0,15,10,3,9,8,6},
        {4,2,1,11,10,13,7,8,15,9,12,5,6,3,0,14},
        {11,8,12,7,1,14,2,13,6,15,0,9,10,4,5,3}
    },
    {
        {12,1,10,15,9,2,6,8,0,13,3,4,14,7,5,11},
        {10,15,4,2,7,12,9,5,6,1,13,14,0,11,3,8},
        {9,14,15,5,2,8,12,3,7,0,4,10,1,13,11,6},
        {4,3,2,12,9,5,15,10,11,14,1,7,6,0,8,13}
    },
    {
        {4,11,2,14,15,0,8,13,3,12,9,7,5,10,6,1},
        {13,0,11,7,4,9,1,10,14,3,5,12,2,15,8,6},
        {1,4,11,13,12,3,7,14,10,15,6,8,0,5,9,2},
        {6,11,13,8,1,4,10,7,9,5,0,15,14,2,3,12}
    },
    {
        {13,2,8,4,6,15,11,1,10,9,3,14,5,0,12,7},
        {1,15,13,8,10,3,7,4,12,5,6,11,0,14,9,2},
        {7,11,4,1,9,12,14,2,0,6,10,13,15,3,5,8},
        {2,1,14,7,4,10,8,13,15,12,9,0,3,5,6,11}
    }};
     
        int per[]=
    {   16,7,20,21,
        29,12,28,17,
        1,15,23,26,
        5,18,31,10,
        2,8,24,14,
        32,27,3,9,
        19,13,30,6,
        22,11,4,25
    };
   
    for(int j=0;j<16;j++)
        {
            String right_expanded= permute(right, exp_d, 48);
            String x= xor_(rkb.get(j), right_expanded);
            String op="";
            for(int i=0;i<8; i++){
            int row= 2*(x.charAt(i*6)-'0')+ (x.charAt(i*6 +5)-'0');
            int col= 8*(x.charAt(i*6 +1)-'0')+ 4*(x.charAt(i*6 +2)-'0')+  
                                 2*(x.charAt(i*6 +3)-'0')+ (x.charAt(i*6 +4)-'0');
            int val= s[i][row][col];
            op+= (char)(val/8+ '0');
            val= val%8;
            op+= (char)(val/4+ '0');
            val= val%4;
            op+= (char)(val/2+ '0');
            val= val%2;
            op+= (char)(val+ '0');

        }
           
            op= permute(op, per, 32);
     
        x= xor_(op, left);
          //System.out.println(bin2hex(left)+" "+bin2hex(right));
        left= x;
         
        //Swapper
           // System.out.println(bin2hex(left)+" "+bin2hex(right));
        if(j!= 15){
             left = left + right;
            right = left.substring(0,left.length()-right.length());
            left = left.substring(right.length());
        }

            System.out.println("K"+(j+1)+" "+rkb.get(j));
            //" "+bin2hex(left)+" "+bin2hex(right)+" "+
        }
    String combine= left+right;
    int final_perm[]=  
    {   40,8,48,16,56,24,64,32,
        39,7,47,15,55,23,63,31,
        38,6,46,14,54,22,62,30,
        37,5,45,13,53,21,61,29,
        36,4,44,12,52,20,60,28,
        35,3,43,11,51,19,59,27,
        34,2,42,10,50,18,58,26,
        33,1,41,9,49,17,57,25
    };
     
    String cipher= bin2hex(permute(combine, final_perm, 64));
    return cipher;
    }
    public static void main(String[] args) {
        String plainText="",key,cipherText="";
        scanner = new Scanner(System.in);
        System.out.println("Enter plain text:");
        plainText+=scanner.nextLine();
       
      plainText=   plainText.replaceAll("\\s","");
int len = plainText.length();
int addzeros=16-(len%16);
for(int i=0;i<addzeros;i++)
    plainText+="0";


        System.out.println("Enter key:");
        key=scanner.nextLine();

        key= hex2bin(key);
        //System.out.println(key);
       
    int keyp[]={57,49,41,33,25,17,9,
        1,58,50,42,34,26,18,
        10,2,59,51,43,35,27,
        19,11,3,60,52,44,36,          
        63,55,47,39,31,23,15,
        7,62,54,46,38,30,22,
        14,6,61,53,45,37,29,
        21,13,5,28,20,12,4
    };
    key= permute(key, keyp, 56);
   
    //Number of bit shifts  
    int shift_table[]=
    {   1, 1, 2, 2,
        2, 2, 2, 2,  
        1, 2, 2, 2,  
        2, 2, 2, 1
    };
     
    //Key- Compression Table
    int key_comp[]=
    {   14,17,11,24,1,5,
        3,28,15,6,21,10,
        23,19,12,4,26,8,
        16,7,27,20,13,2,
        41,52,31,37,47,55,
        30,40,51,45,33,48,
        44,49,39,56,34,53,
        46,42,50,36,29,32
    };
     
    //Splitting
    String left= key.substring(0, 28);
    String right= key.substring(28, 56);
   
    List<String> rk=new ArrayList<String>();
    List<String> rkb=new ArrayList<String>();
    for(int i=0;i<16;i++)
        {
            left= shift_left(left, shift_table[i]);
            right= shift_left(right, shift_table[i]);
            String combine= left + right;
            String RoundKey= permute(combine, key_comp, 48);
            rkb.add(RoundKey);
            rk.add(bin2hex(RoundKey));
        }
    for(int i=0;i<plainText.length();i+=16)
    {
        String pt=plainText.substring(i,i+16);
        cipherText+=encrypt(pt, rkb, rk)+" ";
    }
    System.out.println("ciphertext: "+cipherText);
    cipherText=   cipherText.replaceAll("\\s","");
    Collections.reverse(rk);
    Collections.reverse(rkb);
    plainText="";
    for(int i=0;i<cipherText.length();i+=16)
    {
            String ct=cipherText.substring(i,i+16);
            plainText+= encrypt(ct, rkb, rk)+" ";
    }
    System.out.println("Decryption"+"\n"+"plaintext: "+plainText);
    }
}





\\88 *************************************************** 

import java.math.BigInteger;
import java.util.*;

public class RSA {

        public static void main(String[] args) {
        
        String str;
        Scanner input=new Scanner(System.in);
        System.out.println("Enter Text:\t");
        str=input.nextLine();
        String str2="1";
        for(int i=0; i<str.length(); i++){
            int num=((int)str.charAt(i))-64;
            if(num<10){
                str2+="0";
            }
            str2+=num;
        }
        System.out.println("Message="+str2);
            BigInteger p;//15487039//15487049
            BigInteger q;
            Random rand = new Random();
            p=BigInteger.probablePrime(2048, rand);
        q=p.nextProbablePrime();
        BigInteger n = p.multiply(q);
        System.out.println("p="+p);
        System.out.println("q="+q);
        System.out.println("n="+n);
                       
        BigInteger phi = new BigInteger("1");
        phi = (p.subtract(phi)).multiply(q.subtract(phi));
        System.out.println("phi="+phi);
        
		BigInteger e =BigInteger.probablePrime(1024, rand);
                
        while(phi.gcd(e).compareTo(BigInteger.ONE)>0 && e.compareTo(phi)<0){
            e.add(BigInteger.ONE);
        }
                
        System.out.println("e="+e);
        BigInteger d=e.modInverse(phi);
        System.out.println("d="+d);
        
        BigInteger m=new BigInteger(str2),
        et=m.modPow(e, n),dt;
        
        System.out.println("et="+et);
        dt=et.modPow(d, n);
        System.out.println("dt="+dt);
        String str3=dt.toString();
        for(int i=1; i<str3.length(); i+=2){
            char c=(char) (Integer.parseInt(str3.substring(i, i+2))+64);
            System.out.print(c);
        }
    }
    }

	
\\99 ********************************************************

import java.util.Scanner;
import java.math.BigInteger;

public class DiffieHell {

    public static void main(String args[])
 {
 Scanner sc=new Scanner(System.in);
 
 System.out.println("Enter modulo(p)");
 int p=sc.nextInt();
 System.out.println("Enter primitive root of "+p);
 int g=sc.nextInt();
 System.out.println("Choose 1st secret no(Alice)");
 int a=sc.nextInt();
 System.out.println("Choose 2nd secret no(BOB)");
 int b=sc.nextInt();
 
 int A = (int)Math.pow(g,a)%p;
 int B = (int)Math.pow(g,b)%p;
 
 int S_A = (int)Math.pow(B,a)%p;
 int S_B =(int)Math.pow(A,b)%p; 
 
 if(S_A==S_B)
 {
 System.out.println("Alice and Bob can communicate with each other!!!");
 System.out.println("They share a secret no = "+S_A); 
 }
 
 else
 {
 System.out.println("ALice and Bob cannot communicate with each other!!!");
 }
 } 
}



\\10 *************************************************
package md5;

import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.Scanner;

public class MD5 {
   
    private static BigInteger init_A;
    private static BigInteger init_B;
    private static BigInteger init_C;
    private static BigInteger init_D;
     
  private static final int[] shift = {
    7, 12, 17, 22,
    5,  9, 14, 20,
    4, 11, 16, 23,
    6, 10, 15, 21
  };
 
  private static final int[] k={
    0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,
      1,6,11,0,5,10,15,4,9,14,3,8,13,2,7,12,
      5,8,11,14,1,4,7,10,13,0,3,6,9,12,15,2,
      0,7,14,5,12,3,10,1,8,15,6,13,4,11,2,9
  };
 
 
 static double x;
  private static final String[] table_t = new String[64];
  private static final String[] T=new String [64];
  static
  {
    for (int i = 0; i < 64; i++)
    {
        String s="4294967296";
    BigDecimal p=new BigDecimal(s);
    BigDecimal q=BigDecimal.valueOf(Math.abs(Math.sin(i+1)));
     BigInteger temp=p.multiply(q).toBigInteger();
        table_t[i]=temp.toString();
        T[i]=temp.toString(2);
        String t="";
        if(T[i].length()<32)
        {
            for(int j=0;j<32-T[i].length();j++)
            {
               t+='0';
            }
            t+=T[i];
            T[i]=t;
          }
    }
  }

    public static char AND(char i,char j)
    {
        if((i=='0' && j=='0')||(i=='0'&&j=='1')||(i=='1'&&j=='0'))
            return '0';
        else
            return '1';
         
    }
    public static char OR(char i,char j)
    {
        if(i=='0'&&j=='0')
            return '0';
        else
            return '1';
    }
    public static char NOT(char i)
    {
        if(i=='0')
            return '1';
        else
            return '0';
    }
    public static char xor(char i,char j)
    {
        if(i=='0'&&j=='1'||i=='1'&&j=='0')
            return '1';
        else
            return '0';
    }

    public static String binary_ADD(String s1,String s2)
    {
      StringBuilder sb = new StringBuilder();
    int i = s1.length() - 1, j = s2.length() -1, carry = 0;
    while (i >= 0 || j >= 0) {
        int sum = carry;
        if (j >= 0) sum += s2.charAt(j--) - '0';
        if (i >= 0) sum += s1.charAt(i--) - '0';
        sb.append(sum % 2);
        carry = sum / 2;
    }
   
    return sb.reverse().toString();
           
    }
    public static String func_F(String buffer1,String buffer2,String buffer3)
    {
        String temp="",temp1="",temp2="";
        for(int i=0;i<32;i++)
        {
            temp+=AND(buffer1.charAt(i), buffer2.charAt(i));
        }
       
           
        for(int i=0;i<32;i++)
        {
            temp1+=AND(NOT(buffer1.charAt(i)), buffer3.charAt(i));
        }
       
       
        for(int i=0;i<32;i++)
            temp2+=OR(temp.charAt(i), temp1.charAt(i));
       
        return temp2;

    }
   
    public static String func_G(String buffer1,String buffer2,String buffer3)
    {
        String temp="",temp1="",temp2="";
        for(int i=0;i<32;i++)
        {
            temp+=AND(buffer1.charAt(i), buffer3.charAt(i));
        }
       
        for(int i=0;i<32;i++)
        {
            temp1+=AND(buffer2.charAt(i),NOT( buffer3.charAt(i)));
        }
        for(int i=0;i<32;i++)
            temp2+=OR(temp.charAt(i), temp1.charAt(i));
       
        return temp2;
    }
   
    public static String func_H(String buffer1,String buffer2,String buffer3)
    {
        String temp1="",temp2="";
        for(int i=0;i<32;i++)
        {
            temp1+=xor(buffer1.charAt(i), buffer2.charAt(i));
        }
        for(int i=0;i<32;i++)
        {
            temp2+=xor(temp1.charAt(i), buffer3.charAt(i));
        }
       
        return temp2;
    }
   
    public static String func_I(String buffer1,String buffer2,String buffer3)
    {
        String temp1="",temp2="";
        for(int i=0;i<32;i++)
        {
            temp1+=OR(buffer1.charAt(i), NOT(buffer3.charAt(i)));
        }
        for(int i=0;i<32;i++)
        {
            temp2+=xor(buffer2.charAt(i), temp1.charAt(i));
        }
       
        return temp2;
       
    }
    public static String conv_hex_plain(String plain)
    {

       
        String temp="",temp1="",s1="",str="",copy;
        copy=plain;
        String len_4[]=new String[10];
        int ind=0;
        int length=0;
        while(true)
        {
            if(plain.length()>=4)
            {
                if(plain.length()==4)
                {
                    str=plain.substring(0);
                    plain="";
                }
                else
                {
                    str=plain.substring(0,4);
                    plain=plain.substring(4);
                }
               
                for(int i=str.length()-1;i>=0;i--)
                {
                    temp+=Integer.toHexString(str.charAt(i));
                }
                     }
            else
            {
                temp+="80";
                for(int i=plain.length()-1;i>=0;i--)
                {
                    temp+=Integer.toHexString(plain.charAt(i));
                   
                }
                break;
                 }
            ind++;
           
        }
       
           
        String temp2="",str2="",str1="";
        ind=0;
        while(true)  
        {
            str2="";
          
            if(temp.length()>8)
            {
                str1=temp.substring(0,8);
                temp=temp.substring(8);
            }
            else
            {
                str1=temp.substring(0);
                temp="";
            }
           
            
           
            for(int j=0;j<str1.length();j++)
            {
            String s=Integer.toBinaryString(Integer.parseInt(str1.charAt(j)+"", 16));
         
            s1="";
            if(s.length()<4)
            {  
                for(int k=0;k<4-s.length();k++)                
                    s1+='0';
               
            }
            str2+=s1+s;
           
            }
                      
            if(str2.length()<32)
            {
                for(int k=0;k<32-str2.length();k++)
                temp2+='0';
            }
                    
           temp2+=str2;
           ind++;
           if(temp.length()==0)
               break;
        }
       
        length=copy.length()*8;
        int n=temp2.length()/448;
        int x=(512*(n+1)-64)-temp2.length();
       for(int i=0;i<x;i++)
          temp2+='0';
        temp1="";
        String s=Integer.toBinaryString(length);
        for(int i=0;i<32-s.length();i++)
        {
            temp1+='0';
        }
        temp1+=s;
        for(int i=0;i<32;i++)
            temp1+='0';

        return temp2+temp1;
    }
          static  String[] buffer=new String[4];

     
   public static void init_buffers()
   {
       String init="",result="",temp="";;
            buffer[0]="";buffer[1]="";buffer[2]="";buffer[3]="";
            init="67452301";
        for(int i=0;i<init.length();i++)
        {
            result="";
            char  c=init.charAt(i);
            temp= Integer.toBinaryString(Integer.parseInt(c+"",16))+"";
            for(int j=0;j<(4-temp.length());j++)
                result+='0';
           
            result+=temp;
            temp="";
            buffer[0]+=result;
           
        }
        init="EFCDAB89";
       for(int i=0;i<init.length();i++)
        {
           result="";
           char  c=init.charAt(i);
            temp= Integer.toBinaryString(Integer.parseInt(c+"",16))+"";
            for(int j=0;j<(4-temp.length());j++)
                result+='0';
           
            result+=temp;
            temp="";
            buffer[1]+=result;  
        }

        init="98BADCFE";
       for(int i=0;i<init.length();i++)
        {
            result="";
           char  c=init.charAt(i);
            temp= Integer.toBinaryString(Integer.parseInt(c+"",16))+"";
            for(int j=0;j<(4-temp.length());j++)
                result+='0';
           
            result+=temp;
            temp="";
            buffer[2]+=result;
        }
        init="10325476";
       for(int i=0;i<init.length();i++)
        {
            result="";
           char  c=init.charAt(i);
            temp= Integer.toBinaryString(Integer.parseInt(c+"",16))+"";
            for(int j=0;j<(4-temp.length());j++)
                result+='0';
           
            result+=temp;
            temp="";
            buffer[3]+=result;
        }
       init_A=new BigInteger(buffer[0],2);
       init_B= new BigInteger(buffer[1], 2);
       init_C=new BigInteger(buffer[2], 2);
       init_D= new BigInteger(buffer[3], 2);
       }
   
   
   
   public static String encryption(String plain_txt)
   {
       String[] x=new String[16];
        for(int i=0;i<16;i++)
        {
            x[i]="";
            x[i]=plain_txt.substring(i*32,(i*32)+32);
               }

        int shifts=0;
        int num_blocks=plain_txt.length()/512;
        int ind=0,ind1=0,ind2=0;
        String A="",B="",C="",D="";
        for(int block=0;block<num_blocks;block++)
        {   String temp1="";
            char ch='F';
            shifts=ind1;
            for(int i=0;i<4;i++)
            {
                 ind1+=4;
                 String index="0123";
                for(int j=0;j<16;j++)
                {     
                    if(ch=='F')
                    temp1=binary_ADD(buffer[index.charAt(0)-'0'], func_F(buffer[index.charAt(1)-'0'], buffer[index.charAt(2)-'0'], buffer[index.charAt(3)-'0']));
                    else if(ch=='G')
                     temp1=binary_ADD(buffer[index.charAt(0)-'0'], func_G(buffer[index.charAt(1)-'0'], buffer[index.charAt(2)-'0'], buffer[index.charAt(3)-'0']));
                    else if(ch=='H')
                    temp1=binary_ADD(buffer[index.charAt(0)-'0'], func_H(buffer[index.charAt(1)-'0'], buffer[index.charAt(2)-'0'], buffer[index.charAt(3)-'0']));
                    else if(ch=='I')
                    temp1=binary_ADD(buffer[index.charAt(0)-'0'], func_I(buffer[index.charAt(1)-'0'], buffer[index.charAt(2)-'0'], buffer[index.charAt(3)-'0']));    
                   
                    temp1=binary_ADD(temp1, x[k[ind]]);
                    temp1=binary_ADD(temp1, T[ind]);
                    temp1=temp1.substring(shift[shifts])+temp1.substring(0, shift[shifts]);
                   
                   buffer[index.charAt(0)-'0']=binary_ADD(temp1, buffer[index.charAt(1)-'0']);              
                     if(ind1-shifts==1)
                         shifts-=3;
                     else
                         shifts++;
                     ind++;
                     index=index.substring(3)+index.substring(0,3);
                }
                ch++;
                shifts+=4;                            
            }
        }
        BigInteger temp1=new BigInteger(buffer[0],2);
        BigInteger temp2=new BigInteger(buffer[1],2);
        BigInteger temp3=new BigInteger(buffer[2],2);
        BigInteger temp4=new BigInteger(buffer[3],2);
       
        init_A=init_A.add(temp1);
        init_B= init_B.add(temp2);
        init_C= init_C.add(temp3);
        init_D= init_D.add(temp4);

        String[] final_buffer=new String[4];
        final_buffer[0]=new BigInteger(init_A.toString(),10).toString(16);        
        final_buffer[1]=new BigInteger(init_B.toString(),10).toString(16);        
       final_buffer[2]=new BigInteger(init_C.toString(),10).toString(16);        
         final_buffer[3]=new BigInteger(init_D.toString(),10).toString(16);
       
         System.out.println("Final Buffers");
        for(int i=0;i<4;i++)
        {
            if(final_buffer[i].length()==9)
                final_buffer[i]=final_buffer[i].substring(1);
            System.out.println("Buffer "+(i+1)+" "+final_buffer[i]);
        }
        String result="",str2="";
         
        for(int i=0;i<4;i++)
        {ind=0;
            String str=new StringBuffer(final_buffer[i]).reverse().toString();
               // System.out.println(str);
                str2="";
            for(int j=0;j<final_buffer[i].length()/2;j++)
            {
               
                String t=new StringBuffer(final_buffer[i].substring(ind, ind+2)).reverse().toString();
                //System.out.println(t);
                str2+=t;
               ind+=2;
            }
            result+=new StringBuffer(str2).reverse().toString();
                 }
return result;
   }
   
    public static void main(String[] args) {
        String plain_txt="";
               Scanner s=new Scanner(System.in);
        plain_txt=conv_hex_plain(s.nextLine());
             init_buffers();
              
            System.out.println(encryption(plain_txt));
             
    }
   
}




\\11 *************************************************

import java.math.BigInteger;
import java.util.Scanner;


public class Sha1 {

    public static String[] init_const={
        "67452301", "efcdab89",
        "98badcfe","10325476","c3d2e1f0"
    };
       

     public static String xor(String x,String y)
    {
        String temp="";
        for(int i=0;i<x.length();i++)
        {
       
        if(x.charAt(i)=='0'&&y.charAt(i)=='1'||x.charAt(i)=='1'&&y.charAt(i)=='0')
            temp+='1';
        else
            temp+='0';  
        }
        return temp;  
    }
        public static String AND(String x,String y)
    {
        String temp="";
        for(int i=0;i<x.length();i++)
        {
        if((x.charAt(i)=='0' && y.charAt(i)=='0')||(x.charAt(i)=='0'&&y.charAt(i)=='1')||(x.charAt(i)=='1'&&y.charAt(i)=='0'))
            temp+= '0';
        else
            temp+= '1';
        }
         return temp;
    }
    public static String OR(String x,String y)
    {
        String temp="";
        for(int i=0;i<x.length();i++)
        {
        if(x.charAt(i)=='0'&&y.charAt(i)=='0')
            temp+= '0';
        else
            temp+= '1';
        }
        return temp;
    }
    public static String NOT(String x)
    {
        String temp="";
        for(int i=0;i<x.length();i++)
        {
            if(x.charAt(i)=='0')
            temp+= '1';
            else
           temp+= '0';            
        }
     
        return temp;
    }
   
    public static String[] buffers=new String[32];
    public static void init()
    {
        System.out.println("Five Buffers:");
        char c='A';
        for(int i=0;i<5;i++)
        {
            String s=init_const[i];
            String s2="";
            buffers[i]="";
 
            for(int j=0;j<s.length();j++)
            {
                String s1=Integer.toBinaryString(Integer.parseInt(s.charAt(j)+"", 16));
                if(s1.length()<4)
                {
                    for(int k=0;k<4-s1.length();k++)
                        s2+='0';
                }
                buffers[i]+=s2+s1;
                s2="";
           
        }
            System.out.println((c++)+" "+buffers[i]);
        }
    }
   
    public static String function(int iteration_no,String B,String C,String D)
    {
        if(iteration_no>=0 && iteration_no<=19)
        {
            return OR((AND(B, C)),AND(NOT(B),D));
                     
        }
        else if(iteration_no>=20 && iteration_no<=39)
        {
            return xor(xor(C, D), B);
        }
        else if(iteration_no>=40 && iteration_no<=59)
                {
                    return OR(OR( AND(B,C),AND(B,D)),AND(C,D));
                }
        else{
            return xor(xor(C, D), B);
           
        }
       
    }
    private static String[] k=new String[5];
    static{
        String x="5A827999";
        String temp="";
        for(int i=0;i<8;i++)
        {
            String s=Integer.toBinaryString(Integer.parseInt(x.charAt(i)+"", 16));
                if(s.length()<4)
                {  for(int l=0;l<4-s.length();l++)                    
                        temp+='0';
                }
                temp+=s;            
        }
        k[0]=temp;
        x="6ED9EBA1";
        temp="";
        for(int i=0;i<8;i++)
        {
            String s=Integer.toBinaryString(Integer.parseInt(x.charAt(i)+"", 16));
                if(s.length()<4)
                {  for(int l=0;l<4-s.length();l++)                    
                        temp+='0';
                }
                temp+=s;            
        }
        k[1]=temp;
        x="8F1BBCDC";
        temp="";
        for(int i=0;i<8;i++)
        {
            String s=Integer.toBinaryString(Integer.parseInt(x.charAt(i)+"", 16));
                if(s.length()<4)
                {  for(int l=0;l<4-s.length();l++)                    
                        temp+='0';
                }
                temp+=s;            
        }
        k[2]=temp;
        x="CA62C1D6";
        temp="";
        for(int i=0;i<8;i++)
        {
            String s=Integer.toBinaryString(Integer.parseInt(x.charAt(i)+"", 16));
                if(s.length()<4)
                {  for(int l=0;l<4-s.length();l++)                    
                        temp+='0';
                }
                temp+=s;            
        }
        k[3]=temp;
       
       
       
    }
    public static String constant_k(int iteration_no)
    {
   
                if(iteration_no>=0 && iteration_no<=19)
                    return k[0];
                else if(iteration_no>=20 && iteration_no<=39)
                    return k[1];
                else if(iteration_no>=40 && iteration_no<=59)
                    return k[2];
                else
                    return k[3];
               
    }
   
    public static String binary_ADD(String s1,String s2)
    {
      StringBuilder sb = new StringBuilder();
    int i = s1.length() - 1, j = s2.length() -1, carry = 0;
    while (i >= 0 || j >= 0) {
        int sum = carry;
        if (j >= 0) sum += s2.charAt(j--) - '0';
        if (i >= 0) sum += s1.charAt(i--) - '0';
        sb.append(sum % 2);
        carry = sum / 2;
    }
       return sb.reverse().toString();
           
    }
   
    private static String[] message=new String[80];    
   public static BigInteger[] init_buff=new BigInteger[5];
   
    public static String encryption(String[] message)
    {
         for(int i=0;i<5;i++)
        {
            init_buff[i]=new BigInteger(buffers[i], 2);
        }
         
         String temp="",temp1="",temp2="",temp3="",temp4="";
        for(int i=0;i<80;i++)
        {
            temp2=buffers[1];
            temp3=buffers[2];
            temp4=buffers[3];
           
            temp=binary_ADD(buffers[4],function(i,buffers[1], buffers[2], buffers[3]));
            temp1=buffers[0].substring(5)+buffers[0].substring(0,5);
            temp=binary_ADD(temp1, temp);
            temp=binary_ADD(message[i], temp);
            temp1=buffers[0];
            buffers[0]=binary_ADD(constant_k(i), temp);
            buffers[1]=temp1;
            buffers[2]=temp2.substring(30)+temp2.substring(0,30);
            buffers[3]=temp3;
            buffers[4]=temp4;
           
          }
       
        for(int i=0;i<5;i++)
        {
           
            buffers[i]=init_buff[i].add(new BigInteger(buffers[i], 2)).toString(16);
           
        }
        return buffers[0]+buffers[1]+buffers[2]+buffers[3]+buffers[4];
    }
   
    public static void main(String[] args) {
        
        System.out.println("Enter the plaintxt: ");
        Scanner s=new Scanner(System.in);
        init();
        String plain_txt="";
        plain_txt=con_txt(s.nextLine());
       
        for(int i=0;i<16;i++)
        {
            message[i]=plain_txt.substring(i*32,(i+1)*32);
            //System.out.println(message[i]);
        }
       
        for(int i=16;i<80;i++)
        {
           
           String temp=xor(xor(xor(message[i-3],message[i-8]),message[i-14]),message[i-16]);
           message[i]=temp.substring(1)+temp.charAt(0);    
        }
                      
      String hash= encryption(message);
        System.out.println(hash);
       
    }

    private static String con_txt(String plain) {
       
         String temp1="",temp2="",copy=plain,temp3="";
    while(true)
    {
        if(plain.length()>4)
        {
            String s=plain.substring(0,4);
            for(int i=0;i<s.length();i++)
            {
                temp1+=Integer.toHexString(s.charAt(i));
            }
            plain=plain.substring(4);
             }
        else if(plain.length()==4)
        {
            String s=plain.substring(0);
            for(int i=0;i<s.length();i++)
            {
                temp1+=Integer.toHexString(s.charAt(i));
            }
            plain="";
        }
        else
        {
            if(plain.length()>0)
            {
                String s=plain.substring(0);
                for(int i=0;i<s.length();i++)
            {
                temp1+=Integer.toHexString(s.charAt(i));
            }
               }
        temp1+="80";
            break;
        } 
    }
        System.out.println("Converted Text: "+temp1);
        String str;
        for(int i=0;i<temp1.length();i++)
        {          
                String s=Integer.toBinaryString(Integer.parseInt(temp1.charAt(i)+"", 16));
              
                if(s.length()<4)
                {
                  for(int l=0;l<4-s.length();l++)
                    {
                        temp2+='0';
                    }
                }
                temp2+=s;            
        }
       
        int x=448-temp2.length();
        for(int i=0;i<x;i++)
                   temp2+='0';
       
        int len=copy.length();
        len*=8;
        String s=Integer.toBinaryString(len);
        for(int i=0;i<64-s.length();i++)
            temp2+='0';
        temp2+=s;
           
       
    return temp2;
    }
   
}
