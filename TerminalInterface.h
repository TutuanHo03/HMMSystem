#include <iostream>
#include <string>
#include "HospitalRecord.h"
#include <sstream>
class TerminalInterface {
private:
    HospitalRecord hospital;

public:

    TerminalInterface(HospitalRecord& hospital) : hospital(hospital) {}

    void displayMenu() {
        std::cout << "=============================================" << std::endl;
        std::cout << "===== Hospital Record Management System =====" << std::endl;
        std::cout << "1. Add Patient" << std::endl;
        std::cout << "2. Search Patient" << std::endl;
        std::cout << "3. Update Patient Information" << std::endl;
        std::cout << "4. Delete Patient" << std::endl;
        std::cout << "5. Display All Patients" << std::endl;
        std::cout << "6. Add Medical Record" << std::endl;
        std::cout << "7. Display Medical Records" << std::endl;
        std::cout << "8. Update Medical Record" << std::endl;
        std::cout << "9. Delete Medical Record" << std::endl;
        std::cout << "10. Add Doctor" << std::endl;
        std::cout << "11. Search Doctor" << std::endl;
        std::cout << "12. Update Doctor Information" << std::endl;
        std::cout << "13. Delete Doctor" << std::endl;
        std::cout << "14. Display All Doctors" << std::endl;
        std::cout << "15. Generate Invoice" << std::endl;
        std::cout << "16. Record Payment" << std::endl;
        std::cout << "17. View Outstanding Balances" << std::endl;
        std::cout << "0. Exit" << std::endl;
        std::cout << "=============================================" << std::endl;
    }
    
    std::vector<std::string> split(const std::string& str, char delimiter) {
        std::vector<std::string> tokens;
        std::string token;
        std::istringstream tokenStream(str);
        while (std::getline(tokenStream, token, delimiter)) {
            tokens.push_back(token);
        }
        return tokens;
    }

    void addPatient() {
        std::string id, name;
        int age;
        char gender;

        std::cout << "Enter Patient ID: ";
        std::cin >> id;
        std::cout << "Enter Patient Name: ";
        std::cin.ignore();
        std::getline(std::cin, name);
        std::cout << "Enter Patient Age: ";
        std::cin >> age;
        std::cout << "Enter Patient Gender (M/F): ";
        std::cin >> gender;

        Patient newPatient(id, name, age, gender);
        hospital.addPatient(newPatient);
        std::cout << "Patient added successfully!" << std::endl;
    }

    void searchPatient() {
        std::string id;
        std::cout << "Enter Patient ID to search: ";
        std::cin >> id;

        Patient* patient = hospital.findPatient(id);
        if (patient) {
            std::cout << "Patient Found!" << std::endl;
            std::cout << "Patient ID: " << patient->getPatientID() << std::endl;
            std::cout << "Patient Name: " << patient->getPatientName() << std::endl;
            std::cout << "Age: " << patient->getAge() << std::endl;
            std::cout << "Gender: " << patient->getGender() << std::endl;
        } else {
            std::cout << "Patient with ID " << id << " not found." << std::endl;
        }
    }

    void updatePatient() {
        std::string id;
        std::cout << "Enter Patient ID to update: ";
        std::cin >> id;

        Patient* patient = hospital.findPatient(id);
        if (patient) {
            std::string name;
            int age;
            char gender;

            std::cout << "Enter new Patient Name: ";
            std::cin.ignore();
            std::getline(std::cin, name);
            std::cout << "Enter new Patient Age: ";
            std::cin >> age;
            std::cout << "Enter new Patient Gender (M/F): ";
            std::cin >> gender;

            patient->setPatientName(name);
            patient->setAge(age);
            patient->setGender(gender);

            std::cout << "Patient with ID " << id << " updated successfully." << std::endl;
        } else {
            std::cout << "Patient with ID " << id << " not found." << std::endl;
        }
    }

    void deletePatient() {
        std::string id;
        std::cout << "Enter Patient ID to delete: ";
        std::cin >> id;

        bool success = hospital.deletePatient(id);
        if (success) {
            std::cout << "Patient with ID " << id << " deleted successfully." << std::endl;
        } else {
            std::cout << "Patient with ID " << id << " not found. Delete failed." << std::endl;
        }
    }

    void displayAllPatients() {
        hospital.displayPatients();
    }

    void addMedicalRecord() {
        std::string patientID, recordID, diagnosis, admissionDate, dischargeDate, status;

        std::cout << "Enter Patient ID: ";
        std::cin >> patientID;
        Patient* patient = hospital.findPatient(patientID);

        if (patient) {
            std::cout << "Enter Medical Record ID: ";
            std::cin >> recordID;
            std::cout << "Enter Diagnosis: ";
            std::cin.ignore();
            std::getline(std::cin, diagnosis);
            std::cout << "Enter Admission Date (YYYY-MM-DD): ";
            std::cin >> admissionDate;
            std::cout << "Enter Discharge Date (YYYY-MM-DD): ";
            std::cin >> dischargeDate;
            std::cout << "Enter Patient Status: ";
            std::cin.ignore();
            std::getline(std::cin, status);

            MedicalRecord newRecord(recordID, diagnosis, admissionDate, dischargeDate, status);
            patient->addMedicalRecord(newRecord);
            std::cout << "Medical Record added successfully!" << std::endl;
        } else {
            std::cout << "Patient with ID " << patientID << " not found." << std::endl;
        }
    }

    void displayMedicalRecords() {
        std::string patientID;
        std::cout << "Enter Patient ID to display medical records: ";
        std::cin >> patientID;

        Patient* patient = hospital.findPatient(patientID);
        if (patient) {
            std::vector<MedicalRecord>& records = patient->getMedicalRecords();
            if (!records.empty()) {
                std::cout << "Medical Records for Patient with ID " << patientID << ":" << std::endl;
                for (MedicalRecord& record : records) {
                    std::cout << "Record ID: " << record.getRecordID() << std::endl;
                    std::cout << "Diagnosis: " << record.getDiagnosis() << std::endl;
                    std::cout << "Admission Date: " << record.getAdmissionDate() << std::endl;
                    std::cout << "Discharge Date: " << record.getDischargeDate() << std::endl;
                    std::cout << "Status: " << record.getStatus() << std::endl;
                    std::cout << "------------------------" << std::endl;
                }
            } else {
                std::cout << "No medical records found for Patient with ID " << patientID << "." << std::endl;
            }
        } else {
            std::cout << "Patient with ID " << patientID << " not found." << std::endl;
        }
    }

    void updateMedicalRecord() {
        std::string patientID, recordID, diagnosis, admissionDate, dischargeDate, status;

        std::cout << "Enter Patient ID: ";
        std::cin >> patientID;
        Patient* patient = hospital.findPatient(patientID);

        if (patient) {
            std::cout << "Enter Medical Record ID to update: ";
            std::cin >> recordID;
            MedicalRecord* record = nullptr;

            for (MedicalRecord& medicalRecord : patient->getMedicalRecords()) {
                if (medicalRecord.getRecordID() == recordID) {
                    record = &medicalRecord;
                    break;
                }
            }

            if (record) {
                std::cout << "Enter new Diagnosis: ";
                std::cin.ignore();
                std::getline(std::cin, diagnosis);
                std::cout << "Enter new Admission Date (YYYY-MM-DD): ";
                std::cin >> admissionDate;
                std::cout << "Enter new Discharge Date (YYYY-MM-DD): ";
                std::cin >> dischargeDate;
                std::cout << "Enter new Status: ";
                std::cin.ignore();
                std::getline(std::cin, status);

                record->setDiagnosis(diagnosis);
                record->setAdmissionDate(admissionDate);
                record->setDischargeDate(dischargeDate);
                record->setStatus(status);

                std::cout << "Medical Record with ID " << recordID << " updated successfully." << std::endl;
            } else {
                std::cout << "Medical Record with ID " << recordID << " not found." << std::endl;
            }
        } else {
            std::cout << "Patient with ID " << patientID << " not found." << std::endl;
        }
    }

    void deleteMedicalRecord() {
        std::string patientID, recordID;

        std::cout << "Enter Patient ID: ";
        std::cin >> patientID;
        Patient* patient = hospital.findPatient(patientID);

        if (patient) {
            std::cout << "Enter Medical Record ID to delete: ";
            std::cin >> recordID;
            bool deleted = false;

            std::vector<MedicalRecord>& records = patient->getMedicalRecords();
            for (auto it = records.begin(); it != records.end(); ++it) {
                if (it->getRecordID() == recordID) {
                    records.erase(it);
                    deleted = true;
                    break;
                }
            }

            if (deleted) {
                std::cout << "Medical Record with ID " << recordID << " deleted successfully." << std::endl;
            } else {
                std::cout << "Medical Record with ID " << recordID << " not found." << std::endl;
            }
        } else {
            std::cout << "Patient with ID " << patientID << " not found." << std::endl;
        }
    }


    void addDoctor() {
        std::string id, name, specialization;

        std::cout << "Enter Doctor ID: ";
        std::cin >> id;
        std::cout << "Enter Doctor Name: ";
        std::cin.ignore();
        getline(std::cin, name);
        std::cout<< "Enter Doctor Specialization: ";
        getline(std::cin, specialization);

        Doctor newDoctor(id, name, specialization);
        hospital.addDoctor(newDoctor);
        std::cout<< "Doctor added successfully!"<<std::endl;
    }


    void searchDoctor() {
        std::string id;
        std::cout << "Enter Doctor ID to search: ";
        std::cin >> id;

        Doctor* doctor = hospital.findDoctor(id);
        if (doctor) {
            std::cout << "Doctor Found!" << std::endl;
            std::cout << "Doctor ID: " << doctor->getDoctorID() << std::endl;
            std::cout << "Doctor Name: " << doctor->getDoctorName() << std::endl;
            std::cout << "Specialization: " << doctor->getSpecialization() << std::endl;
        } else {
            std::cout << "Doctor with ID " << id << " not found." << std::endl;
        }
    }
    
    void updateDoctor() {
        std::string id, name, specialization;
        std::cout << "Enter Doctor ID to update: ";
        std::cin >> id;

        Doctor* doctor = hospital.findDoctor(id);
        if (doctor) {
            std::cout << "Enter new Doctor Name: ";
            std::cin.ignore();
            getline(std::cin, name);
            std::cout<< "Enter new Doctor Specialization: ";
            getline(std::cin, specialization);

            doctor->setDoctorName(name);
            doctor->setSpecialization(specialization);

            std::cout<< "Doctor with ID "<<id<<" updated successfully."<<std::endl;
        } else {
            std::cout<< "Doctor with ID "<<id<<" not found."<<std::endl;
        }
    }

    void deleteDoctor() {
        std::string id;
        std::cout << "Enter Doctor ID to delete: ";
        std::cin >> id;

        bool success = hospital.deleteDoctor(id);
        if (success) {
            std::cout << "Doctor with ID " << id << " deleted successfully." << std::endl;
        } else {
            std::cout << "Doctor with ID " << id << " not found. Delete failed." << std::endl;
        }
    }

    void displayAllDoctors() {
        hospital.displayDoctors();
    }
    
    void generateInvoice() {
        std::string patientID, dateOfService;
        std::vector<std::string> services;
        double amountDue;

        std::cout << "Enter Patient ID: ";
        std::cin >> patientID;
        std::cout << "Enter Date of Service (YYYY-MM-DD): ";
        std::cin >> dateOfService;
        std::cout << "Enter Services (separated by commas): ";
        std::string serviceList;
        std::cin.ignore();
        getline(std::cin, serviceList);
        services = split(serviceList, ',');
        std::cout << "Enter Amount Due: ";
        std::cin >> amountDue;

        Patient* patient = hospital.findPatient(patientID);
        if (patient) {
            hospital.generateInvoice(*patient, dateOfService, services, amountDue);
            std::cout << "Invoice generated successfully." << std::endl;
        } else {
            std::cout << "Patient with ID " << patientID << " not found." << std::endl;
        }
    }

    void recordPayment() {
        std::string patientID;
        double amount;

        std::cout << "Enter Patient ID: ";
        std::cin >> patientID;
        std::cout << "Enter Payment Amount: ";
        std::cin >> amount;

        Patient* patient = hospital.findPatient(patientID);
        if (patient) {
            hospital.recordPayment(*patient, amount);
            std::cout << "Payment recorded successfully." << std::endl;
        } else {
            std::cout << "Patient with ID " << patientID << " not found." << std::endl;
        }
    }


    void viewOutstandingBalances() {
        hospital.viewOutstandingBalances();
    }

};
