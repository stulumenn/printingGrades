#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
	char name;
	char surname;
	int mp1;
	int mp2;
	int f;
	double grade;
	
	FILE *fp1 = fopen("students.txt", "r");
	FILE *fp2 = fopen("grades.txt", "w");
	
	while (fscanf (fp1, "%c%c %d %d %d\n", &name, &surname, &mp1, &mp2, &f) != EOF){
		grade = mp1 * 0.3 + mp2 * 0.3 + f * 0.4;

		if (grade <= 100 && grade >= 85)
			fprintf(fp2, "%c%c A %f\n", name, surname, grade);
		else if (grade <=84 && grade >= 70)
			fprintf(fp2, "%c%c B %f\n", name, surname, grade);
		else if (grade <=69 && grade >= 65)
			fprintf(fp2, "%c%c C %f\n", name, surname, grade);
		else if (grade <=64 && grade >= 40)
			fprintf(fp2, "%c%c D %f\n", name, surname, grade);
		else if (grade <=39 && grade >= 0)
			fprintf(fp2, "%c%c F %f\n", name, surname, grade);
	}
	
	printf ("DONE\n");
	fclose (fp1);
	fclose (fp2);
	return 0;
}