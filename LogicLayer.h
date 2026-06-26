/*
 * ============================================================
 *  TIER 2 — LOGIC LAYER
 *  File: LogicLayer.h
 *
 *  Contains all derived classes and the prediction engine.
 *  Extends DataLayer classes. Handles all business logic.
 *
 *  Classes:
 *    - SuspectProfile      (extends PersonBase)
 *    - InvestigatorProfile (extends PersonBase)
 *    - CrimeScene          (virtual extends CrimeBase)
 *    - EvidenceRecord      (virtual extends CrimeBase)
 *    - CaseInvestigationReport (extends CrimeScene + EvidenceRecord)
 *    - PredictionEngine    (finds similar cases)
 * ============================================================
 */

#ifndef LOGICLAYER_H
#define LOGICLAYER_H

#include "DataLayer.h"
#include <vector>
#include <algorithm>
using namespace std;

// ============================================================
//  SuspectProfile — extends PersonBase
//  Adds suspect specific fields
// ============================================================
class SuspectProfile : public PersonBase {
private:
    string suspectCode;
    string criminalRecord;
    string arrestStatus;
    string riskLevel;

public:
    SuspectProfile()
        : PersonBase(), suspectCode(""), criminalRecord(""),
          arrestStatus(""), riskLevel("") {}

    SuspectProfile(string name, string id, string nat, string contact,
                   string code, string record, string arrest, string risk)
        : PersonBase(name, id, nat, contact),
          suspectCode(code), criminalRecord(record),
          arrestStatus(arrest), riskLevel(risk) {}

    ~SuspectProfile() {}

    // Getters
    string getSuspectCode()    const { return suspectCode; }
    string getCriminalRecord() const { return criminalRecord; }
    string getArrestStatus()   const { return arrestStatus; }
    string getRiskLevel()      const { return riskLevel; }

    // Setters
    void setSuspectCode(string v)    { suspectCode = v; }
    void setCriminalRecord(string v) { criminalRecord = v; }
    void setArrestStatus(string v)   { arrestStatus = v; }
    void setRiskLevel(string v)      { riskLevel = v; }

    void display() const override {
        cout << "  -- Suspect Profile --"          << endl;
        PersonBase::display();
        cout << "  Suspect Code   : " << suspectCode    << endl;
        cout << "  Criminal Record: " << criminalRecord << endl;
        cout << "  Arrest Status  : " << arrestStatus   << endl;
        cout << "  Risk Level     : " << riskLevel      << endl;
    }
};

// ============================================================
//  InvestigatorProfile — extends PersonBase
//  Adds officer specific fields
// ============================================================
class InvestigatorProfile : public PersonBase {
private:
    string badgeNumber;
    string rank;
    string department;
    int    yearsExperience;

public:
    InvestigatorProfile()
        : PersonBase(), badgeNumber(""), rank(""),
          department(""), yearsExperience(0) {}

    InvestigatorProfile(string name, string id, string nat, string contact,
                        string badge, string rnk, string dept, int exp)
        : PersonBase(name, id, nat, contact),
          badgeNumber(badge), rank(rnk),
          department(dept), yearsExperience(exp) {}

    ~InvestigatorProfile() {}

    // Getters
    string getBadgeNumber()     const { return badgeNumber; }
    string getRank()            const { return rank; }
    string getDepartment()      const { return department; }
    int    getYearsExperience() const { return yearsExperience; }

    // Setters
    void setBadgeNumber(string v)   { badgeNumber = v; }
    void setRank(string v)          { rank = v; }
    void setDepartment(string v)    { department = v; }
    void setYearsExperience(int v)  { yearsExperience = v; }

    void display() const override {
        cout << "  -- Investigator Profile --"          << endl;
        PersonBase::display();
        cout << "  Badge Number: " << badgeNumber       << endl;
        cout << "  Rank        : " << rank              << endl;
        cout << "  Department  : " << department        << endl;
        cout << "  Experience  : " << yearsExperience << " years" << endl;
    }
};

// ============================================================
//  CrimeScene — virtual inheritance from CrimeBase
//  virtual keyword prevents diamond problem later
// ============================================================
class CrimeScene : virtual public CrimeBase {
private:
    string sceneCondition;
    int    witnessCount;
    string forensicFindings;
    bool   sceneSecured;

public:
    CrimeScene()
        : CrimeBase(), sceneCondition(""), witnessCount(0),
          forensicFindings(""), sceneSecured(false) {}

    CrimeScene(string id, string type, string date, string loc,
               string cond, int wit, string forensic, bool secured)
        : CrimeBase(id, type, date, loc),
          sceneCondition(cond), witnessCount(wit),
          forensicFindings(forensic), sceneSecured(secured) {}

    ~CrimeScene() {}

    // Getters
    string getSceneCondition()   const { return sceneCondition; }
    int    getWitnessCount()     const { return witnessCount; }
    string getForensicFindings() const { return forensicFindings; }
    bool   isSceneSecured()      const { return sceneSecured; }

    // Setters
    void setSceneCondition(string v)   { sceneCondition = v; }
    void setWitnessCount(int v)        { witnessCount = v; }
    void setForensicFindings(string v) { forensicFindings = v; }
    void setSceneSecured(bool v)       { sceneSecured = v; }

    void display() const override {
        cout << "  -- Crime Scene --"                      << endl;
        CrimeBase::display();
        cout << "  Scene Condition  : " << sceneCondition  << endl;
        cout << "  Witness Count    : " << witnessCount    << endl;
        cout << "  Forensic Findings: " << forensicFindings<< endl;
        cout << "  Scene Secured    : " << (sceneSecured ? "Yes" : "No") << endl;
    }
};

// ============================================================
//  EvidenceRecord — virtual inheritance from CrimeBase
//  virtual keyword prevents diamond problem later
// ============================================================
class EvidenceRecord : virtual public CrimeBase {
private:
    string evidenceID;
    string evidenceType;
    string collectedBy;
    string labResult;

public:
    EvidenceRecord()
        : CrimeBase(), evidenceID(""), evidenceType(""),
          collectedBy(""), labResult("") {}

    EvidenceRecord(string id, string type, string date, string loc,
                   string evID, string evType, string collector, string lab)
        : CrimeBase(id, type, date, loc),
          evidenceID(evID), evidenceType(evType),
          collectedBy(collector), labResult(lab) {}

    ~EvidenceRecord() {}

    // Getters
    string getEvidenceID()   const { return evidenceID; }
    string getEvidenceType() const { return evidenceType; }
    string getCollectedBy()  const { return collectedBy; }
    string getLabResult()    const { return labResult; }

    // Setters
    void setEvidenceID(string v)   { evidenceID = v; }
    void setEvidenceType(string v) { evidenceType = v; }
    void setCollectedBy(string v)  { collectedBy = v; }
    void setLabResult(string v)    { labResult = v; }

    void display() const override {
        cout << "  -- Evidence Record --"               << endl;
        CrimeBase::display();
        cout << "  Evidence ID  : " << evidenceID      << endl;
        cout << "  Evidence Type: " << evidenceType    << endl;
        cout << "  Collected By : " << collectedBy     << endl;
        cout << "  Lab Result   : " << labResult       << endl;
    }
};

// ============================================================
//  CaseInvestigationReport — TIER 3 class (lives in LogicLayer
//  because it combines and processes all data)
//
//  Multiple Inheritance: CrimeScene + EvidenceRecord
//  Diamond Problem fixed because both use virtual CrimeBase
// ============================================================
class CaseInvestigationReport : public CrimeScene, public EvidenceRecord {
private:
    string reportID;
    string verdict;
    string caseStatus;
    string approvedBy;

    // Linked objects (composition)
    SuspectProfile*      suspect;
    InvestigatorProfile* investigator;

public:
    CaseInvestigationReport()
        : CrimeBase(), CrimeScene(), EvidenceRecord(),
          reportID(""), verdict(""), caseStatus(""), approvedBy(""),
          suspect(nullptr), investigator(nullptr) {}

    CaseInvestigationReport(
        string caseID,     string crimeType,  string date,      string loc,
        string cond,       int    wit,        string forensic,  bool   secured,
        string evID,       string evType,     string collector, string lab,
        string repID,      string verd,       string status,    string approver)
        :
        CrimeBase(caseID, crimeType, date, loc),
        CrimeScene(caseID, crimeType, date, loc, cond, wit, forensic, secured),
        EvidenceRecord(caseID, crimeType, date, loc, evID, evType, collector, lab),
        reportID(repID), verdict(verd), caseStatus(status), approvedBy(approver),
        suspect(nullptr), investigator(nullptr) {}

    ~CaseInvestigationReport() {}

    // Getters
    string getReportID()   const { return reportID; }
    string getVerdict()    const { return verdict; }
    string getCaseStatus() const { return caseStatus; }
    string getApprovedBy() const { return approvedBy; }

    // Setters
    void setReportID(string v)   { reportID = v; }
    void setVerdict(string v)    { verdict = v; }
    void setCaseStatus(string v) { caseStatus = v; }
    void setApprovedBy(string v) { approvedBy = v; }

    // Link suspect and investigator
    void linkSuspect(SuspectProfile* s)           { suspect = s; }
    void linkInvestigator(InvestigatorProfile* i) { investigator = i; }

    // Getters for linked objects (used by prediction engine)
    SuspectProfile*      getLinkedSuspect()      const { return suspect; }
    InvestigatorProfile* getLinkedInvestigator() const { return investigator; }

    void display() const override {
        cout << "\n  =====================================" << endl;
        cout << "      CASE INVESTIGATION REPORT       "   << endl;
        cout << "  =====================================" << endl;
        cout << "  Report ID  : " << reportID   << endl;
        cout << "  Verdict    : " << verdict     << endl;
        cout << "  Case Status: " << caseStatus  << endl;
        cout << "  Approved By: " << approvedBy  << endl;
        CrimeScene::display();
        EvidenceRecord::display();
        if (suspect)      suspect->display();
        if (investigator) investigator->display();
        cout << "  =====================================" << endl;
    }
};

// ============================================================
//  PredictionEngine — Logic Layer Feature
//
//  Looks at all existing reports and finds similar cases
//  based on: crime type, location, suspect risk level
//
//  Similarity Score:
//    +3 points  — same crime type
//    +2 points  — same location
//    +1 point   — same suspect risk level
//  Score >= 2  — considered a similar case
// ============================================================
class PredictionEngine {
public:

    // Convert string to lowercase for comparison
    static string toLower(string s) {
        for (char& c : s) c = tolower(c);
        return s;
    }

    // Check if two strings contain each other (partial match)
    static bool partialMatch(string a, string b) {
        a = toLower(a);
        b = toLower(b);
        return a.find(b) != string::npos || b.find(a) != string::npos;
    }

    // Calculate similarity score between a query and an existing report
    static int getSimilarityScore(
        string queryCrimeType,
        string queryLocation,
        string queryRiskLevel,
        CaseInvestigationReport* existingReport)
    {
        int score = 0;

        // +3 if crime type matches
        if (partialMatch(queryCrimeType, existingReport->getCrimeType()))
            score += 3;

        // +2 if location matches
        if (partialMatch(queryLocation, existingReport->getCrimeLocation()))
            score += 2;

        // +1 if suspect risk level matches
        if (existingReport->getLinkedSuspect() != nullptr) {
            if (partialMatch(queryRiskLevel,
                existingReport->getLinkedSuspect()->getRiskLevel()))
                score += 1;
        }

        return score;
    }

    // Main prediction function
    // Takes query inputs and a list of all reports
    // Returns a list of similar reports with their scores
    struct PredictionResult {
        CaseInvestigationReport* report;
        int score;
        string matchReason;
    };

    static vector<PredictionResult> findSimilarCases(
        string crimeType,
        string location,
        string riskLevel,
        vector<CaseInvestigationReport*>& allReports)
    {
        vector<PredictionResult> results;

        for (auto rep : allReports) {
            int score = getSimilarityScore(crimeType, location, riskLevel, rep);

            if (score >= 2) {
                string reason = "";

                if (partialMatch(crimeType, rep->getCrimeType()))
                    reason += "Crime type matches. ";

                if (partialMatch(location, rep->getCrimeLocation()))
                    reason += "Location matches. ";

                if (rep->getLinkedSuspect() != nullptr &&
                    partialMatch(riskLevel, rep->getLinkedSuspect()->getRiskLevel()))
                    reason += "Suspect risk level matches. ";

                results.push_back({rep, score, reason});
            }
        }

        // Sort by score — highest first
        sort(results.begin(), results.end(),
            [](PredictionResult& a, PredictionResult& b) {
                return a.score > b.score;
            });

        return results;
    }

    // Give a prediction message based on results
    static string getPredictionMessage(
        string crimeType,
        string location,
        vector<PredictionResult>& results)
    {
        if (results.empty())
            return "No similar cases found. This appears to be a new type of incident in this area.";

        if (results.size() == 1)
            return "1 similar case found. There may be a pattern developing in " + location + ".";

        if (results.size() >= 3)
            return "WARNING: " + to_string(results.size()) +
                   " similar cases found! High pattern detected for " +
                   crimeType + " in " + location +
                   ". Increased patrol recommended.";

        return to_string(results.size()) +
               " similar cases found. Possible repeat pattern for " +
               crimeType + " in " + location + ".";
    }
};

#endif
