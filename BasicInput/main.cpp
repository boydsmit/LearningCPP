#include <iostream>

using namespace std;

class questionnaire {
public:
    static bool isYes(char answer);
    static void age();
};

int main() {
    questionnaire::age();
    return 0;
}

bool questionnaire::isYes(char answer) {
    return answer == 'y';
}

void questionnaire::age() {
    int age;
    char answer;

    cout << "what is your age? \n";
    cin >> age;
    cout << "You said you were " << age << " years old is that correct? (y/n) \n";
    cin >> answer;

    if(questionnaire::isYes(answer)){
        cout << "Thank you for telling me you are " << age << " years old";
    } else {
        cout << "Then what is your age \n";
        cin >> age;
    }

}