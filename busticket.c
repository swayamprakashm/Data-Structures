#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SEATS 50   // Max number of seats on the bus
#define BASE_PRICE 100 // Base price of a ticket

// Structure to store information about each ticket
struct Ticket {
    int ticketNumber;
    char customerName[100];
    int seatNumber;
    int price;
};

// Global variables for seat availability
int availableSeats = MAX_SEATS;
struct Ticket tickets[MAX_SEATS]; // Array to store booked tickets

// Function to calculate dynamic pricing based on available seats
int calculatePrice(int availableSeats) {
    int price = BASE_PRICE;

    // If fewer seats are available, increase the price dynamically
    if (availableSeats <= 10) {
        price += 50; // Increase price by 50 if there are 10 or fewer seats left
    } else if (availableSeats <= 20) {
        price += 30; // Increase price by 30 if there are between 10 and 20 seats left
    }

    return price;
}

// Function to book a ticket
void bookTicket() {
    if (availableSeats == 0) {
        printf("Sorry, no seats available.\n");
        return;
    }

    int seatNumber;
    char customerName[100];

    printf("Enter your name: ");
    getchar(); // To consume the newline character left by previous input
    fgets(customerName, sizeof(customerName), stdin);

    printf("Enter seat number (1 to 50): ");
    scanf("%d", &seatNumber);

    if (seatNumber < 1 || seatNumber > MAX_SEATS) {
        printf("Invalid seat number. Please choose a seat between 1 and 50.\n");
        return;
    }

    if (tickets[seatNumber - 1].ticketNumber != 0) {
        printf("Sorry, this seat is already booked.\n");
        return;
    }

    // Calculate price based on remaining available seats
    int price = calculatePrice(availableSeats);

    // Assign ticket number and other details
    tickets[seatNumber - 1].ticketNumber = seatNumber;
    snprintf(tickets[seatNumber - 1].customerName, sizeof(tickets[seatNumber - 1].customerName), "%s", customerName);
    tickets[seatNumber - 1].seatNumber = seatNumber;
    tickets[seatNumber - 1].price = price;

    // Decrease available seats
    availableSeats--;

    printf("Ticket booked successfully!\n");
    printf("Ticket Number: %d\n", seatNumber);
    printf("Customer Name: %s", customerName);
    printf("Seat Number: %d\n", seatNumber);
    printf("Price: %d\n", price);
}

// Function to display all booked tickets
void displayBookedTickets() {
    printf("\n--- Booked Tickets ---\n");
    int found = 0;
    for (int i = 0; i < MAX_SEATS; i++) {
        if (tickets[i].ticketNumber != 0) {
            found = 1;
            printf("Ticket Number: %d\n", tickets[i].ticketNumber);
            printf("Customer Name: %s", tickets[i].customerName);
            printf("Seat Number: %d\n", tickets[i].seatNumber);
            printf("Price: %d\n", tickets[i].price);
            printf("\n");
        }
    }

    if (!found) {
        printf("No tickets booked yet.\n");
    }
}

// Function to check availability of seats
void checkAvailability() {
    printf("\nAvailable seats: %d\n", availableSeats);
}

// Main menu function
void showMenu() {
    int choice;

    do {
        printf("\n----- Bus Ticket Reservation System -----\n");
        printf("1. Book a Ticket\n");
        printf("2. View All Booked Tickets\n");
        printf("3. Check Seat Availability\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                bookTicket();
                break;
            case 2:
                displayBookedTickets();
                break;
            case 3:
                checkAvailability();
                break;
            case 4:
                printf("Exiting the system...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);
}

int main() {
    // Initialize ticket details to 0 (empty)
    for (int i = 0; i < MAX_SEATS; i++) {
        tickets[i].ticketNumber = 0;
    }

    // Show the menu to the user
    showMenu();

    return 0;
}
