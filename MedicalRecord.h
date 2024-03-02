#ifndef MEDICALRECORD_H
#define MEDICALRECORD_H
#include <string>
using namespace std;
class MedicalRecord {
private:
    string recordID;
    string diagnosis;
    string admissionDate;
    string dischargeDate;
    string status;

public:
    MedicalRecord() {}
    MedicalRecord(string id, string diagnosis, string admissionDate,
                  string dischargeDate, string status)
        : recordID(id), diagnosis(diagnosis), admissionDate(admissionDate),
          dischargeDate(dischargeDate), status(status) {}
	~MedicalRecord() {}
	
    // Setters
    void setRecordID(string& id) { recordID = id; }
    void setDiagnosis(string& diagnosis) { this->diagnosis = diagnosis; }
    void setAdmissionDate(string& date) { admissionDate = date; }
    void setDischargeDate(string& date) { dischargeDate = date; }
    void setStatus(string& status) { this->status = status; }

    // Getters
    string getRecordID() { return recordID; }
    string getDiagnosis() { return diagnosis; }
    string getAdmissionDate() { return admissionDate; }
    string getDischargeDate() { return dischargeDate; }
    string getStatus() { return status; }
};
#endif // MEDICALRECORD_H
