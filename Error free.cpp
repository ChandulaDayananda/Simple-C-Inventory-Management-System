#include <iostream>
#include <fstream>

using namespace std; 

class retail  

	
	{
		private:
			int itemcode ;
			float itemprice ;
			float discount ;
			string itemname ; 
			
		public:
			void menu () ;
			void admininstrator () ;
			void saleassist () ;
			void about () ;
			void add () ;
			void edit () ;
			void rem () ; 
			void list () ;
			void receipt () ;
			
 	};
 	
 	
 	void retail :: menu ()
		{
			m:
				int choice ;
				string username ;
				string password ;
				
			cout << "\t\t\t\t\t			SUPRIME FURNITURE \n " ;
			cout << " 1) Administrator \n " ;
			cout << " 2) Sale Assist	\n " ;
			cout << " 3) About		   \n " ;
			cout << " 4) Exit		   \n " ;
			cout << " \t\t\t	Enter Your Choice \n\n" ;
			cin >> choice ;
			
			switch ( choice ) 
				
				{
					case 1 :
						
						cout << " \t\t\t ______________Login in !__________________\n\n\n " ;
						cout << " \t\t\t\t\t Enter User Name \n " ;
						cin >> username ;
						cout << " \t\t\t\t\t Enter Password \n " ;
						cin >> password ;
						
						if ( username == "Suprime123" && password == "Suprime123" )
							{
								admininstrator () ;
							}
						else
							{
								cout << " \n\n\t\t\t\tInvalid Username & Password \n\n\n";
							}
							break ;
				
			
				
					case 2 :
						{
							saleassist () ; 
						}
						
					case 3 :
						{
							about () ;
						}
						
					case 4 :
						{
							exit ( 0 ) ;
						}
						
					default:
						{
							cout <<" \n\n\t\t\t Invalid Choice !!!\t\t\n\n\n " ;
						}
				
				}
		goto m;
		}
		
	void retail :: admininstrator ()
		
		{
			m:
				int choice ;
				
			cout << " \n\n\t\t\t\t\t _______________Welcome To Administrator Panel_______________________ \n " ;
			cout << " \t\t1) Add the Product \n\n " ;
			cout << " \t\t2) Modify the Product \n\n " ;
			cout << " \t\t3) Delete the Product \n\n " ;
			cout << " \t\t4) Back to  Menu \n\n " ;
			cout << " \t\t\t\t\t Please Enter Your Choice \n\n\n\n" ;
			cin >> choice ;
			
			switch ( choice )
			
				{
					case 1 :
						add () ;
						break ;
						
					case 2 :
						edit () ;
						break ;
						
					case 3 :
						rem () ;
						break ;
						
					case 4 :
						menu () ;
						break ;
						
					default :
						cout << " \t\t\t\t\t	Invalid Choice ! \n\n\n\n ";
				}
				goto m;
		}
	
		void retail :: about () 
	
		{
			m:
				int choice ;
				
				cout << "\t\t\t\t\t________________ Contact US!_____________\n\n\n" ;
				cout << "\t\t  1) Contact info \n\n " ;
				cout << "\t\t  2) Go Back (Press any number expext 1) \n\n " ;
				cin >> choice ;
				
				switch ( choice )
				{
					case 1 :
						cout << "\t\t\t\t\t	_____________Address is__________	\n " ;
						cout << "127/9 Kandy Road, Mulgampola \n\n\n" ;
						cout << "\t\t\t\t\t ___________Phone Number is_____________	\n " ;
						cout << "081-123-4567 \n\n\n" ;
						
					case 2 :
						menu () ;
						
					default :
						cout << " \t\t\t\t\t	Invalid Choice ! \n\n\n\n ";
				}
				goto m ;
		}
		
	void retail :: saleassist ()	
	
		{
			m:
				int choice ;
			
			cout << " \t\t\t\t\t ______________Welcome To saleassist Panel_________________ \n\n\n " ;
			cout << " \t\t 1) Buy Product \n " ;
			cout << " \t\t 2) Go Back \n\n " ;
			cout << " \t\t\t\t\t Enter Your Choice \n\n\n" ;
			cin >> choice ;
			
			switch ( choice )
			
				{
					case 1 :
						receipt () ;
						break ;
						
					case 2 :
						menu () ;
						break ;
					
					default :
						cout << " Invalid Choice " ;	
				}
				goto m ;
		}
		
	void retail :: add () 
		{
			m:
				fstream data ;
				int c ;					// c = item code ( as some of the full word for others are used in some places of the code)
				int token = 0 ;
				float p ;				// p = item price
				float d ;				// d = discount given for the item
				string n ;				// n = item name
				
			cout << " \t\t\t\t\t ________________Add New Product_______________ \n\n\n " ;
			cout << " \t\t Enter Item Code of the Product \n\n " ;
			cin >> itemcode ;
			cout << " \t\t Enter the item Name \n\n  " ;
			cin >> itemname ;
			cout << " \t\t Enter the Price of the item \n\n " ;
			cin >> itemprice ; 
			cout << " \t\t Enter the Discount for the item \n\n  " ;
			cin >> discount ;
			
		
			
			if ( !data )
				{
					data.open ( " database.txt " , ios::app|ios::out ) ;
					data << "	" << itemcode << "	" <<itemname << "	" << itemprice << "	" << discount << "	\n" ;
					data.close () ; 
				 } 
			else
				{
					data >> c >> n >> p >> d ;
					
					while ( !data.eof() )
						{
							if ( c == itemcode )
								{
									token++ ;
								}
							data >> c >> n >> p >> d ;
						 } 
					data.close() ;
					if (token == 1)
						goto m ;
					else
						{
						data.open("database.txt" , ios::app|ios::out) ;
						data << "	" << itemcode << "	" << itemname << "	" << itemprice << "	" << discount << "	\n" ;
						}
				}
			cout << " \n\n\t\t\t Record Updated Successfully ! \n\n" ;
		}
		
	void retail :: edit ()
		{
			fstream data,data1 ;
			int itemkey ;
			int token = 0 ;
			int c ;			// c = item code
			float p ;		// p = item price
			float d ;		// d = dicount given for the item
			string n ;		// n = name of the item
			
			cout << "\t\t\t\t\t _____________Modify the Record !_______________ \n\n\n " ;
			cout << " \t\t Enter a Item Code \n\n " ;
			cin >> itemkey ;
			
			data.open("database.txt" ,ios::in	) ;
			if (!data)
				{
					cout << " File doesn't exist!! \n " ; 
				}
			else
				{
					data1.open("database1.txt",ios::app|ios::out) ;
					data >> itemcode >> itemname >> itemprice >> discount ;
					
					while (!data.eof()) 
						{
							if (itemkey == itemcode)
								{
									cout << " \t\t Enter the New Product Code \n\n ";
									cin >> c ;
									cout << " \t\t Enter the Name of the New Product \n\n ";
									cin >> n ;
									cout << " \t\t Enter the Price \n\n " ;
									cin >> p ;
									cout << " \t\t Enter the Discount \n\n " ;
									cin >> d ;
									
									data1 << "	" << c << "	" << n << "	" << p << "	" << d << "	\n\n" ;
									cout << " \t\t\t\t\t _______________Record Updated________________ \n\n " ;
									token++ ; 
								}
							else
								{
									data1 << "	" << itemcode << "	" << itemname << "	" << itemprice << "	" << discount << "	\n\n\n\n" ;
								}
								data >> itemcode >> itemname >> itemprice >> discount ;
						}
						data.close() ;
						data1.close() ;
						
						remove("database.txt");
						rename("database1.txt" , "database.txt") ;
				
						if ( token == 0 )
							{
								cout << "\t\t\t\t\t ___________________Record not found! Sorry!!_______________________ \n\n\n " ;  
							}
				}
		}
		
	void retail :: rem ()
		{
			fstream data,data1 ;
			int itemkey ;
			int token = 0 ;
			
			cout << " \t\t\t Delete a Item \n\n " ;
			cout << " \t\t\t Enter Item Code \n\n" ;
			cin >> itemkey ;
			
			data.open("database.txt",ios::in) ;
			if (!data)
				{
					cout << " \t\t\t\t\t __________________File doesn't exist !!!! _______________________\n\n\n " ;
				}
			else 
				{
					data1.open("database1.txt",ios::app|ios::out) ;
					data >> itemcode >> itemname >> itemprice >> discount ;
					
					while ( !data.eof()) 
						{
							if ( itemcode == itemkey )
								{
									cout << "\n\n\n\t\t\t ___________________________Product Deleted Successfully!!!______________________________\n\n\n" ;
								} 
							else
								{
									data1 << "	" << itemcode << "	" << itemname << "	" <<itemprice << "	" << discount << "	\n" ;
								}
							data >> itemcode >> itemname >> itemprice >> discount ; 
						}
						
						data.close() ;
						data1.close(); 
						
						remove ( "database.txt") ;
						rename ( "database1.txt" , "database.txt") ;
						
						if ( token == 0) 
							{
								cout << " \n\t\t\t Record Not Found!! " ;
							}
				}
		}
		
	void retail :: list ()
		{
			fstream data ;
			data.open ("database.txt" , ios::in) ;
			
			cout << "Item Code\t\t Item Name\t\t Item Price \n " ;
			cout << "\n\n\n " ;
			
			data >> itemcode >> itemname >> itemprice >> discount ;
			
			while (!data.eof()) 
				{
					cout << itemcode <<"\t\t" << itemname << "\t\t" << itemprice << "\n" ;
					data >> itemcode >> itemname >> itemprice >> discount ; 
				}
			data.close() ;
		}
		
	void retail ::receipt ()
	
		{
			fstream data ;
			
			int arrc [100] ;
			int arrq [100] ;
			char choice ;
			int c = 0 ;
			float amount = 0 ;
			float dis = 0 ;
			float total = 0 ;
			float subtotal = 0 ;
			
			cout << "\n\n\t\t\t\t Receipt!!!! " ;
			
			data.open("database.txt", ios::in) ;
			
			if (!data)
				{
					cout << "\n\n\t\t Empty Database " ;
				}
			else
				{
					data.close();
					list () ;
					
					cout << "\n\n" ;
					cout << " \t\t\t\t\t Enter the order details \n\n\n " ;
					
					do
						{
							m:
								cout << " \t\t\t Enter Item Code \n\n " ;
								cin >> arrc [c] ;
								
								cout << " \t\t\t Enter Item Quantity \n\n " ;
								cin >> arrq [c] ;
								
								for ( int i=0 ; i<c; i++ )
									{
										if ( arrc [c] == arrc[i] )
										{
											cout << "\n\t\t\t\t\t *************Duplicate Product Code! Please Try Again!************************* \n\n\n" ;
											goto m ;	
										} 
									}
								c++ ;
								cout << "\t\t\t If you want to buy another item press y if not press n 	\n\n\n "  ;
								cin >> choice ;
						
						}
						
						while (choice == 'y') ;
						
						cout << "\n\n\t\t\t __________________Receipt_________________ \n\n\n " ;
						cout << " Item No \t Item Name \t Item Quantity \t Price \t Amount \t Amount After Discount \n " ;
						
						for (int i = 0 ; i < c ; i++ )
							{
								data.open("database.txt" , ios::in)	;
								data >> itemcode >> itemname >> itemprice >> discount;
								
								while (!data.eof())
									{
										if (itemcode == arrc[i])
											{
												amount = itemprice * arrq[i] ;
												discount = amount - ( amount * discount / 100 )  ;
												total =  total + discount ;
												
												cout << "\n "<< itemcode << "\t\t" << itemname << "\t\t" << arrq[i] << "\t\t" << itemprice << "\t" << amount << "\t\t" << discount  ;	
											}
											
											data >> itemcode >> itemname >> itemprice >> discount ;
											
											
									}
									data.close () ;
							}
							cout << "\n\n\n" ;
							cout << "\n\n\t\t\t\t\t Total amount is " << total<<"\n\n\n" ;	
							    
				}
		}
			int main ()
		{
			retail s ;
			s.menu() ;
		}