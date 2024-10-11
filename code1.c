// Name: Gavin Billinger
// KUID: 3107788
// Lab Session: Friday 4p.m.
// Lab Assignment: Lab 05
// Description: Takes an input file and uses it to output sales reports.

#include <stdio.h>

void generateSortedSales(float sales[], const char* months[]){
	printf("\nSales Report (highest to lowest))\n\n");
	printf("Month\t\tSales\n");
	for (int i = 0; i < 12; i++){
		if (months[i] == "December" || months[i] == "November" || months[i] == "September" || months[i] == "February"){
			printf("%s\t%.2f\n", months[i], sales[i]);
		}
		else{
			printf("%s\t\t%.2f\n", months[i], sales[i]);
		}
		}
	printf("\n\n");
}

void generateMovingAverage(float sales[], const char* months[]){
	printf("Six-Month moving average report:\n\n");
	for (int i = 5; i < 12; i++){
		// We get the average of the current six.
		float total;
		float average;
		total = sales[i-5] + sales[i-4] + sales[i-3] + sales[i-2] + sales[i-1] + sales[i];
		average = total/6.0;
		// Now we simply print.
		printf("%s-%s\t%.2f\n", months[i-5], months[i], average);
	}
	printf("\n");
}

void generateSalesSummary(float sortedSales[], const char* sortedMonths[]){
	// We'll want the average for later, no better time than now.
	float total;
	float average;
	for (int i = 0; i < 12; i++){
		total += sortedSales[i];
	}
	average = total/12.0;

	// Now back to printing.
	printf("Sales summary report:\n\n");
	printf("Minimum sales: %.2f (%s)\n", sortedSales[11], sortedMonths[11]);
	printf("Maximum sales: %.2f (%s)\n", sortedSales[0], sortedMonths[0]);
	printf("Average sales: %.2f\n\n", average);
	printf("\n");
}

void generateMonthlySales(float sales[], const char* months[]){
	printf("\nMonthly Sales Report for 2024\n\n");
	printf("Month\t\tSales\n");
	for (int i = 0; i < 12; i++){
		if (i == 1 || i == 8 || i == 10 || i == 11){
			printf("%s\t%.2f\n", months[i], sales[i]);
		}
		else{
			printf("%s\t\t%.2f\n", months[i], sales[i]);
		}
	}
	printf("\n");
}

int main(){
	const char* months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
	float sales[12];

	FILE *fp = fopen("input.txt", "r");
	for (int i = 0; i < 12; i++){
		fscanf(fp, "%f", &sales[i]);
	}

	fclose(fp);

	/* I'll keep this code in case I ever want to print check
	for (int i = 0; i < 12; i++){
		printf("%.2f\n", sales[i]);
	}
	*/

	// Later we'll want a sorted version of the sales numbers so...
	float sortedSales[12]; // Initialize sorted list for sales
	const char* sortedMonths[12]; // Initialize sorted list for months
	float copy_sales[12];  // Initialize copy list for sales.
	// Create a copy sales list (in Python you can't just set a list equal to another list to create two lists. 
	// I don't know if that's how it works in C so to be safe I'll just create a copy).
	for (int i = 0; i < 12; i++){
		copy_sales[i] = sales[i]; // Copy is easily made with this for loop.
	}
	int index; // Initialize index variable.
	int ctr = 0; // Initialize counter.
	for (int j = 0; j < 12; j++){
		float max = copy_sales[0]; // Set max by default to sales[0]
		index = 0; // Set index to 0 by default.
		for (int i = 0; i < 12; i++){
			if (max < copy_sales[i]){ // Check max.
				max = copy_sales[i]; // Replace max with new max
				index = i; // Keep track of index of current max.
			}
		}
		sortedSales[j] = max; // Put max at available front of sorted list.
		sortedMonths[j] = months[index]; // Add the max variables corresponding month using index.
		copy_sales[index] = -1; // Replace max in copy with garbage value (this is why we needed a copy).
	}

	/* I keep this code in case I ever want to print check my values.
	for (int i = 0; i < 12; i++){
		printf("%s\t%.2f\n", sortedMonths[i], sortedSales[i]);
	}*/
	
	// Now we will generate the Monthly Sales Report
	generateMonthlySales(sales, months);
	// Then the Sales Summary
	generateSalesSummary(sortedSales, sortedMonths);
	// Next is the Six-Month moving average
	generateMovingAverage(sales, months);
	// Finally, print Sales Report from highest to lowest
	generateSortedSales(sortedSales, sortedMonths);

	return 0;
}
