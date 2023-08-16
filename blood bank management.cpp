#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

#define FILENAME "blood_bank.txt"
#define MAX_RECORDS 1000

typedef struct {
    char name1[30];
    char name2[40];
    int age;
    char gender[10];
    char blood_group[5];
    char contact_number[15];
    char reg[50];
    int wt;
} Donor;

void add_donor() {
    FILE *fp;
    Donor donor;
    int k;
    fp = fopen(FILENAME, "a");
    if (fp == NULL) {
        printf("Error: Unable to open file!\n");
        return;
    }
    printf("Enter donor's first name: ");
    scanf("%s",donor.name1);
    strupr(donor.name1);
   printf("Enter donor's last name: ");
    scanf("%s",donor.name2);
	strupr(donor.name2);
	fflush(stdin);
    printf("Enter donor registration number: ");
    scanf("%s", donor.reg);
    printf("Enter donor age: ");
    scanf("%d", &donor.age);
    fflush(stdin);
    printf("Enter donor gender: ");
    scanf("%s", donor.gender);
    strupr(donor.gender);
    printf("Enter donor weight: ");
    scanf("%d", &donor.wt);
    printf("Enter donor blood group: ");
    scanf("%s", donor.blood_group);
    strupr(donor.blood_group);
    printf("Enter donor contact number: ");
    scanf("%s", donor.contact_number);
    printf("Do you have any symptoms related to cold,flu,sore throat, cold sore?\n(press '1' for YES, press '2' for NO)\n");
    scanf("%d",&k);
    if(k==1)
    {
    	printf("\tOops,you cannot donate blood!!!\n\tAccording to WHO one needs to be in good health to be able to donate blood.\n\tThank you.\n");
    	return;
	}
    if((donor.age>65)||(donor.age<18))
    {
    	printf("\tOops,you cannot donate blood!!!\n\tAccording to WHO one needs to be aged between 18 and 65 to be able to donate blood.\n\tThank you.\n");
    	return;
	}
	if(donor.wt<45)
	{
		printf("Oops,you cannot donate blood!!!\n\tAccording to WHO one needs to have a minimum weight of 45kg to be able to donate blood.\n\tThank you.\n");
    	return;
	}
    fwrite(&donor, sizeof(Donor), 1, fp);
    printf("\tDonor added successfully!\n");
    fclose(fp);
}

void search_donor() {
    FILE *fp;
    Donor donor;
    char blood_group[5];
    int count = 0;
    fp = fopen(FILENAME, "r");
    if (fp == NULL) {
        printf("Error: Unable to open file!\n");
        return;
    }
    printf("Enter blood group to search: ");
    scanf("%s", blood_group);
    while (fread(&donor, sizeof(Donor), 1, fp) == 1) {
        if (strcmp(donor.blood_group, blood_group) == 0) {
            printf("Name: %s %s\n", donor.name1,donor.name2);
            printf("Age: %d\n", donor.age);
            printf("Weight: %d\n", donor.wt);
            printf("Gender: %s\n", donor.gender);
            printf("Blood Group: %s\n", donor.blood_group);
            printf("Contact Number: %s\n", donor.contact_number);
            printf("Registration number: %s\n", donor.reg);
            
            count++;
        }
    }
    if (count == 0) {
        printf("No donor found with blood group %s!\n", blood_group);
    }
    fclose(fp);
}

void list_donors() {
    FILE *fp;
    Donor donor;
    int count = 0;
    fp = fopen(FILENAME, "r");
    if (fp == NULL) {
        printf("Error: Unable to open file!\n");
        return;
    }
    printf("List of donors:\n");
	while (!(feof(fp)))
	{
		if(fread(&donor, sizeof(Donor), 1, fp) != 1) 
		break;
	
        printf("Name: %s %s\n", donor.name1,donor.name2);
        printf("Age: %d\n", donor.age);
        printf("Weight: %d\n", donor.wt);
        printf("Gender: %s\n", donor.gender);
        printf("Blood Group: %s\n", donor.blood_group);
        printf("Contact Number: %s\n", donor.contact_number);
        printf("Registration number: %s\n", donor.reg);
        printf("---------------------\n");
        count++;
    }
    if (count == 0) {
        printf("No donors found!\n");
    }
    fclose(fp);
}
void check_blood_units()
{
	FILE *fp;
	Donor donor;
	int a_pos=0,a_neg=0,b_pos=0,b_neg=0,ab_pos=0,ab_neg=0,o_pos=0,o_neg=0;
	int c=0;
	fp=fopen(FILENAME,"r");
	if(fp==NULL)
	{
		printf("Error: Unable to open file");
		return ;
	}
	while(fread(&donor,sizeof(Donor),1,fp)==1)
	{
		if(strcmp((donor.blood_group),"A+")==0)
		a_pos++;
		if(strcmp(donor.blood_group,"A-")==0)
		a_neg++;
		if(strcmp(donor.blood_group,"B+")==0)
		b_pos++;
		if(strcmp(donor.blood_group,"B-")==0)
		b_neg++;
		if(strcmp(donor.blood_group,"O+")==0)
		o_pos++;
		if(strcmp(donor.blood_group,"O-")==0)
		o_neg++;
		if(strcmp(donor.blood_group,"AB+")==0)
		ab_pos++;
		if(strcmp(donor.blood_group,"AB-")==0)
		ab_neg++;
	}
	printf("\t|Amount of blood present|\n");
	printf("\tA+		:%d\n",a_pos);
	printf("\tA-		:%d\n",a_neg);	
	printf("\tB+		:%d\n",b_pos);
	printf("\tB-		:%d\n",b_neg);	
	printf("\tO+		:%d\n",o_pos);
	printf("\tO-		:%d\n",o_neg);	
	printf("\tAB+		:%d\n",ab_pos);
	printf("\tAB-		:%d\n",ab_neg);
	fclose(fp);	
	}


int main() {
	HANDLE hConsole=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole,FOREGROUND_RED);
    int choice,c;
    do {
    	printf("--------------------\n");
        printf("|Blood Bank Management|\n");
        printf("---------------------\n");
        printf("1.Add Donor\n");
        printf("2.Search Don\n");
        printf("3.List of Donors\n");
        printf("4.Blood units present\n");        
        printf("5.Exit\n");
    
        scanf("%d",&choice);
        switch(choice)
        {
        	case '1':
        		add_donor();
        		break;
        		case 2:
        			search_donor();
        			break;
        			case 3:
        				list_donors();
        				break;
        				case 4:
        					check_blood_units();
        					break;
        					case 5:
        						exit(0);
        						default:
        							printf("Try again.\n");
        				}
        			}while(1);
		}
