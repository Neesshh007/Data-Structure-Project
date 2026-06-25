#include <iostream>

using namespace std;

struct Customer {
    int ticketNumber;
    Customer* next;
};

class BankQueue {
private:
    Customer* front;
    Customer* rear;
    int ticketCounter;

public:
    BankQueue() {
        front = nullptr;
        rear = nullptr;
        ticketCounter = 1;
    }

    void enqueue() {
        Customer* newCustomer = new Customer();
        newCustomer->ticketNumber = ticketCounter++;
        newCustomer->next = nullptr;

        if (rear == nullptr) {
            front = rear = newCustomer;
        }
        else {
            rear->next = newCustomer;
            rear = newCustomer;
        }
        cout << "[+] SUCCESS: Customer with Ticket #" << newCustomer->ticketNumber << " joined the queue.\n";
    }

    void dequeue() {
        if (front == nullptr) {
            cout << "[-] ERROR: The queue is empty! No customers to serve.\n";
            return;
        }

        Customer* temp = front;
        cout << "[*] SERVING: Customer with Ticket #" << temp->ticketNumber << " please proceed to the counter.\n";

        front = front->next;

        if (front == nullptr) {
            rear = nullptr;
        }

        delete temp;
    }

    void viewFront() {
        if (front == nullptr) {
            cout << "[-] INFO: The queue is currently empty.\n";
        }
        else {
            cout << "[?] WAITING: The next customer in line has Ticket #" << front->ticketNumber << ".\n";
        }
    }
};

int main() {
    BankQueue bank;
    int choice;

    while (true) {
        cout << "\n=================================\n";
        cout << "   BANK COUNTER TICKETING SYSTEM   \n";
        cout << "=================================\n";
        cout << "1. Take a Ticket (Enqueue)\n";
        cout << "2. Serve Next Customer (Dequeue)\n";
        cout << "3. View Next in Line (Queue Front)\n";
        cout << "4. Exit Program\n";
        cout << "Enter your choice: ";

        if (!(cin >> choice)) {
            cout << "[-] Invalid input. Please enter a number.\n";
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }

        cout << "\n";
        switch (choice) {
        case 1:
            bank.enqueue();
            break;
        case 2:
            bank.dequeue();
            break;
        case 3:
            bank.viewFront();
            break;
        case 4:
            cout << "Shutting down system. Peace out!\n";
            return 0;
        default:
            cout << "[-] Invalid choice. Bruv, pick a number between 1 and 4.\n";
        }
    }
}