#ifndef PATIENT_H
#define PATIENT_H

#include <string>
#include <vector>
#include "MedicalRecord.h"

class Patient {
private:
    std::string patientID;
    std::string patientName;
    int age;
    char gender;
    std::vector<MedicalRecord> medicalRecords;

public:
    Patient() {}
    Patient(std::string id, std::string name, int age, char gender)
        : patientID(id), patientName(name), age(age), gender(gender) {}

    // Setters
    void setPatientID(std::string& id) { patientID = id; }
    void setPatientName(std::string& name) { patientName = name; }
    void setAge(int age) { this->age = age; }
    void setGender(char gender) { this->gender = gender; }

    // Getters
    std::string getPatientID() { return patientID; }
    std::string getPatientName() { return patientName; }
    int getAge() { return age; }
    char getGender() { return gender; }

    void addMedicalRecord(MedicalRecord& record) {
        medicalRecords.push_back(record);
    }

    std::vector<MedicalRecord>& getMedicalRecords() {
        return medicalRecords;
    }
    bool operator==(Patient& other) {
        return patientID == other.patientID;
    }
};
#endif // PATIENT_H