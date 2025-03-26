#include <iostream>
using namespace std;
struct Node {
    string nama;
    Node* next;
};
class ShiftKerja {
private:
    Node* head;
public:
    ShiftKerja() {
        head = nullptr;
    }
    void tambahKaryawan(string nama) {
        Node* newNode = new Node{nama, nullptr};
        if (!head) {
            head = newNode;
            head->next = head;
        } else {
            Node* temp = head;
            while (temp->next != head) temp = temp->next;
            temp->next = newNode;
            newNode->next = head;
        }
    }
    void tampilkanShift(int hari) {
        if (!head) {
            cout << "Shift kosong.\n";
            return;
        }
        Node* temp = head;
        for (int i = 1; i <= hari; i++) {
            cout << "Hari " << i << ": " << temp->nama << " bertugas\n";
            temp = temp->next;
        }
    }
};
int main() {
    ShiftKerja shift;
    shift.tambahKaryawan("Alice");
    shift.tambahKaryawan("Bob");
    shift.tambahKaryawan("Charlie");

    shift.tampilkanShift(5);
    return 0;
}
