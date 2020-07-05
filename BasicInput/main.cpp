#include <iostream>

using namespace std;

class Questionnaire {
public:
    static void age();
};

int main() {
    Questionnaire::age();
    return 0;
}

void Questionnaire::age() {
    int age;
    char answer;

    cout << "what is your age?" << endl;
    cin >> age;
    cout << "You said you were " << age << " years old is that correct? (y/n)" << endl;
    cin >> answer;

    if(answer == 'y'){
        cout << "Thank you for telling me you are " << age << " years old";
    } else {
        cout << "Then what is your age" << endl;
        cin >> age;
    }

}