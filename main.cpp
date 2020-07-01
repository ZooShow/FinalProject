#include <iostream>
#include <windows.h>
#include <stdlib.h>
#include <fstream>
#include <vector>

using namespace std;
//60
const int delay = 0;

void printDelay(string str) {
    for (int i = 0; i < str.length(); ++i) {
        cout << str[i] << flush;
        Sleep(delay);
    }
    cout << endl;
}


class Shape {
protected:
    string inputName;
    int column;
    int row;
    char **shape;
public:
    void setInputName(string str) {
        inputName = str;
    }

    void setShape() {
        ifstream in;
        in.open(inputName);
        if (in.is_open()) {
            string str;
            getline(in, str);
            int space = str.find(" ");
            string f = str.substr(0, space);
            str.erase(0, space);
            column = atoi(f.c_str());
            row = atoi(str.c_str());
            shape = new char *[row];
            for (int i = 0; i < row; ++i) {
                shape[i] = new char[column];
            }
            for (int i = 0; i < row; ++i) {
                getline(in, str);
                for (int j = 0; j < column; j++) {
                    shape[i][j] = str[j];
                }
            }
        }
    }

    void getShape() const {
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < column; ++j) {
                cout << shape[i][j];
            }
            cout << endl;
        }
    }
};

class Fedor : virtual public Shape {
public:
    void sayFirst() {
        printDelay("- Я живу как карта ляжет или как мама скажет");
    }

    void saySecond() {
        printDelay("- Никакие выходки соседей не помешают мне получить все зачеты!!!");
    }

    void sayThird() {
        printDelay(
                "- Тебе не запугать меня, преподователь по геометрии, ибо я мастер секретной техники «Чиллю но сдаю»");
    }

    void sayFourth() {
        printDelay("- Никакие алгоритмы и структуры данных не смогут меня напугать");
    }

    void sayLast() {
        printDelay("- Я пережил эту неделю и стал королем зачетов");
    }
};

class OtherPeople : public Shape {
protected:
    bool isKind;
public:
    void setIsKind(bool isKind) {
        OtherPeople::isKind = isKind;
    }

    virtual void saySomething() {};
};

class Neighbour : public OtherPeople {
public:
    void saySomething() {
        if (isKind) {
            printDelay("- Ничто не будет тревожить моих соседей никогда, и дрель у меня сломана");
        } else {
            printDelay("- Моя дрель может делать DRRRRRRRRRRRR круглые сутки");
        }
    }
};

class GeometryTeacher : public OtherPeople {
public:
    void saySomething() {
        if (!isKind) {
            printDelay("- Я дам вам всем сто мильярдов коллоков, которые необходимо выучить за два часа!!!");
        } else {
            printDelay(
                    "- Ребятки мои, лапусеньки, вот вам оценочки хорошие сразу за все 4 года обучения, и все отличные");
        }
    }
};

class AlghorithmsTeacher : public OtherPeople {
public:
    void saySomething() {
        if (!isKind) {
            printDelay(
                    "- Вот вам задание: «Взломайте пентагон при помощи ассемблерной вставки, реализовать в блокноте»");
        } else {
            printDelay("- Ну и что, что не ходил ни разу на занятия, зато человек хороший! Вот, держи зачет");
        }
    }
};

class Flat : virtual public Shape {
};

class House : virtual public Shape {
    Flat *flat;
    int flatAmount;
public:
    void buildHouse(string inputFlat) {
        this->flat = new Flat;
        flat->setInputName(inputFlat);
        flat->setShape();
        setShape();
    }

    void getRoof() const {
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < column; ++j) {
                cout << shape[i][j];
            }
            cout << endl;
        }
    }

    void setFlatAMount(int flatAmount) {
        this->flatAmount = flatAmount;
    }

    virtual void getShape() {
        getRoof();
        for (int i = 0; i < flatAmount; ++i) {
            flat->getShape();
        }
    }
};

class ShapeBuilder {
public:
    Fedor *buildFedor(string inputName) {
        Fedor *fedor = new Fedor;
        fedor->setInputName(inputName);
        fedor->setShape();
        return fedor;
    }

    House *buildHouse(int flatAmount, string inputRoof, string inputFlat) {
        House *house = new House;
        house->setFlatAMount(flatAmount);
        house->setInputName(inputRoof);
        house->buildHouse(inputFlat);
        return house;
    }

    Neighbour *buildNeibhour(string inputName, bool isKind) {
        Neighbour *people = new Neighbour;
        people->setInputName(inputName);
        people->setShape();
        people->setIsKind(isKind);
        return people;
    };

    GeometryTeacher *buildGeometryTeacher(string inputName, bool isKind) {
        GeometryTeacher *people = new GeometryTeacher;
        people->setInputName(inputName);
        people->setIsKind(isKind);
        people->setShape();
        return people;
    };

    AlghorithmsTeacher *buildAlghoritmTeacher(string inputName, bool isKind) {
        AlghorithmsTeacher *people = new AlghorithmsTeacher;
        people->setInputName(inputName);
        people->setShape();
        people->setIsKind(isKind);
        return people;
    };

};

class Storyteller {
    int firstAnswer;
    int secondAnswer;
    int thirdAnswer;
    int fourthAnswer;
public:
    void startTheStory() {
        printDelay("Эта история повествует не о мальчике, а о муже");
        printDelay("И имя ему - Федор");
        printDelay("А вот, собственно, и он");
    }

    int firstChapter() {
        printDelay("Как думаете, сколько этажей у Федора в доме?");
        cin >> firstAnswer;
        while (firstAnswer < 2) {
            printDelay(
                    "Но-но-но, все же знают, что одноэтажные дома есть либо у супер-бедных, либо у зажиточных, а наш Федор не такой");
            printDelay("Давайте вы подумаете еще раз");
            cin >> firstAnswer;
        }
        printDelay("Это дом Федора, в котором он прожил всю свою жизнь");
        return firstAnswer;
    }

    void secondChapter(string &inputName, bool &isKind) {
        printDelay("У Федора есть сосед сверху.");
        printDelay("Как думаете, насколько повезло Федору с соседом сверху?");
        cin >> secondAnswer;
        if (secondAnswer > 5) {
            isKind = true;
            inputName = "../src/neighbourKind.txt";
        } else {
            isKind = false;
            inputName = "../src/neighbourAngry.txt";
        }

    }

    void thirdChapter(string &inputName, bool &isKind) {
        printDelay(
                "Но нашему Федору не время заострять внимание на том, что делает его сосед сверху, у него самый сложный для каждого студента период - зачетная неделя");
        printDelay("И первым по списку идет геометрия");
        printDelay("Как думаете, насколько Федору повезло с преподователем геометрии?");
        cin >> thirdAnswer;
        if (thirdAnswer > 5) {
            isKind = true;
            inputName = "../src/geometryTeacherKind.txt";
        } else {
            isKind = false;
            inputName = "../src/geometryTeacherAngry.txt";
        }
    }


    void fourthChapter(string &inputName, bool &isKind) {
        printDelay("Не смотря ни на что, Федор идет к своей мечте о получении всех зачетов.");
        printDelay("После того как он идеально сдал геометрию, его ждала последняя преграда на пути к мечте");
        printDelay("И имя ей СТРУКТУРЫ И АЛГОРИТМЫ КОМПЬЮТЕРНОЙ ОБРАБОТКИ ДАННЫХ");
        printDelay("Как думаете, насколько Федору повезло с преподователем по СИФКОД?");
        cin >> fourthAnswer;
        if (fourthAnswer > 5) {
            isKind = true;
            inputName = "../src/alghoritmTeacherKind.txt";
        } else {
            isKind = false;
            inputName = "../src/alghoritmTeacherAngry.txt";
        }
    }

    void lastChapter() {
        printDelay("Но несмотря ни на что, Федя справился со всеми трудностями и стал королем зачетов!");
    }
};

void sayShape(OtherPeople *shape){
    shape->saySomething();
}

int main() {
    string inputFedor = "../src/me.txt";
    string inputRoof = "../src/roof.txt";
    string inputFlat = "../src/flat.txt";
    string inputName;
    bool isKind;


    ShapeBuilder shapeBuilder;
    Fedor *fedor;
    House *house;
    Neighbour *neighbour;
    GeometryTeacher *geom;
    AlghorithmsTeacher *alghoritm;

    fedor = shapeBuilder.buildFedor(inputFedor);

    Storyteller storyteller;

    storyteller.startTheStory();
    fedor->getShape();
    fedor->sayFirst();

    house = shapeBuilder.buildHouse(storyteller.firstChapter(), inputRoof, inputFlat);
    house->getShape();

    storyteller.secondChapter(inputName, isKind);
    neighbour = shapeBuilder.buildNeibhour(inputName, isKind);
    neighbour->getShape();
    sayShape(neighbour);
    fedor->getShape();
    fedor->saySecond();


    storyteller.thirdChapter(inputName, isKind);
    geom = shapeBuilder.buildGeometryTeacher(inputName, isKind);
    geom->getShape();
    sayShape(geom);
    fedor->getShape();
    fedor->sayThird();


    storyteller.fourthChapter(inputName, isKind);
    alghoritm = shapeBuilder.buildAlghoritmTeacher(inputName, isKind);
    alghoritm->getShape();
    sayShape(alghoritm);
    fedor->getShape();
    fedor->sayFourth();


    storyteller.lastChapter();
    fedor->getShape();
    fedor->sayLast();


    return 0;
}