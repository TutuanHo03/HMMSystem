#include <string>
#include <vector>
#include "Patient.h"

class Invoice {
private:
    Patient patient;
    std::string dateOfService;
    std::vector<std::string> services;
    double amountDue;
    double amountPaid;

public:
    Invoice(Patient patient, std::string dateOfService, std::vector<std::string> services, double amountDue)
        : patient(patient), dateOfService(dateOfService), services(services), amountDue(amountDue), amountPaid(0) {}

    Patient getPatient() {
        return patient;
    }

    double getBalanceDue() {
        return amountDue - amountPaid;
    }

    void recordPayment(double amount) {
        amountPaid += amount;
    }

    
};
