#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef struct{
    int month, day, year;
} Date;

typedef struct{
    int ID;
    char name[50];
    Date dob;
} Employee;

Date getDate(){
    Date td;
    printf("Enter the date today (mm dd yyyy): ");
    scanf("%d %d %d", &td.month, &td.day, &td.year);

    return td;
}

int calculateAge(Employee* e, Date* td){
    int age = td->year-e->dob.year;
    if(e->dob.month>td->month || (e->dob.month==td->year && e->dob.day>td->day)){
        age--;
    } 
    return age;
}

void getEmployee (Employee e[], int s, FILE* f, Date td){
    for (int i = 0; i<s; i++){
        printf("Enter details for employee %d:\n", i+1);
        printf("ID (No Characters): ");
        scanf("%d", &e[i].ID);
        printf("Name: ");
        getchar();

        fgets(e[i].name, 100, stdin);
        e[i].name[strcspn(e[i].name, "\n")] = '\0';

        printf("Enter Date of Birth (mm dd yyyy): ");
        scanf("%d %d %d", &e[i].dob.month, &e[i].dob.day, &e[i].dob.year);
        int age = calculateAge(&e[i], &td);
        fprintf(f, "Employee %d:\nName: %s\nID: %d\nDate of Birth: %d-%d-%d\nAge: %d\n\n", i+1, e[i].name, e[i].ID, e[i].dob.month, e[i].dob.day, e[i].dob.year, age);
    }
}

void deleteFile(const char* filename){
    if(remove(filename)!=0){
        printf("Deletion Failed.");
        return;
    }
    printf("Deleted succesfully.");

}

int main (){
    FILE* f = fopen("employeeData.txt", "w");
    if(f==NULL){
        printf("Error");
        return 0;
    }

    Date td = getDate();
    int s;
    printf("Enter the number of employees: ");
    scanf("%d", &s);
    Employee e[s];

   
    getEmployee(e, s, f, td);

    


    fclose(f);
    // deleteFile("employeeData.txt");
}