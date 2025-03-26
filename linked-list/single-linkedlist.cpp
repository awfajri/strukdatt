#include <iostream>
using namespace std;

struct Node {
    string judul;
    Node* next;
    Node(string j, Node* n = nullptr) : judul(j), next(n) {} // Constructor
};

class Perpustakaan {
private:
    Node* head = nullptr;
public:
    void kelolaBuku(string judul = "") {
        if (judul == "") { // Kembalikan buku
            if (!head) cout << "Tidak ada buku yang sedang dipinjam.\n";
            else {
                Node* temp = head;
                head = head->next;
                cout << "Buku '" << temp->judul << "' dikembalikan.\n";
                delete temp;
            }
        } else { // Pinjam buku
            Node* newNode = new Node(judul);
            if (!head) head = newNode;
            else {
                Node* temp = head;
                while (temp->next) temp = temp->next;
                temp->next = newNode;
            }
            cout << "Buku '" << judul << "' dipinjam.\n";
        }
        // Tampilkan daftar buku
        cout << "Daftar buku yang sedang dipinjam:\n";
        for (Node* temp = head; temp; temp = temp->next)
            cout << " - " << temp->judul << endl;
        cout << endl;
    }
};
int main() {
    Perpustakaan p;
    p.kelolaBuku("Harry Potter");
    p.kelolaBuku("Lord of the Rings");
    p.kelolaBuku("The Catcher in the Rye");

    p.kelolaBuku(); // Mengembalikan buku pertama

    return 0;
}

