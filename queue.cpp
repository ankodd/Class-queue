#include <iostream>
#include <iterator>
#include <ostream>

const int max_queue_size = 100;

class Queue {
    char q[max_queue_size];
    int size;
    int putloc,getloc;

public:
    Queue(int len){ // Контсруктор класса

        if (len > max_queue_size) len = max_queue_size;

        /*если значение объекта больше максимальной вместимости
        это значение будет равным 100
         */

        else if (len <= 0) len = 1
        ; // если значение меньше/равно нулю тогда 1
        size = len;
         // размер очереди
        putloc = getloc = 0;
         // это места добавления и считывания очереди
    }

    void put(char ch) { // метод для добавления элементов в очередь
        if(putloc == size) {
            std::cout << "Queue is full" << std::endl;
            return;
        }
        /*если текущее местоположение путлока равен размеру очереди выводится
        сообщение и возвращается ничего*/

        putloc++;
        q[putloc] = ch;
        /*путлок увеличивается и текущий элемент записывается в массив*/
    }

    char get() { // метод для чтения очереди(в данном случае для вывода)
        if (getloc == putloc) {
            std::cout << "Queue is empty" << std::endl;
            return 0;
        }

        /*Проверяется если путлок ни разу не увеличился
        значит он 0 а значит очередь пуста выводится сообщение
        и возвращается ноль*/

        getloc++;
        return q[getloc];

        //индекс элемента увеличивается и возвращается элемент с текущим индексом
    }
};

int main(){

    Queue qMax(100);
    Queue qSmall(7);
    char ch;

    std::cout << "Using qMax to store the alphabet" << std::endl;
    for(int i = 0; i < 26;++i)
        qMax.put('A' + i);

    std::cout << "Contents of qMax:";
    for(int i = 0;i < 26;++i) {
        ch = qMax.get();
        if(ch) std::cout << ch;
    }

    std::cout << "\n\n";

    std::cout << "Using qsmall to generate errors" << std::endl;
    for(int i = 0;i < 5;++i) {
        std::cout << "Attempting to store " <<
            (char) ('Z' - i);
        qSmall.put('Z' - i);

        std::cout << std::endl;
    }
    std::cout << std::endl;

    std::cout << "Contents of qSmall: ";
    for(int i = 0;i < 5;++i) {
        ch = qSmall.get();

        if(ch) std::cout << ch;
    }

    std::cout << std::endl;
    return 0;
}
