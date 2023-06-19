#include <iostream>
 
struct student
{
    std::string name;
    int group;
    int ses[5];
    int ses_average = 0;
};

int main() {
    std::string namee;
    int groupe;
    int counter = 0;
    student s[5];

    std::cout << "Student names: " << std::endl;
    for (int i = 0; i < 5; i++) {
        std::cin >> s[i].name;
    }

    std::cout << "Group numbers: " << std::endl;
    for (int i = 0; i < 5; i++) {
        std::cin >> s[i].group;
    }

    for (int j = 0; j < 5; j++) {
     for (int i = 0; i < 5; i++) {
         if (s[i].group > s[j].group) {
             namee = s[i].name;
             groupe = s[i].group;
             s[i].group = s[j].group;
             s[i].name = s[j].name;
             s[j].group = groupe;  
             s[j].name = namee;     
         } else {
             continue;
         }
     }
    }

    std::cout << "Student ses: " << std::endl;
    for (int i = 0; i < 5; i++) {
        std::cout << "Student from the " << s[i].group << " group, ses" << ": " << std::endl;
        for (int j = 0; j < 5; j++) {
            std::cin >> s[i].ses[j];
        }
    }

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            s[i].ses_average = s[i].ses[j] + s[i].ses_average;
            if ( j == 4 ) {
                s[i].ses_average = s[i].ses_average / 5;
            }
        }
    }

    for (int i = 0; i < 5; i++) {
        if (s[i].ses_average > 4) {
            std::cout << "Student name: " << s[i].name << "Student group: " << s[i].group << std::endl;
            counter = 1;
        }
    }

    if (counter == 0) {
        std::cout << "All students have ses lower than 4.0 \n";
    }


    return 0;
}
