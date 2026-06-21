#include <iostream>

using namespace std;

// Node structure to represent each customer
struct Customer {
    int ticketNumber;
    Customer* next;
};

class BankQueue {
private:
    Customer* front; // Points to the first person in line
    Customer* rear;  // Points to the last person in line
    int ticketCounter; // Generates the next ticket number

public:
    // Constructor to initialize an empty queue
    BankQueue() {
        front = nullptr;
        rear = nullptr;
        ticketCounter = 1;
    }

    // ENQUEUE: Add a customer to the rear of the line
    void enqueue() {
        Customer* newCustomer = new Customer();
        newCustomer->ticketNumber = ticketCounter++;
        newCustomer->next = nullptr;

        // If the queue is empty, front and rear are the same
        if (rear == nullptr) {
            front = rear = newCustomer;
        }
        else {
            // Add the new customer to the end and update the rear pointer
            rear->next = newCustomer;
            rear = newCustomer;
        }
        cout << "[+] SUCCESS: Customer with Ticket #" << newCustomer->ticketNumber << " joined the queue.\n";
    }

    // DEQUEUE: Call the next customer to the counter
    void dequeue() {
        // Underflow check: Is the queue empty?
        if (front == nullptr) {
            cout << "[-] ERROR: The queue is empty! No customers to serve.\n";
            return;
        }

        // Store the current front to delete it from memory later
        Customer* temp = front;
        cout << "[*] SERVING: Customer with Ticket #" << temp->ticketNumber << " please proceed to the counter.\n";

        // Move front pointer to the next customer
        front = front->next;

        // If the queue becomes empty after serving, reset rear to nullptr
        if (front == nullptr) {
            rear = nullptr;
        }

        // Free up the memory (super important in C++)
        delete temp;
    }

    // QUEUE FRONT: Peek at the next customer without removing them
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

    // Interactive Menu Loop
    while (true) {
        cout << "\n=================================\n";
        cout << "  BANK COUNTER TICKETING SYSTEM   \n";
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