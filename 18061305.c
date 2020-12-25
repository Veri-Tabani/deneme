#include<stdio.h>
#include<stdlib.h>

struct student{
    int index;
    int studentnumber;
    int score;
    struct student* next;
};
// SELAMUN ALEYKUM
typedef struct student Student;

void display(Student* headOfList){ 
    Student* currentStudent= headOfList; 
    while(currentStudent!=NULL){ 
        printf("index no : %-3d ogrenci no : %-6d puan : %-3d\n", 
        currentStudent->index,
        currentStudent->studentnumber,
        currentStudent->score); 
        currentStudent = currentStudent->next; 
    } 
} 

void yazdir(Student* headOfList){
    printf("\nYazdir Cagrildi. Not Giriniz:\n");
    int girdi;
    scanf("%d",&girdi);
    Student* currentStudent= headOfList;
    while(currentStudent!=NULL){
        if(girdi < currentStudent -> score ){
            printf("index no : %-3d  ogrenci no : %-6d  puan : %-3d\n",
            currentStudent->index,currentStudent->studentnumber,currentStudent->score);
        }
    currentStudent = currentStudent->next;
    }
    printf("\nYazdir Fonksiyonu Calisti \n\n");
}

int searchStudent(Student* headOfList,int index){	
 	if ( headOfList == NULL){
 		return 0 ;
	}
		else{
	 	Student* currentStudent = headOfList;
 			while(currentStudent != NULL && currentStudent -> index != index ){
 			currentStudent = currentStudent -> next;
			}
				if ( currentStudent == NULL){
					return 0 ;
				}
				else{
					return 1 ;
				}
		}
}

 void Sil(Student** headOfList,int index){
 	if ( searchStudent(*headOfList,index) == 0 ){
 		printf("Listede silinecek eleman yok\n");
		}
	else{
		 Student* currentStudent = (*headOfList);
 		if(currentStudent -> next == NULL || currentStudent -> index == index){
 			(*headOfList) = currentStudent -> next;
 			free(currentStudent);	
		}
		Student* previousStudent = (*headOfList);
			while(currentStudent != NULL && currentStudent -> index != index){
		 	previousStudent = currentStudent;
		 	currentStudent = currentStudent -> next;
		 	}			
		 		if ( currentStudent != NULL){
				previousStudent -> next = currentStudent -> next;
		 		free(currentStudent);
 				}
	}		
}

void Ekle(Student **headOfList,int index,int studentnumber,int score) {
    Student* currentStudent = (*headOfList);
    Student* newStudent = (Student*)malloc(sizeof(Student));
    Student* prev = NULL;
    newStudent->index =index;
    newStudent->studentnumber = studentnumber;
    newStudent->score = score;
    newStudent->next = NULL;
    if(currentStudent == NULL){
        (*headOfList)= newStudent;
    }
    else if (score > (*headOfList)->score ){
        *headOfList = newStudent;
        newStudent->next = currentStudent;
    }
    
    else {
        while(currentStudent->next != NULL && currentStudent->next->score > score) {
            currentStudent = currentStudent->next;
        }    
        Student* next = currentStudent->next;
        currentStudent->next = newStudent;
        newStudent->next = next;
    } 
}

void degistir(Student ***headOfList,int index,int no,int score){
	Sil(*(&headOfList),index);
	Ekle(*(&headOfList),index,no,score);
	printf("Degistir fonksiyonu calisti\n");
}

int main(){
    Student* headOfList = NULL;
    Ekle(&headOfList,0,18060311,40);
    Ekle(&headOfList,1,20060045,50);
    Ekle(&headOfList,2,19061091,75);
    Ekle(&headOfList,3,20060134,90);
    Ekle(&headOfList,4,20060678,40);
    Ekle(&headOfList,5,18061086,75);
    Ekle(&headOfList,6,20060032,50);
    Ekle(&headOfList,7,20060067,60);
    Ekle(&headOfList,8,19060456,60);
    Ekle(&headOfList,9,18060245,75);
    Ekle(&headOfList,10,20060110,40);
    Ekle(&headOfList,11,20060234,90);
    Ekle(&headOfList,12,20060141,60);
    Ekle(&headOfList,13,20060011,50);
    Ekle(&headOfList,14,20060012,60);

  	display(headOfList);
  	printf("\n");
  	Sil(&headOfList, 7);
  	printf("Sil fonksiyonu calisti\n\n");
  	display(headOfList);
  	printf("\n");
  	degistir(&headOfList, 9, 18060245, 40);
  	display(headOfList);
   	yazdir(headOfList);
    return 0;
}


