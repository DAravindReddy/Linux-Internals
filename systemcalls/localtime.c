#include <stdio.h>
#include <time.h>

int main()
{
    time_t mytime = time(NULL);
    struct tm *ptr = localtime(&mytime);

    char *days[] = {"Sun","Mon","Tue","Wed","Thu","Fri","Sat"};
    char *months[] = {"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};

    printf("%s %s %d %02d:%02d:%02d IST %d\n",
           days[ptr->tm_wday],
           months[ptr->tm_mon],
           ptr->tm_mday,
           ptr->tm_hour,
           ptr->tm_min,
           ptr->tm_sec,
           ptr->tm_year + 1900);

    return 0;
}
