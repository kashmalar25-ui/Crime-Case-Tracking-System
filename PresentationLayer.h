

#ifndef PRESENTATIONLAYER_H
#define PRESENTATIONLAYER_H

#include "LogicLayer.h"
#include <iomanip>
using namespace std;

// ============================================================
//  Simple input helper functions
// ============================================================

void clearInput() {
    cin.ignore(1000, '\n');
}

string getStr(string prompt) {
    string val;
    cout << "  " << prompt;
    getline(cin, val);
    return val;
}

int getInt(string prompt) {
    int val;
    cout << "  " << prompt;
    cin  >> val;
    clearInput();
    return val;
}

void pause() {
    cout << "\n  Press Enter to go back...";
    cin.get();
}

void printLine() {
    cout << "  ---------------------------------------------" << endl;
}

void printTitle(string title) {
    cout << "\n  =============================================" << endl;
    cout << "   " << title                                    << endl;
    cout << "  =============================================" << endl;
}

// ============================================================
//  SHOW MAIN MENU
// ============================================================
void showMainMenu() {
    cout << "\n  =============================================" << endl;
    cout << "    CRIME CASE TRACKING & INVESTIGATION       " << endl;
    cout << "    CS112 | BSSE-II | Air University Multan   " << endl;
    cout << "  =============================================" << endl;
    cout << "                                               " << endl;
    cout << "   --- Records ---                             " << endl;
    cout << "   [1]  Register New Crime Case                " << endl;
    cout << "   [2]  Add Suspect Profile                    " << endl;
    cout << "   [3]  Add Investigator                       " << endl;
    cout << "   [4]  Generate Investigation Report          " << endl;
    cout << "                                               " << endl;
    cout << "   --- View ---                                 " << endl;
    cout << "   [5]  View All Cases                         " << endl;
    cout << "   [6]  View All Suspects                      " << endl;
    cout << "   [7]  View All Investigators                 " << endl;
    cout << "   [8]  View All Reports                       " << endl;
    cout << "                                               " << endl;
    cout << "   --- Analysis ---                             " << endl;
    cout << "   [9]  Run Prediction Analysis                " << endl;
    cout << "                                               " << endl;
    cout << "   [0]  Exit                                   " << endl;
    cout << "  =============================================" << endl;
}

// ============================================================
//  ADD SUSPECT
// ============================================================
void addSuspect(vector<SuspectProfile*>& suspects) {
    printTitle("ADD SUSPECT PROFILE");

    string name    = getStr("Full Name        : ");
    string id      = getStr("National ID      : ");
    string nat     = getStr("Nationality      : ");
    string contact = getStr("Contact Number   : ");
    string code    = getStr("Suspect Code     : ");
    string record  = getStr("Criminal Record  : ");

    cout << "\n  Arrest Status:" << endl;
    cout << "  [1] Arrested" << endl;
    cout << "  [2] At Large" << endl;
    int arrChoice  = getInt("Choose (1 or 2)  : ");
    string arrest  = (arrChoice == 1) ? "Arrested" : "At Large";

    cout << "\n  Risk Level:" << endl;
    cout << "  [1] High"   << endl;
    cout << "  [2] Medium" << endl;
    cout << "  [3] Low"    << endl;
    int riskChoice = getInt("Choose (1/2/3)   : ");
    string risk    = (riskChoice == 1) ? "High" :
                     (riskChoice == 2) ? "Medium" : "Low";

    suspects.push_back(new SuspectProfile(
        name, id, nat, contact, code, record, arrest, risk
    ));

    cout << "\n  [OK] Suspect added successfully!" << endl;
    pause();
}

// ============================================================
//  ADD INVESTIGATOR
// ============================================================
void addInvestigator(vector<InvestigatorProfile*>& investigators) {
    printTitle("ADD INVESTIGATOR");

    string name    = getStr("Full Name        : ");
    string id      = getStr("National ID      : ");
    string nat     = getStr("Nationality      : ");
    string contact = getStr("Contact Number   : ");
    string badge   = getStr("Badge Number     : ");
    string rank    = getStr("Rank             : ");
    string dept    = getStr("Department       : ");
    int    exp     = getInt("Years Experience : ");

    investigators.push_back(new InvestigatorProfile(
        name, id, nat, contact, badge, rank, dept, exp
    ));

    cout << "\n  [OK] Investigator added successfully!" << endl;
    pause();
}

// ============================================================
//  REGISTER CASE — stores basic case info for view list
// ============================================================
struct CaseEntry {
    string caseID;
    string crimeType;
    string date;
    string location;
};

void registerCase(vector<CaseEntry>& cases) {
    printTitle("REGISTER NEW CRIME CASE");

    CaseEntry c;
    c.caseID      = getStr("Case ID          : ");
    c.crimeType   = getStr("Crime Type       : ");
    c.date        = getStr("Date (DD-MM-YYYY): ");
    c.location    = getStr("Location         : ");

    cases.push_back(c);

    cout << "\n  [OK] Case registered! Generate a report to complete it." << endl;
    pause();
}

// ============================================================
//  GENERATE REPORT
// ============================================================
void generateReport(
    vector<CaseEntry>&             cases,
    vector<SuspectProfile*>&       suspects,
    vector<InvestigatorProfile*>&  investigators,
    vector<CaseInvestigationReport*>& reports)
{
    printTitle("GENERATE INVESTIGATION REPORT");

    if (cases.empty()) {
        cout << "\n  [!] No cases registered yet. Register a case first (Option 1)." << endl;
        pause();
        return;
    }

    // Show cases to pick from
    cout << "\n  Available Cases:" << endl;
    printLine();
    for (int i = 0; i < (int)cases.size(); i++) {
        cout << "  [" << i+1 << "] "
             << cases[i].caseID   << "  |  "
             << cases[i].crimeType << "  |  "
             << cases[i].location  << endl;
    }
    printLine();
    int caseChoice = getInt("Select case number: ");

    if (caseChoice < 1 || caseChoice > (int)cases.size()) {
        cout << "\n  [!] Invalid choice." << endl;
        pause();
        return;
    }

    CaseEntry& sc = cases[caseChoice - 1];

    // Scene details
    cout << "\n  -- Scene Details --" << endl;
    string cond    = getStr("Scene Condition  : ");
    int    wit     = getInt("Witness Count    : ");
    string forensic= getStr("Forensic Findings: ");
    int    secInt  = getInt("Scene Secured 1=Yes 0=No : ");
    bool   secured = (secInt == 1);

    // Evidence details
    cout << "\n  -- Evidence Details --" << endl;
    string evID      = getStr("Evidence ID      : ");
    string evType    = getStr("Evidence Type    : ");
    string collector = getStr("Collected By     : ");
    string lab       = getStr("Lab Result       : ");

    // Report details
    cout << "\n  -- Report Details --" << endl;
    string repID   = getStr("Report ID        : ");
    string verdict = getStr("Verdict          : ");

    cout << "\n  Case Status:" << endl;
    cout << "  [1] Open"         << endl;
    cout << "  [2] Under Review" << endl;
    cout << "  [3] Closed"       << endl;
    int stChoice = getInt("Choose (1/2/3)   : ");
    string status = (stChoice == 1) ? "Open" :
                    (stChoice == 2) ? "Under Review" : "Closed";

    string approver = getStr("Approved By      : ");

    // Create the report object — Tier 3 class
    CaseInvestigationReport* rep = new CaseInvestigationReport(
        sc.caseID, sc.crimeType, sc.date, sc.location,
        cond, wit, forensic, secured,
        evID, evType, collector, lab,
        repID, verdict, status, approver
    );

    // Link suspect if available
    if (!suspects.empty()) {
        cout << "\n  Available Suspects:" << endl;
        printLine();
        for (int i = 0; i < (int)suspects.size(); i++)
            cout << "  [" << i+1 << "] "
                 << suspects[i]->getFullName()
                 << "  (" << suspects[i]->getSuspectCode() << ")"
                 << "  Risk: " << suspects[i]->getRiskLevel() << endl;
        printLine();
        int si = getInt("Link suspect # (0 to skip): ");
        if (si >= 1 && si <= (int)suspects.size())
            rep->linkSuspect(suspects[si - 1]);
    }

    // Link investigator if available
    if (!investigators.empty()) {
        cout << "\n  Available Investigators:" << endl;
        printLine();
        for (int i = 0; i < (int)investigators.size(); i++)
            cout << "  [" << i+1 << "] "
                 << investigators[i]->getFullName()
                 << "  [" << investigators[i]->getRank() << "]" << endl;
        printLine();
        int ii = getInt("Link investigator # (0 to skip): ");
        if (ii >= 1 && ii <= (int)investigators.size())
            rep->linkInvestigator(investigators[ii - 1]);
    }

    reports.push_back(rep);

    cout << "\n  [OK] Report generated successfully!" << endl;
    pause();
}

// ============================================================
//  VIEW ALL CASES
// ============================================================
void viewAllCases(vector<CaseEntry>& cases) {
    printTitle("ALL CRIME CASES");

    if (cases.empty()) {
        cout << "\n  No cases registered yet." << endl;
        pause();
        return;
    }

    cout << "\n  "
         << setw(14) << left << "Case ID"
         << setw(16) << left << "Crime Type"
         << setw(20) << left << "Location"
         << "Date" << endl;
    printLine();

    for (auto& c : cases) {
        cout << "  "
             << setw(14) << left << c.caseID
             << setw(16) << left << c.crimeType
             << setw(20) << left << c.location
             << c.date    << endl;
    }

    printLine();
    cout << "  Total: " << cases.size() << " case(s)" << endl;
    pause();
}

// ============================================================
//  VIEW ALL SUSPECTS
// ============================================================
void viewAllSuspects(vector<SuspectProfile*>& suspects) {
    printTitle("ALL SUSPECTS");

    if (suspects.empty()) {
        cout << "\n  No suspects added yet." << endl;
        pause();
        return;
    }

    cout << "\n  "
         << setw(20) << left << "Name"
         << setw(12) << left << "Code"
         << setw(14) << left << "Arrest Status"
         << "Risk" << endl;
    printLine();

    for (auto s : suspects) {
        cout << "  "
             << setw(20) << left << s->getFullName()
             << setw(12) << left << s->getSuspectCode()
             << setw(14) << left << s->getArrestStatus()
             << s->getRiskLevel() << endl;
    }

    printLine();
    cout << "  Total: " << suspects.size() << " suspect(s)" << endl;
    pause();
}

// ============================================================
//  VIEW ALL INVESTIGATORS
// ============================================================
void viewAllInvestigators(vector<InvestigatorProfile*>& investigators) {
    printTitle("ALL INVESTIGATORS");

    if (investigators.empty()) {
        cout << "\n  No investigators added yet." << endl;
        pause();
        return;
    }

    cout << "\n  "
         << setw(20) << left << "Name"
         << setw(14) << left << "Badge"
         << setw(14) << left << "Rank"
         << "Department" << endl;
    printLine();

    for (auto i : investigators) {
        cout << "  "
             << setw(20) << left << i->getFullName()
             << setw(14) << left << i->getBadgeNumber()
             << setw(14) << left << i->getRank()
             << i->getDepartment() << endl;
    }

    printLine();
    cout << "  Total: " << investigators.size() << " investigator(s)" << endl;
    pause();
}

// ============================================================
//  VIEW ALL REPORTS
// ============================================================
void viewAllReports(vector<CaseInvestigationReport*>& reports) {
    printTitle("ALL INVESTIGATION REPORTS");

    if (reports.empty()) {
        cout << "\n  No reports generated yet." << endl;
        pause();
        return;
    }

    for (auto r : reports)
        r->display();

    cout << "\n  Total: " << reports.size() << " report(s)" << endl;
    pause();
}

// ============================================================
//  RUN PREDICTION ANALYSIS
//  Uses PredictionEngine from LogicLayer
// ============================================================
void runPrediction(vector<CaseInvestigationReport*>& reports) {
    printTitle("PREDICTION ANALYSIS");

    if (reports.empty()) {
        cout << "\n  [!] No reports in the system yet." << endl;
        cout << "  Add some cases and reports first, then run prediction." << endl;
        pause();
        return;
    }

    cout << "\n  Enter details of the new case to analyze:" << endl;
    printLine();

    string crimeType = getStr("Crime Type   : ");
    string location  = getStr("Location     : ");

    cout << "\n  Suspect Risk Level to match:" << endl;
    cout << "  [1] High"   << endl;
    cout << "  [2] Medium" << endl;
    cout << "  [3] Low"    << endl;
    int riskChoice   = getInt("Choose (1/2/3): ");
    string riskLevel = (riskChoice == 1) ? "High" :
                       (riskChoice == 2) ? "Medium" : "Low";

    // Call Logic Layer — PredictionEngine
    vector<PredictionEngine::PredictionResult> results =
        PredictionEngine::findSimilarCases(crimeType, location, riskLevel, reports);

    // Get prediction message
    string message = PredictionEngine::getPredictionMessage(crimeType, location, results);

    // Show results
    cout << "\n  =============================================" << endl;
    cout << "   PREDICTION RESULTS                        " << endl;
    cout << "  =============================================" << endl;
    cout << "\n  Query:" << endl;
    cout << "  Crime Type : " << crimeType << endl;
    cout << "  Location   : " << location  << endl;
    cout << "  Risk Level : " << riskLevel << endl;
    printLine();
    cout << "\n  Analysis: " << message << endl;
    printLine();

    if (!results.empty()) {
        cout << "\n  Similar Cases Found:" << endl;

        for (int i = 0; i < (int)results.size(); i++) {
            cout << "\n  [" << i+1 << "] Case ID    : "
                 << results[i].report->getCaseID()    << endl;
            cout << "      Crime Type : "
                 << results[i].report->getCrimeType() << endl;
            cout << "      Location   : "
                 << results[i].report->getCrimeLocation() << endl;
            cout << "      Verdict    : "
                 << results[i].report->getVerdict()   << endl;
            cout << "      Status     : "
                 << results[i].report->getCaseStatus()<< endl;

            if (results[i].report->getLinkedSuspect() != nullptr) {
                cout << "      Suspect    : "
                     << results[i].report->getLinkedSuspect()->getFullName()
                     << "  (Risk: "
                     << results[i].report->getLinkedSuspect()->getRiskLevel()
                     << ")" << endl;
            }

            cout << "      Match Score: " << results[i].score << "/6" << endl;
            cout << "      Reason     : " << results[i].matchReason << endl;
        }
    } else {
        cout << "\n  No similar cases found in the database." << endl;
    }

    cout << "\n  =============================================" << endl;
    pause();
}

#endif
