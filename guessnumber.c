#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>  // 加入 ctype.h 標頭檔

int main() {
    srand(time(0));
    int num, chance = 7;
    int max = 100, min = 1;
    int ans = rand() % 100;
    char input[10];
    while (chance != 0) {
        printf("You have %d chance\nif you need hint enter \"hint\"\n", chance);
        printf("Enter your guess:");
        scanf("%s", input);
        printf("\033c");

        if (strcmp(input, "hint") == 0) { //判斷字元是否為"hint"，提示當前範圍
            printf("%d ~ %d\n", min, max);
        }

        else {
            int validInput = 1;
            for (int i = 0; i < strlen(input); i++) { //判斷當前輸入是否為有效數字，避免"hint"轉換整數型態
                if (!isdigit(input[i])) {
                    validInput = 0;
                    break;
                }
            }

            if (validInput) { //若當前輸入的是數字，執行以下程式碼
                sscanf(input, "%d", &num);
                if (num == ans) {
                    printf("Correct!\n");
                    break;
                } 
                else if (num > ans) {
                    if (num <= max) {
                        max = num - 1;
                    } 
                } 
                else if (num < ans) {
                    if (num >= min) {
                        min = num + 1;
                    }
                }
            }

            else { //當輸入結果並非數字或hint，顯示以下文字表示輸入無效
                printf("Invalid input. Please enter a valid number or \"hint\".\n");
            }
        }
        chance--;
    }

    if (chance == 0) {
        printf("Game over\nans:%d",ans);
    }
    return 0;
}