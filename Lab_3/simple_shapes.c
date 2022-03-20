#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define YEL   "\x1B[33m"
#define WHT   "\x1B[37m"
#define RESET "\x1B[0m"

enum shape {OVAL, RECTANGLE};

typedef struct {
    int shape;
    int size;
    char *color;
} Graphic;

/* 
Students: Create a new type "Graphic" that can store:
- shape (OVAL, RECTANGLE) -> create a new enum for this type
- size
- color
*/


void paint(Graphic graphic) {
    double radius = graphic.size / 2.0;
    int i,j;

    for (i = 0; i <= 2 * radius; i++){
        for (j = 0; j <= 2 * radius; j++){
            switch(graphic.shape) {
                case RECTANGLE: printf("%s*" RESET, graphic.color); break;
                case OVAL: {
                    double distance = sqrt((i - radius) * (i - radius) + (j - radius) * (j - radius));
                    if (distance > radius - 0.5 && distance < radius + 0.5) {
                        printf("%s*" RESET, graphic.color);
                    } else { 
                        printf(" ");
                    }
                } break;

            }
        }
        printf("\n");
    }
}

int main() {
    int input;
    Graphic graphic;

    do {
        printf("Geben Sie die gewünschte Form an [OVAL=0 | RECTANGLE=1]:");
        if (scanf("%d", &input)!=1||
            (input!=1&&input!=0)){
            printf("Geben sie entweder eine 0 oder eine 1 ein.\n");
            exit(0);
        }
        graphic.shape = input;
        // Students: store the input in graphic

        printf("Geben Sie die gewünschte Grösse an:");
        if (scanf("%u", &input)!=1||input<1){
            printf("Geben sie eine positive Zahl ein.\n");
            exit(0);
        }
        graphic.size = input;
        // Students: store the input in graphic

        printf("Geben Sie die gewünschte Farb an [RED=0 | GREEN=1 | YELLOW=2]:");
        if (scanf("%d", &input)!=1||
            (input != 1 && input != 0 && input != 2)){
            printf("Geben sie entweder eine 0, eine 1 oder eine 2 ein.\n");
            exit(0);
        }
        if (input == 0) {
           graphic.color = RED;
        }
        if (input == 1) {
           graphic.color = GRN;
        }
        if (input == 2) {
           graphic.color = YEL;
        }
        
        // Students: store the input in graphic
        
        paint(graphic);
        
        while(getchar() != '\n'); // empty buffer
        printf("\nMöchten sie weiter machen oder abbrechen? [(n)ext|(q)uit] ");
    } while(getchar() == 'n');

    printf("Byebye..\n");
    return EXIT_SUCCESS;
}
