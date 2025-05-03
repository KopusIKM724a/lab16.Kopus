#include <iostream>
#include <string>

using namespace std;

class File {
private:
    string name;
    double sizeMB;
    string creationDate;
    int accessCount;

public:
    void set(string n, double s, string d, int a) {
        name = n;
        sizeMB = s;
        creationDate = d;
        accessCount = a;
    }

    string getName() const { return name; }
    double getSize() const { return sizeMB; }
    string getDate() const { return creationDate; }
    int getAccessCount() const { return accessCount; }

    void show() const {
        cout << "Name: " << name
            << ", Size: " << sizeMB << " MB"
            << ", Creation Date: " << creationDate
            << ", Access Count: " << accessCount << endl;
    }
};

// Bubble sort by file name
void sortByName(File files[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (files[j].getName() > files[j + 1].getName()) {
                File temp = files[j];
                files[j] = files[j + 1];
                files[j + 1] = temp;
            }
        }
    }
}

int main() {
    int N;
    cout << "Enter the number of files: ";
    cin >> N;

    File* files = new File[N];

    // Input file data
    for (int i = 0; i < N; i++) {
        string name, date;
        double size;
        int access;

        cout << "\nEnter data for file " << i + 1 << ":\n";
        cout << "Name: ";
        cin >> name;
        cout << "Size (MB): ";
        cin >> size;
        cout << "Creation Date (): ";
        cin >> date;
        cout << "Access Count: ";
        cin >> access;

        files[i].set(name, size, date, access);
    }

    // a) Sort by name
    sortByName(files, N);
    cout << "\n--- a) Files sorted by name ---\n";
    for (int i = 0; i < N; i++) {
        files[i].show();
    }

    // b) Filter by size
    double sizeLimit;
    cout << "\n--- b) Enter size limit (MB): ";
    cin >> sizeLimit;
    cout << "Files with size > " << sizeLimit << " MB:\n";
    for (int i = 0; i < N; i++) {
        if (files[i].getSize() > sizeLimit) {
            files[i].show();
        }
    }

    // c) Filter by access count
    int accessLimit;
    cout << "\n--- c) Enter access count limit: ";
    cin >> accessLimit;
    cout << "Files with access count > " << accessLimit << ":\n";
    for (int i = 0; i < N; i++) {
        if (files[i].getAccessCount() > accessLimit) {
            files[i].show();
        }
    }

    delete[] files;
    return 0;
}
