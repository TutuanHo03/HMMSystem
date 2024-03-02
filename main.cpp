#include <iostream>
#include <string>
#include "TerminalInterface.h"

int main() {
    HospitalRecord hospital;

    MedicalRecord record1("R001", "Diagnosis 1", "2023-07-01", "2023-07-05", "Recovered");
    MedicalRecord record2("R002", "Diagnosis 2", "2023-07-10", "2023-07-15", "In treatment");
    MedicalRecord record3("R003", "Diagnosis 3", "2023-07-20", "2023-07-25", "Recovered");
    MedicalRecord record4("R004", "Diagnosis 4", "2023-08-05", "2023-08-10", "In treatment");
    MedicalRecord record5("R005", "Diagnosis 5", "2023-08-15", "2023-08-20", "Recovered");

    Patient patient1("P001", "John Doe", 30, 'M');
    Patient patient2("P002", "Jane Smith", 25, 'F');
    Patient patient3("P003", "Michael Johnson", 40, 'M');

    patient1.addMedicalRecord(record1);
    patient1.addMedicalRecord(record2);
    patient1.addMedicalRecord(record3);
    patient1.addMedicalRecord(record4);
    patient1.addMedicalRecord(record5);

    patient2.addMedicalRecord(record1);
    patient2.addMedicalRecord(record2);
    patient2.addMedicalRecord(record3);
    patient2.addMedicalRecord(record4);
    patient2.addMedicalRecord(record5);

    patient3.addMedicalRecord(record1);
    patient3.addMedicalRecord(record2);
    patient3.addMedicalRecord(record3);
    patient3.addMedicalRecord(record4);
    patient3.addMedicalRecord(record5);

    hospital.addPatient(patient1);
    hospital.addPatient(patient2);
    hospital.addPatient(patient3);

TerminalInterface terminal(hospital);

    int choice;

    do {
        terminal.displayMenu();
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        std::cin.ignore();

        switch (choice) {
            case 1: {
                terminal.addPatient();
                break;
            }
            case 2: {
                terminal.searchPatient();
                break;
            }
            case 3: {
                terminal.updatePatient();
                break;
            }
            case 4: {
                terminal.deletePatient();
                break;
            }
            case 5: {
                terminal.displayAllPatients();
                break;
            }
            case 6: {
                terminal.addMedicalRecord();
                break;
            }
            case 7: {
                terminal.displayMedicalRecords();
                break;
            }
            case 8: {
                terminal.updateMedicalRecord();
                break;
            }
            case 9: {
                terminal.deleteMedicalRecord();
                break;
            }
            case 10: {
                terminal.addDoctor();
                break;
            }
            case 11: {
                terminal.searchDoctor();
                break;
            }
            case 12: {
                terminal.updateDoctor();
                break;
            }
            case 13: {
                terminal.deleteDoctor();
                break;
            }
            case 14: {
                terminal.displayAllDoctors();
                break;
            }
             case 15: {
                terminal.generateInvoice();
                break;
            }
            case 16: {
                terminal.recordPayment();
                break;
            }
            case 17: {
                terminal.viewOutstandingBalances();
                break;
            }
            case 0: {
                std::cout << "Exiting the program..." << std::endl;
                break;
            }
            default: {
                std::cout << "Invalid choice. Please try again." << std::endl;
                break;
            }
        }

    } while (choice != 0);

    return 0;
}
