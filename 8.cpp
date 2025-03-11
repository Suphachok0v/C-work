#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <float.h>
#include <map>
#include <vector>
#include <string>
using namespace std;

class Customer {
public:
    char Name[20];
    int Age;
    char Category[20];
    char Product[20];
    float Price;

public:
    void GetCustomerInfo(const char StrMode[50]);
};

class FileHandler {
public:
    FILE *fp;
    char FilePath[100];
    Customer C[500];
    int MaxCustomer;

public:
    FileHandler(const char FilePath[100]);
    void GetFilePath();
    void ReadFile();
    void SelectMode();
};

int main() {
    FileHandler *F = new FileHandler("./output/customer.csv");
    while (1) F->SelectMode();
    return 0;
}

void FileHandler::SelectMode() {
    int Mode = 0;
    printf("Select Mode : ");
    scanf("%d", &Mode);

    if (Mode == 0) { // Exit
        printf("Thank you!\n");
        exit(0);
    } else if (Mode == 1) { // Who bought highest price
        float maxPrice = -FLT_MAX;
        int index = -1;
        for (int i = 0; i < MaxCustomer; i++) {
            if (C[i].Price > maxPrice) {
                maxPrice = C[i].Price;
                index = i;
            }
        }
        if (index != -1) C[index].GetCustomerInfo("Who bought highest price.");
    } else if (Mode == 2) { // Lines of file
        printf("File data = %d records.\n", MaxCustomer);
    } else if (Mode == 3) { // Average Price
        float totalPrice = 0;
        for (int i = 0; i < MaxCustomer; i++) {
            totalPrice += C[i].Price;
        }
        printf("Average price = %.2f\n", totalPrice / MaxCustomer);
    } else if (Mode == 4) { // Count People who age above average.
        float totalAge = 0;
        for (int i = 0; i < MaxCustomer; i++) {
            totalAge += C[i].Age;
        }
        float avgAge = totalAge / MaxCustomer;
        int count = 0;
        for (int i = 0; i < MaxCustomer; i++) {
            if (C[i].Age > avgAge) count++;
        }
        printf("Average age = %.2f.\nPeople who aged above average = %d.\n", avgAge, count);
    } else if (Mode == 5) { // Most Popular Product
        map<string, int> productCount;
        for (int i = 0; i < MaxCustomer; i++) {
            productCount[C[i].Product]++;
        }
        string popularProduct;
        int maxCount = 0;
        for (auto &p : productCount) {
            if (p.second > maxCount) {
                maxCount = p.second;
                popularProduct = p.first;
            }
        }
        printf("Most popular product = %s (sold %d times).\n", popularProduct.c_str(), maxCount);
    } else if (Mode == 6) { // Least Popular Category
        map<string, int> categoryCount;
        for (int i = 0; i < MaxCustomer; i++) {
            categoryCount[C[i].Category]++;
        }
        string leastPopularCategory;
        int minCount = INT_MAX;
        for (auto &c : categoryCount) {
            if (c.second < minCount) {
                minCount = c.second;
                leastPopularCategory = c.first;
            }
        }
        printf("Least popular category = %s (sold %d times).\n", leastPopularCategory.c_str(), minCount);
    } else {
        printf("Invalid selection. Exiting.\n");
        exit(0);
    }
}

FileHandler::FileHandler(const char FilePath[100]) {
    strcpy(this->FilePath, FilePath);
    this->ReadFile();
}

void FileHandler::ReadFile() {
    fp = fopen(FilePath, "r");
    if (!fp) {
        printf("Error opening file!\n");
        exit(1);
    }
    char line[100];
    MaxCustomer = 0;
    while (fgets(line, sizeof(line), fp)) {
        sscanf(line, "%[^,],%d,%[^,],%[^,],%f", C[MaxCustomer].Name, &C[MaxCustomer].Age,
               C[MaxCustomer].Category, C[MaxCustomer].Product, &C[MaxCustomer].Price);
        MaxCustomer++;
    }
    fclose(fp);
}

void Customer::GetCustomerInfo(const char StrMode[50]) {
    printf("--------| %-8s\n", StrMode);
    printf("%-8s : %-10s\n", "Name", this->Name);
    printf("%-8s : %-4d\n", "Age", this->Age);
    printf("%-8s : %-10s\n", "Category", this->Category);
    printf("%-8s : %-10s\n", "Product", this->Product);
    printf("%-8s : %-5.2f\n", "Price", this->Price);
}
