#include<iostream>
#include<vector>
#include<fstream>
#include<sstream>
#include<string>
#define SIZE 100
using namespace std;
void Data(vector<string>&Instruction,vector<string>&Tag,vector<string>&Inson,vector<string>&Arithmetic);//處理資料格式 
void StringInt(string a,int &Address);//十六進制字串轉十進制 
char DecToHex (unsigned int n)//十進制轉十六進制 
{
    char hex[] = {'0', '1', '2', '3','4','5'
                 ,'6','7','8','9','A','B','C'
                 ,'D','E','F'
                 };
    return hex[n] ;
}

class Solution //十進制轉十六進制
{
public :
    string toHex (int num )
    {
        unsigned int unNum = (int) num ;
        string result ;

        do 
        {
            result = DecToHex(unNum % 16) + result ;
            unNum /= 16 ;
        } while (unNum>0);
        return result ;
    }
};
int bin(int a,string &Wordstring)//十進制負數取2補數以十六進制輸出 
{
	int number[24]={0};
	string hexstring="";
	for(int i=23;i>=0;i--)
	{
		number[i]=a%2;
		a=a/2;
	}
	for(int i=0;i<24;i++)
	{
		if(number[i]==0)
			hexstring=hexstring+'1';
		else
			hexstring=hexstring+'0';
	}
	for(int i=0;i<24;i=i+4)
	{
		if(hexstring[i]=='0'&&hexstring[i+1]=='0'&&hexstring[i+2]=='0'&&hexstring[i+3]=='0')
			Wordstring=Wordstring+"0";
		else if(hexstring[i]=='0'&&hexstring[i+1]=='0'&&hexstring[i+2]=='0'&&hexstring[i+3]=='1')
			Wordstring=Wordstring+"1";
		else if(hexstring[i]=='0'&&hexstring[i+1]=='0'&&hexstring[i+2]=='1'&&hexstring[i+3]=='0')
			Wordstring=Wordstring+"2";
	    else if(hexstring[i]=='0'&&hexstring[i+1]=='0'&&hexstring[i+2]=='1'&&hexstring[i+3]=='1')
			Wordstring=Wordstring+"3";
		else if(hexstring[i]=='0'&&hexstring[i+1]=='1'&&hexstring[i+2]=='0'&&hexstring[i+3]=='0')
			Wordstring=Wordstring+"4";
		else if(hexstring[i]=='0'&&hexstring[i+1]=='1'&&hexstring[i+2]=='0'&&hexstring[i+3]=='1')
			Wordstring=Wordstring+"5";
		else if(hexstring[i]=='0'&&hexstring[i+1]=='1'&&hexstring[i+2]=='1'&&hexstring[i+3]=='0')
			Wordstring=Wordstring+"6";
		else if(hexstring[i]=='0'&&hexstring[i+1]=='1'&&hexstring[i+2]=='1'&&hexstring[i+3]=='1')
			Wordstring=Wordstring+"7";
		else if(hexstring[i]=='1'&&hexstring[i+1]=='0'&&hexstring[i+2]=='0'&&hexstring[i+3]=='0')
			Wordstring=Wordstring+"8";
		else if(hexstring[i]=='1'&&hexstring[i+1]=='0'&&hexstring[i+2]=='0'&&hexstring[i+3]=='1')
			Wordstring=Wordstring+"9";
		else if(hexstring[i]=='1'&&hexstring[i+1]=='0'&&hexstring[i+2]=='1'&&hexstring[i+3]=='0')
			Wordstring=Wordstring+"A";
		else if(hexstring[i]=='1'&&hexstring[i+1]=='0'&&hexstring[i+2]=='1'&&hexstring[i+3]=='1')
			Wordstring=Wordstring+"B";
		else if(hexstring[i]=='1'&&hexstring[i+1]=='1'&&hexstring[i+2]=='0'&&hexstring[i+3]=='0')
			Wordstring=Wordstring+"C";
		else if(hexstring[i]=='1'&&hexstring[i+1]=='1'&&hexstring[i+2]=='0'&&hexstring[i+3]=='1')
			Wordstring=Wordstring+"D";
		else if(hexstring[i]=='1'&&hexstring[i+1]=='1'&&hexstring[i+2]=='1'&&hexstring[i+3]=='0')
			Wordstring=Wordstring+"E";
		else if(hexstring[i]=='1'&&hexstring[i+1]=='1'&&hexstring[i+2]=='1'&&hexstring[i+3]=='1')
			Wordstring=Wordstring+"F";
	}
}
int main()
{
	vector<string>Mneonic;
	vector<string>Opcode;
	vector<char>ASCII;
	vector<string>HEXcode;
	Mneonic.push_back("ADD");Mneonic.push_back("ADDF");Mneonic.push_back("ADDR");Mneonic.push_back("AND");Mneonic.push_back("CLEAR");Mneonic.push_back("COMP");Mneonic.push_back("COMPF");Mneonic.push_back("COMPR");Mneonic.push_back("DIV");Mneonic.push_back("DIVF");Mneonic.push_back("DIVR");Mneonic.push_back("FIX");Mneonic.push_back("FLOAT");Mneonic.push_back("HIO");Mneonic.push_back("J");Mneonic.push_back("JEQ");Mneonic.push_back("JGT");Mneonic.push_back("JLT");Mneonic.push_back("JSUB");Mneonic.push_back("LDA");Mneonic.push_back("LDB");Mneonic.push_back("LDCH");Mneonic.push_back("LDF");Mneonic.push_back("LDL");Mneonic.push_back("LDS");Mneonic.push_back("LDT");Mneonic.push_back("LDX");Mneonic.push_back("LPS");Mneonic.push_back("MUL");Mneonic.push_back("MULF");Mneonic.push_back("MULR");Mneonic.push_back("NORM");Mneonic.push_back("OR");Mneonic.push_back("RD");Mneonic.push_back("RMO");Mneonic.push_back("RSUB");Mneonic.push_back("SHIFTL");Mneonic.push_back("SHIFTR");Mneonic.push_back("SIO");Mneonic.push_back("SSK");Mneonic.push_back("STA");Mneonic.push_back("STB");Mneonic.push_back("STCH");Mneonic.push_back("STF");Mneonic.push_back("STI");Mneonic.push_back("STL");Mneonic.push_back("STS");Mneonic.push_back("STSW");Mneonic.push_back("STT");Mneonic.push_back("STX");Mneonic.push_back("SUB");Mneonic.push_back("SUBF");Mneonic.push_back("SUBR");Mneonic.push_back("SVC");Mneonic.push_back("TD");Mneonic.push_back("TIO");Mneonic.push_back("TIX");Mneonic.push_back("TIXR");Mneonic.push_back("WD");
	Opcode.push_back("18");Opcode.push_back("58");Opcode.push_back("90");Opcode.push_back("40");Opcode.push_back("B4");Opcode.push_back("28");Opcode.push_back("88");Opcode.push_back("A0");Opcode.push_back("24");Opcode.push_back("64");Opcode.push_back("9C");Opcode.push_back("C4");Opcode.push_back("C0");Opcode.push_back("F4");Opcode.push_back("3C");Opcode.push_back("30");Opcode.push_back("34");Opcode.push_back("38");Opcode.push_back("48");Opcode.push_back("00");Opcode.push_back("68");Opcode.push_back("50");Opcode.push_back("70");Opcode.push_back("08");Opcode.push_back("6C");Opcode.push_back("74");Opcode.push_back("04");Opcode.push_back("D0");Opcode.push_back("20");Opcode.push_back("60");Opcode.push_back("98");Opcode.push_back("C8");Opcode.push_back("44");Opcode.push_back("D8");Opcode.push_back("AC");Opcode.push_back("4C");Opcode.push_back("A4");Opcode.push_back("A8");Opcode.push_back("F0");Opcode.push_back("EC");Opcode.push_back("0C");Opcode.push_back("78");Opcode.push_back("54");Opcode.push_back("80");Opcode.push_back("D4");Opcode.push_back("14");Opcode.push_back("7C");Opcode.push_back("E8");Opcode.push_back("84");Opcode.push_back("10");Opcode.push_back("1C");Opcode.push_back("5C");Opcode.push_back("94");Opcode.push_back("B0");Opcode.push_back("E0");Opcode.push_back("F8");Opcode.push_back("2C");Opcode.push_back("B8");Opcode.push_back("DC");
	ASCII.push_back('!');   ASCII.push_back('#');   ASCII.push_back('$');   ASCII.push_back('%');   ASCII.push_back('&');    ASCII.push_back('*');   ASCII.push_back('+');   ASCII.push_back(',');   ASCII.push_back('-');   ASCII.push_back('.');   ASCII.push_back('/');   ASCII.push_back('0');   ASCII.push_back('1');	HEXcode.push_back("21");HEXcode.push_back("23");HEXcode.push_back("24");HEXcode.push_back("25");HEXcode.push_back("26");HEXcode.push_back("2A");HEXcode.push_back("2B");HEXcode.push_back("2C");HEXcode.push_back("2D");HEXcode.push_back("2E");HEXcode.push_back("2F");HEXcode.push_back("30");HEXcode.push_back("31");	ASCII.push_back('2');   ASCII.push_back('3');   ASCII.push_back('4');   ASCII.push_back('5');   ASCII.push_back('6');    ASCII.push_back('7');   ASCII.push_back('8');   ASCII.push_back('9');   ASCII.push_back(':');   ASCII.push_back(';');   ASCII.push_back('<');   ASCII.push_back('=');   ASCII.push_back('>');   ASCII.push_back('?');	HEXcode.push_back("32");HEXcode.push_back("33");HEXcode.push_back("34");HEXcode.push_back("35");HEXcode.push_back("36"); HEXcode.push_back("37");HEXcode.push_back("38");HEXcode.push_back("39");HEXcode.push_back("3A");HEXcode.push_back("3B");HEXcode.push_back("3C");HEXcode.push_back("3D");HEXcode.push_back("3E");HEXcode.push_back("3F");
	ASCII.push_back('@');   ASCII.push_back('A');   ASCII.push_back('B');   ASCII.push_back('C');   ASCII.push_back('D');    ASCII.push_back('E');   ASCII.push_back('F');   ASCII.push_back('G');   ASCII.push_back('H');   ASCII.push_back('I');   ASCII.push_back('J');   ASCII.push_back('K');   ASCII.push_back('L');   ASCII.push_back('M');	HEXcode.push_back("40");HEXcode.push_back("41");HEXcode.push_back("42");HEXcode.push_back("43");HEXcode.push_back("44"); HEXcode.push_back("45");HEXcode.push_back("46");HEXcode.push_back("47");HEXcode.push_back("48");HEXcode.push_back("49");HEXcode.push_back("4A");HEXcode.push_back("4B");HEXcode.push_back("4C");HEXcode.push_back("4D");	ASCII.push_back('N');   ASCII.push_back('O');   ASCII.push_back('P');   ASCII.push_back('Q');   ASCII.push_back('R');    ASCII.push_back('S');   ASCII.push_back('T');   ASCII.push_back('U');   ASCII.push_back('V');   ASCII.push_back('W');   ASCII.push_back('X');   ASCII.push_back('Y');   ASCII.push_back('Z');   ASCII.push_back('[');	HEXcode.push_back("4E");HEXcode.push_back("4F");HEXcode.push_back("50");HEXcode.push_back("51");HEXcode.push_back("52"); HEXcode.push_back("53");HEXcode.push_back("54");HEXcode.push_back("55");HEXcode.push_back("56");HEXcode.push_back("57");HEXcode.push_back("58");HEXcode.push_back("59");HEXcode.push_back("5A");HEXcode.push_back("5B");
	ASCII.push_back(']');   ASCII.push_back('^');   ASCII.push_back('_');   ASCII.push_back('`');   ASCII.push_back('a');    ASCII.push_back('b');   ASCII.push_back('c');   ASCII.push_back('d');   ASCII.push_back('e');   ASCII.push_back('f');   ASCII.push_back('g');   ASCII.push_back('h');   ASCII.push_back('i');   ASCII.push_back('j');	HEXcode.push_back("5D");HEXcode.push_back("5E");HEXcode.push_back("5F");HEXcode.push_back("60");HEXcode.push_back("61"); HEXcode.push_back("62");HEXcode.push_back("63");HEXcode.push_back("64");HEXcode.push_back("65");HEXcode.push_back("66");HEXcode.push_back("67");HEXcode.push_back("68");HEXcode.push_back("69");HEXcode.push_back("6A");	ASCII.push_back('k');   ASCII.push_back('l');   ASCII.push_back('m');   ASCII.push_back('n');   ASCII.push_back('o');    ASCII.push_back('p');   ASCII.push_back('q');   ASCII.push_back('r');   ASCII.push_back('s');   ASCII.push_back('t');   ASCII.push_back('u');   ASCII.push_back('v');   ASCII.push_back('w');   ASCII.push_back('x');	HEXcode.push_back("6B");HEXcode.push_back("6C");HEXcode.push_back("6D");HEXcode.push_back("6E");HEXcode.push_back("6F"); HEXcode.push_back("70");HEXcode.push_back("71");HEXcode.push_back("72");HEXcode.push_back("73");HEXcode.push_back("74");HEXcode.push_back("75");HEXcode.push_back("76");HEXcode.push_back("77");HEXcode.push_back("78");	ASCII.push_back('y');   ASCII.push_back('z');   ASCII.push_back('|');   ASCII.push_back('~');   HEXcode.push_back("79");HEXcode.push_back("7A");HEXcode.push_back("7C");HEXcode.push_back("7E");ASCII.push_back(' ');HEXcode.push_back("20");
	
	ifstream fin;//讀檔 
	ifstream in("E:\\sic.txt");//雙引號內為路徑SIC_instruction
	vector<string>Instruction;
	string line;
	while (!in.eof())
	{
		getline(in, line);
		if (line.empty())
		{
			continue;
		}
		int noin=0;//判斷是否註解開關 
		for(int i=0;i<sizeof(line);i++)
		{
			if(line[i]=='.')
				noin=1;	
		}
		if(noin==0)
			Instruction.push_back(line);
	}
	//---------------------------------------------------------------------- 
	/*for(int i=0;i<Instruction.size();i++)
	{
		cout<<Instruction[i]<<endl;
	}*/
	vector<string>Tag;//存取Tag 
	vector<string>Inson;//存取instruction 
	vector<string>Arithmetic;//存取運算元 
	Data(Instruction,Tag,Inson,Arithmetic);
	/*for(int i=0;i<Instruction.size();i++)//檢查資料是否讀進 
	{
		cout<<Tag[i]<<"      "<<Inson[i]<<"      "<<Arithmetic[i]<<endl;
	}*/
	//------------------------------------------------------------------------處理Loc 
	Solution Test ;
	string strNumber ;
	vector<string>Loc;
	vector<string>Errorstr;
	vector<int>Errorline;
	int Address=0;
	int outputerror=0;
	//-------------------------------------------------------------------------偵測指令是否有誤 
	for(int i=0;i<Inson.size();i++)
	{
		int error=0;
		int errorline;
		for(int j=0;j<Mneonic.size();j++)
		{
			if(Inson[i]!=Mneonic[j]&&Inson[i]!="START"&&Inson[i]!="END"&&Inson[i]!="RESW"&&Inson[i]!="RESB"&&Inson[i]!="BYTE"&&Inson[i]!="WORD")
				error++;	
		}
		if(error==59)
		{
				outputerror++;
				errorline=i;
				Errorline.push_back(errorline+1);
				Errorstr.push_back(Inson[i]);
		}
	//------------------------------------------------------------------------處理Loc 
		if(Inson[i]=="START")
		{
			StringInt(Arithmetic[i],Address);	
			strNumber = Test.toHex(Address) ;
			Loc.push_back(strNumber);
			Loc.push_back(strNumber);
		} 
		else if(Inson[i]=="RESW")//運算元需*3 
		{
			int val;
			string str=Arithmetic[i];
			stringstream is(str);
   			is>>val;
   			Address=Address+(val*3);
			strNumber = Test.toHex(Address) ;
			Loc.push_back(strNumber);
		}
		else if(Inson[i]=="WORD")//一律+3 
		{
			Address=Address+3;
			strNumber = Test.toHex(Address) ;
			Loc.push_back(strNumber);
		}
		else if(Inson[i]=="BYTE")//X -> +1 , C -> +'有幾位' 
		{
			string bytesub=Arithmetic[i];
			if(bytesub[0]=='X')
			{
				Address=Address+1;
				strNumber = Test.toHex(Address) ;
				Loc.push_back(strNumber);	
			}
			else 
			{
				Address=Address+bytesub.size();
				strNumber = Test.toHex(Address) ;
				Loc.push_back(strNumber);	
			}
		}
		else if(Inson[i]=="RESB")//數字轉16進制加上去 
		{
			int val;
			string str=Arithmetic[i];
			stringstream is(str);
   			is>>val;
   			Address=Address+val;
			strNumber = Test.toHex(Address) ;
			Loc.push_back(strNumber);
		}
		else
		{
			Address=Address+3;
			strNumber = Test.toHex(Address) ;
			Loc.push_back(strNumber);
		}	
	}
	
	//----------------------------------------------------------------------------------處理Object code
	vector<string>ObjectCode;
	for(int i=0;i<Inson.size();i++)
	{
		string OP="";
		if(Inson[i]=="START"||Inson[i]=="END"||Inson[i]=="RESW"||Inson[i]=="RESB")
		{
			OP="no";
			ObjectCode.push_back(OP);
		}
		else if(Inson[i]=="WORD")//需判斷運算元為正負 
		{
			string opword =Arithmetic[i];
			if(opword[0]!='-')//正數 
			{
				int al;
				string st=Arithmetic[i];
				stringstream is1(st);
    			is1>>al;
				strNumber = Test.toHex(al);
				for(int j=0;j<(6-strNumber.size());j++)
				{
					OP=OP+'0';
				}
				OP=OP+strNumber;
				ObjectCode.push_back(OP);	
			}
			else// 負數處理  去掉負號  減一   取補數  補齊24位  轉16進位表示 
			{
				string wordnum=Arithmetic[i];
				string wordnum1="";
				for(int i=1;i<wordnum.size();i++)
				{
					wordnum1=wordnum1+wordnum[i];
				}
				int wordval;
				stringstream wordis(wordnum1);
    			wordis>>wordval;
    			string Wordstring="";
				bin(wordval-1,Wordstring);
				ObjectCode.push_back(Wordstring);
				Wordstring="";
			}
		}
		else if(Inson[i]=="BYTE")//需判斷運算元為X,C 
		{
			string bytestr=Arithmetic[i];
			
			if(bytestr[0]=='X')//直接印出引號內文字 
			{
				for(int j=2;j<bytestr.size()-1;j++)
				{
					OP=OP+bytestr[j];
				}
				ObjectCode.push_back(OP);
			}
			else//C查ASCII 
			{
				for(int j=0;j<bytestr.size();j++)
				{
					for(int k=0;k<ASCII.size();k++)
					{
						if(bytestr[j]==ASCII[k])
							OP=OP+HEXcode[k];
					}
				}
				ObjectCode.push_back(OP);
			}
		}
		else if(Inson[i]=="RSUB")//op後須補0 
		{
			for(int j=0;j<Mneonic.size();j++)
			{
				if(Mneonic[j]=="RSUB")
					OP=OP+Opcode[j]+"0000";
			}
			ObjectCode.push_back(OP);
		}
		else 
		{
			string pluseight=Arithmetic[i];
			if(pluseight[pluseight.size()-1]=='X'&&pluseight[pluseight.size()-2]==',')//遇到Arithmetic有加X另外處理 
			{
				string stchstr=Arithmetic[i];
				if(stchstr[stchstr.size()-1]=='X')//X需加8000(Hex) 
				{
					for(int j=0;j<Mneonic.size();j++)
					{
						if(Mneonic[j]==Inson[i])
							OP=OP+Opcode[j];
					}
					string stchsub="";
					string finstch;
					for(int j=0;j<stchstr.size();j++)
					{
						if(stchstr[j]!=',')//去掉,X才能對Tag 
							stchsub=stchsub+stchstr[j];
						else
							break;
					}
					for(int j=0;j<Tag.size();j++)
					{
						if(stchsub==Tag[j])
						{
						if(Loc[j].size()==1)
							finstch=finstch+"000"+Loc[j];
						else if(Loc[j].size()==2)
							finstch=finstch+"00"+Loc[j];
						else if(Loc[j].size()==3)
							finstch=finstch+"0"+Loc[j];
						else
							finstch=finstch+Loc[j];
						}
					}
					if(finstch[0]=='0')//+8000 
						finstch[0]='8';
					else if(finstch[0]=='1')
						finstch[0]='9';
					else if(finstch[0]=='2')
						finstch[0]='A';
					else if(finstch[0]=='3')
						finstch[0]='B';
					else if(finstch[0]=='4')
						finstch[0]='C';
					else if(finstch[0]=='5')
						finstch[0]='D';
					else if(finstch[0]=='6')
						finstch[0]='E';
					else if(finstch[0]=='7')
						finstch[0]='F';
					else if(finstch[0]=='8')
						finstch[0]='0';
					else if(finstch[0]=='9')
						finstch[0]='1';
					else if(finstch[0]=='A')
						finstch[0]='2';
					else if(finstch[0]=='B')
						finstch[0]='3';
					else if(finstch[0]=='C')
						finstch[0]='4';
					else if(finstch[0]=='D')
						finstch[0]='5';
					else if(finstch[0]=='E')
						finstch[0]='6';
					else if(finstch[0]=='F')
						finstch[0]='7';
					OP=OP+finstch;
					ObjectCode.push_back(OP);
				}
				else
				{
					for(int j=0;j<Mneonic.size();j++)
					{
						if(Mneonic[j]==Inson[i])
							OP=OP+Opcode[j];
					}
					int tagcount=0;
					for(int j=0;j<Tag.size();j++)
					{
						if(Arithmetic[i]==Tag[j])
						{
						if(Loc[j].size()==1)
							OP=OP+"000"+Loc[j];
						else if(Loc[j].size()==2)
							OP=OP+"00"+Loc[j];
						else if(Loc[j].size()==3)
							OP=OP+"0"+Loc[j];
						else
							OP=OP+Loc[j];
						}
						else
						   tagcount++;
					}
					if(tagcount==Tag.size())//如果對應不到 
						OP=OP+"----  Error!Check Tag!";
					ObjectCode.push_back(OP);
				}
			}
			else//其餘沒特色指令 
			{
				for(int j=0;j<Mneonic.size();j++)
				{
					if(Mneonic[j]==Inson[i])
						OP=OP+Opcode[j];
				}
				int tagcount=0;
				for(int j=0;j<Tag.size();j++)
				{
					if(Arithmetic[i]==Tag[j])
					{
						if(Loc[j].size()==1)
							OP=OP+"000"+Loc[j];
						else if(Loc[j].size()==2)
							OP=OP+"00"+Loc[j];
						else if(Loc[j].size()==3)
							OP=OP+"0"+Loc[j];
						else
							OP=OP+Loc[j];
					}
						
					else
					   tagcount++;
				}
				if(tagcount==Tag.size())//如果對應不到
					OP=OP+"----  Error!Check Tag!";
				ObjectCode.push_back(OP);
				}	
		}
	}
	if(outputerror==0) 
	{
		cout<<"Loc"<<"           "<<"Source statement         "<<"Object code"<<endl;
		for(int i=0;i<Loc.size()-1;i++)//輸出格式處理 
		{
			string ChByte=Arithmetic[i];
			if(Tag[i]=="no")
				cout<<Loc[i]<<"    "<<"          ";
			else if(Tag[i].size()==1)
				cout<<Loc[i]<<"    "<<Tag[i]<<"         ";
			else if(Tag[i].size()==2)
				cout<<Loc[i]<<"    "<<Tag[i]<<"        ";
			else if(Tag[i].size()==3)
				cout<<Loc[i]<<"    "<<Tag[i]<<"       ";
			else if(Tag[i].size()==4)
				cout<<Loc[i]<<"    "<<Tag[i]<<"      ";
			else if(Tag[i].size()==5)
				cout<<Loc[i]<<"    "<<Tag[i]<<"     ";
			else if(Tag[i].size()==6)
				cout<<Loc[i]<<"    "<<Tag[i]<<"    ";
			if(Inson[i].size()==1)
				cout<<Inson[i]<<"      ";
			else if(Inson[i].size()==2)
				cout<<Inson[i]<<"     ";
			else if(Inson[i].size()==3)
				cout<<Inson[i]<<"    ";
			else if(Inson[i].size()==4)
				cout<<Inson[i]<<"   ";
			else if(Inson[i].size()==5)
				cout<<Inson[i]<<"  ";	
			//------------------------------------------------------	
			if(Arithmetic[i]=="no")
				cout<<"            ";
			else if(Arithmetic[i].size()==1&&Inson[i]=="BYTE"&&ChByte[0]!='X')
				cout<<"  C'"<<Arithmetic[i]<<"'       ";
			else if(Arithmetic[i].size()==2&&Inson[i]=="BYTE"&&ChByte[0]!='X')
				cout<<"  C'"<<Arithmetic[i]<<"'     ";
			else if(Arithmetic[i].size()==3&&Inson[i]=="BYTE"&&ChByte[0]!='X')
				cout<<"  C'"<<Arithmetic[i]<<"'    ";
			else if(Arithmetic[i].size()==4&&Inson[i]=="BYTE"&&ChByte[0]!='X')
				cout<<"  C'"<<Arithmetic[i]<<"'   ";
			else if(Arithmetic[i].size()==5&&Inson[i]=="BYTE"&&ChByte[0]!='X')
				cout<<"  C'"<<Arithmetic[i]<<"'  ";
			else if(Arithmetic[i].size()==6&&Inson[i]=="BYTE"&&ChByte[0]!='X')
				cout<<"  C'"<<Arithmetic[i]<<"' ";
			else if(Arithmetic[i].size()==7&&Inson[i]=="BYTE"&&ChByte[0]!='X')
				cout<<"  C'"<<Arithmetic[i]<<"'";
			else if(Arithmetic[i].size()==8&&Inson[i]=="BYTE"&&ChByte[0]!='X')
				cout<<"  C'"<<Arithmetic[i]<<"'";
			//------------------------------------------------------	
			else if(Arithmetic[i].size()==1)
				cout<<"  "<<Arithmetic[i]<<"         ";
			else if(Arithmetic[i].size()==2)
				cout<<"  "<<Arithmetic[i]<<"        ";
			else if(Arithmetic[i].size()==3)
				cout<<"  "<<Arithmetic[i]<<"       ";
			else if(Arithmetic[i].size()==4)
				cout<<"  "<<Arithmetic[i]<<"      ";
			else if(Arithmetic[i].size()==5)
				cout<<"  "<<Arithmetic[i]<<"     ";
			else if(Arithmetic[i].size()==6)
				cout<<"  "<<Arithmetic[i]<<"    ";
			else if(Arithmetic[i].size()==7)
				cout<<"  "<<Arithmetic[i]<<"   ";
			else if(Arithmetic[i].size()==8)
				cout<<"  "<<Arithmetic[i]<<"  ";
			if(ObjectCode[i]=="no")
				cout<<endl;
			else if(ObjectCode[i]!="no")
		 	 cout<<"  "<<ObjectCode[i]<<endl;
		}	
	}
	else//錯誤處理 
	{
		cout<<"Error ! Please confirm if the instructions in the file are incorrect."<<endl;
		for(int i=0;i<Errorstr.size();i++)
		{
			cout<<"Error No."<<Errorline[i]<<" instruction : "<< Errorstr[i]<<" ?"<<endl; 
		}
	}

	Mneonic.clear();
	Opcode.clear();
	ASCII.clear();
	HEXcode.clear();
	Instruction.clear();
	Tag.clear();
	Inson.clear();
	Arithmetic.clear();
	Loc.clear();
	Errorstr.clear();
	Errorline.clear();
	ObjectCode.clear();
}
void StringInt(string a,int &Address)
{
	string s1=a;
	int m=0;//紀錄幾次方 
	int k=1;//記錄乘次方數 
	int num=0;//紀錄十進位數 
	for(int i=s1.size()-1;i>=0;i--)
	{
		if(m>0)
		{
			for(int j=0;j<m;j++)
			{
				k=k*16;
			}
			if(s1[i]=='1')
				{num=num+(1*k);m++;}
			else if(s1[i]=='0')
				{num=num+(0*k);m++;}
			else if(s1[i]=='2')
				{num=num+(2*k);m++;}
			else if(s1[i]=='3')
				{num=num+(3*k);m++;}
			else if(s1[i]=='4')
				{num=num+(4*k);m++;}
			else if(s1[i]=='5')
				{num=num+(5*k);m++;}
			else if(s1[i]=='6')
				{num=num+(6*k);m++;}
			else if(s1[i]=='7')
				{num=num+(7*k);m++;}
			else if(s1[i]=='8')
				{num=num+(8*k);m++;}
			else if(s1[i]=='9')
				{num=num+(9*k);m++;}
			else if(s1[i]=='A'||s1[i]=='a')
				{num=num+(10*k);m++;}
			else if(s1[i]=='B'||s1[i]=='b')
				{num=num+(11*k);m++;}
			else if(s1[i]=='C'||s1[i]=='c')
				{num=num+(12*k);m++;}
			else if(s1[i]=='D'||s1[i]=='d')
				{num=num+(13*k);m++;}
			else if(s1[i]=='E'||s1[i]=='e')
				{num=num+(14*k);m++;}
			else if(s1[i]=='F'||s1[i]=='f')
				{num=num+(15*k);m++;}	
		}
		else
		{
			if(s1[i]=='1')
				{num=num+1;m++;}
			else if(s1[i]=='0')
				{num=num+0;m++;}
			else if(s1[i]=='2')
				{num=num+2;m++;}
			else if(s1[i]=='3')
				{num=num+3;m++;}
			else if(s1[i]=='4')
				{num=num+4;m++;}
			else if(s1[i]=='5')
				{num=num+5;m++;}
			else if(s1[i]=='6')
				{num=num+6;m++;}
			else if(s1[i]=='7')
				{num=num+7;m++;}
			else if(s1[i]=='8')
				{num=num+8;m++;}
			else if(s1[i]=='9')
				{num=num+9;m++;}
			else if(s1[i]=='A'||s1[i]=='a')
				{num=num+10;m++;}
			else if(s1[i]=='B'||s1[i]=='b')
				{num=num+11;m++;}
			else if(s1[i]=='C'||s1[i]=='c')
				{num=num+12;m++;}
			else if(s1[i]=='D'||s1[i]=='d')
				{num=num+13;m++;}
			else if(s1[i]=='E'||s1[i]=='e')
				{num=num+14;m++;}
			else if(s1[i]=='F'||s1[i]=='f')
				{num=num+15;m++;}	
		}
		k=1;
	}
	Address+=num;
} 
void Data(vector<string>&Instruction,vector<string>&Tag,vector<string>&Inson,vector<string>&Arithmetic)
{
	vector<string>buf;
	for(int i=0;i<Instruction.size();i++)
	{
		string checkByte=Instruction[i];
		string newc="C'";
		string newc1="C '";
		int  coff=0;//開關 
		for(int j=0;j<checkByte.size()-1;j++)//處理BYTE C' '格式 
		{
			string ssub="";
			string bytesub="";
			ssub=ssub+checkByte[j]+checkByte[j+1];
			if(ssub==newc)
			{
				coff=1;
				for(int k=j+2;k<checkByte.size()-1;k++)
				{
					bytesub=bytesub+checkByte[k];	
				}		
				Arithmetic.push_back(bytesub); 
				string tokenc;
				stringstream ssc(Instruction[i]);
				while (ssc>>tokenc)
				{
					buf.push_back(tokenc);
				}
				Tag.push_back(buf[0]);
				Inson.push_back(buf[1]);
				break;
			}
		}
		for(int j=0;j<checkByte.size()-2;j++)//處理BYTE C ' '格式 
		{
			string ssub1="";
			string bytesub1="";
			ssub1=ssub1+checkByte[j]+checkByte[j+1]+checkByte[j+2];
			if(ssub1==newc1)
			{
				coff=1;
				for(int k=j+3;k<checkByte.size()-1;k++)
				{
					bytesub1=bytesub1+checkByte[k];	
				}		
				Arithmetic.push_back(bytesub1); 
				string tokenc1;
				stringstream ssc1(Instruction[i]);
				while (ssc1>>tokenc1)
				{
					buf.push_back(tokenc1);
				}
				Tag.push_back(buf[0]);
				Inson.push_back(buf[1]);
				break;
			}
		}
		if(coff==0) 
		{
			string token;
			stringstream ss(Instruction[i]);
			while (ss>>token)
			{
				buf.push_back(token);
			}
			if(buf.size()>2&&buf[1]=="BUFFER")
			{
				Tag.push_back("no");
				Inson.push_back(buf[0]);
				string ba="";
				for(int j=1;j<buf.size();j++)
					ba=ba+buf[j];
				Arithmetic.push_back(ba); 
			}
			else if(buf.size()==1)
			{
				Tag.push_back("no");
				Inson.push_back(buf[0]);
				Arithmetic.push_back("no");
			}
			else if(buf.size()==2)
			{
				Tag.push_back("no");
				Inson.push_back(buf[0]);
				Arithmetic.push_back(buf[1]);
			}
			else if(buf.size()==3&&buf[1]!="BUFFER")
			{
				Tag.push_back(buf[0]);
				Inson.push_back(buf[1]);
				Arithmetic.push_back(buf[2]);
			}
			else if(buf.size()>3&&buf[1]!="BUFFER")//處理BYTE  c,x 
			{
				Tag.push_back(buf[0]);
				Inson.push_back(buf[1]);
				string a="";
				for(int j=2;j<buf.size();j++)
					a=a+buf[j];
				Arithmetic.push_back(a); 
			}
		}
		buf.clear();
	}
}
