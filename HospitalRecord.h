#include <iostream>
#include <vector>
#include <algorithm> // for std::find_if
#include "Patient.h"
#include "Doctor.h"
#include "Invoice.h"


class HospitalRecord {
private:
    std::vector<Patient> patients;
    std::vector<Doctor> doctors;
    std::vector<Invoice> invoices;

public:
    void addPatient(Patient& patient) {
        patients.push_back(patient);
    }

    void addDoctor(const Doctor& doctor) {
        doctors.push_back(doctor);
    }

    Patient* findPatient(std::string& patientID) {
        auto it = std::find_if(patients.begin(), patients.end(), [&](Patient& patient) {
            return patient.getPatientID() == patientID;
        });

        if (it != patients.end()) {
            return &(*it);
        }
        return nullptr;
    }

    Doctor* findDoctor(std::string& doctorID) {
        auto it = std::find_if(doctors.begin(), doctors.end(), [&](Doctor& doctor) {
            return doctor.getDoctorID() == doctorID;
        });

        if (it != doctors.end()) {
            return &(*it);
        }
        return nullptr;
    }

    bool updatePatient(std::string& patientID, Patient& newPatient) {
        Patient* patientToUpdate = findPatient(patientID);
        if (patientToUpdate) {
            *patientToUpdate = newPatient;
            return true;
        }
        return false;
    }

    bool updateDoctor(std::string& doctorID, Doctor& newDoctor) {
        Doctor* doctorToUpdate = findDoctor(doctorID);
        if (doctorToUpdate) {
            *doctorToUpdate = newDoctor;
            return true;
        }
        return false;
    }

    bool deletePatient(std::string& patientID) {
        auto it = std::remove_if(patients.begin(), patients.end(), [&](Patient& patient) {
            return patient.getPatientID() == patientID;
        });

        if (it != patients.end()) {
            patients.erase(it, patients.end());
            return true;
        }
        return false;
    }

    bool deleteDoctor(std::string& doctorID) {
        auto it = std::remove_if(doctors.begin(), doctors.end(), [&](Doctor& doctor) {
            return doctor.getDoctorID() == doctorID;
        });

        if (it != doctors.end()) {
            doctors.erase(it, doctors.end());
            return true;
        }
        return false;
    }

    void displayPatients() {
        std::cout << "Hospital Records: " << std::endl;
        for (Patient& patient : patients) {
            std::cout << "Patient ID: " << patient.getPatientID() << ", Name: " << patient.getPatientName() << std::endl;
        }
    }

    void displayDoctors() {
        std::cout << "Doctors in the Hospital: " << std::endl;
        for (Doctor& doctor : doctors) {
            std::cout << "Doctor ID: " << doctor.getDoctorID() << ", Name: " << doctor.getDoctorName() << std::endl;
        }
    }

    void generateInvoice(Patient patient, std::string dateOfService, std::vector<std::string> services, double amountDue) {
            Invoice invoice(patient, dateOfService, services, amountDue);
            invoices.push_back(invoice);
        }

    void recordPayment(Patient patient, double amount) {
        for (Invoice& invoice : invoices) {
            if (invoice.getPatient() == patient) {
                invoice.recordPayment(amount);
                 break;
                }
            }
        }

    void viewOutstandingBalances() {
        for (Invoice& invoice : invoices) {
            if (invoice.getBalanceDue() > 0) {
                std::cout << "Patient: " << invoice.getPatient().getPatientName()
                        << ", Balance Due: " << invoice.getBalanceDue() << std::endl;
                }
            }
        }
    };