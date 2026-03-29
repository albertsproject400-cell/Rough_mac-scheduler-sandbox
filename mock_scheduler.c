#include <stdio.h>
#include <math.h>

typedef struct {
    int id;
    int is_URLLC;
    double head_of_line_delay; 
} User;

int main() {
    User users[2] = {
        {1, 0, 5.0},  
        {2, 1, 9.5}   
    };
    
    int deadline = 10;
    int winner_id = -1;
    double highest_priority = -1.0;

    for(int i = 0; i < 2; i++) {
        double priority = 1.0; 
        
        if (users[i].is_URLLC == 1) {
            if (users[i].head_of_line_delay >= deadline) {
                priority = 999999.0; 
            } else {
                priority = exp(users[i].head_of_line_delay / (deadline - users[i].head_of_line_delay));
            }
        }
        
        if (priority > highest_priority) {
            highest_priority = priority;
            winner_id = users[i].id;
        }
    }

    printf("WINNER: Resource Block assigned to User %d\n", winner_id);
    return 0;
}