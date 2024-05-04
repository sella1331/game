#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>



using namespace std;
// Game World Jumble
int main() {
    enum field {WORD, HINT, NUM_FIELDS};
    int count = 0;
    int choice = 0;
    const int NUM_WORLDS = 11;
    const string WORLDS[NUM_WORLDS][NUM_FIELDS] = {
            {"young", "Молодой на английском языке"},
            {"example", "Пример на английском языке"},
            {"mountain", "Гора на английском языке"},
            {"answer", "Отвечать на английском языке"},
            {"word", "Слово на английском языке"},
            {"nothing", "Ничего на английском языке"},
            {"surface", "Поверхность на английском языке"},
            {"wheel", "Колесо на английском языке" },
            {"possible", "Возможность на английском языке"},
            {"thousand", "тысяча на английском языке"},
            {"distant", "отдаленный на английском языке"}


    };

// выбор случайного слова из вариантов
    while ( count != 5){
srand(static_cast<unsigned int>(time(0)));
        choice = (rand() % NUM_WORLDS);
        string theWorld = WORLDS[choice][WORD];// слово
        string  theHint = WORLDS[choice][HINT];//подсказка для слова

        string jumble = theWorld;
        int length = jumble.size();
        for (int i = 0; i < length; ++i) {
            int index1 = (rand() % length);
            int index2 = (rand() % length);

            char temp = jumble[index1];
            jumble[index1] = jumble[index2];
            jumble[index2] = temp;
        }
        // Текст консоли

        cout << "\t\t Hi, это игра называется Словомеска!\n\n";
        cout << "Попробуй угадать загаданное слово. \n";
        cout << "Введи 'go' для начала.\n";
        cout << "Введи 'exit' для выхода.\n\n";
        cout << "За каждое угаданное слово тебе будет начислятся 1 балл.\n";
        cout << "Играем до 5 очков!\n";
        cout << "Твой счет: "<< count<<endl;
        cout << "Это слово: " << jumble;
        string guess;
        cout << "\n\nТвой выбор(go/exit):  ";
        cin >> guess;
        if( guess == "go"){
            cout << theHint;
        }
        else {
            break;
        }


        while (guess != theWorld){
            cout << "\n\nТвое слово: ";
            cin >> guess;
            if(guess == theWorld){
                count++;
                cout << "Да здравствует победитель! Верно.\n\n";
                cout << string( 100, '\n' );
                break;
            }
            else if (guess == "exit") {
                exit(1);
            }
            else {
                cout << "Увы, пока не оно";
                continue;
            }
            cout << "\n\nТвое слово: ";


        }

    }

    if(count == 5){
        cout << "Ура, ты просто гениален. Победа. Так держать";
    }
    else {
        cout << "Пока. Еще увидимся)\n";
    }

    return 0;
}




