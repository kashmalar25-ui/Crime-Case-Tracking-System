#include "PresentationLayer.h"

int main() {

    // ---- Storage (dynamic memory using vectors of pointers) ----
    vector<SuspectProfile*>           suspects;
    vector<InvestigatorProfile*>      investigators;
    vector<CaseInvestigationReport*>  reports;
    vector<CaseEntry>                 cases;

    int choice;

    do {
        // Presentation Layer — show menu
        showMainMenu();
        choice = getInt("Enter your choice : ");

        // Route to correct Presentation Layer function
        switch (choice) {

            case 1:
                registerCase(cases);
                break;

            case 2:
                addSuspect(suspects);
                break;

            case 3:
                addInvestigator(investigators);
                break;

            case 4:
                generateReport(cases, suspects, investigators, reports);
                break;

            case 5:
                viewAllCases(cases);
                break;

            case 6:
                viewAllSuspects(suspects);
                break;

            case 7:
                viewAllInvestigators(investigators);
                break;

            case 8:
                viewAllReports(reports);
                break;

            case 9:
                // Prediction Analysis — calls Logic Layer inside
                runPrediction(reports);
                break;

            case 0:
                cout << "\n  Exiting system..." << endl;
                break;

            default:
                cout << "\n  [!] Invalid choice. Enter a number from the menu." << endl;
                pause();
                break;
        }

    } while (choice != 0);

    // ---- Clean up dynamic memory ----
    // Virtual destructors in DataLayer ensure clean deletion
    for (auto r : reports)       delete r;
    for (auto s : suspects)      delete s;
    for (auto i : investigators) delete i;

    cout << "\n  All memory cleaned up." << endl;
    cout << "  Goodbye!" << endl;

    return 0;
}
