#ifndef DOCTOR_H
#define DOCTOR_H

#include <string>
#include <vector>
#include "Patient.h"

class Doctor {
private:
    std::string doctorID;
    std::string doctorName;
    std::string specialization;
    std::vector<Patient*> assignedPatients; // Store pointers to patients assigned to this doctor

public:
    Doctor() {}
    Doctor(std::string id, std::string name, std::string specialization) 
        : doctorID(id), doctorName(name), specialization(specialization) {}

    // Setters
    void setDoctorID(std::string& id) { doctorID = id; }
    void setDoctorName(std::string& name) { doctorName = name; }
    void setSpecialization(std::string& specialization) { this->specialization = specialization; }

    // Getters
    std::string getDoctorID() { return doctorID; }
    std::string getDoctorName() { return doctorName; }
    std::string getSpecialization() { return specialization; }
    
    // Doctor-Patient Assignment
    void assignPatient(Patient* patient);
    void unassignPatient(Patient* patient);
    std::vector<Patient*>& getAssignedPatients();
};

#endif // DOCTOR_H
