#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int choice, month, year,yearsum = 0,k,i,day;
int nummonth[]={0,31,31,31,31,31,31,30,30,30,30,30};
//بنظر من اگر در آخر 29 بگذارم بی معنی است چون به هرحال از 1 اسفند به بعد حساب نمیشود و در عوض آن سالی که کبیسه است را 366 روزه قرار دادم
int attempts =1;
int daylen=0;
//مثل این است که ما در روز 29 اسفند سال 1205 قرار داریم حال آن یکی دو روز اختلاف هم حساب میکنیم.
//پس 31 روز اول را هم حساب میکند
void Calendar(int choice,int month,int year,int yearsum,int k,int i,int day);
void lobby(int choice,int month,int year,int yearsum,int k,int i,int day);
void age(int choice,int month,int year,int yearsum,int k,int i,int day);
void Calendar(int choice,int month,int year,int yearsum,int k,int i,int day){
    printf("\n");
    yearsum =0;
    year =0;
    month =0;
    k=0;
    i=0;
    printf("press [0] to lobby\n");
    printf("Enter year: ");
    scanf("%d", &year);
    if (year == 0) {
        attempts -=1;
        system("cls");
        lobby(choice,month,year,yearsum,k,i,day);
    }
    if (year > 1489 || year < 1206) {
        system("cls");
        printf("Invalid input\n----------------------------\n");
        Calendar(choice,month,year,yearsum,k,i,day);
    }
    printf("Enter month: ");
    scanf("%d", &month);
    printf("\n");
    if (month == 0) {
        attempts -=1;
        system("cls");
        month=0;
        lobby(choice,month,year,yearsum,k,i,day);
    }
    while(month>12||month<0){
      system("cls");
      printf("pay attention!\n");
      printf("press [0] to lobby\n");
      printf("Enter year: %d \n",year);
      printf("please enter month: ");
      scanf("%d",&month);
    }
    //چون سالی که دادیم کامل نیست.باید یکی کمتر از سال ما مجموع 365 یا 366 را حساب کند
    for (int i = 1206;i< year; ++i) {
        if ((i % 4 == 0 && i % 100 != 0) || (i % 400 == 0)) {
            yearsum += 366;
        }else{
            yearsum += 365;
        }
    }
    system("cls");
    //چون آن ماهی که من دادم کامل نیست و یکی کمتر از آن را حساب میکند
    for(int i=0;i<month;++i){
        yearsum +=nummonth[i];
    }
    switch (month){
    case 1:
        printf("        Farvardin");
        break;
    case 2:
        printf("        Ordibehesht");
        break;
    case 3:
        printf("        Khordad");
        break;
    case 4:
        printf("        Tir");
        break;
    case 5:
        printf("        Mordad");
        break;
    case 6:
        printf("        Shahrivar");
        break;
    case 7:
        printf("        Mehr");
        break;
    case 8:
        printf("        Aban");
        break;
    case 9:
        printf("        Azar");
        break;
    case 10:
        printf("        Dey");
        break;
    case 11:
        printf("        Bahman");
        break;
    case 12:
        printf("         Sfand");
        break;
    }
    printf("\n");
    yearsum -=1;//خطا
    //چون 1206 1 فروردین پنج شنبه هست.برای پیدا کردن چند شنبه بودن اول ماه,باید عددمان را +6 کنیم و باقی مانده اش تقسیم 7 همان جواب ما است
    k = (yearsum+6)%7;/////////////////////////////////////////////////////////////////////////////////////
    int a=0;
    printf("\nSH YE DO SE CH PA JO\n");
    for(int i=0;i<3*k-3;i++){
        printf(" ");
        a+=1;
    }
    for(int i=1;i<31;i++){
        printf("%2d ",i);
        a+=3; 
        if(a>20){
            printf("\n");
            a=0;
        }
    }
    if(month==12){
        if((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)){ 
            printf("31"); 
        }
    }
    printf("\n");
    while(month!=0){
      yearsum =0;
      printf("press [0] to lobby\n");
      printf("Enter month: ");
      scanf("%d", &month);
      printf("\n");
      if (month == 0) {
          attempts -=1;
          system("cls");
          month=0;
          lobby(choice,month,year,yearsum,k,i,day);
      }
      while(month>12||month<0){
        system("cls");
        printf("pay attention!\n");
        printf("press [0] to lobby\n");
        printf("Enter year: %d \n",year);
        printf("please enter month: ");
        scanf("%d",&month);
      }
      //چون سالی که دادیم کامل نیست.باید یکی کمتر از سال ما مجموع 365 یا 366 را حساب کند
      for (int i = 1206;i< year; ++i) {
          if ((i % 4 == 0 && i % 100 != 0) || (i % 400 == 0)) {
              yearsum += 366;
          }else{
              yearsum += 365;
          }
      }
      system("cls");
      //چون آن ماهی که من دادم کامل نیست و یکی کمتر از آن را حساب میکند
      for(int i=0;i<month;++i){
          yearsum +=nummonth[i];
      }
      switch (month){
      case 1:
          printf("        Farvardin");
          break;
      case 2:
          printf("        Ordibehesht");
          break;
      case 3:
          printf("        Khordad");
          break;
      case 4:
          printf("        Tir");
          break;
      case 5:
          printf("        Mordad");
          break;
      case 6:
          printf("        Shahrivar");
          break;
      case 7:
          printf("        Mehr");
          break;
      case 8:
          printf("        Aban");
          break;
      case 9:
          printf("        Azar");
          break;
      case 10:
          printf("        Dey");
          break;
      case 11:
          printf("        Bahman");
          break;
      case 12:
          printf("         Sfand");
          break;
      }
      printf("\n");
      yearsum -=1;//خطا
      //چون 1206 1 فروردین پنج شنبه هست.برای پیدا کردن چند شنبه بودن اول ماه,باید عددمان را +6 کنیم و باقی مانده اش تقسیم 7 همان جواب ما است
      k = (yearsum+6)%7;/////////////////////////////////////////////////////////////////////////////////////
      int a=0;
      printf("\nSH YE DO SE CH PA JO\n");
      for(int i=0;i<3*k-3;i++){
          printf(" ");
          a+=1;
      }
      for(int i=1;i<31;i++){
          printf("%2d ",i);
          a+=3; 
          if(a>20){
              printf("\n");
              a=0;
          }
      }
      if(month==12){
          if((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)){ 
              printf("31"); 
          }
      }
      printf("\n");
    }
    if(month==0){
      system("cls");
      lobby(choice,month,year,yearsum,k,i,day);
    }
}
void Age(int choice,int month,int year,int yearsum,int k,int i,int day){
    yearsum=0;
    int monthlen=0;
    int yearlen=0;
    int nummonth[] ={0,31,31,31,31,31,31,30,30,30,30,30,29};
    printf("Year: ");
    scanf("%d",&year);
    if(year==0){
        attempts -=1;
        system("cls");
        lobby(choice,month,year,yearsum,k,i,day);
    }
    if(year<1200||year>1402){
        system("cls");
        printf("Invalid input\n----------------------------\n");
        Age(choice,month,year,yearsum,k,i,day);
    }
    printf("month: ");
    scanf("%d",&month);
    if(month==0){
        attempts -=1;
        system("cls");
        lobby(choice,month,year,yearsum,k,i,day);
    }
    if(month>12||month<1){
        system("cls");
        printf("Invalid input\n----------------------------\n");
        Age(choice,month,year,yearsum,k,i,day);
    }
    printf("Day:");
    scanf("%d",&day);
    if(day==0){
        attempts -=1;
        system("cls");
        lobby(choice,month,year,yearsum,k,i,day);
    }
    if(day>365||day<0){
        system("cls");
        printf("Invalid input\n----------------------------\n");
        Age(choice,month,year,yearsum,k,i,day);
    }
    yearsum +=2;//فاصله ابتدای روز تا انتهای روز بعدی 2 روز است
    if(year<1402){
        for (int i = year+1;i< 1402; ++i) {
            if ((i % 4 == 0 && i % 100 != 0) || (i % 400 == 0)) {
                yearsum += 366;
            }else{
                yearsum += 365;
            }
        }
        for(i=month+1;i<=12;i++){
            yearsum +=nummonth[i];
        }
        yearsum += nummonth[month] - day;
        if(day>nummonth[month]){
            system("cls");
            printf("\npay attention!\n");
            Age(choice,month,year,yearsum,k,i,day);
        }
        yearsum +=276;//مبدا را سال 1402 ماه 10 انتخاب کردم و روز 1 به همین دلیل 276 روز باقی را جمع کردم
    }
    //خطا
    if((year % 4 != 0 && year % 100 != 0) || (year % 400 != 0)){
        yearsum +=1;
    }
    if(year==1402){
        if(month>10){
            system("cls");
            printf("please pay attention!\n");
            Age(choice,month,year,yearsum,k,i,day);
        }
        for(i=month+1;i<=9;i++){
            yearsum +=nummonth[i];
        }
        yearsum += nummonth[month] - day;
        if(day>nummonth[month]){
            system("cls");
            printf("\npay attention!\n");
            Age(choice,month,year,yearsum,k,i,day);
        }
    }
    if(year==1402&&month==10){
        yearsum =1;
        daylen =1;
    }
    system("cls");
    printf("press [0] to lobby\n------------------------------------------------------");
    printf("\nFrom your date to 10/01/1402, %d days have passed,",yearsum);
    printf("you were born in ");
    k = (yearsum%7);////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        switch (k){
        case 6:
            printf("Shanbe");
            break;
        case 5:
            printf("Yekshanbe");
            break;
        case 4:
            printf("Doshanbe");
            break;
        case 3:
            printf("Seshanbe");
            break;
        case 2:
            printf("Chaharshanbe");
            break;
        case 1:
            printf("Panjshanbe");
            break;
        case 0:
            printf("Jomeh");
            break;
        }
    printf("\n");
    yearlen = 1402-year;
    monthlen = 10-month;
    daylen = 1-day;
    if(daylen<0){
        daylen +=30;
        monthlen -=1;
    }
    if(monthlen<0){
        monthlen +=12;
        yearlen -=1;
    }
    //خود عمل تفریق دو عدد از هم دیگر است
    // عدد 1402/10/01 را از اعدد مثلا 1383/10/08 کم میکنیم
    //ابتدا از 1 8 را کم کنیم چون منفی می آید از ماه میگیرم 30 تا به روز اضافه و ...
    day+=1;//خطا
    printf("you have %d year,%d month and %d days",yearlen,monthlen,daylen);
    printf("\n");
    Age(choice,month,year,yearsum,k,i,day);
}
void lobby(int choice,int month,int year,int yearsum,int k,int i,int day){
    if(attempts==0){
        printf("back to menu!\n");
        attempts =+1;
    }
    printf("\033[32m");
    printf("\nplease choice your demand\n");
    printf("[0] Quit\n[1] Calendar\n[2] Age\n");
    printf("\033[37m");
    scanf("%d", &choice);
    switch(choice){
        case 0:
            system("cls");
            printf("Bye!\n");
            exit(0);
            break;
        case 1:
            system("cls");
            Calendar(choice,month,year,yearsum,k,i,day);
            break;
        case 2:
            system("cls");
            printf("end of history is 1402/10/01\n"); 
            printf("press [0] return lobby\n");
            Age(choice,month,year,yearsum,k,i,day);
            break;
        default:
            system("cls");
            printf("\ninvalid input!\n---------------------------------------------\n");
            return lobby(choice,month,year,yearsum,k,i,day);
    }
}
int main(){
    system("cls");
    lobby(choice,month,year,yearsum,k,i,day);
    return 0;
}