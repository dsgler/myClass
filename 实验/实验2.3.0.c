#include <stdio.h>  
  
double calculate_tax_if(double salary) {  
    double tax = 0.0;  
  
    if (salary >= 5000) {  
        tax += (salary - 4999) * 0.25;  
        salary = 4999;  
    }  
    if (salary >= 4000) {  
        tax += (salary - 3999) * 0.20;  
        salary = 3999;  
    }  
    if (salary >= 3000) {  
        tax += (salary - 2999) * 0.15;  
        salary = 2999;  
    }  
    if (salary >= 2000) {  
        tax += (salary - 1999) * 0.10;  
        salary = 1999;  
    }  
    if (salary >= 1000) {  
        tax += (salary - 999) * 0.05;  
    }  
  
    return tax;  
}  
  
int main() {  
    double salary;  
    printf("请输入工资金额：");  
    scanf("%lf", &salary);  
  
    double tax = calculate_tax_if(salary);  
    printf("应收取税金额度为：%.2lf元\n", tax);  
  
    return 0;  
}  
