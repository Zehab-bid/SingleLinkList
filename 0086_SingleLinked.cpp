#include <iostream>
using namespace std;

class Node
{
    public:
        int noMhs;
        Node *next;
};

class LinkedList
{
    Node *START;

    public:
        LinkedList()
        {
            START = NULL;
        }

        void addNode()
        {
            int nim;
            cout << "\nmasukkan nomor mahasiswa : ";
            cin >> nim;

            Node *nodeBaru = new Node;
            nodeBaru->noMhs = nim;

            if (START == NULL || nim <= START ->noMhs)
            {
                if ((START != NULL ) && (nim == START->noMhs))
                {
                    cout << "\nduplikasi noMhs tidak diijinkan\n";
                    return;
                }
                nodeBaru->next = START;
                START = nodeBaru;
                return;
            }

            Node * previous = START;
            Node *current = START;

            while ((current != NULL) && (nim >= current->noMhs))
            {
                if (nim == current->noMhs)
                {
                    cout << "\nduplikasi tidak diijinkan\n";
                    return;
                }
                previous = current;
                current = current->next;
            }
            nodeBaru->next = current;
            previous->next = nodeBaru;
        }

        bool listEmpty()
        {
            return (START == NULL);
        }

        bool Search(int nim, Node **previous, Node **current)
        {
            *previous = START;
            *current = START;

            while ((*current != NULL) && (nim != (*current)->noMhs))
            {
                *previous = *current;
                *current = (*current)->next;
            }
            return (*current != NULL);
        }

        bool delNode(int nim)
        {
            Node *current, *previous;
            if (!Search(nim, & previous, &current))
                return false;

            if (current == START)
                START = START->next;

                delete current;
                return true;
        }

        void traverse() {
            if (listEmpty()) {
                cout << "\nList Kosong\n";
            } else {
                cout << "\nData di dalam list adalah:\n";
                Node *currentNode = START;
                while (currentNode != NULL) {
                    cout << currentNode->noMhs << endl;
                    currentNode = currentNode->next;
                }
            }
        }
};

int main() {
    LinkedList mhs;
    int nim;
    char ch;

    do {
        cout << "\nMenu";
        cout << "\n1. Menambah data kedalam list";
        cout << "\n2. Menghapus data dari dalam list";
        cout << "\n3. Menampilkan semua data didalam list";
        cout << "\n4. Mencari data dalam list";
        cout << "\n5. Keluar";
        cout << "\nMasukkan pilihan (1-5): ";
        cin >> ch;

        switch (ch) {
            case '1': {
                mhs.addNode();
                break;
            }
            case '2': {
                if (mhs.listEmpty()) {
                    cout << "\nList Kosong\n" << endl;
                    break;
                }
                cout << "\nMasukkan no mahasiswa yang akan dihapus: ";
                cin >> nim;
                if (mhs.delNode(nim)) {
                    cout << "Data dengan nomor mahasiswa " << nim << " berhasil dihapus\n" << endl;
                } else {
                    cout << "Data tidak ditemukan\n" << endl;
                }
                break;
            }
            case '3': {
                mhs.traverse();
                break;
            }
            case '4': {
                if (mhs.listEmpty() == true) {
                    cout << "\nList Kosong\n";
                    break;
                }

                Node *previous, *current;
                cout << "\nMasukkan no mahasiswa yang dicari: ";
                cin >> nim;
                if (mhs.Search(nim, &previous, &current) == false)
                    cout << "\nData tidak ditemukan\n" << endl;
                else {
                    cout << "\nData ditemukan\n";
                    cout << "\nNIM Mahasiswa: " << current->noMhs << endl;
                }
                break;