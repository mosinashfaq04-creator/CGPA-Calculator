#include<iostream>
using namespace std;

class Node {
public:
    string cName;
    int credithrs;
    float grad;
    int semcreditHours;
    float semGPA;
    Node* next;

    Node() {}
    Node(string val) {
        cName = val;
        credithrs = 0;
        grad = 0.0;
        semcreditHours = 0;
        semGPA = 0.0;
        next = NULL;
    }
};

float gpaCalculator(Node* head, int TotalCredithours, float Totalpoints) {
    if (TotalCredithours == 0) return 0.0;
    return static_cast<float>(Totalpoints / TotalCredithours);
}

int main() {
    int choice = 0;

    cout << "\n          |------WELCOME TO CGPA CALCULATOR------|\n";

    do {
        Node* Head1 = NULL, * tail1 = NULL;
        int creditHours = 0, semcreditHours = 0;
        float grades = 0, semGPA = 0;
        int TotalCredithours = 0;
        float Totalpoints = 0.0;
        string courseName;
        int courseNum = 0;
        cout << "\n If You Want to Calculate your GPA and CGPA Press '2' Key to Continue Otherwise Press '1' for Exit\n";
        cout << "\n Enter Your Choice : ";
        cin >> choice;
        if (choice == 1) break;

        cout << "\n  Enter The Number of Courses : ";
        cin >> courseNum;

        // cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear buffer

         // ✅ Get course names properly
        for (int i = 0; i < courseNum; i++) {
            cout << "  Enter the Name of the Course " << i + 1 << ": ";
            cin >> courseName;
            // getline(cin, courseName);

            Node* newNode = new Node(courseName);
            if (!Head1) {
                Head1 = tail1 = newNode;
            }
            else {
                tail1->next = newNode;
                tail1 = newNode;
            }
        }

        cout << "\n|-------- Enter The Course Credit Hours And POINTS --------|\n\n";

        Node* temp1 = Head1;
        while (temp1)
        {
            cout << "   Enter Credit Hours for " << temp1->cName << ": ";
            cin >> creditHours;
            temp1->credithrs = creditHours;

            cout << "   Enter Points for " << temp1->cName << ": ";
            cin >> grades;
            temp1->grad = grades;

            temp1 = temp1->next;
        }

        cout << "\n|-------DISPLAY RESULT-------|\n";
        Node* temp2 = Head1;
        while (temp2) {
            if (temp2->grad <= 4 && temp2->grad > 3.5)
            {
                cout << "\n COURSE NAME : '" << temp2->cName << "' COURSE GRADES : 'A'\n";
            }
            if (temp2->grad <= 3.5 && temp2->grad > 3.0)
            {
                cout << "\n COURSE NAME : '" << temp2->cName << "' COURSE GRADES : 'B'\n";
            }
            if (temp2->grad <= 3.0 && temp2->grad > 2.5)
            {
                cout << "\n COURSE NAME : '" << temp2->cName << "' COURSE GRADES : 'C'\n";
            }
            if (temp2->grad <= 2.5 && temp2->grad > 2.0)
            {
                cout << "\n COURSE NAME : '" << temp2->cName << "' COURSE GRADES : 'D'\n";
            }
            if (temp2->grad < 2.0)
            {
                cout << "\n COURSE NAME : '" << temp2->cName << "' COURSE GRADES : 'F'\n";
            }
            temp2 = temp2->next;
        }

        Node* curr = Head1;
        while (curr)
        {
            TotalCredithours += curr->credithrs;
            Totalpoints += curr->credithrs * curr->grad;
            curr = curr->next;
        }

        cout << " \n YOUR GPA OF THIS SEMESTER IS <" << gpaCalculator(Head1, TotalCredithours, Totalpoints) << ">\n";

        int semNumber;
        cout << " Please Enter Number of Semester Which You have Done : ";
        cin >> semNumber;

        if (semNumber == 0) {
            cout << " \n YOUR CGPA IS <" << gpaCalculator(Head1, TotalCredithours, Totalpoints) << ">\n";
        }
        else {
            temp2 = Head1;
            for (int i = 0; i < semNumber && temp2; i++) {
                cout << " Enter The Credit Hours Of Semester : '" << i + 1 << "' ";
                cin >> semcreditHours;
                temp2->semcreditHours = semcreditHours;

                cout << " Enter The GPA Of Semester : '" << i + 1 << "' ";
                cin >> semGPA;
                temp2->semGPA = semGPA;

                temp2 = temp2->next;
            }

            temp2 = Head1;
            float semgrades = 0.0, CGPA;
            while (temp2) {
                semgrades += temp2->semGPA * temp2->semcreditHours;
                TotalCredithours += temp2->semcreditHours;
                temp2 = temp2->next;
            }

            Totalpoints += semgrades;
            CGPA = Totalpoints / TotalCredithours;
            cout << "\n YOUR CGPA OF ALL SEMESTER IS <" << CGPA << ">\n";
        }

        // ✅ Free memory
        while (Head1) {
            Node* del = Head1;
            Head1 = Head1->next;
            delete del;
        }
    } while (choice != 1);
    system("cls");

    cout << "\n|-----Thank You For the Calculation-----|\n";
}

