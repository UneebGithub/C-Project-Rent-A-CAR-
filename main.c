/*
username:admin
password: 12a
////////////////////////////////
Current Advisor:Sir Nuhman UlHaq.
////////////////////////////////


The Project Of PF;
Project Name: Rent A Car Management System
Group Memebers: 6
Group Member Names:
Khawaja Uneeb Ullah (Leader)
sp22-bcs-120
Mohib Lodhi 
sp22-bcs-122
Khizar Lodhi
sp22-bcs-081
Hamza Ali
sp22-bcs-107
Wajeeh Ullah
sp22-bcs-147
Ibraheem
sp22-bcs-131

*/
#include<stdio.h>
#include<windows.h>
#include<string.h>
#include<conio.h>
#include<mmsystem.h>
//void load();
//void wid();

static int back;
static int r[5],rent1[5],total[5]={10,10,10,10,10},pay[5];
struct rent{
	char name[20];
	int CNIC;
	char adr[50];
	int phone;
	char mail[50];
	char today[10];
	char return_date[10];
	char car_name[10];
	char car_no[8];
	int numbers_cars;
	char city_from[10];
	char city_to[10];
	int payment;
	char res_py;
	int rent_day;
	int pay;
	
};//user info
struct menubar{
	int number;
};//menu bar input
struct login{
	char username[10];
	char pass[3];
};//login
void rent_user(){
	printf("<--Back(0)\n");
	printf("\n");
    char another;
     FILE *fp;
     int n,i;
     struct rent info;
    // struct car_disk cd;
   do{
       system("cls");
       printf("\t\t\t\t=======Add USER Info=======\n\n\n"); 
       fp=fopen("information.txt","a"); //use can give any file name. Give the name with extention or without extention.
         	printf("\n\t\t\tEnter Your Name: ");
         	scanf("%s",&info.name);
         	printf("\n\t\t\tCNIC:");
         	scanf("%d",&info.CNIC);
         	printf("\n\t\t\tAddress:");
         	scanf("%s",&info.adr);
         	printf("\n\t\t\tEnter Your Personal Number:");
         	scanf("%d",&info.phone);
         	printf("\n\t\t\tEnter Your E-Mail:");
         	scanf("%s",&info.mail);
         	printf("\n\t\t\tEnter Today Date: ");
         	scanf("%s",&info.today);
         	printf("\n\t\t\tEnter Return Date:");
         	scanf("%s",&info.return_date);
         	printf("\n\t\t\tCity From :");
         	scanf("%s",&info.city_from);
         	printf("\n\t\t\tCity To:");
         	scanf("%s",&info.city_to);
         	printf("\n\t\t\tCar Name:");
         	scanf("%s",&info.car_name);
         	printf("\n\t\t\tEnter Numbers Of Cars:");
         	scanf("%d",&info.numbers_cars);
         	printf("\n\t\t\tReturn days:");
         	scanf("%d",&info.rent_day);
         	if(strcmp(info.car_name,"kia")==0){
         		if(info.numbers_cars>total[0]){
         			printf("sorry try again.");
         			getch();
         			system("cls");
         			menu();
				}
				 else{
				 
				info.pay=5600*info.numbers_cars*info.rent_day;
				r[0]=rent1[0]+info.numbers_cars;
				total[0]=10-info.numbers_cars;	 
			 }
		}
			else if(strcmp(info.car_name,"bmw")==0){
				if(info.rent_day>total[1]){
         			printf("sorry try again.");
         			getch();
         			system("cls");
         			menu();
				 }
			  else{
				 
				info.pay=7600*info.numbers_cars*info.rent_day;
				r[1]=rent1[1]+info.numbers_cars;
				total[1]=10-info.numbers_cars;	 
			 }
		}
			 else if(strcmp(info.car_name,"alto")==0){
			 	if(info.rent_day>total[2]){
         			printf("sorry try again.");
         			getch();
         			system("cls");
         			menu();
				 }
				 else{
				 
				info.pay=3000*info.numbers_cars*info.rent_day;
				r[2]=rent1[2]+info.numbers_cars;
				total[2]=10-info.numbers_cars;	 
			 }
		}
			 else if(strcmp(info.car_name,"suzuki")==0){
			 	if(info.rent_day>total[3]){
         			printf("sorry try again.");
         			getch();
         			system("cls");
         			menu();
				 }
				 else{
				 
				info.pay=4200*info.numbers_cars*info.rent_day;
				r[3]=rent1[3]+info.numbers_cars;
				total[3]=10-info.numbers_cars;	 
			 }
		}
		
			 else if(strcmp(info.car_name,"toyota")==0){
			 	if(info.rent_day>total[4]){
         			printf("sorry try again.");
         			getch();
         			system("cls");
         			menu();
				 }
				 else{
				 
				info.pay=5000*info.numbers_cars*info.rent_day;
				r[4]=rent1[4]+info.numbers_cars;
				total[4]=10-info.numbers_cars;	 
			 }
		}
			 printf("\n\t\t\tYour Total payment IS:%d",info.pay);
          
          printf("\n\t\t\t______________________________\n");
       
      if(fp==NULL){
        fprintf(stderr,"can't open file");
    }else{
        printf("\t\t\tRecord stored successfuly\n");
    }
    
    fwrite(&info, sizeof(struct rent), 1, fp); 
    fclose(fp);
    
    printf("\t\t\tYou want to add another record?(y/n) : ");
    
    
    scanf("%s",&another);
    
    
   }while(another=='y'||another=='Y');
   system("cls");
   menu();
}//user input disk
void rec_del(){
		
      struct rent info;
      FILE *fp, *fp1;
     
       
    int cnic,found=0;
    
       printf("\t\t\t\t=======DELETE USER RECORD=======\n\n\n");
    fp=fopen("information.txt","r");
    fp1=fopen("temp.txt","w");
    printf("\t\t\t\tEnter User CNIC : ");
    scanf("%d",&cnic);
    if(fp==NULL){
         fprintf(stderr,"DATA NOT SAVE: \n");
         getch();
         system("cls");
         menu();
         
      }
    
    while(fread(&info,sizeof(struct rent),1,fp)){
        if(info.CNIC == cnic){
          
            found=1;
        
        }else{
           fwrite(&info,sizeof(struct rent),1,fp1);
        }
  
    }
     fclose(fp);
     fclose(fp1);

    if(!found){
          printf("\n\t\t\t\tRecord not found\n");
          getch();
          system("cls");
          menu();
        }
      if(found){ 
    remove("information.txt");
        rename("temp.txt","information.txt");
        
        printf("\n\t\t\t\tRecord deleted succesfully\n");
        }
 
  getch();
          system("cls");
          menu();
  }
	
void userinfo(){
   
     FILE *fp;

    struct rent info;
    fp=fopen("information.txt","r");
    
     printf("\t\t\t\t=======USER RECORD=======\n\n\n");
      
    if(fp==NULL){
        
        fprintf(stderr,"USER DATA NOT FOUND\n");
        getch();
		system("cls");
		menu();
        
    }else{
    	
        printf("\t\t\t\tRECORDS :\n");
        printf("\t\t\t\t___________\n\n");
    }
        
        while(fread(&info,sizeof(struct rent),1,fp)){
        printf("\n\t\t\t\t Person Name  : %s",info.name);
        printf("\n\t\t\t\t Person CNIC       : %d",info.CNIC);
        printf("\n\t\t\t\t Person Adress         : %s",info.adr);
        printf("\n\t\t\t\t Phone  : %d",info.phone);
        printf("\n\t\t\t\t Payment    : %d",info.pay);
        printf("\n\t\t\t\t Mail    : %s",info.mail);
        printf("\n\t\t\t\t Date:    : %s",info.today);
        printf("\n\t\t\t\t Return Date    : %s",info.return_date);
        printf("\n\t\t\t\t CAR Name    : %s",info.car_name);
        printf("\n\t\t\t\t From    : %s",info.city_from);
        printf("\n\t\t\t\t To    : %s",info.city_to);
        
        printf("\n\t\t\t\t ________________________________\n");
      
         }
        fclose(fp);
        getch();
        system("cls");
        menu();
      
  }//userrecord disk
  void serinfo(){
       struct rent info;
      FILE *fp;
      int user_ser,found=0;
     
    fp=fopen("information.txt","r");
    printf("\t\t\t\t=======SEARCH INRENT-USER RECORD=======\n\n\n");
    printf("\t\t\tENTER THE USER CNIC NO ( without - ) : ");
   
    scanf("%d",&user_ser);
     
    char yes_no[10];
    
         
    while(fread(&info,sizeof(struct rent),1,fp)>0){
		 
        if(info.CNIC==user_ser){
           
        found=1;
        printf("\n\t\t\t\t Person Name  : %s",info.name);
        printf("\n\t\t\t\t Person CNIC       : %d",info.CNIC);
        printf("\n\t\t\t\t Person Adress         : %s",info.adr);
        printf("\n\t\t\t\t Phone  : %d",info.phone);
        printf("\n\t\t\t\t Payment    : %d",info.pay);
        printf("\n\t\t\t\t Mail    : %s",info.mail);
        printf("\n\t\t\t\t Date:    : %s",info.today);
        printf("\n\t\t\t\t Return Date    : %s",info.return_date);
        printf("\n\t\t\t\t CAR Name    : %s",info.car_name);
        printf("\n\t\t\t\t From    : %s",info.city_from);
        printf("\n\t\t\t\t To    : %s",info.city_to);
        
        printf("\n\t\t\t\t ________________________________\n");
	
	//	else{
		
		
    getch();
    system("cls");
    menu();

}
    }

     
    if(!found){
       printf("\n\t\t\tRecord not found\n");
       getch();
       system("cls");
       menu();
    }
  
    fclose(fp);
    getch();
    
}
void logout(){
	char logout_YN[3];
	printf("\t\t\t\t\t\n");
	printf("\t\t\t\t\t\n");
	printf("\t\t\t\t\t\n");
	printf("\n\n\n\n\n");
	printf("\t\t\t******************************\t\n");
	printf("\t\t\t*  DO YOU WANT TO LOG-OUT    *\t\n");
	printf("\t\t\t*                            *\t\n");
	printf("\t\t\t*                            *\t\n");
	printf("\t\t\t*   YES           NO         *\t\n");
	printf("\t\t\t*                            *\t\n");
	printf("\t\t\t*                            *\t\n");
	printf("\t\t\t*                            *\t\n");
	printf("\t\t\t*                            *\t\n");
	printf("\t\t\t* -------------------------- *\t\n");
	printf("\t\t\t*    COMSATS ABBOTTABAD      *\t\n");
	printf("\t\t\t******************************\n");
	printf("\t\t\tENTER COMMAND (yes\no): ");
	scanf("%s",&logout_YN);
	if(strcmp(logout_YN,"yes")==0){
		system("cls");
		main();
	}
	else{
		system("cls");
		menu();
	}
}
 


  
	
void car_info(){
	//struct car_disk cd;	
	printf("<--BACK(0)\n");
	printf("NAME\t\tPAYMENT\tINRENT\tTOTAL\n");
	printf("KIA\t\t5600\t%d\t%d\n",r[0],10);
	printf("ALTO\t\t3200\t%d\t%d\n",r[1],10);
	printf("BMW \t\t7600\t%d\t%d\n",r[2],10);
	printf("Toyota\t\t5500\t%d\t%d\n",r[3],10);
	printf("Suzuki\t\t4400\t%d\t%d\n",r[4],10);
	printf("\t\t\tENTER COMMAND: ");
	scanf("%d",&back);
	if(back==0){
		system("cls");
		menu();
	}
	
}//car info disk

void about(){
	printf("\t\t\t\t\t\n");
	printf("<--BACK\n");
	printf("\t\t\t\t\t\n");
	printf("\t\t\t\t\t\n");
	printf("\n\n\n\n\n");
	printf("\t\t\t    PRESS ENTER FOR BACK:\n ");
	printf("\t\t\t******************************\t\n");
	printf("\t\t\t*Current Advisor:Nuhman UlHaq*\t\n");
	printf("\t\t\t******************************\t\n");
	printf("\t\t\t* GROUP LEADER: UNEEBULLAH   *\t\n");
	printf("\t\t\t*         (SP22-BCS-120)     *\t\n");
	printf("\t\t\t*      ->Mohib Lodhi         *\t\n");
	printf("\t\t\t*        (SP22-BCS-122)      *\t\n");
	printf("\t\t\t*      ->Wajeeh Ullah        *\t\n");
	printf("\t\t\t*        (SP22-BCS-147)      *\t\n");
	printf("\t\t\t*      ->Khizar Lodhi        *\t\n");
	printf("\t\t\t*         (Sp22-BCS-081)     *\t\n");
	printf("\t\t\t*      ->Hamza Ali           *\t\n");
	printf("\t\t\t*         (Sp22-BCS-107)     *\t\n");
	printf("\t\t\t*      ->Ibraheem            *\t\n");
	printf("\t\t\t*         (Sp22-BCS-131)     *\t\n");
	printf("\t\t\t*                            *\t\n");
	printf("\t\t\t* -------------------------- *\t\n");
	printf("\t\t\t*    COMSATS ABBOTTABAD      *\t\n");
	printf("\t\t\t******************************\t\n");
	printf("\t\t\tPRESS ENTER: ");
	getch();
	system("cls");
	menu();
}
void exit_program(){
	char exit[3];
	printf("<--BACK\n");
	printf("\t\t\tPRESS NO FOR BACK: ");
	printf("\t\t\t\t\t\n");
	printf("\t\t\t\t\t\n");
	printf("\t\t\t\t\t\n");
	printf("\n\n\n\n\n");
	printf("\t\t\t******************************\t\n");
	printf("\t\t\t*  DO YOU WANT TO EXIT       *\t\n");
	printf("\t\t\t*                            *\t\n");
	printf("\t\t\t*                            *\t\n");
	printf("\t\t\t*   YES           NO         *\t\n");
	printf("\t\t\t*                            *\t\n");
	printf("\t\t\t*                            *\t\n");
	printf("\t\t\t*                            *\t\n");
	printf("\t\t\t*                            *\t\n");
	printf("\t\t\t* -------------------------- *\t\n");
	printf("\t\t\t*    COMSATS ABBOTTABAD      *\t\n");
	printf("\t\t\t******************************\t\n");
	printf("\t\t\tENTER COMMAND: ");
	scanf("%s",&exit);
	if(strcmp(exit,"yes")==0){
		
		system("cls");
		printf("\n\n\n");
		printf("\t\t\tTHANK YOU FOR USING MY SOFTWARE\n");
		Sleep(8000);
		getch();
	}
	else{
		system("cls");
		menu();
	}
	
}

void menu(){
	struct menubar nb;
	printf("\t\t WELLCOME TO RENT A CAR MANAGEMENT SYSTEM.\n");
	printf("\t\t\tNOTE:USE NUMBERS FOR SELECTING\n");
	printf("\n");
	printf("\t\t\t1)Cars Info\n ");
	printf("\t\t\t2)User Info\n ");
	printf("\t\t\t3)Add New Record \n ");
	printf("\t\t\t4)Del User Info\n ");
	printf("\t\t\t5)Search\n ");
	printf("\t\t\t6)Log-Out\n ");
	printf("\t\t\t7)About\n ");
	printf("\t\t\t8)Exit\n ");
	printf("\t\t\tENTER COMMAND: ");
	scanf("%d",&nb.number);
	if(nb.number==1){
		system("cls");
		car_info();
	}
	else if(nb.number==2){
		system("cls");
		userinfo();
	}
	else if(nb.number==3){
		system("cls");
		rent_user();
	
	}
	else if(nb.number==4){
		system("cls");
		rec_del();
	}
	else if(nb.number==5){
		system("cls");
		serinfo();
	}
	else if(nb.number==6){
		system("cls");
		logout();
	}
	else if(nb.number==7){
		system("cls");
		about();
	}
	else if(nb.number==8){
		system("cls");
		exit_program();
	}
	else{
		system("cls");
		printf("\t\t\tPlz Use Numbers (1-8):\n");
		menu();
	}
	
	

}//menu bar

int main(){
	
	struct login lg;
	//printf("\n\n\n");
	//printf("\n\n\n");
	printf("\t\t\tENTER USER NAME: ");
	scanf("%s",&lg.username);
	printf("\t\t\tENTER Password: ");
	scanf("%s",&lg.pass);
	
	if(strcmp(lg.username,"admin")==0){
		if(strcmp(lg.pass,"12a")==0){
			

			system("cls");
			printf("\n\n\n");
			printf("\n\n\n");
			printf("\t\t\tLOGIN SUCCESSFULLY ...\n");
			printf("\t\t\t WAIT 3 SEC\n");
			Sleep(2100);
			printf("\t\t\tPress Enter:");
			getch();
			system("cls");
			menu();
	
			
		
	}//password
	
	else{
		system("cls");
	
		printf("\t\t\t\aYOUR PASSWORD IS INVALID\n");
		main();
	}
	
	}//username
	
	else{
		system("cls");
		printf("\t\t\t\aUserName Invalid \n");
		main();

	}

	
	return 0;


}//main & login


///////////////////END///////////////////////////
